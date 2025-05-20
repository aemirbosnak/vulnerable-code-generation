//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 110
#define SERVER_ADDRESS "localhost"

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // connect to server
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // send username and password
    char username[20] = "username";
    char password[20] = "password";
    char *credentials = malloc(strlen(username) + strlen(password) + 2);
    strcat(strcat(credentials, username), "\0");
    strcat(credentials, password);
    send(sockfd, credentials, strlen(credentials), 0);

    // receive server response
    memset(buffer, 0, BUFFER_SIZE);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s\n", buffer);

    // send POP3 commands
    send(sockfd, "STAT\r\n", 6, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("STAT response: %s\n", buffer);

    send(sockfd, "LIST\r\n", 6, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("LIST response: %s\n", buffer);

    send(sockfd, "RETR 1\r\n", 9, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("RETR response: %s\n", buffer);

    // close socket
    close(sockfd);

    return 0;
}