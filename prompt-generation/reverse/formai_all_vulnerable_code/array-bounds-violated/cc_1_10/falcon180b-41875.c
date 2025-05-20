//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 25
#define BUFFER_SIZE 1024

int main() {
    int socket_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDR, &server_addr.sin_addr);

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");
    printf("Enter your message: ");
    fgets(buffer, BUFFER_SIZE, stdin);

    if (send(socket_fd, buffer, strlen(buffer), 0) == -1) {
        printf("Error sending message\n");
        return 1;
    }

    bytes_received = 0;
    while (bytes_received < BUFFER_SIZE) {
        if ((bytes_received = recv(socket_fd, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0)) == -1) {
            printf("Error receiving response\n");
            return 1;
        }
    }

    buffer[bytes_received] = '\0';
    printf("Server response: %s\n", buffer);

    close(socket_fd);
    return 0;
}