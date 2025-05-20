//FormAI DATASET v1.0 Category: Chat server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1024

void serve_client(int client_sock) {
    char buffer[MAX_SIZE];
    int byte_count;
    if((byte_count = recv(client_sock, buffer, MAX_SIZE, 0)) > 0) {
        buffer[byte_count] = '\0';
        printf("Received: %s\n", buffer);
        send(client_sock, buffer, byte_count, 0);
        serve_client(client_sock);
    }
}

void start_server(int port) {
    int socket_desc, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char client_message[MAX_SIZE];
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_desc == -1) {
        printf("Could not create socket.\n");
        exit(1);
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);
    if(bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Could not bind to port %d\n", port);
        exit(1);
    }
    listen(socket_desc, 3);
    printf("Listening on port %d...\n", port);
    c = sizeof(struct sockaddr_in);
    while((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c))) {
        printf("Connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        serve_client(client_sock);
        close(client_sock);
    }
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s port\n", argv[0]);
        return 1;
    }
    start_server(atoi(argv[1]));
    return 0;
}