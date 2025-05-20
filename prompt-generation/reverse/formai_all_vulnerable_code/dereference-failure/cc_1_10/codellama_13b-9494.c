//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: Linus Torvalds
// SMTP Client Example Program in a Linus Torvalds style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &server.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton failed\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        fprintf(stderr, "socket failed\n");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        fprintf(stderr, "connect failed\n");
        return 1;
    }

    char buf[BUFSIZE];
    ssize_t n = read(sock, buf, BUFSIZE);
    if (n <= 0) {
        fprintf(stderr, "read failed\n");
        return 1;
    }

    printf("Received %zd bytes from server:\n", n);
    printf("%s\n", buf);

    close(sock);
    return 0;
}