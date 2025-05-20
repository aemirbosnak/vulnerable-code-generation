//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

static int sockfd;
static struct sockaddr_in servaddr;
static pthread_t thread_id;
static int thread_running = 1;

void *thread_function(void *arg)
{
    char buffer[1024];
    int n;

    while (thread_running) {
        n = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
        if (n < 0) {
            perror("recvfrom");
            break;
        }
        buffer[n] = '\0';
        printf("Received: %s\n", buffer);
    }

    return NULL;
}

int main(int argc, char **argv)
{
    int ret;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Bind the socket to the server address
    ret = bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (ret < 0) {
        perror("bind");
        return -1;
    }

    // Create a thread to receive messages from the client
    ret = pthread_create(&thread_id, NULL, thread_function, NULL);
    if (ret < 0) {
        perror("pthread_create");
        return -1;
    }

    // Wait for the user to press Enter
    printf("Press Enter to exit\n");
    getchar();

    // Stop the thread
    thread_running = 0;
    pthread_join(thread_id, NULL);

    // Close the socket
    close(sockfd);

    return 0;
}