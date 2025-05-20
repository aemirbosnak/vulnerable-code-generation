//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define PORT 25

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1000];

    if ((server = gethostbyname("localhost")) == NULL) {
        fprintf(stderr, "ERROR: Cannot find localhost\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("SMTP client connected to %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    if (send(sockfd, "HELO localhost\r\n", 13, 0) < 0) {
        perror("ERROR sending command");
        exit(1);
    }

    if (recv(sockfd, buffer, 1000, 0) < 0) {
        perror("ERROR receiving data");
        exit(1);
    }

    printf("SMTP server response: %s\n", buffer);

    if (send(sockfd, "MAIL FROM: <root@localhost>\r\n", 31, 0) < 0) {
        perror("ERROR sending command");
        exit(1);
    }

    if (recv(sockfd, buffer, 1000, 0) < 0) {
        perror("ERROR receiving data");
        exit(1);
    }

    printf("SMTP server response: %s\n", buffer);

    if (send(sockfd, "RCPT TO: <root@localhost>\r\n", 30, 0) < 0) {
        perror("ERROR sending command");
        exit(1);
    }

    if (recv(sockfd, buffer, 1000, 0) < 0) {
        perror("ERROR receiving data");
        exit(1);
    }

    printf("SMTP server response: %s\n", buffer);

    if (send(sockfd, "DATA\r\n", 7, 0) < 0) {
        perror("ERROR sending command");
        exit(1);
    }

    if (recv(sockfd, buffer, 1000, 0) < 0) {
        perror("ERROR receiving data");
        exit(1);
    }

    printf("SMTP server response: %s\n", buffer);

    if (send(sockfd, "Hello, world.\r\n.\r\n", 25, 0) < 0) {
        perror("ERROR sending command");
        exit(1);
    }

    if (recv(sockfd, buffer, 1000, 0) < 0) {
        perror("ERROR receiving data");
        exit(1);
    }

    printf("SMTP server response: %s\n", buffer);

    if (send(sockfd, "quit\r\n", 7, 0) < 0) {
        perror("ERROR sending command");
        exit(1);
    }

    if (recv(sockfd, buffer, 1000, 0) < 0) {
        perror("ERROR receiving data");
        exit(1);
    }

    printf("SMTP server response: %s\n", buffer);

    close(sockfd);
    return 0;
}