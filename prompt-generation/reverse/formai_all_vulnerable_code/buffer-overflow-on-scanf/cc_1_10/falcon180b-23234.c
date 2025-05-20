//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9
#define NIL -1

typedef struct {
    int v;
    int color;
    struct AdjListNode* next;
} AdjListNode;

typedef struct {
    int degree;
    AdjListNode* head;
} AdjList;

AdjList adjList[V];
int color[V];

void addEdge(int v, int w) {
    AdjListNode* newNode = (AdjListNode*) malloc(sizeof(AdjListNode));
    newNode->v = w;
    newNode->color = NIL;
    newNode->next = adjList[v].head;
    adjList[v].head = newNode;
    adjList[w].degree++;
}

void printSolution(int n) {
    printf("Vertex   Color\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", i, color[i]);
    }
}

int dfs(int v, int c) {
    color[v] = c;
    AdjListNode* node = adjList[v].head;
    while (node!= NULL) {
        int w = node->v;
        if (color[w] == NIL) {
            int k = dfs(w, c + 1);
            if (k == 0) {
                return 0;
            }
        } else if (color[w]!= c + 1) {
            return 0;
        }
        node = node->next;
    }
    return 1;
}

int graphColoring(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] == NIL) {
            if (dfs(i, 1) == 0) {
                return 0;
            }
            count++;
        }
    }
    return count;
}

int main() {
    int n, m;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        color[i] = NIL;
    }

    printf("Enter the edges: ");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    int chromaticNumber = graphColoring(n);

    printf("The chromatic number of the given graph is %d\n", chromaticNumber);
    return 0;
}