//FormAI DATASET v1.0 Category: Simple Web Server ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>

#define BUF_SIZE 1024
#define PORT 8080
#define WEB_ROOT "./www"

void send_data(int client_sock, char *content_type, char *file_path);
void send_error(int client_sock, int error_code);
char *get_content_type(char *file_path);
bool is_dir(char *path);
char *get_file_path(char *request);
void handle_request(int client_sock);
void serve_client(int client_sock);

int main(int argc, char const *argv[]) {
    int server_fd, client_sock;
    struct sockaddr_in server, client;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Bind address and port to socket
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Serve clients in a loop
    while (true) {
        socklen_t client_len = sizeof(client);

        // Accept incoming connection
        if ((client_sock = accept(server_fd, (struct sockaddr *)&client, &client_len)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Serve client's request
        serve_client(client_sock);

        // Close connection
        close(client_sock);
    }

    return 0;
}

/**
 * Sends HTTP response data to the client socket.
 * client_sock: the client socket to send the response to
 * content_type: the MIME type of the content being sent
 * file_path: the file path to the content being sent
 */
void send_data(int client_sock, char *content_type, char *file_path) {
    FILE *file = fopen(file_path, "rb");

    // Check if file exists
    if (file == NULL) {
        send_error(client_sock, 404);
        return;
    }

    // Send response header
    char response_header[BUF_SIZE];
    snprintf(response_header, BUF_SIZE, "HTTP/1.1 200 OK\r\nContent-Type: %s\r\n\r\n", content_type);
    send(client_sock, response_header, strlen(response_header), 0);

    // Send file content
    char buffer[BUF_SIZE];
    while (true) {
        int bytes_read = fread(buffer, 1, BUF_SIZE, file);
        if (bytes_read <= 0) break;
        send(client_sock, buffer, bytes_read, 0);
    }

    fclose(file);
}

/**
 * Sends HTTP error response to the client socket.
 * client_sock: the client socket to send the response to
 * error_code: the HTTP error code to send
 */
void send_error(int client_sock, int error_code) {
    char *error_message;
    char response_header[BUF_SIZE];

    switch (error_code) {
        case 400:
            error_message = "400 Bad Request";
            break;
        case 404:
            error_message = "404 Not Found";
            break;
        case 500:
            error_message = "500 Internal Server Error";
            break;
        default:
            error_message = "Error";
            break;
    }

    snprintf(response_header, BUF_SIZE, "HTTP/1.1 %s\r\n\r\n", error_message);
    send(client_sock, response_header, strlen(response_header), 0);
    send(client_sock, error_message, strlen(error_message), 0);
}

/**
 * Returns the MIME type of the given file path.
 * file_path: the file path to get the MIME type of
 */
char *get_content_type(char *file_path) {
    char *extension = strrchr(file_path, '.');

    if (extension != NULL) {
        if (strcmp(extension, ".html") == 0 || strcmp(extension, ".htm") == 0) {
            return "text/html";
        } else if (strcmp(extension, ".css") == 0) {
            return "text/css";
        } else if (strcmp(extension, ".js") == 0) {
            return "application/javascript";
        } else if (strcmp(extension, ".png") == 0) {
            return "image/png";
        } else if (strcmp(extension, ".gif") == 0) {
            return "image/gif";
        } else if (strcmp(extension, ".jpg") == 0 || strcmp(extension, ".jpeg") == 0) {
            return "image/jpeg";
        }
    }

    return "application/octet-stream";
}

/**
 * Returns whether or not the given path is a directory.
 * path: the path to check
 */
bool is_dir(char *path) {
    int path_len = strlen(path);
    return path[path_len - 1] == '/';
}

/**
 * Returns the file path of the resource being requested in the given HTTP request.
 * request: the HTTP request string
 */
char *get_file_path(char *request) {
    char *path_start = strchr(request, ' ') + 1;
    char *path_end = strchr(path_start, ' ');

    int path_len = path_end - path_start;
    char path[path_len + 1];

    strncpy(path, path_start, path_len);
    path[path_len] = '\0';

    if (strcmp(path, "/") == 0) {
        strcat(path, "index.html");
    }

    int root_len = strlen(WEB_ROOT);
    char file_path[root_len + strlen(path) + 1];

    strcpy(file_path, WEB_ROOT);
    strcat(file_path, path);

    if (is_dir(file_path)) {
        strcat(file_path, "index.html");
    }

    return strdup(file_path);
}

/**
 * Handles an HTTP request from the client.
 * client_sock: the client socket to handle the request for
 */
void handle_request(int client_sock) {
    char request[BUF_SIZE];
    int bytes_received = recv(client_sock, request, BUF_SIZE - 1, 0);
    request[bytes_received] = '\0';

    // Ignore if request is empty
    if (bytes_received == 0) {
        return;
    }

    // Ignore if request method is not GET
    if (strncmp(request, "GET ", 4) != 0) {
        send_error(client_sock, 400);
        return;
    }

    // Ignore if HTTP version is not 1.1 or 1.0
    if (strncmp(request + strlen(request) - 8, "HTTP/1.1", 8) != 0
        && strncmp(request + strlen(request) - 8, "HTTP/1.0", 8) != 0) {
        send_error(client_sock, 400);
        return;
    }

    // Get file path from request
    char *file_path = get_file_path(request);

    // Get content type from file path
    char *content_type = get_content_type(file_path);

    // Send data back to client
    send_data(client_sock, content_type, file_path);

    free(file_path);
}

/**
 * Serves the client connected on the given socket.
 * client_sock: the client socket to serve
 */
void serve_client(int client_sock) {
    handle_request(client_sock);
}