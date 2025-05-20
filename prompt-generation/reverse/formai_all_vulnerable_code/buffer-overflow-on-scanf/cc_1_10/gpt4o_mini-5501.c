//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define NODE_COUNT 5

typedef struct {
    int id;
    int value;
} Node;

// Function prototypes
void* node_thread(void* arg);
void print_menu(int node_id);
void perform_bitwise(int node_id, Node* nodes);

Node nodes[NODE_COUNT];

// Main function
int main() {
    pthread_t threads[NODE_COUNT];
    
    // Initialize nodes with random values
    for (int i = 0; i < NODE_COUNT; i++) {
        nodes[i].id = i;
        nodes[i].value = rand() % 256;  // Random value between 0-255
        printf("Node %d initialized with value: %d\n", nodes[i].id, nodes[i].value);
    }

    // Create threads for each node
    for (int i = 0; i < NODE_COUNT; i++) {
        if (pthread_create(&threads[i], NULL, node_thread, (void*)&nodes[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < NODE_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

// Function to simulate a node's behavior
void* node_thread(void* arg) {
    Node* node = (Node*)arg;
    while (1) {
        print_menu(node->id);
        sleep(2);  // Pause for user interaction
    }
    return NULL;
}

// Function to print the menu for bitwise operations
void print_menu(int node_id) {
    printf("\nNode %d Menu:\n", node_id);
    printf("1. Bitwise AND with another node\n");
    printf("2. Bitwise OR with another node\n");
    printf("3. Bitwise XOR with another node\n");
    printf("4. Bitwise NOT (self)\n");
    printf("0. Exit\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 0) {
        printf("Exiting Node %d...\n", node_id);
        pthread_exit(NULL);
    }

    int target_node_id;
    if (choice >= 1 && choice <= 3) {
        printf("Enter target node ID (0 to %d): ", NODE_COUNT - 1);
        scanf("%d", &target_node_id);
        if (target_node_id < 0 || target_node_id >= NODE_COUNT || target_node_id == node_id) {
            printf("Invalid node ID!\n");
            return;
        }
    }

    switch (choice) {
        case 1:
            printf("Node %d AND Node %d: %d & %d = %d\n", 
                   node_id, target_node_id, 
                   nodes[node_id].value, nodes[target_node_id].value, 
                   (nodes[node_id].value & nodes[target_node_id].value));
            break;
        case 2:
            printf("Node %d OR Node %d: %d | %d = %d\n", 
                   node_id, target_node_id, 
                   nodes[node_id].value, nodes[target_node_id].value, 
                   (nodes[node_id].value | nodes[target_node_id].value));
            break;
        case 3:
            printf("Node %d XOR Node %d: %d ^ %d = %d\n", 
                   node_id, target_node_id, 
                   nodes[node_id].value, nodes[target_node_id].value, 
                   (nodes[node_id].value ^ nodes[target_node_id].value));
            break;
        case 4:
            printf("Node %d NOT: ~%d = %d\n", 
                   node_id, nodes[node_id].value, 
                   ~nodes[node_id].value & 0xFF); // Mask to 8 bits
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}