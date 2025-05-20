//Code Llama-13B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <address> <port>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return 1;
    }

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    printf("Connected to %s:%s\n", argv[1], argv[2]);

    char buffer[BUFFER_SIZE];
    while (1) {
        int n = read(0, buffer, BUFFER_SIZE);
        if (n == -1) {
            perror("read");
            break;
        } else if (n == 0) {
            break;
        }

        if (write(server_socket, buffer, n) == -1) {
            perror("write");
            break;
        }
    }

    close(server_socket);
    return 0;
}