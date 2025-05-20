//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_BUFFER 1024

int main(void) {
    int sockfd;
    char buffer[MAX_BUFFER];
    struct sockaddr_in server_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    server = gethostbyname("pop.example.com");
    if (server == NULL) {
        perror("Error: no such host");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0) {
        perror("Error receiving message from server");
        return 1;
    }

    printf("Message received from server:\n%s", buffer);

    sprintf(buffer, "USER myusername\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        return 1;
    }

    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0) {
        perror("Error receiving message from server");
        return 1;
    }

    printf("Message received from server:\n%s", buffer);

    sprintf(buffer, "PASS mypassword\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        return 1;
    }

    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0) {
        perror("Error receiving message from server");
        return 1;
    }

    printf("Message received from server:\n%s", buffer);

    sprintf(buffer, "STAT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        return 1;
    }

    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0) {
        perror("Error receiving message from server");
        return 1;
    }

    printf("Message received from server:\n%s", buffer);

    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message to server");
        return 1;
    }

    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0) {
        perror("Error receiving message from server");
        return 1;
    }

    printf("Message received from server:\n%s", buffer);

    close(sockfd);

    return 0;
}