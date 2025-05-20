//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// A struct for representing a node in the graph
typedef struct Node {
    int value;
    struct Node** neighbors;
    int num_neighbors;
} Node;

// A function for initializing a Node
Node* init_node(int value, int num_neighbors) {
    Node* node = calloc(1, sizeof(Node));
    node->value = value;
    node->num_neighbors = num_neighbors;
    node->neighbors = calloc(num_neighbors, sizeof(Node*));
    return node;
}

// A function for adding a neighbor to a Node
void add_neighbor(Node* node, Node* neighbor) {
    node->neighbors[node->num_neighbors++] = neighbor;
}

// A function for finding the shortest path between two Nodes
int bfs(Node* start, Node* end) {
    int visited[1000] = {0}; // An array to keep track of visited Nodes
    int distances[1000] = {0}; // An array to keep track of distances from start
    Node* queue[1000];
    int front = 0;
    int rear = 0;
    
    // Add the start Node to the queue and mark it as visited
    queue[rear++] = start;
    visited[start->value] = 1;
    
    // Perform BFS
    while (front < rear) {
        Node* current = queue[front++];
        
        // Check if we have found the end Node
        if (current == end) {
            return distances[current->value];
        }
        
        // Add all unvisited neighbors to the queue
        for (int i = 0; i < current->num_neighbors; i++) {
            Node* neighbor = current->neighbors[i];
            if (!visited[neighbor->value]) {
                visited[neighbor->value] = 1;
                distances[neighbor->value] = distances[current->value] + 1;
                queue[rear++] = neighbor;
            }
        }
    }
    
    // If no path is found, return -1
    return -1;
}

int main() {
    // Create some Nodes and add neighbors to them
    Node* node0 = init_node(0, 3);
    Node* node1 = init_node(1, 2);
    Node* node2 = init_node(2, 2);
    Node* node3 = init_node(3, 3);
    add_neighbor(node0, node1);
    add_neighbor(node0, node2);
    add_neighbor(node0, node3);
    add_neighbor(node1, node0);
    add_neighbor(node1, node2);
    add_neighbor(node2, node0);
    add_neighbor(node2, node1);
    add_neighbor(node3, node0);
    add_neighbor(node3, node2);
    add_neighbor(node3, node1);
    
    // Find the shortest path from node0 to node2
    int distance = bfs(node0, node2);
    printf("The shortest path from node0 to node2 is %d\n", distance);
    
    return 0;
}