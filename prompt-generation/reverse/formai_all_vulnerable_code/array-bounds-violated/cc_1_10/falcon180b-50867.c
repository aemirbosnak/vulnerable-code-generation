//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define TRUE   1
#define FALSE  0
#define PORT 8080
#define MAX 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    int opt = 1;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1)
        error("socket failed");

    setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("bind failed");

    if (listen(listen_socket, 3) < 0)
        error("listen");

    while (TRUE) {
        socklen_t addr_size;
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &addr_size);

        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        send(client_socket, "Surrealistic TCP/IP Programming\r\n", 33, 0);

        while (recv(client_socket, buffer, MAX, 0) > 0) {
            buffer[recv(client_socket, buffer, MAX, 0)] = '\0';
            printf("%s", buffer);
        }

        close(client_socket);
    }

    return 0;
}