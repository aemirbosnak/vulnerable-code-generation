//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define PORT 21
#define MAX_COMMAND_LENGTH 1024
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int n;

    if (argc!= 4) {
        printf("Usage:./ftp_client <server_ip> <username> <password>\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Could not connect to server\n");
        return 1;
    }

    printf("Connected to server\n");

    char *username = argv[2];
    char *password = argv[3];
    char login_command[MAX_COMMAND_LENGTH];

    snprintf(login_command, MAX_COMMAND_LENGTH, "USER %s\r\n", username);
    send(sockfd, login_command, strlen(login_command), 0);

    snprintf(login_command, MAX_COMMAND_LENGTH, "PASS %s\r\n", password);
    send(sockfd, login_command, strlen(login_command), 0);

    char response[BUFFER_SIZE];
    n = recv(sockfd, response, BUFFER_SIZE, 0);
    response[n] = '\0';
    printf("Server response: %s", response);

    while (1) {
        printf("Enter command: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\r\n")] = '\0';
        send(sockfd, buffer, strlen(buffer), 0);

        n = recv(sockfd, response, BUFFER_SIZE, 0);
        response[n] = '\0';
        printf("Server response: %s", response);
    }

    close(sockfd);
    return 0;
}