//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

void error(const char* message);

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <server_address> <file_name>\n", argv[0]);
        return 1;
    }

    char* server_address = argv[1];
    char* file_name = argv[2];

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        error("Error creating socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server_address, &server_addr.sin_addr);

    if (connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error("Error connecting to server");
    }

    char username[20] = "anonymous";
    char password[20] = "anonymous@example.com";

    send(server_socket, username, strlen(username), 0);
    send(server_socket, password, strlen(password), 0);

    char command[30] = "RETR ";
    strcat(command, file_name);
    send(server_socket, command, strlen(command), 0);

    FILE* file = fopen(file_name, "wb");
    if (file == NULL) {
        error("Error opening file for writing");
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        fwrite(buffer, bytes_received, 1, file);
    }

    fclose(file);
    close(server_socket);

    return 0;
}

void error(const char* message) {
    perror(message);
    exit(1);
}