//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>
#include <pthread.h>

int sockfd;
struct sockaddr_in server_addr;
char buffer[1024];

void *thread_func(void *arg) {
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        ssize_t read_size = recv(sockfd, buffer, sizeof(buffer), 0);
        if (read_size <= 0) {
            printf("Read error: %s\n", strerror(errno));
            break;
        }
        printf("Received message: %s\n", buffer);
    }
    close(sockfd);
    pthread_exit(0);
}

int main() {
    int port = 8080;
    char *ip = "127.0.0.1";
    struct hostent *server = gethostbyname(ip);
    if (server == NULL) {
        printf("Error: Host not found.\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Socket creation failed.\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr))!= 0) {
        printf("Error: Connection failed.\n");
        exit(1);
    }

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_func, NULL);

    while (1) {
        char message[1024];
        fgets(message, sizeof(message), stdin);
        send(sockfd, message, strlen(message), 0);
        if (strlen(message) == 0 || strcmp(message, "/quit") == 0) {
            break;
        }
    }

    close(sockfd);
    return 0;
}