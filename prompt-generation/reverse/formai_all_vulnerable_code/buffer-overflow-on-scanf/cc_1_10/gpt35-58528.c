//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_ADDRESS "pop.server.com"
#define SERVER_PORT 110

// function to read server response
void read_response(int sockfd) {
    char buffer[1024];
    int bytes_read;

    bytes_read = recv(sockfd, buffer, 1024, 0);
    buffer[bytes_read] = '\0';

    printf("\n=== SERVER RESPONSE ===\n%s\n", buffer);
}

int main() {
    int sockfd, bytes_sent, bytes_read;
    char username[100], password[100], buffer[1024];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // set server address and port
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
    serv_addr.sin_port = htons(SERVER_PORT);

    // connect to server
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // read server greeting
    read_response(sockfd);

    // send user credentials
    printf("Username: ");
    scanf("%s", &username);
    sprintf(buffer, "USER %s\r\n", username);
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);

    printf("Password: ");
    scanf("%s", &password);
    sprintf(buffer, "PASS %s\r\n", password);
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);

    // read server response
    read_response(sockfd);

    // send QUIT command to end session
    sprintf(buffer, "QUIT\r\n");
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);

    // read server response and close connection
    read_response(sockfd);
    close(sockfd);

    return 0;
}