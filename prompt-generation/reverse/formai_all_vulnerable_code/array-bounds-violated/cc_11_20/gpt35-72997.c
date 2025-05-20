//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Invalid arguments. Usage: ./imapclient [SERVER_ADDR] [SERVER_PORT] [USERNAME]\n");
        return 1;
    }

    char message[MAX_BUFFER];
    struct hostent *server;
    struct sockaddr_in server_addr;
    int sockfd, portno, n;

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket!\n");
        return 1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Host not found!\n");
        return 1;
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server!\n");
        return 1;
    }

    n = recv(sockfd, message, MAX_BUFFER - 1, 0);
    if (n < 0) {
        perror("Error reading from socket!\n");
        return 1;
    }
    message[n] = '\0';
    printf("%s\n", message);

    sprintf(message, "LOGIN %s PASSWORD\n", argv[3]);
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("Error writing to socket!\n");
        return 1;
    }

    n = recv(sockfd, message, MAX_BUFFER - 1, 0);
    if (n < 0) {
        perror("Error reading from socket!\n");
        return 1;
    }
    message[n] = '\0';
    printf("%s\n", message);

    sprintf(message, "SELECT INBOX\n");
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("Error writing to socket!\n");
        return 1;
    }

    n = recv(sockfd, message, MAX_BUFFER - 1, 0);
    if (n < 0) {
        perror("Error reading from socket!\n");
        return 1;
    }
    message[n] = '\0';
    printf("%s\n", message);

    sprintf(message, "FETCH 1:5 BODY[HEADER]\n");
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("Error writing to socket!\n");
        return 1;
    }

    n = recv(sockfd, message, MAX_BUFFER - 1, 0);
    if (n < 0) {
        perror("Error reading from socket!\n");
        return 1;
    }
    message[n] = '\0';
    printf("%s\n", message);

    sprintf(message, "LOGOUT\n");
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("Error writing to socket!\n");
        return 1;
    }

    printf("Logged out successfully!\n");

    close(sockfd);
    return 0;
}