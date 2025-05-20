//Falcon-180B DATASET v1.0 Category: Networking ; Style: safe
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
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_ADDRESS "127.0.0.1"

int main(int argc, char *argv[]) {
    int client_socket, bytes_received, total_bytes_received = 0;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;
    time_t start_time, end_time;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);
    server_addr.sin_port = htons(SERVER_PORT);

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error: Failed to create socket\n");
        exit(1);
    }

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received == 0) {
            printf("Server disconnected\n");
            break;
        } else if (bytes_received == -1) {
            printf("Error: Failed to receive data from server\n");
            exit(1);
        }

        total_bytes_received += bytes_received;
        printf("Received %d bytes of data\n", bytes_received);

        if (strstr(buffer, "quit")!= NULL) {
            send(client_socket, "bye", strlen("bye"), 0);
            break;
        }
    }

    close(client_socket);
    return 0;
}