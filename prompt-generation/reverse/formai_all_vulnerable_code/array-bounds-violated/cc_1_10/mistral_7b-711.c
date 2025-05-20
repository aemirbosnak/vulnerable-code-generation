//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define SERVER_IP "127.0.0.1"

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    char stock_symbol[10];
    char response[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to stock market server.\n");

    while (1) {
        printf("Enter stock symbol: ");
        scanf("%s", stock_symbol);

        sprintf(buffer, "GET %s\n", stock_symbol);
        send(sockfd, buffer, strlen(buffer), 0);

        ssize_t n = recv(sockfd, response, BUFFER_SIZE, 0);
        response[n] = '\0';

        if (strcmp(response, "ERROR") == 0) {
            printf("Invalid stock symbol.\n");
            continue;
        }

        printf("\nCurrent price for %s: %s\n", stock_symbol, response);

        memset(response, 0, BUFFER_SIZE);
    }

    close(sockfd);
    return 0;
}