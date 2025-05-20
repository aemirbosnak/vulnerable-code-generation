//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hostname> <sender> <recipient>\n", argv[0]);
        return 1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: No such host\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Socket creation failed\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(SMTP_PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: Connection failed\n");
        return 1;
    }

    bzero(buffer, 256);
    n = recv(sockfd, buffer, 255, 0);
    if (n < 0) {
        fprintf(stderr, "Error: Receiving data failed\n");
        return 1;
    }
    printf("%s", buffer);

    bzero(buffer, 256);
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        fprintf(stderr, "Error: Sending data failed\n");
        return 1;
    }

    bzero(buffer, 256);
    n = recv(sockfd, buffer, 255, 0);
    if (n < 0) {
        fprintf(stderr, "Error: Receiving data failed\n");
        return 1;
    }
    printf("%s", buffer);

    bzero(buffer, 256);
    sprintf(buffer, "MAIL FROM:<%s>\r\n", argv[2]);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        fprintf(stderr, "Error: Sending data failed\n");
        return 1;
    }

    bzero(buffer, 256);
    n = recv(sockfd, buffer, 255, 0);
    if (n < 0) {
        fprintf(stderr, "Error: Receiving data failed\n");
        return 1;
    }
    printf("%s", buffer);

    bzero(buffer, 256);
    sprintf(buffer, "RCPT TO:<%s>\r\n", argv[3]);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        fprintf(stderr, "Error: Sending data failed\n");
        return 1;
    }

    bzero(buffer, 256);
    n = recv(sockfd, buffer, 255, 0);
    if (n < 0) {
        fprintf(stderr, "Error: Receiving data failed\n");
        return 1;
    }
    printf("%s", buffer);

    bzero(buffer, 256);
    sprintf(buffer, "DATA\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        fprintf(stderr, "Error: Sending data failed\n");
        return 1;
    }

    bzero(buffer, 256);
    n = recv(sockfd, buffer, 255, 0);
    if (n < 0) {
        fprintf(stderr, "Error: Receiving data failed\n");
        return 1;
    }
    printf("%s", buffer);

    bzero(buffer, 256);
    sprintf(buffer, "Subject: Test message\r\n\r\nThis is a test message.\r\n.\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        fprintf(stderr, "Error: Sending data failed\n");
        return 1;
    }

    bzero(buffer, 256);
    n = recv(sockfd, buffer, 255, 0);
    if (n < 0) {
        fprintf(stderr, "Error: Receiving data failed\n");
        return 1;
    }
    printf("%s", buffer);

    bzero(buffer, 256);
    sprintf(buffer, "QUIT\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        fprintf(stderr, "Error: Sending data failed\n");
        return 1;
    }

    bzero(buffer, 256);
    n = recv(sockfd, buffer, 255, 0);
    if (n < 0) {
        fprintf(stderr, "Error: Receiving data failed\n");
        return 1;
    }
    printf("%s", buffer);

    close(sockfd);

    return 0;
}