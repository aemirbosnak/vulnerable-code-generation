#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t read_size;

    while ((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        int data[10];
        memcpy(data, buffer, read_size);

        // Intentionally vulnerable code: unchecked data size assumption
        for (int i = 0; i < 10; ++i)
            data[i] = data[i] * 2; // Integer overflow here

        // Rest of the function (sending response, closing connection, etc.)
        // ...
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 5);

    printf("Listening on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        handle_client(client_socket);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}
