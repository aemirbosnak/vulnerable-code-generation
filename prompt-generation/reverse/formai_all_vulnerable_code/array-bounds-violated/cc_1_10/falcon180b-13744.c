//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define SERVER "localhost"
#define PORT 25

void send_command(int sock, const char* command);
void send_data(int sock, const char* data);
void receive_response(int sock);

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    send_command(sock, "EHLO localhost\r\n");
    send_command(sock, "AUTH LOGIN\r\n");
    send_data(sock, "username");
    send_data(sock, "password");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        receive_response(sock);
        printf("Response: %s", buffer);
    }

    close(sock);
    return 0;
}

void send_command(int sock, const char* command) {
    send(sock, command, strlen(command), 0);
}

void send_data(int sock, const char* data) {
    send(sock, data, strlen(data), 0);
    send(sock, "\r\n", 2, 0);
}

void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    int bytes_received = 0;
    while ((bytes_received = recv(sock, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received: %s", buffer);
    }
}