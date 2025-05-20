//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 1024
#define PORT 8080

struct sockaddr_in server_addr;
int sockfd;

void *thread(void *arg) {
    char buffer[MAX_SIZE];
    while (TRUE) {
        memset(buffer, 0, MAX_SIZE);
        int bytes_received = recv(sockfd, buffer, MAX_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("Received: %s\n", buffer);
    }
    return NULL;
}

int main() {
    int opt = TRUE;
    pthread_t thread_id;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        printf("Error opening socket\n");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(EXIT_FAILURE);
    }

    while (opt) {
        char buffer[MAX_SIZE];
        memset(buffer, 0, MAX_SIZE);
        gets(buffer);
        send(sockfd, buffer, strlen(buffer), 0);
        if (strcmp(buffer, "bye") == 0) {
            opt = FALSE;
        }
    }

    close(sockfd);
    pthread_exit(0);

    return 0;
}