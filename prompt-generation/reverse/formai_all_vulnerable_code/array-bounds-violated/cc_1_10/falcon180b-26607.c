//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define SERVER "127.0.0.1"
#define PORT 110

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    char username[50] = "your_username";
    char password[50] = "your_password";
    char login_command[100];
    sprintf(login_command, "USER %s\r\n", username);
    send(sockfd, login_command, strlen(login_command), 0);

    char response[BUFFER_SIZE];
    int bytes_received = recv(sockfd, response, BUFFER_SIZE, 0);
    response[bytes_received] = '\0';
    printf("Server response after USER command: %s\n", response);

    sprintf(login_command, "PASS %s\r\n", password);
    send(sockfd, login_command, strlen(login_command), 0);

    bytes_received = recv(sockfd, response, BUFFER_SIZE, 0);
    response[bytes_received] = '\0';
    printf("Server response after PASS command: %s\n", response);

    char list_command[100];
    sprintf(list_command, "LIST\r\n");
    send(sockfd, list_command, strlen(list_command), 0);

    bytes_received = recv(sockfd, response, BUFFER_SIZE, 0);
    response[bytes_received] = '\0';
    printf("Server response after LIST command: %s\n", response);

    close(sockfd);
    return 0;
}