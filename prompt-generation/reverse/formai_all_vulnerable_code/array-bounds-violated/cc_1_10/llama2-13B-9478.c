//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 5
#define MAX_MESSAGE_LEN 1024

struct client_t {
    int sock;
    char name[50];
};

void handle_client(int sock) {
    char buffer[MAX_MESSAGE_LEN];
    int len;

    printf("Client connected: %s\n", buffer);

    while (1) {
        len = recv(sock, buffer, MAX_MESSAGE_LEN, 0);
        if (len < 0) {
            perror("recv failed");
            break;
        }
        printf("Received message: %s\n", buffer);

        send(sock, "Hello, client!", 13, 0);
    }
}

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sock, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", server_addr.sin_port);

    struct client_t clients[MAX_CLIENTS];
    int client_idx = 0;

    while (1) {
        sock = accept(sock, NULL, NULL);
        if (sock < 0) {
            perror("accept failed");
            break;
        }

        clients[client_idx].sock = sock;
        printf("New client connected: %s\n", clients[client_idx].name);

        handle_client(clients[client_idx].sock);

        close(clients[client_idx].sock);
        client_idx++;
    }

    return 0;
}