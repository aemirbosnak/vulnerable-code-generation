//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT_RANGE_START 1
#define PORT_RANGE_END 1024

int main(int argc, char **argv) {
    int sock, i, port, n;
    struct sockaddr_in serv_addr;
    char *hostname;
    char *message = "Hello, World!";

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    hostname = argv[1];
    port = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address/ Address not supported\n");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        return 1;
    }

    n = write(sock, message, strlen(message));
    if (n < 0) {
        perror("Write failed");
        return 1;
    }

    printf("Wrote %d bytes\n", n);

    close(sock);

    return 0;
}