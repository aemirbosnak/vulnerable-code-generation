//Falcon-180B DATASET v1.0 Category: Game of Life ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <math.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define ROWS 20
#define COLS 50
#define MAX_NEIGHBOURS 8
#define ALIVE 1
#define DEAD 0
#define BORDER 0

int create_socket(int port) {
    int sockfd;
    int opt = 1;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void *handle_client(void *arg) {
    int sockfd = *(int *)arg;
    char buffer[1024];
    int n;

    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0';
        printf("Client %d: %s\n", sockfd, buffer);
    }

    close(sockfd);
    pthread_exit(0);
}

int main() {
    int server_socket;
    int client_socket;
    struct sockaddr_in client_addr;
    socklen_t addr_size;
    pthread_t thread_id;

    server_socket = create_socket(PORT);

    while (1) {
        addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);

        if (client_socket == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New client connected on socket %d\n", client_socket);

        pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket);
    }

    return 0;
}