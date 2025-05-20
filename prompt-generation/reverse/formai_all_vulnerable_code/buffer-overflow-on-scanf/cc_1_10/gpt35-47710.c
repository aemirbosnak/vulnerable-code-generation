//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: decentralized
/*
* Decentralized TCP/IP Programming Example
* This program demonstrates a decentralized style of TCP/IP programming using sockets in C.
* It creates a network of nodes where each node can connect to other nodes without a central server.
* By: [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_NODES 10
#define MAX_BUFFER_SIZE 1024

typedef struct {
    char ip[16];
    int port;
} Node;

Node nodes[MAX_NODES];
int num_nodes = 0;
int node_socket[MAX_NODES];
pthread_t thread_id[MAX_NODES];

void *server_thread(void *arg) {
    int node_id = *(int*)arg;

    char buffer[MAX_BUFFER_SIZE];
    int length;

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        length = recv(node_socket[node_id], buffer, MAX_BUFFER_SIZE, 0);

        if (length > 0) {
            printf("Node %d received message: %s", node_id, buffer);

            for (int i = 0; i < num_nodes; i++) {
                if (i != node_id && node_socket[i] > 0) {
                    send(node_socket[i], buffer, strlen(buffer), 0);
                }
            }
        } else {
            printf("Node %d disconnected.\n", node_id);

            close(node_socket[node_id]);
            pthread_exit(NULL);
        }
    }
}

void *client_thread(void *arg) {
    int node_id = *(int*)arg;
    int node_socket_fd;
    struct sockaddr_in node_addr;

    while (1) {
        node_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        memset(&node_addr, 0, sizeof(node_addr));
        node_addr.sin_family = AF_INET;
        node_addr.sin_port = htons(nodes[node_id].port);
        if (inet_pton(AF_INET, nodes[node_id].ip, &node_addr.sin_addr) <= 0) {
            printf("Invalid IP address.\n");
            sleep(5);
            continue;
        }

        if (connect(node_socket_fd, (struct sockaddr*)&node_addr, sizeof(node_addr)) < 0) {
            printf("Connection failed.\n");
            sleep(5);
            continue;
        }

        printf("Node %d connected.\n", node_id);
        node_socket[node_id] = node_socket_fd;
        pthread_create(&thread_id[node_id], NULL, server_thread, (void*)&node_id);
        pthread_detach(thread_id[node_id]);

        break;
    }

    pthread_exit(NULL);
}

int main() {
    char input_ip[16];
    int input_port;

    printf("Enter IP and Port for this node (separated by a space): ");
    scanf("%s %d", input_ip, &input_port);

    Node self;
    strcpy(self.ip, input_ip);
    self.port = input_port;
    nodes[num_nodes++] = self;

    printf("Enter IP and Port for other nodes (enter -1 to finish):\n");

    while (num_nodes < MAX_NODES) {
        scanf("%s %d", input_ip, &input_port);

        if (strcmp(input_ip, "-1") == 0) {
            break;
        }

        Node node;
        strcpy(node.ip, input_ip);
        node.port = input_port;
        nodes[num_nodes++] = node;
    }

    for (int i = 1; i < num_nodes; i++) {
        pthread_create(&thread_id[i], NULL, client_thread, (void*)&i);
        sleep(1); // to avoid all clients trying to connect at same time
    }

    pthread_create(&thread_id[0], NULL, server_thread, (void*)&num_nodes);

    pthread_join(thread_id[0], NULL);

    return 0;
}