//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if(argc != 4) {
        fprintf(stderr, "Usage: %s <SMTP server> <from> <to>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* smtpServer = argv[1];
    char* from = argv[2];
    char* to = argv[3];

    struct hostent *host = gethostbyname(smtpServer);
    if(host == NULL) {
        herror("gethostbyname() failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    memcpy(&serverAddress.sin_addr, host->h_addr, host->h_length);
    serverAddress.sin_port = htons(25);

    int socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if(socketFd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    if(connect(socketFd, (struct sockaddr *)&serverAddress,
               sizeof(struct sockaddr)) < 0) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUFFER_SIZE] = { '\0' };
    int bytesRead = read(socketFd, buffer, sizeof(buffer));
    if(bytesRead >= MAX_BUFFER_SIZE) {
        fprintf(stderr, "Maximum buffer size exceeded\n");
        exit(EXIT_FAILURE);
    }
    buffer[bytesRead] = '\0';
    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "HELO localhost\r\n");
    if(write(socketFd, buffer, strlen(buffer)) < 0) {
        perror("write() failed");
        exit(EXIT_FAILURE);
    }

    bytesRead = read(socketFd, buffer, sizeof(buffer));
    if(bytesRead >= MAX_BUFFER_SIZE) {
        fprintf(stderr, "Maximum buffer size exceeded\n");
        exit(EXIT_FAILURE);
    }
    buffer[bytesRead] = '\0';
    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", from);
    if(write(socketFd, buffer, strlen(buffer)) < 0) {
        perror("write() failed");
        exit(EXIT_FAILURE);
    }

    bytesRead = read(socketFd, buffer, sizeof(buffer));
    if(bytesRead >= MAX_BUFFER_SIZE) {
        fprintf(stderr, "Maximum buffer size exceeded\n");
        exit(EXIT_FAILURE);
    }
    buffer[bytesRead] = '\0';
    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", to);
    if(write(socketFd, buffer, strlen(buffer)) < 0) {
        perror("write() failed");
        exit(EXIT_FAILURE);
    }

    bytesRead = read(socketFd, buffer, sizeof(buffer));
    if(bytesRead >= MAX_BUFFER_SIZE) {
        fprintf(stderr, "Maximum buffer size exceeded\n");
        exit(EXIT_FAILURE);
    }
    buffer[bytesRead] = '\0';
    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    if(write(socketFd, buffer, strlen(buffer)) < 0) {
        perror("write() failed");
        exit(EXIT_FAILURE);
    }

    bytesRead = read(socketFd, buffer, sizeof(buffer));
    if(bytesRead >= MAX_BUFFER_SIZE) {
        fprintf(stderr, "Maximum buffer size exceeded\n");
        exit(EXIT_FAILURE);
    }
    buffer[bytesRead] = '\0';
    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "Hello world!\r\n");
    if(write(socketFd, buffer, strlen(buffer)) < 0) {
        perror("write() failed");
        exit(EXIT_FAILURE);
    }

    snprintf(buffer, sizeof(buffer), ".\r\n");
    if(write(socketFd, buffer, strlen(buffer)) < 0) {
        perror("write() failed");
        exit(EXIT_FAILURE);
    }

    bytesRead = read(socketFd, buffer, sizeof(buffer));
    if(bytesRead >= MAX_BUFFER_SIZE) {
        fprintf(stderr, "Maximum buffer size exceeded\n");
        exit(EXIT_FAILURE);
    }
    buffer[bytesRead] = '\0';
    printf("%s", buffer);

    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    if(write(socketFd, buffer, strlen(buffer)) < 0) {
        perror("write() failed");
        exit(EXIT_FAILURE);
    }

    bytesRead = read(socketFd, buffer, sizeof(buffer));
    if(bytesRead >= MAX_BUFFER_SIZE) {
        fprintf(stderr, "Maximum buffer size exceeded\n");
        exit(EXIT_FAILURE);
    }
    buffer[bytesRead] = '\0';
    printf("%s", buffer);

    close(socketFd);

    return 0;
}