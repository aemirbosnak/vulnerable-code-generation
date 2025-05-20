//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

//function to handle client requests
void handle_client(int client_socket)
{
    char buffer[1024];
    int n = 0;
    while ((n = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0';
        printf("Received message: %s\n", buffer);
        send(client_socket, buffer, n, 0);
    }
    close(client_socket);
}

int main()
{
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    int bind_result, listen_result;
    socklen_t client_address_len = sizeof(client_address);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Failed to create socket.\n");
        return 1;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    bind_result = bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (bind_result == -1) {
        printf("Failed to bind to port 8080.\n");
        return 1;
    }

    listen_result = listen(server_socket, 10);
    if (listen_result == -1) {
        printf("Failed to listen on socket.\n");
        return 1;
    }

    printf("Server is now listening on port 8080.\n");

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket == -1) {
            printf("Failed to accept client connection.\n");
            continue;
        }

        char *client_ip = inet_ntoa(client_address.sin_addr);
        printf("Client connected from %s:%d\n", client_ip, ntohs(client_address.sin_port));

        handle_client(client_socket);
    }

    close(server_socket);
    return 0;
}