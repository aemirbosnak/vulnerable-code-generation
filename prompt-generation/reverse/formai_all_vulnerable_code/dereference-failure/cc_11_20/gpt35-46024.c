//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_LENGTH 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];

    // check if arguments provided are correct
    if (argc != 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    // get the port number
    portno = atoi(argv[2]);

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error opening socket\n");
        exit(1);
    }

    // get the server name
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error, no such host\n");
        exit(1);
    }

    // fill in the server details
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error connecting\n");
        exit(1);
    }

    // get the welcome message from the server
    memset(buffer, 0, MAX_LENGTH);
    n = read(sockfd, buffer, MAX_LENGTH - 1);
    if (n < 0) {
        fprintf(stderr, "Error reading from socket\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // send the username to the server
    printf("Username: ");
    scanf("%s", username);
    sprintf(buffer, "USER %s\r\n", username);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error writing to socket\n");
        exit(1);
    }

    // get the response from the server
    memset(buffer, 0, MAX_LENGTH);
    n = read(sockfd, buffer, MAX_LENGTH - 1);
    if (n < 0) {
        fprintf(stderr, "Error reading from socket\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // send the password to the server
    printf("Password: ");
    scanf("%s", password);
    sprintf(buffer, "PASS %s\r\n", password);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error writing to socket\n");
        exit(1);
    }

    // get the response from the server
    memset(buffer, 0, MAX_LENGTH);
    n = read(sockfd, buffer, MAX_LENGTH - 1);
    if (n < 0) {
        fprintf(stderr, "Error reading from socket\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // list all the emails
    sprintf(buffer, "LIST\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error writing to socket\n");
        exit(1);
    }

    // get the response from the server
    memset(buffer, 0, MAX_LENGTH);
    n = read(sockfd, buffer, MAX_LENGTH - 1);
    if (n < 0) {
        fprintf(stderr, "Error reading from socket\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // quit the server
    sprintf(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error writing to socket\n");
        exit(1);
    }

    // get the response from the server
    memset(buffer, 0, MAX_LENGTH);
    n = read(sockfd, buffer, MAX_LENGTH - 1);
    if (n < 0) {
        fprintf(stderr, "Error reading from socket\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // close the socket
    close(sockfd);

    return 0;
}