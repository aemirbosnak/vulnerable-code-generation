//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 8192

int main() {
    int server_socket;
    int client_socket;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    double start_time, end_time;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, 10) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server started on port %d\n", SERVER_PORT);

    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr))) == -1) {
            perror("accept");
            exit(1);
        }

        bytes_received = 0;
        start_time = time(0);

        while (bytes_received < BUFFER_SIZE) {
            if ((bytes_received += recv(client_socket, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0)) <= 0) {
                break;
            }
        }

        close(client_socket);

        end_time = time(0);
        printf("Received %d bytes in %lf seconds\n", bytes_received, end_time - start_time);
    }

    return 0;
}