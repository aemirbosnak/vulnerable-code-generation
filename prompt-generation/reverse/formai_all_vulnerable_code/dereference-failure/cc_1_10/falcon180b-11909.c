//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 4096
#define PORT 8080

void error_handling(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_socket == -1) {
        error_handling("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listening_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        error_handling("bind");
    }

    if (listen(listening_socket, 3) == -1) {
        error_handling("listen");
    }

    printf("Proxy server is listening on port %d\n", port);

    while (1) {
        int client_socket = accept(listening_socket, NULL, NULL);
        if (client_socket == -1) {
            error_handling("accept");
        }

        char buffer[MAX_LINE];
        memset(buffer, 0, sizeof(buffer));

        while (fgets(buffer, sizeof(buffer), stdin)!= NULL) {
            send(client_socket, buffer, strlen(buffer), 0);
        }

        close(client_socket);
    }

    return 0;
}