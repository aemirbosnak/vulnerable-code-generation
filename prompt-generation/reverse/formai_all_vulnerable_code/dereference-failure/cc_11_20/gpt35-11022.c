//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024
#define IMAP_PORT 143

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname username\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(IMAP_PORT);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send login command to server
    sprintf(buffer, "LOGIN %s\r\n", argv[2]);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read response from server
    memset(buffer, 0, MAX_BUFFER_SIZE);
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    // Parse server response for success
    char *success = strstr(buffer, "OK");
    if (success == NULL) {
        printf("Login failed. Server response: %s\n", buffer);
        close(sockfd);
        return 1;
    }

    printf("Logged in successfully.\n");

    // Send select inbox command to server
    sprintf(buffer, "SELECT INBOX\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read response from server
    memset(buffer, 0, MAX_BUFFER_SIZE);
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    // Parse server response for success
    success = strstr(buffer, "OK");
    if (success == NULL) {
        printf("Select inbox failed. Server response: %s\n", buffer);
        close(sockfd);
        return 1;
    }

    printf("Inbox selected.\n");

    // Send fetch command to server
    sprintf(buffer, "FETCH 1:* (FLAGS BODY[HEADER.FIELDS (DATE FROM)])\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read response from server
    memset(buffer, 0, MAX_BUFFER_SIZE);
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Fetched email headers:\n%s\n", buffer);

    close(sockfd);
    return 0;
}