//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Resolve hostname and port
    server = gethostbyname("pop.gmail.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR: hostname not found\n");
        exit(1);
    }
    portno = htons(110);

    // Create a sockaddr_in structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Login to the server
    printf("Enter your email address: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    printf("Enter your password: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    // Send login command
    n = write(sockfd, "USER ", 5);
    if (n < 0) {
        perror("write failed");
        exit(1);
    }
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write failed");
        exit(1);
    }
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("read failed");
        exit(1);
    }
    printf("Server response: %s\n", buffer);

    // Send password
    n = write(sockfd, "PASS ", 5);
    if (n < 0) {
        perror("write failed");
        exit(1);
    }
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write failed");
        exit(1);
    }
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("read failed");
        exit(1);
    }
    printf("Server response: %s\n", buffer);

    // Check if the login was successful
    if (strcmp(buffer, "235 Successful login") == 0) {
        printf("Login successful!\n");
    } else {
        printf("Login failed!\n");
        exit(1);
    }

    // Send list command
    n = write(sockfd, "LIST\r\n", 8);
    if (n < 0) {
        perror("write failed");
        exit(1);
    }
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("read failed");
        exit(1);
    }
    printf("Server response: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}