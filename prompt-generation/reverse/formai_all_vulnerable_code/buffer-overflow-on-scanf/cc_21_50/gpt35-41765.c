//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program maps a network topology using a retro-style interface

int main() {
    // Initialize variables
    char response[10];
    int num_nodes = 0;
    int **connections;
    int **distance;
    
    // Get user input for number of nodes in network
    printf("Welcome to the Network Topology Mapper.\n");
    printf("How many nodes are in your network?\n");
    scanf("%d", &num_nodes);
    
    // Dynamically allocate memory for connection and distance matrices
    // Connection matrix will have values of 0 for no connection, 1 for connection
    // Distance matrix will have values of -1 for no connection, and actual distance for connection
    connections = (int **) malloc(num_nodes * sizeof(int *));
    distance = (int **) malloc(num_nodes * sizeof(int *));
    for (int i = 0; i < num_nodes; i++) {
        connections[i] = (int *) calloc(num_nodes, sizeof(int));
        distance[i] = (int *) calloc(num_nodes, sizeof(int));
        for (int j = 0; j < num_nodes; j++) {
            connections[i][j] = 0;
            distance[i][j] = -1;
        }
    }
    
    // Get user input for connections and distances between nodes
    for (int i = 0; i < num_nodes; i++) {
        for (int j = i+1; j < num_nodes; j++) {
            printf("Is there a connection between node %d and node %d?\n", i+1, j+1);
            scanf("%s", response);
            if (strcmp(response, "yes") == 0 || strcmp(response, "Yes") == 0) {
                connections[i][j] = 1;
                connections[j][i] = 1;
                printf("What is the distance (in miles) between node %d and node %d?\n", i+1, j+1);
                scanf("%d", &distance[i][j]);
                distance[j][i] = distance[i][j];
            }
        }
    }
    
    // Print out network topology
    printf("\n\n");
    printf("NETWORK TOPOLOGY:\n");
    printf("\t");
    for (int i = 0; i < num_nodes; i++) {
        printf("node %d\t", i+1);
    }
    printf("\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("node %d\t", i+1);
        for (int j = 0; j < num_nodes; j++) {
            printf("%d\t", connections[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    
    // Print out shortest path between two nodes
    int start_node, end_node;
    printf("Would you like to find the shortest path between two nodes?\n");
    scanf("%s", response);
    if (strcmp(response, "yes") == 0 || strcmp(response, "Yes") == 0) {
        printf("What is the starting node?\n");
        scanf("%d", &start_node);
        printf("What is the ending node?\n");
        scanf("%d", &end_node);
        
        // Dijkstra's algorithm for finding shortest path
        int visited[num_nodes];
        int dist[num_nodes];
        int prev[num_nodes];
        for (int i = 0; i < num_nodes; i++) {
            visited[i] = 0;
            dist[i] = -1;
            prev[i] = -1;
        }
        dist[start_node-1] = 0;
        
        while (1) {
            int min_dist = -1;
            int min_node = -1;
            for (int i = 0; i < num_nodes; i++) {
                if (!visited[i] && dist[i] != -1 && (min_dist == -1 || dist[i] < min_dist)) {
                    min_dist = dist[i];
                    min_node = i;
                }
            }
            if (min_node == -1) {
                break;
            }
            visited[min_node] = 1;
            for (int i = 0; i < num_nodes; i++) {
                if (connections[min_node][i] && (dist[i] == -1 || dist[i] > dist[min_node] + distance[min_node][i])) {
                    dist[i] = dist[min_node] + distance[min_node][i];
                    prev[i] = min_node;
                }
            }
        }
        
        if (dist[end_node-1] == -1) {
            printf("There is no path between node %d and node %d.\n", start_node, end_node);
        } else {
            printf("The shortest path between node %d and node %d is:", start_node, end_node);
            int path[num_nodes];
            int path_index = 0;
            int curr_node = end_node-1;
            while (curr_node != start_node-1) {
                path[path_index++] = curr_node;
                curr_node = prev[curr_node];
            }
            path[path_index++] = start_node-1;
            for (int i = path_index-1; i >= 0; i--) {
                printf(" %d", path[i]+1);
                if (i != 0) {
                    printf(" ->");
                }
            }
            printf("\n");
        }
    }
    
    // Free dynamically allocated memory
    for (int i = 0; i < num_nodes; i++) {
        free(connections[i]);
        free(distance[i]);
    }
    free(connections);
    free(distance);
    
    printf("Thank you for using the Network Topology Mapper!\n");
    
    return 0;
}