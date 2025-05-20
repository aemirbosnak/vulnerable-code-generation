//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_HEADER_SIZE 4096

int main(int argc, char *argv[]) {
    int server_sockfd, client_sockfd, port;
    struct sockaddr_in server_addr, client_addr;
    struct hostent *server_host;
    char header[MAX_HEADER_SIZE], request[MAX_HEADER_SIZE], response[MAX_HEADER_SIZE], buf[MAX_HEADER_SIZE];
    int header_size, request_size, response_size;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    port = atoi(argv[1]);

    // Create socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        perror("socket failed");
        return 1;
    }

    // Set up server address
    server_host = gethostbyname("localhost");
    if (server_host == NULL) {
        perror("gethostbyname failed");
        return 1;
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server_host->h_addr, (char *)&server_addr.sin_addr.s_addr, server_host->h_length);
    server_addr.sin_port = htons(port);

    // Bind socket
    if (bind(server_sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        return 1;
    }

    // Listen
    if (listen(server_sockfd, 5) < 0) {
        perror("listen failed");
        return 1;
    }

    printf("HTTP Proxy Server is listening on port %d...\n", port);

    while (1) {
        // Accept incoming connection
        client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_addr, (socklen_t*) &header_size);
        if (client_sockfd < 0) {
            perror("accept failed");
            return 1;
        }

        printf("New connection from %s\n", inet_ntoa(client_addr.sin_addr));

        // Read HTTP header
        bzero(header, MAX_HEADER_SIZE);
        header_size = read(client_sockfd, header, MAX_HEADER_SIZE);
        if (header_size < 0) {
            perror("read failed");
            return 1;
        }
        printf("Header received: %s\n", header);

        // Parse HTTP header
        char *method = strtok(header, " ");
        char *url = strtok(NULL, " ");
        char *protocol = strtok(NULL, " ");

        // Construct HTTP response header
        header_size = snprintf(response, MAX_HEADER_SIZE, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\n", header_size);
        if (header_size < 0) {
            perror("snprintf failed");
            return 1;
        }

        // Read HTTP request
        bzero(request, MAX_HEADER_SIZE);
        request_size = read(client_sockfd, request, MAX_HEADER_SIZE);
        if (request_size < 0) {
            perror("read failed");
            return 1;
        }
        printf("Request received: %s\n", request);

        // Forward HTTP request to server
        int server_sockfd2 = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sockfd2 < 0) {
            perror("socket failed");
            return 1;
        }

        if (connect(server_sockfd2, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
            perror("connect failed");
            return 1;
        }

        if (write(server_sockfd2, request, request_size) < 0) {
            perror("write failed");
            return 1;
        }

        // Read HTTP response from server
        bzero(buf, MAX_HEADER_SIZE);
        response_size = read(server_sockfd2, buf, MAX_HEADER_SIZE);
        if (response_size < 0) {
            perror("read failed");
            return 1;
        }
        printf("Response received: %s\n", buf);

        // Construct HTTP response body
        bzero(response, MAX_HEADER_SIZE);
        response_size = snprintf(response, MAX_HEADER_SIZE, "%s\n", buf);
        if (response_size < 0) {
            perror("snprintf failed");
            return 1;
        }

        // Send HTTP response to client
        bzero(header, MAX_HEADER_SIZE);
        header_size = snprintf(header, MAX_HEADER_SIZE, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\n", response_size);
        if (header_size < 0) {
            perror("snprintf failed");
            return 1;
        }

        if (write(client_sockfd, header, header_size) < 0) {
            perror("write failed");
            return 1;
        }

        if (write(client_sockfd, response, response_size) < 0) {
            perror("write failed");
            return 1;
        }

        close(server_sockfd2);
    }

    close(server_sockfd);
    return 0;
}