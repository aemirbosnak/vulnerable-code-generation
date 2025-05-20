//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CONNECTIONS 5
#define MAX_BUFFER_SIZE 1024

typedef struct {
    int socket_fd;
    struct sockaddr_in address;
    socklen_t address_len;
} client_info;

static int create_server_socket(void) {
    int server_socket_fd;
    struct sockaddr_in server_address;

    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);

    if (bind(server_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket_fd, MAX_CONNECTIONS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    return server_socket_fd;
}

static client_info accept_client(int server_socket_fd) {
    client_info client;

    client.socket_fd = accept(server_socket_fd, (struct sockaddr *)&client.address, &client.address_len);
    if (client.socket_fd == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    return client;
}

static void handle_client(client_info client) {
    char buffer[MAX_BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client.socket_fd, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer);

        // Process the message and send a response back to the client.
        char response[] = "OK";
        send(client.socket_fd, response, strlen(response), 0);
    }

    if (bytes_received == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    close(client.socket_fd);
}

int main(void) {
    int server_socket_fd;

    server_socket_fd = create_server_socket();

    while (1) {
        client_info client = accept_client(server_socket_fd);
        handle_client(client);
    }

    close(server_socket_fd);

    return EXIT_SUCCESS;
}