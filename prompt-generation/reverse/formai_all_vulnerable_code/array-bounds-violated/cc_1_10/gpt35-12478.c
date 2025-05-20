//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    const char *host = argv[1];
    const char *port = argv[2];
    struct addrinfo hints;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    struct addrinfo *res;
    int status = getaddrinfo(host, port, &hints, &res);
    if (status != 0) {
        fprintf(stderr, "Error: %s\n", gai_strerror(status));
        return 1;
    }

    int sock_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock_fd < 0) {
        perror("Error: socket failed");
        return 1;
    }

    if (connect(sock_fd, res->ai_addr, res->ai_addrlen) < 0) {
        perror("Error: connect failed");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_read = recv(sock_fd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_read < 0) {
        perror("Error: recv failed");
        return 1;
    }
    buffer[bytes_read] = '\0';

    printf("Received: %s\n", buffer);

    close(sock_fd);
    freeaddrinfo(res);
    return 0;
}