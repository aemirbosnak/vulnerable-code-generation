//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname message\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error: no such host\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    serv_addr.sin_port = htons(SMTP_PORT);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        perror("Error receiving");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    sprintf(buffer, "HELO %s\r\n", argv[1]);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending");
        exit(1);
    }

    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        perror("Error receiving");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    sprintf(buffer, "MAIL FROM:<%s>\r\n", argv[1]);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending");
        exit(1);
    }

    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        perror("Error receiving");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    sprintf(buffer, "RCPT TO:<%s>\r\n", argv[2]);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending");
        exit(1);
    }

    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        perror("Error receiving");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    sprintf(buffer, "DATA\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending");
        exit(1);
    }

    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        perror("Error receiving");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    sprintf(buffer, "Subject: SMTP Client Example\r\n\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending");
        exit(1);
    }

    sprintf(buffer, "Hello from my SMTP client!\r\n.\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending");
        exit(1);
    }

    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        perror("Error receiving");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    sprintf(buffer, "QUIT\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending");
        exit(1);
    }

    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        perror("Error receiving");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    close(sockfd);
    return 0;
}