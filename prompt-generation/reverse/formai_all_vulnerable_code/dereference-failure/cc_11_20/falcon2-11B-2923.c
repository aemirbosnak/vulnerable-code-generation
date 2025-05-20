//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    int server_fd, new_socket, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFF_SIZE];
    char *method;
    char *url;
    char *version;
    char *query_string;
    char *content_type;
    char *content_length;
    char *http_version;
    int addrlen;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);
    printf("Server starting on port %d...\n", portno);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(1);
    }

    memset((char *) &serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(server_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_fd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *) &cli_addr, (socklen_t*) &addrlen);
        if (new_socket == -1) {
            perror("accept");
            exit(1);
        }

        printf("New connection on port %d from %s\n", ntohs(cli_addr.sin_port), inet_ntoa(cli_addr.sin_addr));

        while (1) {
            bzero(buffer, BUFF_SIZE);
            recv(new_socket, buffer, BUFF_SIZE, 0);
            printf("Received: %s\n", buffer);
            if (strstr(buffer, "GET / HTTP/1.1")!= NULL) {
                method = strstr(buffer, "GET /");
                url = strstr(buffer, " HTTP/1.1");
                version = strstr(buffer, " HTTP/1.1");
                query_string = strstr(buffer, " HTTP/1.1");
                content_type = strstr(buffer, " HTTP/1.1");
                content_length = strstr(buffer, " HTTP/1.1");
                http_version = strstr(buffer, " HTTP/1.1");

                printf("Method: %s\n", method);
                printf("URL: %s\n", url);
                printf("Version: %s\n", version);
                printf("Query string: %s\n", query_string);
                printf("Content type: %s\n", content_type);
                printf("Content length: %s\n", content_length);
                printf("HTTP version: %s\n", http_version);

                if (strcmp(method, "GET / HTTP/1.1") == 0) {
                    printf("Sending 'HTTP/1.1 200 OK\r\n\r\n'...\n");
                    send(new_socket, "HTTP/1.1 200 OK\r\n\r\n", 22, 0);
                    printf("Sending 'Hello, world!'\n");
                    send(new_socket, "Hello, world!", 12, 0);
                } else {
                    printf("Sending 'HTTP/1.1 404 Not Found\r\n\r\n'...\n");
                    send(new_socket, "HTTP/1.1 404 Not Found\r\n\r\n", 29, 0);
                }
            } else if (strstr(buffer, "HEAD / HTTP/1.1")!= NULL) {
                method = strstr(buffer, "HEAD /");
                url = strstr(buffer, " HTTP/1.1");
                version = strstr(buffer, " HTTP/1.1");
                query_string = strstr(buffer, " HTTP/1.1");
                content_type = strstr(buffer, " HTTP/1.1");
                content_length = strstr(buffer, " HTTP/1.1");
                http_version = strstr(buffer, " HTTP/1.1");

                printf("Method: %s\n", method);
                printf("URL: %s\n", url);
                printf("Version: %s\n", version);
                printf("Query string: %s\n", query_string);
                printf("Content type: %s\n", content_type);
                printf("Content length: %s\n", content_length);
                printf("HTTP version: %s\n", http_version);

                if (strcmp(method, "HEAD / HTTP/1.1") == 0) {
                    printf("Sending 'HTTP/1.1 200 OK\r\n\r\n'...\n");
                    send(new_socket, "HTTP/1.1 200 OK\r\n\r\n", 22, 0);
                    printf("Sending 'Hello, world!'\n");
                    send(new_socket, "Hello, world!", 12, 0);
                } else {
                    printf("Sending 'HTTP/1.1 404 Not Found\r\n\r\n'...\n");
                    send(new_socket, "HTTP/1.1 404 Not Found\r\n\r\n", 29, 0);
                }
            } else if (strstr(buffer, "POST / HTTP/1.1")!= NULL) {
                method = strstr(buffer, "POST /");
                url = strstr(buffer, " HTTP/1.1");
                version = strstr(buffer, " HTTP/1.1");
                query_string = strstr(buffer, " HTTP/1.1");
                content_type = strstr(buffer, " HTTP/1.1");
                content_length = strstr(buffer, " HTTP/1.1");
                http_version = strstr(buffer, " HTTP/1.1");

                printf("Method: %s\n", method);
                printf("URL: %s\n", url);
                printf("Version: %s\n", version);
                printf("Query string: %s\n", query_string);
                printf("Content type: %s\n", content_type);
                printf("Content length: %s\n", content_length);
                printf("HTTP version: %s\n", http_version);

                if (strcmp(method, "POST / HTTP/1.1") == 0) {
                    printf("Sending 'HTTP/1.1 200 OK\r\n\r\n'...\n");
                    send(new_socket, "HTTP/1.1 200 OK\r\n\r\n", 22, 0);
                    printf("Sending 'Hello, world!'\n");
                    send(new_socket, "Hello, world!", 12, 0);
                } else {
                    printf("Sending 'HTTP/1.1 404 Not Found\r\n\r\n'...\n");
                    send(new_socket, "HTTP/1.1 404 Not Found\r\n\r\n", 29, 0);
                }
            } else {
                printf("Invalid request...\n");
            }
        }
    }

    return 0;
}