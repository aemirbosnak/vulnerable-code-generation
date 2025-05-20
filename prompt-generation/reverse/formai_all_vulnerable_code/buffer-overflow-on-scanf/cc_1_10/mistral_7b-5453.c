//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int src, dest, weight;
} Edge;

// Function to find set of an element i
int FindSet(int parent[], int i) {
    if (parent[i] == i)
        return i;

    return parent[i] = FindSet(parent, parent[i]);
}

// Function to union two sets of x and y
void UnionSet(int parent[], int rank[], int x, int y) {
    int s1 = FindSet(parent, x);
    int s2 = FindSet(parent, y);

    if (rank[s1] < rank[s2]) {
        parent[s1] = s2;
    } else if (rank[s1] > rank[s2]) {
        parent[s2] = s1;
    } else {
        parent[s2] = s1;
        rank[s1]++;
    }
}

// Function to implement Kruskal's algorithm
void KruskalMST(Edge edges[], int n) {
    int parent[MAX_VERTICES], rank[MAX_VERTICES];
    int e, i, j = 0;

    for (i = 0; i < MAX_VERTICES; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    Edge result[MAX_VERTICES]; // To store included edges

    // Number of edges to be taken is equal to V-2
    for (e = 0; e < n - 2; e++) {
        int u = FindSet(parent, edges[e].src);
        int v = FindSet(parent, edges[e].dest);

        // If including this edge does not cause cycle, add it to result
        if (u != v) {
            result[j++] = edges[e];
            UnionSet(parent, rank, edges[e].src, edges[e].dest);
        }
    }

    printf("Edge \t Source \t Destination \t Weight\n");
    for (i = 0; i < j; i++) {
        printf("%d \t %d \t %d \t %d\n", i + 1, result[i].src,
               result[i].dest, result[i].weight);
    }
}

int main() {
    int n, i;
    Edge edges[MAX_VERTICES];

    // Number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &i);

    // Add edge details one by one
    printf("Enter edge details (source, destination, weight)\n");
    for (int j = 0; j < i; j++) {
        scanf("%d %d %d", &edges[j].src, &edges[j].dest,
              &edges[j].weight);
    }

    KruskalMST(edges, n);

    return 0;
}