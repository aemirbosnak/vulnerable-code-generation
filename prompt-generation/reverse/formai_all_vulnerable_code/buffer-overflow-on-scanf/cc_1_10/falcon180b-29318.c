//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    printf("Enter FTP server IP address: ");
    scanf("%s", &command);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(21);
    inet_pton(AF_INET, command, &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter command (quit to exit): ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        send(sockfd, command, strlen(command), 0);
        memset(buffer, 0, BUFFER_SIZE);
        recv(sockfd, buffer, BUFFER_SIZE, 0);
        printf("%s", buffer);
    }

    close(sockfd);
}