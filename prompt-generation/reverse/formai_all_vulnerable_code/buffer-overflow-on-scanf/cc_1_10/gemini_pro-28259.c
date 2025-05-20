//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <poll.h>

#define SERVER_PORT 8080
#define CLIENT_PORT 9090

// Client thread
void *client_thread(void *arg) {
    int sockfd = *(int *)arg;
    char buffer[1024];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        printf("Enter message: ");
        scanf("%s", buffer);
        if (strcmp(buffer, "quit") == 0) {
            break;
        }
        send(sockfd, buffer, strlen(buffer), 0);
    }
    close(sockfd);
    return NULL;
}

// Server thread
void *server_thread(void *arg) {
    int sockfd = *(int *)arg;
    char buffer[1024];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("Message received from client: %s\n", buffer);
    }
    close(sockfd);
    return NULL;
}

int main() {
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;

    // Initialize socket addresses
    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(CLIENT_PORT);
    client_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Create sockets
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        perror("Error creating server socket");
        return -1;
    }
    client_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sockfd < 0) {
        perror("Error creating client socket");
        close(server_sockfd);
        return -1;
    }

    // Bind server socket
    if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding server socket");
        close(server_sockfd);
        close(client_sockfd);
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_sockfd, 5) < 0) {
        perror("Error listening for incoming connections");
        close(server_sockfd);
        close(client_sockfd);
        return -1;
    }

    // Accept incoming connection
    int client_addr_len = sizeof(client_addr);
    int client_sockfd_accepted = accept(server_sockfd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr_len);
    if (client_sockfd_accepted < 0) {
        perror("Error accepting incoming connection");
        close(server_sockfd);
        close(client_sockfd);
        return -1;
    }

    // Create threads
    pthread_t client_thread_id;
    pthread_create(&client_thread_id, NULL, client_thread, &client_sockfd_accepted);

    pthread_t server_thread_id;
    pthread_create(&server_thread_id, NULL, server_thread, &client_sockfd_accepted);

    // Join threads
    pthread_join(client_thread_id, NULL);
    pthread_join(server_thread_id, NULL);

    // Close sockets
    close(server_sockfd);
    close(client_sockfd);

    return 0;
}