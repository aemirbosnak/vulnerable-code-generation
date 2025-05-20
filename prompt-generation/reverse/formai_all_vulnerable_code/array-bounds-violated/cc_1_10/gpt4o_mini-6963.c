//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_socket(const char *hostname, int port) {
    struct hostent *server;
    struct sockaddr_in server_addr;
    int sock;

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR: No such host\n");
        return -1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("ERROR opening socket");
    }

    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    server_addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    return sock;
}

void send_http_request(int socket, const char *hostname) {
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET / HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", hostname);
    
    if (send(socket, request, strlen(request), 0) < 0) {
        error("ERROR sending request");
    }
}

void receive_http_response(int socket) {
    char response[BUFFER_SIZE];
    int bytes_received;

    printf("HTTP Response:\n");
    while ((bytes_received = recv(socket, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // null-terminate the response
        fputs(response, stdout);
    }

    if (bytes_received < 0) {
        error("ERROR receiving response");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);
    int sock;

    sock = create_socket(hostname, port);
    if (sock < 0) {
        exit(EXIT_FAILURE);
    }

    send_http_request(sock, hostname);
    receive_http_response(sock);

    close(sock);
    return 0;
}