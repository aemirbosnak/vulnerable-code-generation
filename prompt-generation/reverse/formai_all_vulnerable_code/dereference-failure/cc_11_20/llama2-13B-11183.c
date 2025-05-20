//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct request {
    char *method;
    char *uri;
    char *query;
    char *headers[10];
};

struct response {
    char *status;
    char *body;
};

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }

    listen(sock, 3);

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        struct request *req = malloc(sizeof(struct request));
        if (req == NULL) {
            perror("malloc() failed");
            exit(EXIT_FAILURE);
        }

        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept() failed");
            exit(EXIT_FAILURE);
        }

        char *buffer = malloc(1024);
        if (buffer == NULL) {
            perror("malloc() failed");
            exit(EXIT_FAILURE);
        }

        int bytes_read = read(client_sock, buffer, 1024);
        if (bytes_read < 0) {
            perror("read() failed");
            exit(EXIT_FAILURE);
        }

        char *token = strtok(buffer, " ");
        char *method = token;
        token = strtok(NULL, " ");
        char *uri = token;
        token = strtok(NULL, " ");
        char *query = token;

        struct response *res = malloc(sizeof(struct response));
        if (res == NULL) {
            perror("malloc() failed");
            exit(EXIT_FAILURE);
        }

        if (strcmp(method, "GET") == 0) {
            res->status = "200 OK";
            res->body = "Hello, world!";
        } else if (strcmp(method, "POST") == 0) {
            res->status = "201 Created";
            res->body = "Request accepted";
        } else {
            res->status = "400 Bad Request";
            res->body = "Method not supported";
        }

        send(client_sock, res->body, strlen(res->body), 0);
        close(client_sock);
    }

    return 0;
}