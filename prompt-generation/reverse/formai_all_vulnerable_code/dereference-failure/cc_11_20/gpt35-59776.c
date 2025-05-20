//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: detailed
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Usage: ./proxy <port>\n");
        exit(1);
    }
    int port = atoi(argv[1]);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1) {
        printf("Failed to create server socket. Exiting...\n");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(port);

    if(bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Failed to bind to port %d. Exiting...\n", port);
        exit(1);
    }

    if(listen(server_socket, 10) < 0) {
        printf("Failed to listen. Exiting...\n");
        exit(1);
    }

    while(true) {
        int client_socket = accept(server_socket, NULL, NULL);

        char buffer[BUFFER_SIZE] = {0};
        if(recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
            printf("Failed to read request. Exiting...\n");
            exit(1);
        }

        char *first_line = strtok(buffer, "\n");
        char *method = strtok(first_line, " ");
        char *url = strtok(NULL, " ");

        if(url == NULL) {
            printf("Failed to parse url. Exiting...\n");
            exit(1);
        }
        
        bool is_https = false;
        if(strncmp(url, "https:", 6) == 0) {
            is_https = true;
        }

        struct hostent *server = gethostbyname(strtok(url + 2, "/"));
        if(!server) {
            printf("Failed to find remote host. Exiting...\n");
            exit(1);
        }

        int remote_port = is_https ? 443 : 80;

        int remote_socket = socket(AF_INET, SOCK_STREAM, 0);
        if(remote_socket == -1) {
            printf("Failed to create remote socket. Exiting...\n");
            exit(1);
        }

        struct sockaddr_in remote_address;
        remote_address.sin_family = AF_INET;
        memcpy(&remote_address.sin_addr.s_addr, server->h_addr, server->h_length);
        remote_address.sin_port = htons(remote_port);

        if(connect(remote_socket, (struct sockaddr*) &remote_address, sizeof(remote_address)) < 0) {
            printf("Failed to connect to remote server. Exiting...\n");
            exit(1);
        }

        if(send(remote_socket, buffer, strlen(buffer), 0) < 0) {
            printf("Failed to send request to remote server. Exiting...\n");
            exit(1);
        }

        char remote_buffer[BUFFER_SIZE];
        while(recv(remote_socket, remote_buffer, BUFFER_SIZE, 0)) {
            if(send(client_socket, remote_buffer, strlen(remote_buffer), 0) < 0) {
                printf("Failed to send response to client. Exiting...\n");
                exit(1);
            }
        }

        close(remote_socket);
        close(client_socket);
    }
    return 0;
}