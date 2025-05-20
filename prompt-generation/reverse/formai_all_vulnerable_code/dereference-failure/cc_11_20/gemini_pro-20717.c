//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFSIZE];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: could not create socket\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: could not connect to server\n");
        exit(1);
    }

    // Send the USER command
    sprintf(buffer, "USER %s\r\n", argv[3]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: could not send USER command\n");
        exit(1);
    }

    // Read the server's response
    n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0) {
        fprintf(stderr, "Error: could not read server's response\n");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send the PASS command
    sprintf(buffer, "PASS %s\r\n", argv[4]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: could not send PASS command\n");
        exit(1);
    }

    // Read the server's response
    n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0) {
        fprintf(stderr, "Error: could not read server's response\n");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send the LIST command
    strcpy(buffer, "LIST\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: could not send LIST command\n");
        exit(1);
    }

    // Read the server's response
    while ((n = read(sockfd, buffer, BUFSIZE - 1)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }
    if (n < 0) {
        fprintf(stderr, "Error: could not read server's response\n");
        exit(1);
    }

    // Send the QUIT command
    strcpy(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: could not send QUIT command\n");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}