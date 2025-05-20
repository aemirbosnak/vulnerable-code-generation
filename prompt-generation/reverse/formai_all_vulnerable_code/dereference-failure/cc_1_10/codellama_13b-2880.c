//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: sophisticated
// Port Scanner in C
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <ip_address> <port_range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    char *port_range = argv[2];

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(atoi(port_range));
    inet_pton(AF_INET, ip_address, &address.sin_addr);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket()");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("connect()");
        return 1;
    }

    char buffer[BUFSIZE];
    int n = read(sock, buffer, BUFSIZE);
    if (n < 0) {
        perror("read()");
        return 1;
    }

    printf("Received %d bytes from %s:%s\n", n, ip_address, port_range);
    printf("Data: %s\n", buffer);

    close(sock);

    return 0;
}