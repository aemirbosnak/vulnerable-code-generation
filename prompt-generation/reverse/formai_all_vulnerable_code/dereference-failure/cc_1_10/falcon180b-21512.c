//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

typedef struct node {
    char ip[16];
    int port;
    int status;
    struct node *next;
} node_t;

node_t *head = NULL;

void add_node(char *ip, int port) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    strcpy(new_node->ip, ip);
    new_node->port = port;
    new_node->status = 0;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node_t *curr = head;
        while (curr->next!= NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

void print_nodes() {
    node_t *curr = head;
    while (curr!= NULL) {
        printf("IP: %s, Port: %d, Status: %d\n", curr->ip, curr->port, curr->status);
        curr = curr->next;
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received == 0) {
                printf("Client disconnected\n");
                close(client_socket);
                break;
            }

            char *ip = strtok(buffer, ":");
            int port = atoi(strtok(NULL, ":"));

            add_node(ip, port);
        }
    }

    close(server_socket);
    return 0;
}