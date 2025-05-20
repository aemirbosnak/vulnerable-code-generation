//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 512
#define FTP_PORT 21
#define BUFFER_SIZE 1024
#define FTP_USER "anonymous"
#define FTP_PASS "anonymous@example.com"

int main() {
    char hostname[256];
    int port = FTP_PORT;
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *command = malloc(MAX_COMMAND_LENGTH);

    printf("Enter FTP server hostname: ");
    scanf("%s", hostname);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server.\n");
        exit(2);
    }

    printf("Connected to %s.\n", hostname);

    while (1) {
        printf("Enter command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = '\0';

        if (send(sockfd, command, strlen(command), 0) == -1) {
            printf("Error sending command.\n");
            exit(3);
        }

        memset(buffer, 0, BUFFER_SIZE);
        while (recv(sockfd, buffer, BUFFER_SIZE, 0) > 0) {
            printf("%s", buffer);
        }
    }

    close(sockfd);
    free(command);
    return 0;
}