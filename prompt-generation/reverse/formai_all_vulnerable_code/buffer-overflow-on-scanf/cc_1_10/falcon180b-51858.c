//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *server_ip = "127.0.0.1";
    char *server_port = "21";
    char buffer[BUF_SIZE];
    int n;
    char command[100];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(server_port));
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "USER") == 0) {
            sprintf(buffer, "USER %s\r\n", command);
            send(sockfd, buffer, strlen(buffer), 0);
        } else if (strcmp(command, "PASS") == 0) {
            sprintf(buffer, "PASS %s\r\n", command);
            send(sockfd, buffer, strlen(buffer), 0);
        } else if (strcmp(command, "LIST") == 0) {
            sprintf(buffer, "LIST\r\n");
            send(sockfd, buffer, strlen(buffer), 0);
        } else if (strcmp(command, "QUIT") == 0) {
            sprintf(buffer, "QUIT\r\n");
            send(sockfd, buffer, strlen(buffer), 0);
            break;
        }
    }

    close(sockfd);

    return 0;
}