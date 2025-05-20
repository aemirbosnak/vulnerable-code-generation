//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024
#define SERVER_PORT 8080

int main() {
    int server_fd, client_fds[MAX_CLIENTS], max_fd, i, address_length, client_fd, read_val;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_address, client_address;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd < 0){
        perror("Socket creation failed!\n");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(bind(server_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0){
        perror("Socket bind failed!\n");
        exit(EXIT_FAILURE);
    }

    if(listen(server_fd, MAX_CLIENTS) < 0){
        perror("Listen failed!\n");
        exit(EXIT_FAILURE);
    }

    memset(client_fds, 0, sizeof(client_fds));
    max_fd = server_fd;

    printf("Futuristic simple HTTP proxy server started...\n");

    while(1){
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(server_fd, &fds);
        for(i = 0; i < MAX_CLIENTS; i++){
            client_fd = client_fds[i];
            if(client_fd > 0){
                FD_SET(client_fd, &fds);
            }
            if(client_fd > max_fd){
                max_fd = client_fd;
            }
        }

        if(select(max_fd + 1, &fds, NULL, NULL, NULL) < 0){
            perror("Select failed!\n");
            exit(EXIT_FAILURE);
        }

        if(FD_ISSET(server_fd, &fds)){
            address_length = sizeof(client_address);
            client_fd = accept(server_fd, (struct sockaddr *) &client_address, (socklen_t *) &address_length);

            if(client_fd < 0){
                perror("Accept failed!\n");
                exit(EXIT_FAILURE);
            }

            printf("New client connected! IP address: %s, port: %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

            for(i = 0; i < MAX_CLIENTS; i++){
                if(client_fds[i] == 0){
                    client_fds[i] = client_fd;
                    break;
                }
            }
        }

        for(i = 0; i < MAX_CLIENTS; i++){
            client_fd = client_fds[i];
            if(FD_ISSET(client_fd, &fds)){
                read_val = read(client_fd, buffer, BUFFER_SIZE);
                if(read_val < 0){
                    perror("Read failed!\n");
                    exit(EXIT_FAILURE);
                }
                if(read_val == 0){
                    close(client_fd);
                    client_fds[i] = 0;
                    printf("Client disconnected! IP address: %s, port: %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                }
                else{
                    printf("Proxy received data from client: \n%s", buffer);
                }
            }
        }
    }

    return 0;
}