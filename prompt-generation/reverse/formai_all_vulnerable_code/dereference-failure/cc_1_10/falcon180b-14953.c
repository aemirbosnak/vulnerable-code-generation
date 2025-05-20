//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    int socket_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        close(socket_fd);
        return 1;
    }

    printf("Connected to server.\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        printf("Enter command: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        bytes_received = send(socket_fd, buffer, strlen(buffer), 0);
        if (bytes_received == -1) {
            printf("Error sending command: %s\n", strerror(errno));
            close(socket_fd);
            return 1;
        }

        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            printf("Error receiving response: %s\n", strerror(errno));
            close(socket_fd);
            return 1;
        }

        printf("Response: %s", buffer);
    }

    close(socket_fd);
    return 0;
}