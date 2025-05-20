//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void send_data(int socket, const char* data, int len) {
    int bytes_sent = 0;
    while (bytes_sent < len) {
        int result = send(socket, data + bytes_sent, len - bytes_sent, 0);
        if (result <= 0) {
            printf("Error sending data\n");
            exit(1);
        }
        bytes_sent += result;
    }
}

void receive_data(int socket, char* buffer, int max_len) {
    int bytes_received = 0;
    while (bytes_received < max_len) {
        int result = recv(socket, buffer + bytes_received, max_len - bytes_received, 0);
        if (result <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }
        bytes_received += result;
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    sprintf(buffer, "GET /speed_test.html HTTP/1.1\r\nHost: 127.0.0.1\r\nConnection: close\r\n\r\n");
    send_data(server_socket, buffer, strlen(buffer));

    char response[BUFFER_SIZE];
    receive_data(server_socket, response, BUFFER_SIZE);

    close(server_socket);

    return 0;
}