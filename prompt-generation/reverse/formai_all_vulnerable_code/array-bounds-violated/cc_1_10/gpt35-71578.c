//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int socket_fd;
    char *hostname = "example.com";
    char *path = "/";
    int port = 80;
    struct sockaddr_in server_address;
    char request[BUFFER_SIZE] = {0};
    char response[BUFFER_SIZE] = {0};
    char *body_start = NULL;
    int body_length = 0;

    // create socket
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Failed to create socket\n");
        return EXIT_FAILURE;
    }

    // set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &server_address.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address or address not supported\n");
        return EXIT_FAILURE;
    }

    // connect to server
    if (connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Failed to connect to server\n");
        return EXIT_FAILURE;
    }

    // create request
    sprintf(request, "GET %s HTTP/1.1\r\n"
                      "Host: %s\r\n"
                      "Connection: close\r\n"
                      "\r\n", path, hostname);

    // send request
    if (send(socket_fd, request, strlen(request), 0) < 0) {
        fprintf(stderr, "Failed to send request\n");
        return EXIT_FAILURE;
    }

    // receive response
    int byte_count = 0;
    while ((byte_count = recv(socket_fd, response, BUFFER_SIZE - 1, 0)) > 0) {
        response[byte_count] = '\0';
        if (body_start == NULL && (body_start = strstr(response, "\r\n\r\n"))) {
            body_start += 4;
        }
        body_length += byte_count;
        printf("%s", response);
        memset(response, 0, sizeof(response));
    }

    // print body length
    printf("\nBody length: %d\n", body_length - (body_start - response));

    // close socket
    close(socket_fd);
    return EXIT_SUCCESS;
}