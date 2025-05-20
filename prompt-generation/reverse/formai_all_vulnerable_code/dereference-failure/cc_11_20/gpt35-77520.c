//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h> 

#define BUFFER_SIZE 1024
#define PORT 993

int main(int argc, char *argv[]) {

    int sockfd, n, portno = PORT;
    char buffer[BUFFER_SIZE];

    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Could not open socket.\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    server = gethostbyname("imap.gmail.com");
    if (server == NULL) {
        printf("Error: Host not found.\n");
        exit(1);
    }

    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Connection refused.\n");
        exit(1);
    }

    // Login by sending username and password
    bzero(buffer, BUFFER_SIZE);
    sprintf(buffer, ". LOGIN %s %s\r\n", "username", "password");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error: Could not write to socket.\n");
        exit(1);
    }

    // Read and output IMAP server response
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        printf("Error: Could not read from socket.\n");
        exit(1);
    }
    printf("%s", buffer);

    // Fetch emails from INBOX
    bzero(buffer, BUFFER_SIZE);
    sprintf(buffer, ". SELECT INBOX\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error: Could not write to socket.\n");
        exit(1);
    }

    // Read and output IMAP server response
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        printf("Error: Could not read from socket.\n");
        exit(1);
    }
    printf("%s", buffer);

    // Fetch email flags
    bzero(buffer, BUFFER_SIZE);
    sprintf(buffer, ". FETCH 1:* FLAGS\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error: Could not write to socket.\n");
        exit(1);
    }

    // Read and output IMAP server response
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        printf("Error: Could not read from socket.\n");
        exit(1);
    }
    printf("%s", buffer);

    // Logout
    bzero(buffer, BUFFER_SIZE);
    sprintf(buffer, ". LOGOUT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error: Could not write to socket.\n");
        exit(1);
    }

    // Read and output IMAP server response
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        printf("Error: Could not read from socket.\n");
        exit(1);
    }
    printf("%s", buffer);

    close(sockfd);
    
    return 0;
}