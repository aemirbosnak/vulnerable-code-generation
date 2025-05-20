//FormAI DATASET v1.0 Category: Chat server ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 30
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    int server_socket, client_socket, activity, new_socket, max_fd;
    struct sockaddr_in server_address, client_address;

    char buffer[BUFFER_SIZE];
    fd_set read_fds;

    int clients[MAX_CLIENTS], client_count = 0;
    memset(clients, 0, sizeof(clients));

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    listen(server_socket, 5);

    printf("Chat server started on port 8080\n");

    while(true) {

        FD_ZERO(&read_fds);
        FD_SET(server_socket, &read_fds);
        max_fd = server_socket;

        for(int i = 0; i < MAX_CLIENTS; i++) {
            client_socket = clients[i];
            if(client_socket > 0) {
                FD_SET(client_socket, &read_fds);
            }
            if(client_socket > max_fd) {
                max_fd = client_socket;
            }
        }

        activity = select(max_fd + 1, &read_fds, NULL, NULL, NULL);

        if(FD_ISSET(server_socket, &read_fds)) {
            new_socket = accept(server_socket, (struct sockaddr*)&client_address, (socklen_t*)&client_socket);
            printf("New client connected: %s at socket %d\n", inet_ntoa(client_address.sin_addr), new_socket);

            for(int i = 0; i < MAX_CLIENTS; i++) {
                if(clients[i] == 0) {
                    clients[i] = new_socket;
                    client_count++;
                    break;
                }
            }
        }

        for(int i = 0; i < MAX_CLIENTS; i++) {
            client_socket = clients[i];

            if(FD_ISSET(client_socket, &read_fds)) {
                int bytes_read = read(client_socket, buffer, BUFFER_SIZE);

                if(bytes_read == 0) {
                    printf("Client %d disconnected\n", client_socket);
                    close(client_socket);
                    clients[i] = 0;
                    client_count--;
                } else {
                    for(int j = 0; j < MAX_CLIENTS; j++) {
                        if(clients[j] != 0 && clients[j] != client_socket) {
                            write(clients[j], buffer, bytes_read);
                        }
                    }
                }
            }
        }
    }

    return 0;
}