//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFSIZE];

    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "Error: no such hostname\n");
        exit(EXIT_FAILURE);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    memcpy((char *) &serv_addr.sin_addr.s_addr,
           (char *) server->h_addr,
           server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, buffer, BUFSIZE - 1, 0) < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }

    printf("Server message: %s\n", buffer);

    // Send POP3 protocol commands to server
    char user[BUFSIZE];
    char pass[BUFSIZE];

    printf("Enter username: ");
    scanf("%s", user);

    sprintf(buffer, "USER %s\r\n", user);
    send(sockfd, buffer, strlen(buffer), 0);

    if (recv(sockfd, buffer, BUFSIZE - 1, 0) < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }

    printf("Server message: %s\n", buffer);

    printf("Enter password: ");
    scanf("%s", pass);

    sprintf(buffer, "PASS %s\r\n", pass);
    send(sockfd, buffer, strlen(buffer), 0);

    if (recv(sockfd, buffer, BUFSIZE - 1, 0) < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }

    printf("Server message: %s\n", buffer);

    // Retrieve email statistics
    sprintf(buffer, "STAT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    if (recv(sockfd, buffer, BUFSIZE - 1, 0) < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }

    printf("Server message: %s\n", buffer);

    // Retrieve email content
    int num_messages;
    sscanf(buffer, "+OK %d", &num_messages);

    for (int i = 1; i <= num_messages; i++) {
        sprintf(buffer, "RETR %d\r\n", i);
        send(sockfd, buffer, strlen(buffer), 0);

        if (recv(sockfd, buffer, BUFSIZE - 1, 0) < 0) {
            perror("Error reading from socket");
            exit(EXIT_FAILURE);
        }

        printf("Message %d:\n%s\n", i, buffer);
    }

    // Quit POP3 session
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    if (recv(sockfd, buffer, BUFSIZE - 1, 0) < 0) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }

    printf("Server message: %s\n", buffer);

    close(sockfd);

    return EXIT_SUCCESS;
}