//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char* argv[]) {
    // check for correct number of command line arguments
    if (argc < 4) {
        printf("Usage: %s servername username password\n", argv[0]);
        exit(1);
    }

    // retrieve command line arguments
    char* servername = argv[1];
    char* username = argv[2];
    char* password = argv[3];

    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // retrieve server information
    struct hostent* server = gethostbyname(servername);
    if (server == NULL) {
        printf("Error: no such host named '%s'\n", servername);
        exit(1);
    }

    // initialize server address structure
    struct sockaddr_in serv_addr;
    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(110);

    // connect to server
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // read server greeting
    char buffer[BUFSIZE];
    bzero(buffer, BUFSIZE);
    if (read(sockfd, buffer, BUFSIZE) < 0) {
        perror("Error reading server greeting");
        exit(1);
    }
    printf("%s\n", buffer);

    // send username
    bzero(buffer, BUFSIZE);
    sprintf(buffer, "USER %s\r\n", username);
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error sending username");
        exit(1);
    }

    // read server response to username
    bzero(buffer, BUFSIZE);
    if (read(sockfd, buffer, BUFSIZE) < 0) {
        perror("Error reading server response to username");
        exit(1);
    }
    printf("%s\n", buffer);

    // send password
    bzero(buffer, BUFSIZE);
    sprintf(buffer, "PASS %s\r\n", password);
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error sending password");
        exit(1);
    }

    // read server response to password
    bzero(buffer, BUFSIZE);
    if (read(sockfd, buffer, BUFSIZE) < 0) {
        perror("Error reading server response to password");
        exit(1);
    }
    printf("%s\n", buffer);

    // send command to list messages
    bzero(buffer, BUFSIZE);
    sprintf(buffer, "LIST\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("Error sending 'list' command");
        exit(1);
    }

    // read server response to 'list' command
    bzero(buffer, BUFSIZE);
    if (read(sockfd, buffer, BUFSIZE) < 0) {
        perror("Error reading server response to 'list' command");
        exit(1);
    }
    printf("%s\n", buffer);

    // close socket
    close(sockfd);

    return 0;
}