//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void error_handling(char* message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

int create_socket(int port) {
    int sockfd;
    struct sockaddr_in serv_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        error_handling("socket failed");
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        error_handling("bind failed");
    }
    if (listen(sockfd, 5) < 0) {
        error_handling("listen failed");
    }
    return sockfd;
}

void* handle_client(void* arg) {
    int client_socket = *(int*)arg;
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        send(client_socket, buffer, bytes_received, 0);
    }
    close(client_socket);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    int port;
    if (argc!= 2) {
        error_handling("Usage:./proxy <port>");
    }
    port = atoi(argv[1]);
    int server_socket = create_socket(port);
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            error_handling("accept failed");
        }
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void*)&client_socket);
    }
    return 0;
}