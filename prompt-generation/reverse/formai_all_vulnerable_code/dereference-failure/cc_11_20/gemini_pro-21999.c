//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <port> <target>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int port = atoi(argv[1]);
    const char *target = argv[2];

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    int bind_result = bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (bind_result == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    int listen_result = listen(server_socket, 5);
    if (listen_result == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        int target_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (target_socket == -1) {
            perror("socket");
            close(client_socket);
            continue;
        }

        struct sockaddr_in target_addr;
        memset(&target_addr, 0, sizeof(target_addr));
        target_addr.sin_family = AF_INET;
        target_addr.sin_addr.s_addr = inet_addr(target);
        target_addr.sin_port = htons(80);

        int connect_result = connect(target_socket, (struct sockaddr *)&target_addr, sizeof(target_addr));
        if (connect_result == -1) {
            perror("connect");
            close(client_socket);
            close(target_socket);
            continue;
        }

        char buffer[BUFFER_SIZE];
        int bytes_read;
        while ((bytes_read = read(client_socket, buffer, BUFFER_SIZE)) > 0) {
            int bytes_written = write(target_socket, buffer, bytes_read);
            if (bytes_written == -1) {
                perror("write");
                break;
            }
        }

        if (bytes_read == -1) {
            perror("read");
        }

        close(client_socket);
        close(target_socket);
    }

    close(server_socket);

    return EXIT_SUCCESS;
}