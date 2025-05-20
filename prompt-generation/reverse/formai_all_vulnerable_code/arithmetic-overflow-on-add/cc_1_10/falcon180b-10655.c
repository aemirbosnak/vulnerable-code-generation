//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_DATA_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

void send_data(int sock, char* data, int size) {
    send(sock, data, size, 0);
}

void recv_data(int sock, char* data, int size) {
    int bytes_received = 0;
    while (bytes_received < size) {
        int result = recv(sock, data + bytes_received, size - bytes_received, 0);
        if (result <= 0) {
            printf("Error receiving data.\n");
            exit(1);
        }
        bytes_received += result;
    }
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr))!= 0) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    char* request_data = "GET /speed_test HTTP/1.1\r\nHost: 127.0.0.1\r\nConnection: close\r\n\r\n";
    send_data(sock, request_data, strlen(request_data));

    char* response_data = malloc(MAX_DATA_SIZE);
    memset(response_data, 0, MAX_DATA_SIZE);
    recv_data(sock, response_data, MAX_DATA_SIZE);

    printf("Response:\n%s", response_data);

    close(sock);
    free(response_data);
    return 0;
}