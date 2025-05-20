//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buf[256], from[256], to[256], message[256];
    char *host = "smtp.example.com";
    char *port = "587";

    // Initialize socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Create address struct and fill in server information
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send email
    printf("Enter from email: ");
    fgets(from, sizeof(from), stdin);
    printf("Enter to email: ");
    fgets(to, sizeof(to), stdin);
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    // Send HELO command
    n = write(sockfd, "HELO ", 5);
    if (n < 0) {
        perror("Error sending HELO command");
        exit(1);
    }

    // Send MAIL FROM command
    n = write(sockfd, "MAIL FROM:<", 10);
    if (n < 0) {
        perror("Error sending MAIL FROM command");
        exit(1);
    }
    n = write(sockfd, from, strlen(from));
    if (n < 0) {
        perror("Error sending MAIL FROM command");
        exit(1);
    }
    n = write(sockfd, ">", 2);
    if (n < 0) {
        perror("Error sending MAIL FROM command");
        exit(1);
    }

    // Send RCPT TO command
    n = write(sockfd, "RCPT TO:<", 11);
    if (n < 0) {
        perror("Error sending RCPT TO command");
        exit(1);
    }
    n = write(sockfd, to, strlen(to));
    if (n < 0) {
        perror("Error sending RCPT TO command");
        exit(1);
    }
    n = write(sockfd, ">", 2);
    if (n < 0) {
        perror("Error sending RCPT TO command");
        exit(1);
    }

    // Send DATA command
    n = write(sockfd, "DATA\r\n", 10);
    if (n < 0) {
        perror("Error sending DATA command");
        exit(1);
    }

    // Send message
    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        perror("Error sending message");
        exit(1);
    }

    // Send QUIT command
    n = write(sockfd, "QUIT\r\n", 9);
    if (n < 0) {
        perror("Error sending QUIT command");
        exit(1);
    }

    // Close socket
    close(sockfd);

    return 0;
}