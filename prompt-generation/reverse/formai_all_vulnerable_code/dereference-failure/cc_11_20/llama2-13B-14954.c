//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>

#define NODE_COUNT 5
#define PORT 8080

struct node {
    int sock;
    char name[50];
};

int main(void) {
    int i, j, k;
    struct node *nodes;
    socklen_t len = sizeof(struct node);
    int client_sock;

    // Create nodes
    nodes = (struct node *)calloc(NODE_COUNT, sizeof(struct node));
    for (i = 0; i < NODE_COUNT; i++) {
        nodes[i].sock = socket(AF_INET, SOCK_STREAM, 0);
        nodes[i].name[0] = '\0';
        printf("Node %d: %s\n", i, nodes[i].name);
    }

    // Start nodes
    for (i = 0; i < NODE_COUNT; i++) {
        if (nodes[i].sock == 0) {
            perror("Error creating socket");
            exit(1);
        }
        if (bind(nodes[i].sock, (struct sockaddr *)&nodes[i].name, strlen(nodes[i].name)) < 0) {
            perror("Error binding socket");
            exit(1);
        }
        if (listen(nodes[i].sock, 3) < 0) {
            perror("Error listening");
            exit(1);
        }
        printf("Node %d listening on port %d...\n", i, PORT);
    }

    // Create client
    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock == 0) {
        perror("Error creating socket");
        exit(1);
    }
    printf("Client connecting...\n");

    // Connect client to nodes
    for (i = 0; i < NODE_COUNT; i++) {
        if (connect(client_sock, (struct sockaddr *)&nodes[i].name, strlen(nodes[i].name)) < 0) {
            perror("Error connecting to node");
            exit(1);
        }
    }

    // Start client
    printf("Client connected to all nodes...\n");
    for (i = 0; i < NODE_COUNT; i++) {
        recv(client_sock, nodes[i].name, 50, 0);
        printf("Client: %s\n", nodes[i].name);
    }

    // Simulate workload
    for (i = 0; i < 10000; i++) {
        for (j = 0; j < NODE_COUNT; j++) {
            if (rand() % 2 == 0) {
                // Send message to another node
                int random_node = rand() % NODE_COUNT;
                char message[] = "Hello, world!";
                send(nodes[random_node].sock, message, strlen(message), 0);
                printf("Node %d sent message to node %d\n", random_node, j);
            } else {
                // Receive message from another node
                int random_node = rand() % NODE_COUNT;
                char message[50];
                recv(nodes[j].sock, message, 50, 0);
                printf("Node %d received message from node %d: %s\n", j, random_node, message);
            }
        }
    }

    // Clean up
    for (i = 0; i < NODE_COUNT; i++) {
        close(nodes[i].sock);
    }
    close(client_sock);
    free(nodes);

    return 0;
}