//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAXSIZE 256

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAXSIZE];

    // check for correct arguments
    if (argc < 3) {
        fprintf(stderr, "usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    // get port number
    portno = atoi(argv[2]);

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error opening socket\n");
        exit(1);
    }

    // get host name
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: host not found\n");
        exit(1);
    }

    // set server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }

    // read server greeting
    memset(buffer, 0, MAXSIZE);
    n = read(sockfd, buffer, MAXSIZE-1);
    if (n < 0) {
        fprintf(stderr, "Error reading from socket\n");
        exit(1);
    }
    printf("%s", buffer);

    // send HELO
    char username[MAXSIZE];
    printf("Enter your email: ");
    fgets(username, MAXSIZE-1, stdin);
    sprintf(buffer, "HELO %s\r\n", username);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error writing to socket\n");
        exit(1);
    }

    // read server response
    memset(buffer, 0, MAXSIZE);
    n = read(sockfd, buffer, MAXSIZE-1);
    if (n < 0) {
        fprintf(stderr, "Error reading from socket\n");
        exit(1);
    }
    printf("%s", buffer);

    // send MAIL FROM
    char from[MAXSIZE];
    printf("Enter sender email address: ");
    fgets(from, MAXSIZE-1, stdin);
    sprintf(buffer, "MAIL FROM:<%s>\r\n", from);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error writing to socket\n");
        exit(1);
    }

    // read server response
    memset(buffer, 0, MAXSIZE);
    n = read(sockfd, buffer, MAXSIZE-1);
    if (n < 0) {
        fprintf(stderr, "Error reading from socket\n");
        exit(1);
    }
    printf("%s", buffer);

    // send RCPT TO
    char to[MAXSIZE];
    printf("Enter recipient email address: ");
    fgets(to, MAXSIZE-1, stdin);
    sprintf(buffer, "RCPT TO:<%s>\r\n", to);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error writing to socket\n");
        exit(1);
    }

    // read server response
    memset(buffer, 0, MAXSIZE);
    n = read(sockfd, buffer, MAXSIZE-1);
    if (n < 0) {
        fprintf(stderr, "Error reading from socket\n");
        exit(1);
    }
    printf("%s", buffer);

    // send DATA
    n = write(sockfd, "DATA\r\n", 6);
    if (n < 0) {
        fprintf(stderr, "Error writing to socket\n");
        exit(1);
    }

    // read server response
    memset(buffer, 0, MAXSIZE);
    n = read(sockfd, buffer, MAXSIZE-1);
    if (n < 0) {
        fprintf(stderr, "Error reading from socket\n");
        exit(1);
    }
    printf("%s", buffer);

    // send email body
    char subject[MAXSIZE], body[MAXSIZE*10];
    printf("Enter email subject: ");
    fgets(subject, MAXSIZE-1, stdin);
    printf("Enter email body: ");
    fgets(body, MAXSIZE*10-1, stdin);
    sprintf(buffer, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error writing to socket\n");
        exit(1);
    }

    // read server response
    memset(buffer, 0, MAXSIZE);
    n = read(sockfd, buffer, MAXSIZE-1);
    if (n < 0) {
        fprintf(stderr, "Error reading from socket\n");
        exit(1);
    }
    printf("%s", buffer);

    // send QUIT
    n = write(sockfd, "QUIT\r\n", 6);
    if (n < 0) {
        fprintf(stderr, "Error writing to socket\n");
        exit(1);
    }

    // close socket
    close(sockfd);

    return 0;
}