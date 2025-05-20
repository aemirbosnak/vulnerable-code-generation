//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int num_clients = 0;

void *listen_thread(void *arg) {
    int server_socket = *(int *) arg;

    while(TRUE) {
        int client_socket = accept(server_socket, NULL, NULL);

        if(client_socket == -1) {
            if(errno!= EINTR) {
                perror("Error accepting connection");
            }
            continue;
        }

        int i;
        for(i = 0; i < MAX_CLIENTS; i++) {
            if(clients[i] == -1) {
                clients[i] = client_socket;
                num_clients++;
                break;
            }
        }

        if(i == MAX_CLIENTS) {
            close(client_socket);
            printf("Maximum number of clients reached\n");
        }
    }

    return NULL;
}

void *send_thread(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[BUFFER_SIZE];

    while(TRUE) {
        ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if(bytes_received == -1) {
            if(errno!= EINTR) {
                perror("Error receiving data");
            }
            break;
        } else if(bytes_received == 0) {
            printf("Client %d disconnected\n", client_socket);
            close(client_socket);
            clients[client_socket] = -1;
            num_clients--;
            break;
        }

        send(client_socket, buffer, bytes_received, 0);
    }

    return NULL;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(server_socket == -1) {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket");
        exit(1);
    }

    if(listen(server_socket, 10) == -1) {
        perror("Error listening on socket");
        exit(1);
    }

    printf("Server started on port %d\n", PORT);

    pthread_t listen_thread_id, send_thread_id;
    pthread_create(&listen_thread_id, NULL, &listen_thread, &server_socket);

    while(num_clients < MAX_CLIENTS) {
        pthread_create(&send_thread_id, NULL, &send_thread, &clients[num_clients]);
        num_clients++;
    }

    pthread_join(listen_thread_id, NULL);
    pthread_join(send_thread_id, NULL);

    close(server_socket);
    return 0;
}