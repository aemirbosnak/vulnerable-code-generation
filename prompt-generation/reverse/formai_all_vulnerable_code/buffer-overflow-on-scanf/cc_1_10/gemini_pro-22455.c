//GEMINI-pro DATASET v1.0 Category: Networking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

// Structure to represent a node in the decentralized network
typedef struct node {
    int id;
    struct sockaddr_in addr;
    struct node *next;
} node_t;

// Global variables
node_t *head = NULL;
int num_nodes = 0;

// Function to add a node to the decentralized network
void add_node(int id, struct sockaddr_in addr) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->id = id;
    new_node->addr = addr;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        node_t *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    num_nodes++;
}

// Function to remove a node from the decentralized network
void remove_node(int id) {
    if (head == NULL) {
        return;
    }

    if (head->id == id) {
        head = head->next;
    } else {
        node_t *current = head;
        while (current->next != NULL) {
            if (current->next->id == id) {
                current->next = current->next->next;
                break;
            }
            current = current->next;
        }
    }

    num_nodes--;
}

// Function to send a message to all nodes in the decentralized network
void send_message(char *message) {
    if (head == NULL) {
        return;
    }

    node_t *current = head;
    while (current != NULL) {
        int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (sockfd < 0) {
            perror("socket");
            continue;
        }

        if (sendto(sockfd, message, strlen(message), 0, (struct sockaddr *) &current->addr, sizeof(current->addr)) < 0) {
            perror("sendto");
            close(sockfd);
            continue;
        }

        close(sockfd);
        current = current->next;
    }
}

// Function to handle incoming messages from other nodes in the decentralized network
void *handle_messages(void *arg) {
    int sockfd = *(int *) arg;

    while (1) {
        char buffer[1024];
        struct sockaddr_in addr;
        socklen_t addrlen = sizeof(addr);

        int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *) &addr, &addrlen);
        if (n < 0) {
            perror("recvfrom");
            continue;
        }

        buffer[n] = '\0';
        printf("Received message: %s\n", buffer);
    }

    close(sockfd);

    return NULL;
}

// Main function
int main() {
    // Create a UDP socket for sending and receiving messages
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Bind the socket to a random port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = 0;

    if (bind(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("bind");
        close(sockfd);
        return 1;
    }

    // Get the port number assigned to the socket
    socklen_t addrlen = sizeof(addr);
    if (getsockname(sockfd, (struct sockaddr *) &addr, &addrlen) < 0) {
        perror("getsockname");
        close(sockfd);
        return 1;
    }

    // Create a thread to handle incoming messages
    pthread_t thread;
    if (pthread_create(&thread, NULL, handle_messages, &sockfd) != 0) {
        perror("pthread_create");
        close(sockfd);
        return 1;
    }

    // Add the local node to the decentralized network
    add_node(0, addr);

    // Join the decentralized network by sending a message to all nodes
    send_message("Hello, world!");

    // Wait for user input to quit the program
    char input[1024];
    while (strcmp(input, "quit") != 0) {
        printf("Enter a message to send to all nodes (or \"quit\" to exit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") != 0) {
            send_message(input);
        }
    }

    // Remove the local node from the decentralized network
    remove_node(0);

    // Close the socket and exit the program
    close(sockfd);

    return 0;
}