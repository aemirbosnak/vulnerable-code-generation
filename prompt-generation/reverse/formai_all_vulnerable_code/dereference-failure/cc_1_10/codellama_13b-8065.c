//Code Llama-13B DATASET v1.0 Category: Networking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    int sock, port, client_sock, client_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[256];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    port = atoi(argv[1]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(sock, 3) < 0) {
        perror("listen");
        return 1;
    }

    client_len = sizeof(client_addr);
    client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("accept");
        return 1;
    }

    while (1) {
        int n = read(client_sock, buffer, sizeof(buffer));
        if (n < 0) {
            perror("read");
            return 1;
        }
        if (n == 0) {
            break;
        }
        printf("Received: %s", buffer);
    }

    return 0;
}