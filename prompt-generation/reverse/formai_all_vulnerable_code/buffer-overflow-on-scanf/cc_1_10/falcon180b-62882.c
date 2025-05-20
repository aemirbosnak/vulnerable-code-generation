//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE 1024
#define MAX_COMMAND_LENGTH 100

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAX_LINE];
    char command[MAX_COMMAND_LENGTH];
    int n;
    int port;
    char* host;

    printf("Enter the IMAP server hostname or IP address: ");
    scanf("%s", host);
    printf("Enter the IMAP server port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: socket creation failed\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, host, &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error: connection failed\n");
        exit(1);
    }

    printf("Connected to IMAP server\n");

    while (1) {
        printf("Enter command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        send(sockfd, command, strlen(command), 0);

        memset(buffer, 0, sizeof(buffer));
        n = recv(sockfd, buffer, MAX_LINE, 0);
        if (n <= 0) {
            printf("Error: connection closed\n");
            exit(1);
        }
        printf("Server response: %s", buffer);
    }

    close(sockfd);
    return 0;
}