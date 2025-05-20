//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define DEFAULT_PORT 8080
#define MAX_REQUEST_SIZE 1024

typedef struct {
    char *host;
    int port;
    char *root;
} ServerConfig;

void parse_args(int argc, char **argv, ServerConfig *config) {
    config->host = "localhost";
    config->port = DEFAULT_PORT;
    config->root = ".";

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--host") == 0) {
            config->host = argv[++i];
        } else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--port") == 0) {
            config->port = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "--root") == 0) {
            config->root = argv[++i];
        } else {
            fprintf(stderr, "Unknown option: %s\n", argv[i]);
            exit(1);
        }
    }
}

int main(int argc, char **argv) {
    ServerConfig config;
    parse_args(argc, argv, &config);

    // Create a new socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    // Set up the socket address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(config.port);
    addr.sin_addr.s_addr = inet_addr(config.host);

    // Bind the socket to the address
    if (bind(sock, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 5) == -1) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connections
    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock == -1) {
            perror("accept");
            exit(1);
        }

        // Handle the client request
        char request[MAX_REQUEST_SIZE];
        memset(request, 0, sizeof(request));
        if (recv(client_sock, request, MAX_REQUEST_SIZE, 0) == -1) {
            perror("recv");
            close(client_sock);
            continue;
        }

        // Parse the request
        char *method = strtok(request, " ");
        char *path = strtok(NULL, " ");
        char *version = strtok(NULL, "\r\n");

        // Handle the GET request
        if (strcmp(method, "GET") == 0) {
            char *file = malloc(strlen(config.root) + strlen(path) + 1);
            strcpy(file, config.root);
            strcat(file, path);

            FILE *fp = fopen(file, "r");
            if (fp == NULL) {
                // Send a 404 Not Found response
                char response[] = "HTTP/1.1 404 Not Found\r\n\r\n<h1>404 Not Found</h1>";
                if (send(client_sock, response, strlen(response), 0) == -1) {
                    perror("send");
                    close(client_sock);
                    continue;
                }
            } else {
                // Send a 200 OK response
                char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
                if (send(client_sock, response, strlen(response), 0) == -1) {
                    perror("send");
                    close(client_sock);
                    continue;
                }

                // Send the file contents
                while (!feof(fp)) {
                    char buffer[1024];
                    memset(buffer, 0, sizeof(buffer));
                    fread(buffer, 1, sizeof(buffer), fp);
                    if (send(client_sock, buffer, strlen(buffer), 0) == -1) {
                        perror("send");
                        close(client_sock);
                        continue;
                    }
                }

                fclose(fp);
            }
            free(file);
        } else {
            // Send a 400 Bad Request response
            char response[] = "HTTP/1.1 400 Bad Request\r\n\r\n<h1>400 Bad Request</h1>";
            if (send(client_sock, response, strlen(response), 0) == -1) {
                perror("send");
                close(client_sock);
                continue;
            }
        }

        // Close the client socket
        close(client_sock);
    }

    // Close the server socket
    close(sock);

    return 0;
}