//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

// Function prototypes
int create_socket(int port);
void parse_request(char *request);
void send_response(int client_socket, char *response);

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    server_socket = create_socket(atoi(argv[1]));

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        parse_request(buffer);
    }

    close(server_socket);
    return 0;
}

int create_socket(int port) {
    int socket_fd;
    struct sockaddr_in server_addr;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd == -1) {
        perror("socket failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(socket_fd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    return socket_fd;
}

void parse_request(char *request) {
    char method[10];
    char uri[100];
    char version[10];

    sscanf(request, "%s %s %s", method, uri, version);

    printf("Method: %s\nURI: %s\nVersion: %s\n", method, uri, version);
}

void send_response(int client_socket, char *response) {
    send(client_socket, response, strlen(response), 0);
}