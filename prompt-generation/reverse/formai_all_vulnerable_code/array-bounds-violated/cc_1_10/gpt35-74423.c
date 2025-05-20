//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int s;

void imapConnect(char *hostname, char *port) {
    struct addrinfo hints, *result;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(hostname, port, &hints, &result) != 0) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    for (struct addrinfo *p = result; p != NULL; p = p->ai_next) {
        if ((s = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(s, p->ai_addr, p->ai_addrlen) == -1) {
            close(s);
            perror("connect");
            continue;
        }

        break;
    }

    if (s == -1) {
        fprintf(stderr, "Failed to connect to %s:%s\n", hostname, port);
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Connected to %s:%s\n", hostname, port);

    freeaddrinfo(result);
}

void imapLogin(char* username, char* password) {
    char buffer[MAX_BUFFER_SIZE] = { 0 };
    ssize_t bytesReceived = 0;

    // Send login commands
    sprintf(buffer, "login %s %s\n", username, password);

    if (send(s, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive response
    bytesReceived = recv(s, buffer, MAX_BUFFER_SIZE, 0);

    if (bytesReceived == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    buffer[bytesReceived] = '\0';

    fprintf(stdout, "%s", buffer);
}

void imapLogout() {
    char buffer[MAX_BUFFER_SIZE] = { 0 };
    ssize_t bytesReceived = 0;

    // Send logout command
    sprintf(buffer, "logout\n");

    if (send(s, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive response
    bytesReceived = recv(s, buffer, MAX_BUFFER_SIZE, 0);

    if (bytesReceived == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    buffer[bytesReceived] = '\0';

    fprintf(stdout, "%s", buffer);
}

void imapList() {
    char buffer[MAX_BUFFER_SIZE] = { 0 };
    ssize_t bytesReceived = 0;

    // Send list command
    sprintf(buffer, "list\n");

    if (send(s, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive response
    bytesReceived = recv(s, buffer, MAX_BUFFER_SIZE, 0);

    if (bytesReceived == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    buffer[bytesReceived] = '\0';

    fprintf(stdout, "%s", buffer);
}

int main() {
    imapConnect("imap.gmail.com", "993");
    imapLogin("username@gmail.com", "password");
    imapList();
    imapLogout();

    close(s);

    return 0;
}