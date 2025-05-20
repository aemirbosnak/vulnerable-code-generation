//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT "8080"
#define SERVER_ADDRESS "localhost"

void error_handling(char* message);

int main(int argc, char** argv) {
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error_handling("socket failed");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        error_handling("connect failed");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        printf("Enter message: ");
        fgets(buffer, sizeof(buffer), stdin);

        n = strlen(buffer);
        send(sockfd, buffer, n, 0);

        memset(buffer, 0, sizeof(buffer));
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        buffer[n] = '\0';

        printf("Received message: %s\n", buffer);
    }

    close(sockfd);
    exit(0);
}

void error_handling(char* message) {
    fprintf(stderr, "%s (%d): %s\n", message, errno, strerror(errno));
    exit(1);
}