//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct {
    int nodeNumber;
    int distance;
} Neighbour;

typedef struct {
    int nodeNumber;
    Neighbour neighbours[MAX_NODES];
    int numNeighbours;
} Node;

int main() {
    Node network[MAX_NODES];
    int numNodes, sourceNode;

    printf("Welcome to the Network Topology Mapper!\n\n");

    // Get the number of nodes in the network
    printf("How many nodes are in the network? (maximum of %d)\n", MAX_NODES);
    scanf("%d", &numNodes);

    // Initialize all nodes in the network
    for (int i = 0; i < numNodes; i++) {
        network[i].nodeNumber = i;
        network[i].numNeighbours = 0;
    }

    // Get the number of neighbours for each node
    for (int i = 0; i < numNodes; i++) {
        int numNeighbours;
        printf("How many neighbours does node %d have?\n", i);
        scanf("%d", &numNeighbours);

        // Get the neighbours for this node
        for (int j = 0; j < numNeighbours; j++) {
            int neighbourNumber, distance;
            printf("Enter neighbour %d and the distance to neighbour %d from node %d: ", j+1, j+1, i);
            scanf("%d %d", &neighbourNumber, &distance);

            // Add the neighbour to the current node's list of neighbours
            network[i].neighbours[j].nodeNumber = neighbourNumber;
            network[i].neighbours[j].distance = distance;
            network[i].numNeighbours++;
        }
    }

    // Get the source node for the network map
    printf("Which node do you want to use as the starting point for the network map?\n");
    scanf("%d", &sourceNode);

    printf("The network map for node %d is:\n", sourceNode);

    // Print the network map for the source node
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d | Distance: ", i);
        if (i == sourceNode) {
            printf("0 | Path: %d\n", i);
        } else {
            int dist = -1;
            int path[MAX_NODES] = {0};
            int pathIdx = 0;
            int visited[MAX_NODES] = {0};

            // Initialize all nodes to be unvisited
            for (int j = 0; j < numNodes; j++) {
                visited[j] = 0;
            }

            // Initialize the starting node's distance and path
            dist = network[sourceNode].neighbours[i].distance;
            path[pathIdx++] = sourceNode;
            path[pathIdx++] = i;
            visited[sourceNode] = 1;

            // Traverse the network to find the shortest path and distance
            while (pathIdx > 0) {
                int curNode = path[--pathIdx];
                Neighbour *neighbours = network[curNode].neighbours;
                int numNeighbours = network[curNode].numNeighbours;

                // Check all unvisited neighbours of the current node
                for (int j = 0; j < numNeighbours; j++) {
                    Neighbour *neighbour = &neighbours[j];
                    int neighbourNumber = neighbour->nodeNumber;
                    int neighbourDist = neighbour->distance;

                    if (!visited[neighbourNumber]) {
                        int newDist = dist + neighbourDist;
                        if (newDist < dist || dist == -1) {
                            dist = newDist;
                            path[pathIdx++] = curNode;
                            path[pathIdx++] = neighbourNumber;
                        }
                    }
                }
                visited[curNode] = 1;
            }

            // Print the shortest distance and path to the current node
            printf("%d | Path: ", dist);
            for (int j = 0; j < pathIdx; j++) {
                printf("%d -> ", path[j]);
            }
            printf("%d\n", i);
        }
    }

    printf("\nThanks for using the Network Topology Mapper!\n");

    return 0;
}