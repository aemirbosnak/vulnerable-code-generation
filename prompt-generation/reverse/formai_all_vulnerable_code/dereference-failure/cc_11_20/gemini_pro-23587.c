//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

struct circuit {
    int num_nodes;
    int num_edges;
    int *nodes;
    int **edges;
};

struct message {
    int type;
    int data;
};

int main() {
    int sockfd, newsockfd, valread;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;

    // Create server socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set server socket options
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind server socket to address
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for client connections
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept client connection
    clilen = sizeof(cliaddr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
    if (newsockfd < 0) {
        perror("accept");
        exit(1);
    }

    // Create circuit
    struct circuit circuit;
    circuit.num_nodes = 10;
    circuit.num_edges = 15;
    circuit.nodes = malloc(sizeof(int) * circuit.num_nodes);
    circuit.edges = malloc(sizeof(int *) * circuit.num_nodes);
    for (int i = 0; i < circuit.num_nodes; i++) {
        circuit.nodes[i] = i;
    }
    for (int i = 0; i < circuit.num_nodes; i++) {
        circuit.edges[i] = malloc(sizeof(int) * circuit.num_nodes);
        for (int j = 0; j < circuit.num_nodes; j++) {
            circuit.edges[i][j] = 0;
        }
    }

    // Send circuit to client
    struct message message;
    message.type = 0;
    message.data = circuit.num_nodes;
    send(newsockfd, &message, sizeof(message), 0);

    message.type = 1;
    message.data = circuit.num_edges;
    send(newsockfd, &message, sizeof(message), 0);

    for (int i = 0; i < circuit.num_nodes; i++) {
        message.type = 2;
        message.data = circuit.nodes[i];
        send(newsockfd, &message, sizeof(message), 0);
    }

    for (int i = 0; i < circuit.num_nodes; i++) {
        for (int j = 0; j < circuit.num_nodes; j++) {
            message.type = 3;
            message.data = circuit.edges[i][j];
            send(newsockfd, &message, sizeof(message), 0);
        }
    }

    // Receive simulation results from client
    int result[circuit.num_nodes];
    for (int i = 0; i < circuit.num_nodes; i++) {
        valread = recv(newsockfd, &result[i], sizeof(int), 0);
        if (valread < 0) {
            perror("recv");
            exit(1);
        }
    }

    // Print simulation results
    printf("Simulation results:\n");
    for (int i = 0; i < circuit.num_nodes; i++) {
        printf("Node %d: %d\n", i, result[i]);
    }

    // Clean up
    free(circuit.nodes);
    for (int i = 0; i < circuit.num_nodes; i++) {
        free(circuit.edges[i]);
    }
    free(circuit.edges);
    close(newsockfd);
    close(sockfd);

    return 0;
}