//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 1000
#define INF INT_MAX

int n, e; // number of nodes, edges
int graph[MAX_NODES][MAX_NODES]; // graph represented with adjacency matrix

// A structure to represent the nodes in the graph
typedef struct node {
    int vertex;
    int dist;
    int prev;
    int visited;
} Node;

// A structure to represent the min-heap used in Dijkstra's algorithm
typedef struct min_heap {
    Node** arr;
    int size;
    int capacity;
} MinHeap;

// Create a new node with the given vertex, distance, and prev value
Node* create_node(int vertex, int dist, int prev) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->vertex = vertex;
    node->dist = dist;
    node->prev = prev;
    node->visited = 0; // initialize visited value to false
    return node;
}

// Create a new min-heap with the given capacity
MinHeap* create_min_heap(int capacity) {
    MinHeap* heap = (MinHeap*) malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->arr = (Node**) malloc(capacity * sizeof(Node*));
    return heap;
}

// Swap two nodes in the min-heap
void swap(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

// Min-Heapify a given node in the min-heap
void min_heapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->arr[left]->dist < heap->arr[smallest]->dist) {
        smallest = left;
    }

    if (right < heap->size && heap->arr[right]->dist < heap->arr[smallest]->dist) {
        smallest = right;
    }

    if (smallest != idx) {
        swap(&heap->arr[idx], &heap->arr[smallest]);
        min_heapify(heap, smallest);
    }
}

// Extract the minimum node from the min-heap
Node* extract_min(MinHeap* heap) {
    Node* min_node = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    min_heapify(heap, 0);
    return min_node;
}

// Decrease the distance of a node in the min-heap
void decrease_key(MinHeap* heap, int vertex, int dist, int prev) {
    int i;
    for (i = 0; i < heap->size; i++) {
        if (heap->arr[i]->vertex == vertex) {
            heap->arr[i]->dist = dist;
            heap->arr[i]->prev = prev;
            while (i && heap->arr[i]->dist < heap->arr[(i - 1) / 2]->dist) {
                swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
            break;
        }
    }
}

// Dijkstra's algorithm to find the shortest path from a source node to all other nodes in the graph
void dijkstra(int source) {
    int i;
    MinHeap* heap = create_min_heap(n);

    for (i = 0; i < n; i++) {
        // Initialize all nodes with distance INF, prev -1, and visited false
        heap->arr[i] = create_node(i, INF, -1);
    }

    // Set the source node to distance 0 and prev -1
    decrease_key(heap, source, 0, -1);

    while (heap->size > 0) {
        // Extract the minimum distance node from the heap
        Node* curr_node = extract_min(heap);
        int curr_vertex = curr_node->vertex;

        // Mark the current node as visited
        curr_node->visited = 1;

        // Relax edges from the current node to its neighbors
        for (i = 0; i < n; i++) {
            if (graph[curr_vertex][i] && !heap->arr[i]->visited) {
                int new_dist = curr_node->dist + graph[curr_vertex][i];
                if (new_dist < heap->arr[i]->dist) {
                    decrease_key(heap, i, new_dist, curr_vertex);
                }
            }
        }
    }

    // Print the shortest path from the source to all other nodes
    printf("Shortest Path from Node %d:\n", source);
    for (i = 0; i < n; i++) {
        printf("Node: %d Dist: %d Prev: %d\n", i, heap->arr[i]->dist, heap->arr[i]->prev);
    }
}

int main() {
    int i, j, source;

    // Read in number of nodes and edges
    printf("Enter number of nodes and edges: ");
    scanf("%d%d", &n, &e);

    // Initialize graph with all 0s
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Read in edges and their weights
    for (i = 0; i < e; i++) {
        int from, to, weight;
        printf("Enter an edge and its weight: ");
        scanf("%d%d%d", &from, &to, &weight);
        graph[from][to] = weight;
    }

    // Read in source node
    printf("Enter source node: ");
    scanf("%d", &source);

    // Run Dijkstra's algorithm with the given source node
    dijkstra(source);

    return 0;
}