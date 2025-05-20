//FormAI DATASET v1.0 Category: Client Server Application ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [server]/[client] [port]\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[2]);
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (strcmp(argv[1], "server") == 0) {
        struct sockaddr_in addr = {0};
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = INADDR_ANY;

        if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            perror("bind");
            exit(1);
        }

        if (listen(sock, 1) < 0) {
            perror("listen");
            exit(1);
        }

        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept");
            exit(1);
        }

        char buf[256];
        ssize_t len;
        while ((len = recv(client_sock, buf, sizeof(buf), 0)) > 0) {
            buf[len] = 0;
            printf("%s", buf);
            fflush(stdout);
        }

        close(client_sock);
    } else if (strcmp(argv[1], "client") == 0) {
        struct sockaddr_in addr = {0};
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);

        if (inet_aton("127.0.0.1", &addr.sin_addr) == 0) {
            printf("Invalid IP address\n");
            exit(1);
        }

        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            perror("connect");
            exit(1);
        }

        char *message = "Hello, server!";
        ssize_t len = send(sock, message, strlen(message), 0);
        if (len < 0) {
            perror("send");
            exit(1);
        }
    } else {
        printf("Invalid argument: %s\n", argv[1]);
        exit(1);
    }

    close(sock);

    return 0;
}