//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>

#define PORT 80
#define BACKLOG 10
#define MAX_REQUEST_LENGTH 1024
#define ROOT_DIRECTORY "./www"
#define INDEX_FILE "index.html"

void handle_request(int client_socket);
void send_response(int client_socket, char *response);
char *get_file_content(char *filename);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_size;
    char buffer[MAX_REQUEST_LENGTH];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        client_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_size);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        handle_request(client_socket);

        close(client_socket);
    }

    return 0;
}

void handle_request(int client_socket) {
    char request[MAX_REQUEST_LENGTH];
    char *filename;
    char *path;
    char method[10];
    char version[10];
    int i;

    memset(request, 0, MAX_REQUEST_LENGTH);

    if (recv(client_socket, request, MAX_REQUEST_LENGTH, 0) <= 0) {
        send_response(client_socket, "Server Error");
        return;
    }

    sscanf(request, "%s %s %s", method, version, request);

    if (strcmp(method, "GET")!= 0) {
        send_response(client_socket, "Method Not Allowed");
        return;
    }

    path = strtok(request, " ");

    if (path == NULL) {
        filename = ROOT_DIRECTORY;
    } else {
        filename = path;
    }

    if (filename[strlen(filename) - 1] == '/') {
        strcat(filename, INDEX_FILE);
    }

    if (access(filename, F_OK)!= 0) {
        send_response(client_socket, "File Not Found");
        return;
    }

    send_response(client_socket, get_file_content(filename));
}

void send_response(int client_socket, char *response) {
    send(client_socket, response, strlen(response), 0);
}

char *get_file_content(char *filename) {
    FILE *file;
    char *content = NULL;
    size_t size = 0;

    file = fopen(filename, "r");

    if (file == NULL) {
        return NULL;
    }

    while ((getline(&content, &size, file))!= -1) {
        content = realloc(content, size + 1);
        content[size] = '\0';
    }

    fclose(file);

    return content;
}