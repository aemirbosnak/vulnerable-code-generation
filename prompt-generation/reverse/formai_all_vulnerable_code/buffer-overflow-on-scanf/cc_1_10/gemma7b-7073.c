//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    int sockfd, n, port, i;
    char buffer[MAX_BUFFER_SIZE], hostname[256], command[256];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Enter command: ");
    scanf("%s", command);

    send(sockfd, command, strlen(command) + 1, 0);

    n = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (n < 0) {
        perror("Error receiving data");
        exit(1);
    }

    printf("Received data: %s\n", buffer);

    close(sockfd);

    return 0;
}