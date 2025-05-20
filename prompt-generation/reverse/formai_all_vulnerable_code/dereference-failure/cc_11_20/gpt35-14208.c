//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[])
{
    if(argc < 3){
        fprintf(stderr, "Usage: %s <port> <destination_ip> <destination_port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);
    char* dst_addr = argv[2];
    int dst_port = atoi(argv[3]);

    int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(server_socket < 0){
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_address = {0};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0){
        fprintf(stderr, "Error binding socket to address\n");
        exit(1);
    }

    if(listen(server_socket, 1) < 0){
        fprintf(stderr, "Error listening on socket\n");
        exit(1);
    }

    printf("Proxy server started on port %d\n", port);

    while(1){
        struct sockaddr_in client_address = {0};
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_length);
        if(client_socket < 0){
            fprintf(stderr, "Error accepting client connection\n");
            exit(1);
        }

        printf("Accepted client connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Creating the destination socket
        int dst_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if(dst_socket < 0){
            fprintf(stderr, "Error creating socket to destination\n");
            close(client_socket);
            continue;
        }

        struct sockaddr_in dst_address = {0};
        dst_address.sin_family = AF_INET;
        dst_address.sin_port = htons(dst_port);
        dst_address.sin_addr.s_addr = inet_addr(dst_addr);

        if(connect(dst_socket, (struct sockaddr*)&dst_address, sizeof(dst_address)) < 0){
            fprintf(stderr, "Error connecting to destination\n");
            close(client_socket);
            close(dst_socket);
            continue;
        }

        printf("Connected to destination %s:%d\n", dst_addr, dst_port);

        // Forwarding data between the client socket and destination socket
        char buf[BUF_SIZE];
        int n = recv(client_socket, buf, BUF_SIZE, 0);
        while(n > 0){
            if(send(dst_socket, buf, n, 0) != n){
                fprintf(stderr, "Error forwarding data to destination\n");
                close(client_socket);
                close(dst_socket);
                exit(1);
            }

            n = recv(client_socket, buf, BUF_SIZE, 0);
        }

        if(n < 0){
            fprintf(stderr, "Error receiving data from client\n");
        }

        close(client_socket);
        close(dst_socket);
    }

    close(server_socket);
    return 0;
}