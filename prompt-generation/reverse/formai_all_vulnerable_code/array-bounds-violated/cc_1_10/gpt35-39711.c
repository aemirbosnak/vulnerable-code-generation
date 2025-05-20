//FormAI DATASET v1.0 Category: Simple Web Server ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define PORT 80
#define WEB_ROOT "./webroot"

char *get_file_extension(char *file_name) {
    char *extension = strrchr(file_name, '.');
    if (!extension) {
        return "";
    }
    return extension + 1;
}

bool send_file(int client_socket, char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        return false;
    }
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file))) {
        send(client_socket, buffer, bytes_read, 0);
    }
    fclose(file);
    return true;
}

int handle_request(int client_socket, char *request) {
    char *method = strtok(request, " ");
    if (!method) {
        return -1;
    }
    char *path = strtok(NULL, " ");
    if (!path) {
        return -1;
    }
    strtok(NULL, "\r\n");
    printf("Request method: %s\n", method);
    printf("Request path: %s\n", path);
    if (strcmp(method, "GET") != 0) {
        return -1;
    }
    char file_path[BUFFER_SIZE];
    sprintf(file_path, "%s%s", WEB_ROOT, path);
    if (file_path[strlen(file_path) - 1] == '/') {
        strcat(file_path, "index.html");
    }
    if (access(file_path, F_OK) == -1) {
        return -1;
    }
    char *content_type;
    char *extension = get_file_extension(file_path);
    if (strcmp(extension, "html") == 0) {
        content_type = "text/html";
    } else if (strcmp(extension, "css") == 0) {
        content_type = "text/css";
    } else if (strcmp(extension, "js") == 0) {
        content_type = "application/javascript";
    } else if (strcmp(extension, "jpg") == 0 || strcmp(extension, "jpeg") == 0) {
        content_type = "image/jpeg";
    } else if (strcmp(extension, "gif") == 0) {
        content_type = "image/gif";
    } else if (strcmp(extension, "png") == 0) {
        content_type = "image/png";
    } else {
        content_type = "text/plain";
    }
    char response_header[BUFFER_SIZE];
    sprintf(response_header, "HTTP/1.1 200 OK\r\nContent-Type: %s\r\n\r\n", content_type);
    send(client_socket, response_header, strlen(response_header), 0);
    send_file(client_socket, file_path);
    return 0;
}

int main() {
    int server_socket, client_socket, addr_len;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }
    if (listen(server_socket, 10) < 0) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }
    printf("Listening on port %d...\n", PORT);
    while (true) {
        addr_len = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, (socklen_t *)&addr_len);
        if (client_socket < 0) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }
        ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("Error receiving data from client");
            close(client_socket);
            continue;
        }
        buffer[bytes_received] = '\0';
        printf("Received request:\n%s\n", buffer);
        if (handle_request(client_socket, buffer) < 0) {
            char *error_response = "HTTP/1.1 404 Not Found\r\nContent-Length: 9\r\n\r\nNot Found";
            send(client_socket, error_response, strlen(error_response), 0);
        }
        close(client_socket);
    }
    return 0;
}