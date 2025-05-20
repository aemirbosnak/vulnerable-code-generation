//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct {
    int vertex;
    struct Edge *next;
} AdjList;

typedef struct {
    int src, dest, weight;
} Edge;

bool isGraphBipartiteUtil(int **adjList, int *visited, int v, int color[]) {
    if (visited[v] != -1) {
        return visited[v] == color[v];
    }

    visited[v] = color[v] = 1;

    for (AdjList *it = adjList[v]; it != NULL; it = it->next) {
        int u = it->vertex;
        if (!isGraphBipartiteUtil(adjList, visited, u, color)) {
            return false;
        }
    }

    return true;
}

bool isGraphBipartite(int numVertices, int **adjList) {
    int *visited = calloc(numVertices, sizeof(int));
    int *color = calloc(numVertices, sizeof(int));

    for (int i = 0; i < numVertices; ++i) {
        if (visited[i] == -1) {
            if (!isGraphBipartiteUtil(adjList, visited, i, color)) {
                free(visited);
                free(color);
                return false;
            }
        }
    }

    free(visited);
    free(color);
    return true;
}

int main(int argc, char const *argv[]) {
    int numVertices, numEdges;

    scanf("%d %d", &numVertices, &numEdges);

    int **adjList = malloc(numVertices * sizeof(int *));
    for (int i = 0; i < numVertices; ++i) {
        adjList[i] = NULL;
    }

    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);

        AdjList *newEdge = (AdjList *) malloc(sizeof(AdjList));
        newEdge->vertex = v;
        newEdge->next = adjList[u];
        adjList[u] = newEdge;

        newEdge = (AdjList *) malloc(sizeof(AdjList));
        newEdge->vertex = u;
        newEdge->next = adjList[v];
        adjList[v] = newEdge;
    }

    if (isGraphBipartite(numVertices, adjList)) {
        printf("Graph is bipartite.\n");
    } else {
        printf("Graph is not bipartite.\n");
    }

    for (int i = 0; i < numVertices; ++i) {
        AdjList *temp = adjList[i];
        while (temp != NULL) {
            free(temp);
            temp = temp->next;
        }
        free(adjList[i]);
    }

    free(adjList);

    return 0;
}