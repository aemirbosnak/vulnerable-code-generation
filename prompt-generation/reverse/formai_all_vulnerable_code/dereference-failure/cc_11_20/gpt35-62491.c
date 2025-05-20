//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 25

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];
    char message[1024] = "Hello, this is a test email.";

    // check if enough arguments are provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // check if socket is created successfully
    if (sockfd < 0) {
        fprintf(stderr, "Error: Cannot create socket.\n");
        exit(0);
    }

    server = gethostbyname(argv[1]);

    // check if host is valid
    if (server == NULL) {
        fprintf(stderr, "Error: Invalid hostname.\n");
        exit(0);
    }

    // set server address attributes
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: Cannot connect to server.\n");
        exit(0);
    }

    // read greeting message from server
    bzero(buffer, sizeof(buffer));
    if (read(sockfd, buffer, sizeof(buffer)) < 0) {
        fprintf(stderr, "Error: Cannot read from socket.\n");
        exit(0);
    }
    printf("%s", buffer);

    // send HELO command to server
    bzero(buffer, sizeof(buffer));
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        fprintf(stderr, "Error: Cannot write to socket.\n");
        exit(0);
    }

    // read response from server
    bzero(buffer, sizeof(buffer));
    if (read(sockfd, buffer, sizeof(buffer)) < 0) {
        fprintf(stderr, "Error: Cannot read from socket.\n");
        exit(0);
    }
    printf("%s", buffer);

    // send MAIL FROM command to server
    bzero(buffer, sizeof(buffer));
    sprintf(buffer, "MAIL FROM:<sender@example.com>\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        fprintf(stderr, "Error: Cannot write to socket.\n");
        exit(0);
    }

    // read response from server
    bzero(buffer, sizeof(buffer));
    if (read(sockfd, buffer, sizeof(buffer)) < 0) {
        fprintf(stderr, "Error: Cannot read from socket.\n");
        exit(0);
    }
    printf("%s", buffer);

    // send RCPT TO command to server
    bzero(buffer, sizeof(buffer));
    sprintf(buffer, "RCPT TO:<recipient@example.com>\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        fprintf(stderr, "Error: Cannot write to socket.\n");
        exit(0);
    }

    // read response from server
    bzero(buffer, sizeof(buffer));
    if (read(sockfd, buffer, sizeof(buffer)) < 0) {
        fprintf(stderr, "Error: Cannot read from socket.\n");
        exit(0);
    }
    printf("%s", buffer);

    // send DATA command to server
    bzero(buffer, sizeof(buffer));
    sprintf(buffer, "DATA\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        fprintf(stderr, "Error: Cannot write to socket.\n");
        exit(0);
    }

    // read response from server
    bzero(buffer, sizeof(buffer));
    if (read(sockfd, buffer, sizeof(buffer)) < 0) {
        fprintf(stderr, "Error: Cannot read from socket.\n");
        exit(0);
    }
    printf("%s", buffer);

    // send email message to server
    bzero(buffer, sizeof(buffer));
    sprintf(buffer, "%s\r\n.\r\n", message);
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        fprintf(stderr, "Error: Cannot write to socket.\n");
        exit(0);
    }

    // read response from server
    bzero(buffer, sizeof(buffer));
    if (read(sockfd, buffer, sizeof(buffer)) < 0) {
        fprintf(stderr, "Error: Cannot read from socket.\n");
        exit(0);
    }
    printf("%s", buffer);

    // send QUIT command to server
    bzero(buffer, sizeof(buffer));
    sprintf(buffer, "QUIT\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        fprintf(stderr, "Error: Cannot write to socket.\n");
        exit(0);
    }

    // read response from server
    bzero(buffer, sizeof(buffer));
    if (read(sockfd, buffer, sizeof(buffer)) < 0) {
        fprintf(stderr, "Error: Cannot read from socket.\n");
        exit(0);
    }
    printf("%s", buffer);

    // close socket
    close(sockfd);

    return 0;
}