//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: single-threaded
// Single-threaded Network Topology Mapper in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

// Structure to store information about each node in the network
typedef struct node {
    int id;
    char ip_addr[16];
    int port;
    struct node* next;
} node_t;

// Function to create a new node
node_t* new_node(int id, char* ip_addr, int port) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->id = id;
    strcpy(node->ip_addr, ip_addr);
    node->port = port;
    node->next = NULL;
    return node;
}

// Function to add a node to the list of nodes
void add_node(node_t** head, node_t* node) {
    node_t* current = *head;
    if (current == NULL) {
        *head = node;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

// Function to print the list of nodes
void print_nodes(node_t* head) {
    node_t* current = head;
    while (current != NULL) {
        printf("Node %d: %s:%d\n", current->id, current->ip_addr, current->port);
        current = current->next;
    }
}

// Function to send a message to a node
void send_message(node_t* node, char* message) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR: Socket creation failed");
        exit(1);
    }

    // Initialize the server address
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(node->port);
    inet_pton(AF_INET, node->ip_addr, &servaddr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR: Connection failed");
        exit(1);
    }

    // Send the message
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("ERROR: Message sending failed");
        exit(1);
    }

    // Close the socket
    close(sockfd);
}

// Function to receive a message from a node
char* receive_message(node_t* node) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR: Socket creation failed");
        exit(1);
    }

    // Initialize the server address
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(node->port);
    inet_pton(AF_INET, node->ip_addr, &servaddr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR: Connection failed");
        exit(1);
    }

    // Receive the message
    n = recv(sockfd, buffer, 1024, 0);
    if (n < 0) {
        perror("ERROR: Message receiving failed");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    // Return the message
    return buffer;
}

int main(int argc, char* argv[]) {
    // Initialize the list of nodes
    node_t* nodes = NULL;

    // Add nodes to the list
    add_node(&nodes, new_node(1, "192.168.1.1", 8000));
    add_node(&nodes, new_node(2, "192.168.1.2", 8001));
    add_node(&nodes, new_node(3, "192.168.1.3", 8002));
    add_node(&nodes, new_node(4, "192.168.1.4", 8003));

    // Print the list of nodes
    print_nodes(nodes);

    // Send a message to each node
    char* message = "Hello, world!";
    node_t* current = nodes;
    while (current != NULL) {
        send_message(current, message);
        current = current->next;
    }

    // Receive a message from each node
    current = nodes;
    while (current != NULL) {
        char* received_message = receive_message(current);
        printf("Received message from node %d: %s\n", current->id, received_message);
        current = current->next;
    }

    // Free the list of nodes
    current = nodes;
    while (current != NULL) {
        node_t* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}