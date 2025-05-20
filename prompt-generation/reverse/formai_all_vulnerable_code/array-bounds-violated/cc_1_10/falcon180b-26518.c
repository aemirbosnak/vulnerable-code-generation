//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<limits.h>
#include<time.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<errno.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define MAX_LINE 1024
#define MAX_CLIENTS 10

int listen_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void broadcast(int sender_socket, char message[]) {
    int i;
    for(i=0;i<num_clients;i++) {
        if(i!= sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}

void handle_client(int client_socket) {
    char message[MAX_LINE];
    while(TRUE) {
        memset(message, 0, MAX_LINE);
        int bytes_received = recv(client_socket, message, MAX_LINE, 0);
        if(bytes_received <= 0) {
            close(client_socket);
            break;
        }
        message[bytes_received-1] = '\0';
        broadcast(client_socket, message);
    }
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if((listen_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    if(bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    if(listen(listen_socket, BACKLOG) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server is listening on port %d\n", PORT);

    while(TRUE) {
        socklen_t addr_size;
        if((client_sockets[num_clients] = accept(listen_socket, (struct sockaddr *)&server_addr, &addr_size)) < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }
        num_clients++;
        if(num_clients == MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            exit(1);
        }
        printf("Client %d connected\n", num_clients-1);
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void *)handle_client, (void *)&client_sockets[num_clients-1]);
    }

    return 0;
}