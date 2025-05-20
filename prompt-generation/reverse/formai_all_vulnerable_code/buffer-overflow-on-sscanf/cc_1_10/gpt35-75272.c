//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: %s <url>\n", argv[0]);
        exit(1);
    }

    char *url = strdup(argv[1]);
    const char *hostname = malloc(strlen(url));
    const char *path = malloc(strlen(url));

    sscanf(url, "http://%[^/]/%s", hostname, path);

    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR: no such host: %s\n", hostname);
        exit(1);
    }

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        fprintf(stderr, "ERROR: could not create socket\n");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(80);

    if (connect(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "ERROR: could not connect to server\n");
        exit(1);
    }

    char request[1000];
    sprintf(request, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, hostname);

    if (write(server_socket, request, strlen(request)) < 0) {
        fprintf(stderr, "ERROR: could not write to socket\n");
        exit(1);
    }

    char response[10000];
    int response_length = 0;
    int bytes_read;

    while ((bytes_read = read(server_socket, response + response_length, 10000 - response_length)) > 0) {
        response_length += bytes_read;
    }

    if (bytes_read < 0) {
        fprintf(stderr, "ERROR: could not read from socket\n");
        exit(1);
    }

    printf("%s", response);

    close(server_socket);

    return 0;
}