//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_NODES 100
#define MAX_EDGES 500

typedef struct {
    int from;
    int to;
    int weight;
} Edge;

typedef struct {
    int nodeCount;
    char** nodeNames;
    int edgeCount;
    Edge* edges;
} Graph;

typedef struct {
    Graph* graph;
    int startNode;
    int endNode;
    int* distances;
} DijkstraArgs;

void* dijkstra(void* args) {
    // Get args
    DijkstraArgs* dijkstraArgs = (DijkstraArgs*) args;
    Graph* graph = dijkstraArgs->graph;
    int startNode = dijkstraArgs->startNode;
    int endNode = dijkstraArgs->endNode;
    int* distances = dijkstraArgs->distances;

    // Initialize distances
    for (int i = 0; i < graph->nodeCount; i++) {
        distances[i] = -1;
    }
    distances[startNode] = 0;

    // Implement Dijkstra's algorithm
    int currentNode = startNode;
    while (currentNode != endNode) {
        // Update distances to neighbors
        for (int i = 0; i < graph->edgeCount; i++) {
            Edge edge = graph->edges[i];
            if (edge.from == currentNode && distances[edge.to] == -1) {
                distances[edge.to] = distances[currentNode] + edge.weight;
            } else if (edge.to == currentNode && distances[edge.from] == -1) {
                distances[edge.from] = distances[currentNode] + edge.weight;
            }
        }

        // Choose next node to visit
        int minDist = -1;
        for (int i = 0; i < graph->nodeCount; i++) {
            if (distances[i] != -1 && (minDist == -1 || distances[i] < minDist)) {
                minDist = distances[i];
                currentNode = i;
            }
        }
        if (minDist == -1) {
            break; // No more reachable nodes
        }
    }

    return NULL;
}

int main() {
    // Parse input file
    FILE* input = fopen("network_topology.txt", "r");
    if (input == NULL) {
        perror("Failed to open file");
        return 1;
    }

    // Initialize graph
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->nodeCount = 0;
    graph->edgeCount = 0;
    graph->nodeNames = (char**) malloc(MAX_NODES * sizeof(char*));
    memset(graph->nodeNames, 0, MAX_NODES * sizeof(char*)); // Set all pointers to NULL
    graph->edges = (Edge*) malloc(MAX_EDGES * sizeof(Edge));

    // Fill in graph data
    char fromName[64], toName[64];
    int weight, from, to;
    while (fscanf(input, "%s %s %d", fromName, toName, &weight) != EOF) {
        // Get or create node indices
        for (from = 0; from < graph->nodeCount; from++) {
            if (strcmp(graph->nodeNames[from], fromName) == 0) {
                break;
            }
        }
        if (from == graph->nodeCount) { // New node
            graph->nodeNames[from] = (char*) malloc(64); // 64 max node name length
            strcpy(graph->nodeNames[from], fromName);
            graph->nodeCount++;
        }

        for (to = 0; to < graph->nodeCount; to++) {
            if (strcmp(graph->nodeNames[to], toName) == 0) {
                break;
            }
        }
        if (to == graph->nodeCount) { // New node
            graph->nodeNames[to] = (char*) malloc(64); // 64 max node name length
            strcpy(graph->nodeNames[to], toName);
            graph->nodeCount++;
        }

        // Add edge to graph
        graph->edges[graph->edgeCount].from = from;
        graph->edges[graph->edgeCount].to = to;
        graph->edges[graph->edgeCount].weight = weight;
        graph->edgeCount++;
    }

    // Close input file
    fclose(input);

    // Set up multi-threaded Dijkstra's algorithm
    int startNode, endNode;
    printf("Enter the starting node name: ");
    scanf("%s", fromName);
    printf("Enter the ending node name: ");
    scanf("%s", toName);
    for (startNode = 0; startNode < graph->nodeCount; startNode++) {
        if (strcmp(graph->nodeNames[startNode], fromName) == 0) {
            break;
        }
    }
    for (endNode = 0; endNode < graph->nodeCount; endNode++) {
        if (strcmp(graph->nodeNames[endNode], toName) == 0) {
            break;
        }
    }

    int* distances = (int*) malloc(graph->nodeCount * sizeof(int)); // Accumulated distances
    pthread_t threads[4]; // Up to 4 threads
    DijkstraArgs args[4];

    for (int i = 0; i < 4; i++) {
        args[i].graph = graph;
        args[i].startNode = startNode + i;
        args[i].endNode = endNode;
        args[i].distances = distances;

        pthread_create(&threads[i], NULL, dijkstra, (void*) &args[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print resulting distances
    printf("Distances:\n");
    for (int i = 0; i < graph->nodeCount; i++) {
        printf("%s: %d\n", graph->nodeNames[i], distances[i]);
    }

    // Free memory
    for (int i = 0; i < graph->nodeCount; i++) {
        free(graph->nodeNames[i]);
    }
    free(graph->nodeNames);
    free(graph->edges);
    free(graph);
    free(distances);

    return 0;
}