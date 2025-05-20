//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int addrlen;
    int bytes_received;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <listen_port> <destination_host>\n", argv[0]);
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    if (inet_pton(AF_INET, argv[2], &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid destination host\n");
        exit(1);
    }

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket\n");
        exit(1);
    }

    if (listen(listen_socket, 5) == -1) {
        fprintf(stderr, "Error listening on socket\n");
        exit(1);
    }

    while (1) {
        addrlen = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &addrlen);
        if (client_socket == -1) {
            fprintf(stderr, "Error accepting connection\n");
            continue;
        }

        fprintf(stdout, "Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0) {
                fprintf(stdout, "Client disconnected\n");
                break;
            }

            send(client_socket, buffer, bytes_received, 0);
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}