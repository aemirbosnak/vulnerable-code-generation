//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define DEFAULT_PORT 8080

struct client {
    int sock;
    struct sockaddr_in addr;
};

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0)) > 0) {
        send(client_sock, buffer, bytes_received, 0);
    }

    close(client_sock);
}

int main(int argc, char *argv[]) {
    int server_sock, client_sock, addrlen;
    struct sockaddr_in server_addr, client_addr;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        return 1;
    }

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    while (1) {
        addrlen = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addrlen);
        if (client_sock == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        handle_client(client_sock);
    }

    close(server_sock);
    return 0;
}