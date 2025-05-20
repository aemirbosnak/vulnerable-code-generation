//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: future-proof
// Building a SMTP Client example program in a future-proof style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 25 // default SMTP port
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    // check command line arguments
    if (argc != 3) {
        fprintf(stderr, "usage: %s <host> <msg>\n", argv[0]);
        return 1;
    }

    // create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // create address structure
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0) {
        fprintf(stderr, "invalid host\n");
        return 1;
    }

    // connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("connect");
        return 1;
    }

    // send message
    char *msg = argv[2];
    if (send(sock, msg, strlen(msg), 0) == -1) {
        perror("send");
        return 1;
    }

    // receive response
    char buf[BUFSIZE];
    if (recv(sock, buf, BUFSIZE, 0) == -1) {
        perror("recv");
        return 1;
    }
    printf("response: %s\n", buf);

    // close socket
    if (close(sock) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}