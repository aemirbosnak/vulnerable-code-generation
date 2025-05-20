//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <username>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];

    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        fprintf(stderr, "Error: could not resolve hostname '%s'\n", hostname);
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *(struct in_addr *)host->h_addr;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        fprintf(stderr, "Error: could not create socket: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        fprintf(stderr, "Error: could not connect to host: %s\n", strerror(errno));
        exit(1);
    }

    char buf[BUFSIZE];

    // Read the welcome message
    if (read(sock, buf, BUFSIZE) < 0) {
        fprintf(stderr, "Error: could not read welcome message: %s\n", strerror(errno));
        exit(1);
    }

    // Send the login command
    sprintf(buf, "LOGIN %s\r\n", username);
    if (write(sock, buf, strlen(buf)) < 0) {
        fprintf(stderr, "Error: could not send login command: %s\n", strerror(errno));
        exit(1);
    }

    // Read the login response
    if (read(sock, buf, BUFSIZE) < 0) {
        fprintf(stderr, "Error: could not read login response: %s\n", strerror(errno));
        exit(1);
    }

    // Check if the login was successful
    if (strncmp(buf, "OK", 2) != 0) {
        fprintf(stderr, "Error: login failed: %s\n", buf);
        exit(1);
    }

    // Send the LIST command
    sprintf(buf, "LIST \"\"\r\n");
    if (write(sock, buf, strlen(buf)) < 0) {
        fprintf(stderr, "Error: could not send LIST command: %s\n", strerror(errno));
        exit(1);
    }

    // Read the LIST response
    while (read(sock, buf, BUFSIZE) > 0) {
        printf("%s", buf);
    }

    // Send the QUIT command
    sprintf(buf, "QUIT\r\n");
    if (write(sock, buf, strlen(buf)) < 0) {
        fprintf(stderr, "Error: could not send QUIT command: %s\n", strerror(errno));
        exit(1);
    }

    // Close the socket
    close(sock);

    return 0;
}