//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 25
#define DELIMITER "\r\n"

int main() {
    int socket_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    char *response;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error creating socket!\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server!\n");
        exit(1);
    }

    printf("Connected to server!\n");

    while (1) {
        bytes_received = 0;
        memset(buffer, 0, BUFFER_SIZE);
        printf("Enter command: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        if (strlen(buffer) == 0) {
            continue;
        }
        if (strcmp(buffer, "quit") == 0) {
            break;
        }
        send(socket_fd, buffer, strlen(buffer), 0);
        response = malloc(BUFFER_SIZE);
        bytes_received = recv(socket_fd, response, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Server disconnected!\n");
            exit(1);
        }
        response[bytes_received - 1] = '\0';
        printf("Server response: %s", response);
        free(response);
    }

    close(socket_fd);
    return 0;
}