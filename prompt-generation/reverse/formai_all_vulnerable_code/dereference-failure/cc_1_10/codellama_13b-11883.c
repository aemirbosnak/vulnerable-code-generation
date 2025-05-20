//Code Llama-13B DATASET v1.0 Category: Networking ; Style: retro
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>

    int main(int argc, char *argv[]) {
        if (argc != 2) {
            fprintf(stderr, "Usage: %s <port>\n", argv[0]);
            return 1;
        }

        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("socket");
            return 1;
        }

        struct sockaddr_in addr = {
            .sin_family = AF_INET,
            .sin_port = htons(atoi(argv[1])),
            .sin_addr = {.s_addr = INADDR_ANY}
        };

        if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            perror("bind");
            return 1;
        }

        if (listen(sock, 3) < 0) {
            perror("listen");
            return 1;
        }

        int client = accept(sock, NULL, NULL);
        if (client < 0) {
            perror("accept");
            return 1;
        }

        char buffer[1024];
        int n;
        while ((n = read(client, buffer, sizeof(buffer))) > 0) {
            write(client, buffer, n);
        }

        close(client);
        close(sock);
        return 0;
    }