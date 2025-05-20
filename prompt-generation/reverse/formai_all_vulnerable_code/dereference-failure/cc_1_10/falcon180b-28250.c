//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
pthread_t thread_ids[MAX_CLIENTS];

void *handle_client(void *socket_desc) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(*((int *) socket_desc), buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d: %s\n", *((int *) socket_desc), buffer);
    }

    close(*((int *) socket_desc));
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    int opt = 1;
    int master_socket;
    struct sockaddr_in server_addr;
    int addrlen = sizeof(server_addr);
    int client_socket;
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    master_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (master_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *) &opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(master_socket, (struct sockaddr *) &server_addr, addrlen) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(master_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server is running on port %d\n", atoi(argv[1]));

    while (1) {
        socklen_t addr_size;
        int new_socket;

        addr_size = sizeof(server_addr);
        new_socket = accept(master_socket, (struct sockaddr *) &server_addr, &addr_size);

        if (new_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        if (pthread_create(&thread_ids[0], NULL, handle_client, (void *) &new_socket)) {
            printf("Error creating thread\n");
            close(new_socket);
            continue;
        }

        for (int i = 1; i < MAX_CLIENTS; i++) {
            if (thread_ids[i] == 0) {
                if (pthread_create(&thread_ids[i], NULL, handle_client, (void *) &new_socket)) {
                    printf("Error creating thread\n");
                    close(new_socket);
                    break;
                }
            }
        }
    }

    return 0;
}