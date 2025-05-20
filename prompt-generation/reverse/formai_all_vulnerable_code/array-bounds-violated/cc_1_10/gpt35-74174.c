//FormAI DATASET v1.0 Category: Firewall ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

void send_error(int code, char *message, int socket) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "HTTP/1.1 %d %s\r\n\r\n", code, message);
    write(socket, buffer, strlen(buffer));
}

int main(int argc, char *argv[]) {
    int port = 8080;
    if (argc > 1) port = atoi(argv[1]);

    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length = sizeof(client_address);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error: Failed to create socket\n");
        return 1;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Error: Failed to bind socket\n");
        return 1;
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error: Failed to listen on socket\n");
        return 1;
    }

    printf("Server running on port %d\n", port);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket == -1) {
            printf("Error: Failed to accept client connection\n");
            continue;
        }

        char buffer[BUFFER_SIZE];
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 1) {
            printf("Error: Failed to read request\n");
            close(client_socket);
            continue;
        }

        buffer[bytes_received] = 0;

        printf("Received request:\n%s\n", buffer);

        if (strstr(buffer, "ninjastorm.com")) {
            send_error(403, "Forbidden", client_socket);
            printf("Blocked request to ninjastorm.com\n");
            close(client_socket);
            continue;
        }

        char response[BUFFER_SIZE];
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, world!\n");
        write(client_socket, response, strlen(response));

        printf("Sent response:\n%s\n", response);

        close(client_socket);
    }

    return 0;
}