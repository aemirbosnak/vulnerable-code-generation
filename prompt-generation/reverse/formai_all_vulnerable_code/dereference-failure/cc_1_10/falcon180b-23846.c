//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Failed to create socket.\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server.\n");
        exit(1);
    }

    printf("Connected to server.\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);
        if (strcmp(buffer, "/quit") == 0) {
            break;
        }
        send(sockfd, buffer, strlen(buffer), 0);
    }

    close(sockfd);

    return 0;
}