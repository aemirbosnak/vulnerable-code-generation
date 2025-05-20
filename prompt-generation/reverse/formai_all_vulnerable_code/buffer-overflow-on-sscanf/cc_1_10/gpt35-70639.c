//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void handle_client_request(int client_socket_fd){
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    // read the client request from the socket
    ssize_t num_bytes_rcvd = recv(client_socket_fd, buffer, BUFFER_SIZE, 0);
    if(num_bytes_rcvd < 0){
        perror("recv() failed");
        exit(EXIT_FAILURE);
    }

    // parse the client request to get the requested URL
    char url[BUFFER_SIZE];
    memset(url, 0, BUFFER_SIZE);
    sscanf(buffer, "GET http://%[^/]/", url);

    // connect to the requested server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, url, &(server_addr.sin_addr.s_addr));
    int server_socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(connect(server_socket_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0){
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    // forward the client request to the server
    if(send(server_socket_fd, buffer, num_bytes_rcvd, 0) < 0){
        perror("send() failed");
        exit(EXIT_FAILURE);
    }

    // forward the server response to the client
    while(1){
        char read_buffer[BUFFER_SIZE];
        memset(read_buffer, 0, BUFFER_SIZE);
        ssize_t num_bytes_rcvd = recv(server_socket_fd, read_buffer, BUFFER_SIZE, 0);
        if(num_bytes_rcvd < 0){
            perror("recv() failed");
            exit(EXIT_FAILURE);
        } else if(num_bytes_rcvd == 0){
            break;
        } else {
            if(send(client_socket_fd, read_buffer, num_bytes_rcvd, 0) < 0){
                perror("send() failed");
                exit(EXIT_FAILURE);
            }
        }
    }

    // close the server socket and client socket
    close(server_socket_fd);
    close(client_socket_fd);
}

int main(int argc, char** argv){
    if(argc != 2){
        printf("Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);

    // create a listening socket
    int listen_socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(listen_socket_fd < 0){
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // bind the listening socket to the specified port
    struct sockaddr_in listen_addr;
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(port);
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(listen_socket_fd, (struct sockaddr*) &listen_addr, sizeof(listen_addr)) < 0){
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }

    // start listening for incoming client connections
    if(listen(listen_socket_fd, SOMAXCONN) < 0){
        perror("listen() failed");
        exit(EXIT_FAILURE);
    }

    // handle client requests in a loop
    while(1){
        // accept a new client connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket_fd = accept(listen_socket_fd, (struct sockaddr*) &client_addr, &client_addr_len);
        if(client_socket_fd < 0){
            perror("accept() failed");
            continue;
        }

        // handle the client request
        handle_client_request(client_socket_fd);
    }

    // close the listening socket
    close(listen_socket_fd);

    return 0;
}