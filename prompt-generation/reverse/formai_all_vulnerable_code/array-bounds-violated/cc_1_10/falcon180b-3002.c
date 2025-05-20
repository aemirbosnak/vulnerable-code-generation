//Falcon-180B DATASET v1.0 Category: Firewall ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024

int connections[MAX_CONNECTIONS];
int num_connections = 0;

void *handle_connection(void *arg) {
    int sock = *(int *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer);
    }

    close(sock);
    return NULL;
}

int main() {
    int server_sock;
    struct sockaddr_in server_addr;
    int opt = 1;
    int addrlen = sizeof(struct sockaddr_in);

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(struct sockaddr_in)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, MAX_CONNECTIONS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 8080\n");

    while (1) {
        int client_sock;
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(struct sockaddr_in);

        if ((client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_len)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        if (num_connections == MAX_CONNECTIONS) {
            printf("Maximum number of connections reached\n");
            close(client_sock);
            continue;
        }

        connections[num_connections++] = client_sock;
        pthread_t thread_id;

        if (pthread_create(&thread_id, NULL, handle_connection, (void *) &client_sock)!= 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}