//Code Llama-13B DATASET v1.0 Category: Networking ; Style: Linus Torvalds
/*
 * A unique C Networking example program in a Linus Torvalds style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(sock, 3) < 0) {
        perror("listen");
        return 1;
    }

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sock < 0) {
            perror("accept");
            return 1;
        }

        char buf[1024];
        ssize_t n = read(client_sock, buf, sizeof(buf));
        if (n < 0) {
            perror("read");
            return 1;
        }

        printf("Received message from %s:%d: %s\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buf);

        n = write(client_sock, "Hello, client!", 13);
        if (n < 0) {
            perror("write");
            return 1;
        }

        close(client_sock);
    }

    close(sock);

    return 0;
}