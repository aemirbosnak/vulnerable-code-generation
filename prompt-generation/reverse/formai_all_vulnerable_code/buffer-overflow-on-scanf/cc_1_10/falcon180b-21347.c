//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 21
#define MAX_LINE 1024
#define MAX_COMMAND_LINE 80

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[30], password[30];
    int n;
    char str[MAX_LINE];
    char command[MAX_COMMAND_LINE];

    printf("Enter the FTP server address: ");
    scanf("%s", str);

    printf("Enter the username: ");
    scanf("%s", username);

    printf("Enter the password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(0);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, str, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }

    printf("Connected to server\n");

    printf("Enter the command (e.g. 'ls', 'get', 'put'): ");
    scanf("%s", command);

    send(sockfd, command, strlen(command), 0);

    while (1) {
        memset(str, 0, sizeof(str));
        n = recv(sockfd, str, MAX_LINE, 0);

        if (n <= 0) {
            printf("Disconnected from server\n");
            exit(0);
        }

        printf("%s", str);
    }

    close(sockfd);

    return 0;
}