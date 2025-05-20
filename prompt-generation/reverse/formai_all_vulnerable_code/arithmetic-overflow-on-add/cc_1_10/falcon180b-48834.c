//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SERVER_ADDRESS "speedtest.net"
#define PORT 80

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int total_bytes_received = 0;
    double start_time, end_time;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(server_socket);
        return 1;
    }

    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr))) == -1) {
        printf("Error accepting connection\n");
        close(server_socket);
        return 1;
    }

    start_time = time(NULL);

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        total_bytes_received += bytes_received;
    }

    end_time = time(NULL);
    close(client_socket);
    close(server_socket);

    printf("Total bytes received: %d\n", total_bytes_received);
    printf("Time taken: %f seconds\n", difftime(end_time, start_time));

    return 0;
}