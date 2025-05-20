//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: sophisticated
// ftp_client.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_BUF 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 1;
    }

    // Resolve the server address and port
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    struct addrinfo *serv_addr;
    if (getaddrinfo(host, port, &hints, &serv_addr) != 0) {
        fprintf(stderr, "getaddrinfo() failed\n");
        return 1;
    }

    // Connect to the server
    if (connect(sock, serv_addr->ai_addr, serv_addr->ai_addrlen) != 0) {
        perror("connect() failed");
        return 1;
    }

    // Send a message to the server
    char buf[MAX_BUF];
    sprintf(buf, "USER anonymous\r\n");
    if (send(sock, buf, strlen(buf), 0) != strlen(buf)) {
        perror("send() failed");
        return 1;
    }

    sprintf(buf, "PASS anonymous\r\n");
    if (send(sock, buf, strlen(buf), 0) != strlen(buf)) {
        perror("send() failed");
        return 1;
    }

    sprintf(buf, "SYST\r\n");
    if (send(sock, buf, strlen(buf), 0) != strlen(buf)) {
        perror("send() failed");
        return 1;
    }

    // Receive the server's response
    char response[MAX_BUF];
    memset(response, 0, MAX_BUF);
    if (recv(sock, response, MAX_BUF, 0) <= 0) {
        perror("recv() failed");
        return 1;
    }

    printf("Received response from server: %s\n", response);

    // Close the socket
    close(sock);

    return 0;
}