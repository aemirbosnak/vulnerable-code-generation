//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define FTP_PORT 21

int main() {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(FTP_PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send the USER command
    char *user = "username";
    char user_cmd[strlen(user) + 6];
    sprintf(user_cmd, "USER %s\r\n", user);
    if (send(sockfd, user_cmd, strlen(user_cmd), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the server response
    char response[1024];
    int n;
    if ((n = recv(sockfd, response, sizeof(response), 0)) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    response[n] = '\0';
    printf("Server response: %s", response);

    // Send the PASS command
    char *pass = "password";
    char pass_cmd[strlen(pass) + 6];
    sprintf(pass_cmd, "PASS %s\r\n", pass);
    if (send(sockfd, pass_cmd, strlen(pass_cmd), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the server response
    if ((n = recv(sockfd, response, sizeof(response), 0)) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    response[n] = '\0';
    printf("Server response: %s", response);

    // Send the LIST command
    char *list_cmd = "LIST\r\n";
    if (send(sockfd, list_cmd, strlen(list_cmd), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the server response
    while ((n = recv(sockfd, response, sizeof(response), 0)) > 0) {
        response[n] = '\0';
        printf("Server response: %s", response);
    }

    // Close the socket
    close(sockfd);

    return 0;
}