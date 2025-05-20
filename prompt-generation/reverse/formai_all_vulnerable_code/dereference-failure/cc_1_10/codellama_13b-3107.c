//Code Llama-13B DATASET v1.0 Category: Chat server ; Style: irregular
// Chat server example in an irregular style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10
#define MAX_BUFFER_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[])
{
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[MAX_BUFFER_SIZE];
    int str_len, i;

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        error_handling("socket() error");
    }

    // Set address information
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    // Bind address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("bind() error");
    }

    // Listen
    if (listen(server_fd, MAX_CLIENTS) == -1) {
        error_handling("listen() error");
    }

    printf("Server is ready\n");

    while (1) {
        // Accept client
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd == -1) {
            error_handling("accept() error");
        }

        // Receive message
        str_len = read(client_fd, buffer, MAX_BUFFER_SIZE);
        if (str_len == -1) {
            error_handling("read() error");
        }

        // Send message
        for (i = 0; i < str_len; i++) {
            buffer[i] = tolower(buffer[i]);
        }
        write(client_fd, buffer, str_len);

        // Close client
        close(client_fd);
    }

    // Close server
    close(server_fd);
    return 0;
}

void error_handling(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}