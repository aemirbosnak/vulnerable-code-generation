//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define PORT 8080
#define MAX_CLIENTS 10

struct client {
    int sockfd;
    char name[100];
    int x, y;
};

struct client clients[MAX_CLIENTS];
int num_clients = 0;

void broadcast(char *msg) {
    for (int i = 0; i < num_clients; i++) {
        send(clients[i].sockfd, msg, strlen(msg), 0);
    }
}

void handle_client(int sockfd) {
    char buffer[1024];
    int n;

    // Receive the client's name
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n <= 0) {
        perror("recv");
        return;
    }
    buffer[n - 1] = '\0';
    strcpy(clients[num_clients].name, buffer);

    // Send the client its initial position
    sprintf(buffer, "%d %d", clients[num_clients].x, clients[num_clients].y);
    send(sockfd, buffer, strlen(buffer), 0);

    // Broadcast the new client's arrival
    sprintf(buffer, "%s joined the game", clients[num_clients].name);
    broadcast(buffer);

    // Main loop: receive commands from the client and update its position
    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n - 1] = '\0';
        if (strcmp(buffer, "up") == 0) {
            clients[num_clients].y--;
        } else if (strcmp(buffer, "down") == 0) {
            clients[num_clients].y++;
        } else if (strcmp(buffer, "left") == 0) {
            clients[num_clients].x--;
        } else if (strcmp(buffer, "right") == 0) {
            clients[num_clients].x++;
        }

        // Broadcast the client's new position
        sprintf(buffer, "%s %d %d", clients[num_clients].name, clients[num_clients].x, clients[num_clients].y);
        broadcast(buffer);
    }

    // Client disconnected
    sprintf(buffer, "%s left the game", clients[num_clients].name);
    broadcast(buffer);

    close(sockfd);
    num_clients--;
}

int main() {
    int sockfd, newsockfd, opt = 1;
    struct sockaddr_in serv_addr, cli_addr;
    int addrlen = sizeof(cli_addr);

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket");
        return -1;
    }

    // Set the socket options
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        return -1;
    }

    // Bind the socket to the port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        return -1;
    }

    // Start listening for connections
    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        return -1;
    }

    // Main loop: accept new connections and handle clients
    while (1) {
        if ((newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen)) < 0) {
            perror("accept");
            continue;
        }

        // Add the new client to the list of clients
        clients[num_clients].sockfd = newsockfd;
        clients[num_clients].x = 0;
        clients[num_clients].y = 0;
        num_clients++;

        // Create a thread to handle the client
        pthread_t thread;
        pthread_create(&thread, NULL, (void *)handle_client, (void *)newsockfd);
    }

    return 0;
}