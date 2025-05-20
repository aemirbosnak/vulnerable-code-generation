//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: shape shifting
#include <stdio.h>
#include <string.h>

// Function prototypes
int get_num_vertices();
void get_connections(int n, int edges[n][2]);
void display_topology(int n, int edges[n][2]);

int main() {
    int num_vertices = get_num_vertices();
    int edges[num_vertices][2];
    
    get_connections(num_vertices, edges);
    
    printf("The network topology is:\n");
    display_topology(num_vertices, edges);
    
    return 0;
}

// Function to get the number of vertices in the network
int get_num_vertices() {
    int num_vertices;
    printf("Enter the number of vertices in the network: ");
    scanf("%d", &num_vertices);
    return num_vertices;
}

// Function to get the connections between the vertices
void get_connections(int n, int edges[n][2]) {
    for (int i = 0; i < n; i++) {
        printf("Enter the connections for vertex %d (comma separated): ", i+1);
        scanf("%d,%d", &edges[i][0], &edges[i][1]);
    }
}

// Function to display the network topology
void display_topology(int n, int edges[n][2]) {
    for (int i = 0; i < n; i++) {
        printf("Vertex %d is connected to vertices ", i+1);
        for (int j = 0; j < n; j++) {
            if (edges[j][0] == i+1) {
                printf("%d, ", edges[j][1]);
            }
            else if (edges[j][1] == i+1) {
                printf("%d, ", edges[j][0]);
            }
        }
        printf("\n");
    }
}