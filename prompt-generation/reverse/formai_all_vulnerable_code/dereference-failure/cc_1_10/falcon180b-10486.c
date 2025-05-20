//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

char *filename;
int sockfd, newsockfd, len;
struct sockaddr_in serv_addr, cli_addr;

void *thread_function(void *arg) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while (1) {
        bytes_received = recv(newsockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer);
    }

    close(newsockfd);
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    int opt, val;
    pthread_t thread_id;

    if (argc!= 3) {
        printf("Usage:./server <port_number> <filename>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    val = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(sockfd, BACKLOG);

    printf("Server is listening on port %s\n", argv[1]);
    printf("File name: %s\n", argv[2]);

    while (1) {
        len = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &len);
        if (newsockfd == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        pthread_create(&thread_id, NULL, thread_function, (void *)newsockfd);
    }

    return 0;
}