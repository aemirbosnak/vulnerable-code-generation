//MISTRAL-7B DATASET v1.0 Category: TCP/IP Programming ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define PATH_SIZE 256

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char path[PATH_SIZE] = {0};

    // Initialize server
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        // Accept new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Receive file path from client
        valread = recv(new_socket, path, PATH_SIZE, 0);
        if (valread == -1) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }
        path[valread] = '\0';
        printf("Received file path: %s\n", path);

        // Open file for reading
        FILE *fp = fopen(path, "rb");
        if (fp == NULL) {
            perror("Error opening file");
            send(new_socket, "Error opening file\n", strlen("Error opening file\n"), 0);
            close(new_socket);
            continue;
        }

        // Send file size to client
        fseek(fp, 0, SEEK_END);
        off_t filesize = ftell(fp);
        send(new_socket, &filesize, sizeof(filesize), 0);

        // Send file content to client
        fseek(fp, 0, SEEK_SET);
        size_t n;
        while ((n = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
            send(new_socket, buffer, n, 0);
        }

        // Close file and socket
        fclose(fp);
        close(new_socket);
        printf("File sent to client: %s\n", path);
    }

    return 0;
}