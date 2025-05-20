//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PORT 143
#define SERVER "localhost"
#define USERNAME "your_username"
#define PASSWORD "your_password"

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *login_command = "LOGIN your_username your_password\r\n";
    char *select_command = "SELECT INBOX\r\n";
    char *logout_command = "LOGOUT\r\n";
    char *response[BUFFER_SIZE];
    int response_len;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Login to server
    send(sockfd, login_command, strlen(login_command), 0);
    response_len = recv(sockfd, response, BUFFER_SIZE, 0);
    response[response_len] = '\0';
    printf("Login response: %s\n", response);

    // Select inbox
    send(sockfd, select_command, strlen(select_command), 0);
    response_len = recv(sockfd, response, BUFFER_SIZE, 0);
    response[response_len] = '\0';
    printf("Select response: %s\n", response);

    // List messages in inbox
    char *list_command = "LIST "" ""\r\n";
    send(sockfd, list_command, strlen(list_command), 0);
    response_len = recv(sockfd, response, BUFFER_SIZE, 0);
    response[response_len] = '\0';
    printf("List response: %s\n", response);

    // Logout from server
    send(sockfd, logout_command, strlen(logout_command), 0);
    response_len = recv(sockfd, response, BUFFER_SIZE, 0);
    response[response_len] = '\0';
    printf("Logout response: %s\n", response);

    // Close socket
    close(sockfd);

    return 0;
}