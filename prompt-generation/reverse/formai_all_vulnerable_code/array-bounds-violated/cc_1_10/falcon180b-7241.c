//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set server IP and port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    portno = 110;
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Login to POP3 server
    char username[30] = "username";
    char password[30] = "password";
    char login_command[100] = "USER ";
    strcat(login_command, username);
    strcat(login_command, "\r\n");
    send(sockfd, login_command, strlen(login_command), 0);

    char response[BUFFER_SIZE];
    n = recv(sockfd, response, BUFFER_SIZE, 0);
    response[n] = '\0';
    printf("Server response: %s\n", response);

    strcat(login_command, "PASS ");
    strcat(login_command, password);
    strcat(login_command, "\r\n");
    send(sockfd, login_command, strlen(login_command), 0);

    n = recv(sockfd, response, BUFFER_SIZE, 0);
    response[n] = '\0';
    printf("Server response: %s\n", response);

    // Retrieve message list
    char message_list_command[100] = "LIST\r\n";
    send(sockfd, message_list_command, strlen(message_list_command), 0);

    n = recv(sockfd, response, BUFFER_SIZE, 0);
    response[n] = '\0';
    printf("Server response: %s\n", response);

    // Close connection
    close(sockfd);

    return 0;
}