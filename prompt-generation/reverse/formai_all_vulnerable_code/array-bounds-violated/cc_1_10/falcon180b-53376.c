//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Function prototypes
int create_socket(int port);
int accept_connection(int server_socket);
void handle_client(int client_socket);
void broadcast_message(int sender_socket, char* message);

int main() {
    int server_socket = create_socket(8080);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    printf("Server started on port %d\n", 8080);

    while (1) {
        int client_socket = accept_connection(server_socket);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
        } else {
            handle_client(client_socket);
        }
    }

    close(server_socket);
    return 0;
}

int create_socket(int port) {
    int socket_fd;
    struct sockaddr_in server_addr;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        close(socket_fd);
        return -1;
    }

    if (listen(socket_fd, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        close(socket_fd);
        return -1;
    }

    return socket_fd;
}

int accept_connection(int server_socket) {
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int client_socket;

    client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_len);

    if (client_socket == -1) {
        printf("Error accepting connection\n");
        return -1;
    }

    return client_socket;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while (1) {
        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Client disconnected\n");
            close(client_socket);
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Client message: %s\n", buffer);

        broadcast_message(client_socket, buffer);
    }
}

void broadcast_message(int sender_socket, char* message) {
    char buffer[BUFFER_SIZE];
    int bytes_sent;

    strcpy(buffer, message);

    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (i == sender_socket)
            continue;

        bytes_sent = send(i, buffer, strlen(buffer), 0);

        if (bytes_sent <= 0) {
            printf("Error sending message to client %d\n", i);
        }
    }
}