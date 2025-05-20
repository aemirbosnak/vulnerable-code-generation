//FormAI DATASET v1.0 Category: Client Server Application ; Style: Romeo and Juliet
/* A Romeo and Juliet style Chat Application */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_SIZE 1024
#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd;
    char buf[BUF_SIZE];
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_socklen = sizeof(client_addr);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 10) == -1) {
        perror("Failed to listen");
        exit(EXIT_FAILURE);
    }

    int clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_socklen);

    if (clientfd == -1) {
        perror("Failed to accept");
        exit(EXIT_FAILURE);
    }

    while (1) {
        memset(buf, 0, BUF_SIZE);
        recv(clientfd, buf, BUF_SIZE, 0);

        if (strcmp(buf, "exit") == 0) {
            break;
        }

        printf("Juliet: %s\n", buf);
        printf("Romeo: ");

        fgets(buf, BUF_SIZE, stdin);
        buf[strlen(buf)-1] = '\0';

        send(clientfd, buf, strlen(buf), 0);
    }

    close(clientfd);
    close(sockfd);
    return 0;
}