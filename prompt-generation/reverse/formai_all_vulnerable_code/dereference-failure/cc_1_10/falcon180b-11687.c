//Falcon-180B DATASET v1.0 Category: Networking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TRUE    1
#define FALSE   0
#define PORT    8080
#define BACKLOG 10

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int listen_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = TRUE;
    int addrlen = sizeof(client_addr);

    if ((listen_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error_handling("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt))) {
        error_handling("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_socket, BACKLOG) < 0) {
        error_handling("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (TRUE) {
        if ((new_socket = accept(listen_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
            error_handling("accept");
            exit(EXIT_FAILURE);
        }

        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));

        if (recv(new_socket, buffer, sizeof(buffer), 0) <= 0) {
            error_handling("recv");
            exit(EXIT_FAILURE);
        }

        printf("Received message: %s\n", buffer);

        send(new_socket, "ACK", strlen("ACK"), 0);
        close(new_socket);
    }

    close(listen_socket);
    return 0;
}

void error_handling(char *message) {
    fprintf(stderr, "%s: %s\n", message, strerror(errno));
    exit(EXIT_FAILURE);
}