//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <smtp server> <from email address> <to email address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char buffer[MAXSIZE];
    int sock = 0, port = 25;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    memset(buffer, 0, MAXSIZE);
    memset(&serv_addr, 0, sizeof(serv_addr));

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    if ((server = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr = *((struct in_addr *) server->h_addr);

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("could not connect to smtp server");
        exit(EXIT_FAILURE);
    }

    int n = read(sock, buffer, MAXSIZE);
    if (n < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }

    printf("Received: %s\n", buffer);

    // Send HELO command
    sprintf(buffer, "HELO localhost\r\n");
    n = write(sock, buffer, strlen(buffer));
    if (n < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }

    n = read(sock, buffer, MAXSIZE);
    if (n < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }

    printf("Received: %s\n", buffer);

    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", argv[2]);
    n = write(sock, buffer, strlen(buffer));
    if (n < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }

    n = read(sock, buffer, MAXSIZE);
    if (n < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }

    printf("Received: %s\n", buffer);

    // Send RCPT TO command
    sprintf(buffer, "RCPT TO:<%s>\r\n", argv[3]);
    n = write(sock, buffer, strlen(buffer));
    if (n < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }

    n = read(sock, buffer, MAXSIZE);
    if (n < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }

    printf("Received: %s\n", buffer);

    // Send DATA command
    sprintf(buffer, "DATA\r\n");
    n = write(sock, buffer, strlen(buffer));
    if (n < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }

    n = read(sock, buffer, MAXSIZE);
    if (n < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }

    printf("Received: %s\n", buffer);

    // Send email message
    sprintf(buffer, "From: <%s>\r\nTo: <%s>\r\nSubject: Test\r\n\r\nThis is a test email from the SMTP client.\r\n\r\n.\r\n", argv[2], argv[3]);
    n = write(sock, buffer, strlen(buffer));
    if (n < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }

    n = read(sock, buffer, MAXSIZE);
    if (n < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }

    printf("Received: %s\n", buffer);

    // Send QUIT command
    sprintf(buffer, "QUIT\r\n");
    n = write(sock, buffer, strlen(buffer));
    if (n < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }

    n = read(sock, buffer, MAXSIZE);
    if (n < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }

    printf("Received: %s\n", buffer);

    close(sock);

    return 0;
}