//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock_fd, n, len;
    char buffer[BUF_SIZE], command[BUF_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // Create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    // Set server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    // Connect to server
    if (connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Receive welcome message
    n = recv(sock_fd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        perror("ERROR receiving");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // Login
    printf("Please enter your email address: ");
    fgets(buffer, BUF_SIZE-1, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline
    sprintf(command, "a001 LOGIN %s\r\n", buffer);
    n = send(sock_fd, command, strlen(command), 0);
    if (n < 0) {
        perror("ERROR sending");
        exit(1);
    }
    n = recv(sock_fd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        perror("ERROR receiving");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // Select mailbox
    printf("Which mailbox do you want to select? ");
    fgets(buffer, BUF_SIZE-1, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline
    sprintf(command, "a002 SELECT %s\r\n", buffer);
    n = send(sock_fd, command, strlen(command), 0);
    if (n < 0) {
        perror("ERROR sending");
        exit(1);
    }
    n = recv(sock_fd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        perror("ERROR receiving");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // List messages
    sprintf(command, "a003 FETCH 1:* (BODY[HEADER.FIELDS (SUBJECT DATE)])\r\n");
    n = send(sock_fd, command, strlen(command), 0);
    if (n < 0) {
        perror("ERROR sending");
        exit(1);
    }
    n = recv(sock_fd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        perror("ERROR receiving");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // Logout
    sprintf(command, "a004 LOGOUT\r\n");
    n = send(sock_fd, command, strlen(command), 0);
    if (n < 0) {
        perror("ERROR sending");
        exit(1);
    }
    n = recv(sock_fd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        perror("ERROR receiving");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // Close socket
    close(sock_fd);

    return 0;
}