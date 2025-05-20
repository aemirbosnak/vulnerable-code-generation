//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define BUF_SIZE 1024
#define TRUE 1
#define FALSE 0

struct sockaddr_in server_addr;
int sockfd;
char *message = "Hello from client";
char buffer[BUF_SIZE];

void *thread_func(void *arg) {
    while (TRUE) {
        memset(buffer, 0, BUF_SIZE);
        if (recv(sockfd, buffer, BUF_SIZE, 0) <= 0) {
            printf("Connection closed by server\n");
            pthread_exit(0);
        }
        printf("Received message: %s\n", buffer);
    }
}

int main() {
    int port = 8080;
    pthread_t thread_id;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    pthread_create(&thread_id, NULL, thread_func, NULL);

    while (TRUE) {
        memset(buffer, 0, BUF_SIZE);
        printf("Enter message to send: ");
        scanf("%s", buffer);
        send(sockfd, buffer, strlen(buffer), 0);
    }

    close(sockfd);
    return 0;
}