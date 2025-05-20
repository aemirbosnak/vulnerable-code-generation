//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 25
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    if (argc < 2) {
        fprintf(stderr,"Usage: %s hostname\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        perror("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        perror("ERROR connecting");

    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0)
        perror("ERROR reading from socket");
    printf("%s", buffer);

    char* message = "Hello, world!";
    char* to = "example@mail.com";
    char* from = "youremail@mail.com";

    snprintf(buffer, BUFFER_SIZE, "HELO %s\r\n", argv[1]);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0)
        perror("ERROR reading from socket");
    printf("%s", buffer);
    bzero(buffer, BUFFER_SIZE);

    snprintf(buffer, BUFFER_SIZE, "MAIL FROM:%s\r\n", from);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0)
        perror("ERROR reading from socket");
    printf("%s", buffer);
    bzero(buffer, BUFFER_SIZE);

    snprintf(buffer, BUFFER_SIZE, "RCPT TO:%s\r\n", to);
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0)
        perror("ERROR reading from socket");
    printf("%s", buffer);
    bzero(buffer, BUFFER_SIZE);

    snprintf(buffer, BUFFER_SIZE, "DATA\r\n");
    write(sockfd, buffer, strlen(buffer));
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0)
        perror("ERROR reading from socket");
    printf("%s", buffer);
    bzero(buffer, BUFFER_SIZE);

    snprintf(buffer, BUFFER_SIZE, "Subject: My Email\r\n");

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        perror("ERROR writing to socket");

    bzero(buffer, BUFFER_SIZE);

    n = write(sockfd, message, strlen(message));
    if (n < 0)
        perror("ERROR writing to socket");

    bzero(buffer, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "\r\n.\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        perror("ERROR writing to socket");

    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0)
        perror("ERROR reading from socket");
    printf("%s", buffer);
    bzero(buffer, BUFFER_SIZE);

    snprintf(buffer, BUFFER_SIZE, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        perror("ERROR writing to socket");

    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0)
        perror("ERROR reading from socket");
    printf("%s", buffer);
    bzero(buffer, BUFFER_SIZE);

    close(sockfd);
    return 0;
}