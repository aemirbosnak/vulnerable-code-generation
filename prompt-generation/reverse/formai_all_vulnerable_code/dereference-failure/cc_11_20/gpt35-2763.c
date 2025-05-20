//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: configurable
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int opt=1, received_bytes, sent_bytes;
    int proxy_port, server_port, client_socket, proxy_socket, server_socket;
    struct sockaddr_in client_address, proxy_address, server_address;
    struct addrinfo hints, *res;
    char buffer[BUFFER_SIZE], client_address_string[INET_ADDRSTRLEN], *server_host;
    socklen_t address_length = sizeof(proxy_address);

    //Parse input arguments
    if(argc != 4) {
        printf("Usage: ./proxy <proxy_port> <server_host> <server_port>\n");
        exit(1);
    }
    proxy_port = atoi(argv[1]);
    server_host = argv[2];
    server_port = atoi(argv[3]);

    //Prepare socket structure for proxy
    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(proxy_socket < 0) {
        perror("Unable to open proxy socket");
        exit(1);
    }
    memset(&proxy_address, 0, sizeof(proxy_address));
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_addr.s_addr = INADDR_ANY;
    proxy_address.sin_port = htons(proxy_port);

    //Allow reuse of proxy port
    if(setsockopt(proxy_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Unable to set socket options");
        exit(1);
    }

    //Bind proxy socket to address and port
    if(bind(proxy_socket, (struct sockaddr *)&proxy_address, sizeof(proxy_address)) < 0) {
        close(proxy_socket);
        perror("Unable to bind proxy socket");
        exit(1);
    }

    //Listen for incoming connections
    if(listen(proxy_socket, 10) < 0) {
        close(proxy_socket);
        perror("Unable to start listening on proxy socket");
        exit(1);
    }

    printf("Proxy server listening at %s:%d\n", inet_ntoa(proxy_address.sin_addr), proxy_port);

    //Wait for incoming client connections
    while(1) {
        //Accept incoming client connection
        if((client_socket = accept(proxy_socket, (struct sockaddr *)&client_address, &address_length)) < 0) {
            perror("Unable to accept incoming client connection");
            continue;
        }

        //Convert client address to string for logging
        inet_ntop(AF_INET, &(client_address.sin_addr), client_address_string, INET_ADDRSTRLEN);
        printf("Received incoming connection from %s:%d\n", client_address_string, ntohs(client_address.sin_port));

        //Lookup server address
        memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;

        if(getaddrinfo(server_host, NULL, &hints, &res) != 0) {
            close(client_socket);
            perror("Unable to get address info for server");
            continue;
        }
        memcpy(&server_address, res->ai_addr, res->ai_addrlen);
        server_address.sin_port = htons(server_port);

        //Connect to server
        server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if(server_socket < 0) {
            close(client_socket);
            perror("Unable to create server socket");
            continue;
        }
        if(connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
            close(server_socket);
            close(client_socket);
            perror("Unable to connect to server");
            continue;
        }

        //Pass data between client and server
        while(1) {
            //Read data from client
            received_bytes = read(client_socket, buffer, BUFFER_SIZE);
            if(received_bytes <= 0) {
                break;
            }

            //Send data to server
            sent_bytes = write(server_socket, buffer, received_bytes);
            if(sent_bytes != received_bytes) {
                break;
            }

            //Read data from server
            received_bytes = read(server_socket, buffer, BUFFER_SIZE);
            if(received_bytes <= 0) {
                break;
            }

            //Send data to client
            sent_bytes = write(client_socket, buffer, received_bytes);
            if(sent_bytes != received_bytes) {
                break;
            }
        }

        //Close client and server sockets
        close(client_socket);
        close(server_socket);
    }

    //Close proxy socket and exit
    close(proxy_socket);
    return 0;
}