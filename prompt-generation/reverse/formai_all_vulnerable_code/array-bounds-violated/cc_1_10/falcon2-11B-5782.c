//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

int server_socket(int port) {
    int sockfd;
    struct sockaddr_in server_address;
    int addrlen = sizeof(server_address);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void *client_thread(void *arg) {
    int sockfd;
    struct sockaddr_in client_address;
    int addrlen = sizeof(client_address);

    sockfd = *(int*)arg;

    while (1) {
        if ((sockfd = accept(sockfd, (struct sockaddr*)&client_address, &addrlen)) == -1) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));

        int num_bytes_read = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
        buffer[num_bytes_read] = '\0';

        printf("Received message: %s\n", buffer);

        char *message = "Hello, client!";
        int num_bytes_sent = send(sockfd, message, strlen(message), 0);
        printf("Sent message: %s\n", message);

        close(sockfd);
    }

    return NULL;
}

int main() {
    int server_socket_fd = server_socket(12345);

    pthread_t client_thread_id;

    int client_socket_fd;

    pthread_create(&client_thread_id, NULL, client_thread, &server_socket_fd);

    while (1) {
        if ((client_socket_fd = accept(server_socket_fd, NULL, NULL)) == -1) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        break;
    }

    pthread_join(client_thread_id, NULL);

    close(server_socket_fd);
    close(client_socket_fd);

    return 0;
}