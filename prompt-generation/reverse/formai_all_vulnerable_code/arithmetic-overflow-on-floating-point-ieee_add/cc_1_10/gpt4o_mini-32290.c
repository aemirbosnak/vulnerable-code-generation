//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define NUM_NODES 5 // Total number of nodes
#define MSG_SIZE 256
#define PROBABILITY_THRESHOLD 0.7

// Function to generate random probability
double generate_random_probability() {
    return ((double)rand() / RAND_MAX); // Generates a number between 0.0 and 1.0
}

// Function to start a server node
void start_server(int node_id) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MSG_SIZE] = {0};
    double probability = generate_random_probability();

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT + node_id);

    // Binding socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Node %d is listening on port %d with probability: %f\n", node_id, PORT + node_id, probability);

    // Accepting incoming connections
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) >= 0) {
        send(new_socket, &probability, sizeof(probability), 0);
        close(new_socket);
    }

    if (new_socket < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }
}

// Function to request probabilities from nodes
double request_probabilities() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    double total_probability = 0.0;

    for (int i = 0; i < NUM_NODES; i++) {
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            printf("Socket creation error \n");
            return -1;
        }
        
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(PORT + i);
        
        // Convert IPv4 and IPv6 addresses from text to binary form
        if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
            printf("Invalid address/ Address not supported \n");
            return -1;
        }

        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            printf("Connection to node %d failed \n", i);
            continue; // Skip failed connections
        }

        double probability;
        read(sock, &probability, sizeof(probability));
        total_probability += probability;
        close(sock);
    }

    return total_probability / NUM_NODES; // Average probability
}

// Main function
int main() {
    srand(time(NULL)); // Seed for random probability generation

    if (fork() == 0) { // Running node as a child process
        start_server(0);
        return 0; // Exit child process
    }
    for (int i = 1; i < NUM_NODES; i++) {
        if (fork() == 0) { // Forking child process for each node
            start_server(i);
            return 0;
        }
    }

    sleep(2); // Wait for nodes to initialize 

    double final_probability = request_probabilities();
    printf("Final Alien Invasion Probability: %f\n", final_probability);
    
    if (final_probability > PROBABILITY_THRESHOLD) {
        printf("Warning: High risk of alien invasion!\n");
    } else {
        printf("Low risk of alien invasion.\n");
    }

    // Waiting for child processes
    for (int i = 0; i < NUM_NODES; i++) {
        wait(NULL);
    }

    return 0;
}