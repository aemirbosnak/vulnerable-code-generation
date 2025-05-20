//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>

#define BUFFER_SIZE 1024

void serve_client(int client_socket, struct sockaddr_in client_address) {
    // create socket to connect to server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        return;
    }

    // connect to server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);
    if (connect(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Error connecting to server: %s\n", strerror(errno));
        return;
    }

    // read HTTP request from client
    char request[BUFFER_SIZE];
    int bytes_received = recv(client_socket, request, BUFFER_SIZE, 0);
    request[bytes_received] = '\0';

    // extract host name from request
    char* host_start = strstr(request, "Host:") + 6;
    char* host_end = strchr(host_start, '\r');
    int host_length = host_end - host_start;
    char host[host_length+1];
    memcpy(host, host_start, host_length);
    host[host_length] = '\0';

    // create new HTTP request with modified host header
    char new_request[BUFFER_SIZE];
    sprintf(new_request, "%sHost: localhost\r\n", request + (request[4] == 's' ? 8 : 7));

    // send new HTTP request to server
    if (send(server_socket, new_request, strlen(new_request), 0) < 0) {
        printf("Error sending request to server: %s\n", strerror(errno));
        return;
    }

    // read server response and send it back to client
    char response[BUFFER_SIZE];
    while (bytes_received = recv(server_socket, response, BUFFER_SIZE, 0)) {
        if (bytes_received < 0) {
            printf("Error receiving response from server: %s\n", strerror(errno));
            return;
        }
        if (send(client_socket, response, bytes_received, 0) < 0) {
            printf("Error sending response to client: %s\n", strerror(errno));
            return;
        }
    }

    // close sockets
    close(client_socket);
    close(server_socket);

    // print log message
    time_t now = time(NULL);
    char timestamp[20];
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
    printf("[%s] served %s:%d\n", timestamp, inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
}

int main() {
    // create socket to listen for incoming connections
    int listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    // allow socket to be reused immediately after closing
    int reuse = 1;
    if (setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
        printf("Error setting socket options: %s\n", strerror(errno));
        return 1;
    }

    // bind socket to IP address and port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;
    if (bind(listen_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Error binding socket: %s\n", strerror(errno));
        return 1;
    }

    // start listening for incoming connections
    if (listen(listen_socket, 5) < 0) {
        printf("Error listening for incoming connections: %s\n", strerror(errno));
        return 1;
    }

    // serve clients forever
    while (1) {
        // accept incoming connection from client
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(listen_socket, (struct sockaddr*)&client_address, &client_address_len);
        if (client_socket < 0) {
            printf("Error accepting incoming connection: %s\n", strerror(errno));
            continue;
        }

        // fork new process to handle client
        pid_t pid = fork();
        if (pid == 0) { // child process
            serve_client(client_socket, client_address);
            exit(0);
        }
        if (pid < 0) { // error forking
            printf("Error forking new process: %s\n", strerror(errno));
            continue;
        }
        // parent process
        close(client_socket);
    }

    // close listening socket
    close(listen_socket);

    return 0;
}