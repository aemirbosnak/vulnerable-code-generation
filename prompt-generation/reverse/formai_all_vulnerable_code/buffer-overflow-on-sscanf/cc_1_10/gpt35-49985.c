//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define BUFSIZE 4096
#define PORT 8080

// Function to handle requests from clients
void *handle_request(void *arg) {
    int client_sockfd = *(int *) arg;
    char buf[BUFSIZE], method[BUFSIZE], path[BUFSIZE], protocol[BUFSIZE];
    char url[BUFSIZE], hostname[BUFSIZE], port_str[BUFSIZE];
    int n, port = 80, server_sockfd;
    struct hostent *he;
    struct sockaddr_in server_address;

    bzero(buf, BUFSIZE);
    n = recv(client_sockfd, buf, BUFSIZE, 0);

    sscanf(buf, "%s %s %s", method, url, protocol);

    if (strcasecmp(method, "CONNECT") == 0) {
        // Handle HTTPS requests by opening a separate SSL connection
        sscanf(url, "%[^:]:%[^:]", hostname, port_str);
        port = atoi(port_str);
    }
    else {
        // Extract the URL path from the request
        sscanf(url, "http://%[^/]/%s", hostname, path);
    }

    // Resolve the hostname to an IP address
    he = gethostbyname(hostname);
    if (he == NULL) {
        printf("Error: Could not resolve hostname \"%s\"\n", hostname);
        pthread_exit(NULL);
    }

    // Create a TCP socket for the server and connect to it
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    memcpy(&server_address.sin_addr, he->h_addr_list[0], he->h_length);

    if (connect(server_sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Error: Could not connect to \"%s\" on port %d\n", hostname, port);
        pthread_exit(NULL);
    }

    // Forward the request to the server
    n = send(server_sockfd, buf, strlen(buf), 0);

    while ((n = recv(server_sockfd, buf, BUFSIZE, 0)) > 0) {
        // Forward the response to the client
        send(client_sockfd, buf, n, 0);
    }

    close(server_sockfd);
    close(client_sockfd);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int sockfd, client_sockfd;
    struct sockaddr_in address, client_address;
    socklen_t client_address_len;
    pthread_t thread;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: Could not create socket\n");
        exit(EXIT_FAILURE);
    }

    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        printf("Error: Could not bind to port %d\n", PORT);
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) < 0) {
        printf("Error: Could not listen on socket\n");
        exit(EXIT_FAILURE);
    }

    printf("Proxy server running on port %d...\n", PORT);

    while (1) {
        client_address_len = sizeof(client_address);
        client_sockfd = accept(sockfd, (struct sockaddr *) &client_address, &client_address_len);

        if (client_sockfd < 0) {
            printf("Error: Could not accept client connection\n");
            continue;
        }

        if (pthread_create(&thread, NULL, handle_request, &client_sockfd) != 0) {
            printf("Error: Could not create thread to handle client request\n");
            continue;
        }
    }

    close(sockfd);

    return 0;
}