//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_NODES 10 // Maximum nodes in the graph
#define MAX_COLORS 4 // Maximum number of colors

struct Node {
    int data;
    int color;
    struct Node* next;
};

void addEdge(struct Node* graph[MAX_NODES], int u, int v);
int getRandomColor(int available_colors[MAX_COLORS], int degree);
void colorGraph(struct Node* graph[MAX_NODES], int color[MAX_NODES], int nodes);

int main() {
    srand(time(NULL));

    struct Node* graph[MAX_NODES];
    int color[MAX_NODES] = {0};
    int nodes, edges, u, v;

    printf("Enter the number of nodes in the graph (maximum %d): ", MAX_NODES);
    scanf("%d", &nodes);

    for(int i=0; i<nodes; i++) {
        graph[i] = NULL;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

   printf("Enter the edges: \n");
   for(int i=0; i<edges; i++) {
       scanf("%d%d", &u, &v);
       addEdge(graph, u, v);
       addEdge(graph, v, u);
   }

   colorGraph(graph, color, nodes);

   printf("Node\tColor\n");
   for(int i=0; i<nodes; i++) {
       printf("%d\t%d\n", i, color[i]);
   }

   return 0;
}

void addEdge(struct Node* graph[MAX_NODES], int u, int v) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = graph[u];
    graph[u] = newNode;
}

int getRandomColor(int available_colors[MAX_COLORS], int degree) {
    int current_color = rand() % MAX_COLORS;
    for(int i=0; i<degree; i++) {
        if(available_colors[i] == current_color) {
            current_color = getRandomColor(available_colors, degree); // Recurse until a unique color is found
        }
    }
    return current_color;
}

void colorGraph(struct Node* graph[MAX_NODES], int color[MAX_NODES], int nodes) {
    int available_colors[MAX_COLORS];
    for(int i=0; i<nodes; i++) {
        int degree = 0;
        struct Node* current = graph[i];
        while(current != NULL) {
            degree++;
            current = current->next;
        }
        for(int j=0; j<degree; j++) {
            available_colors[j] = color[graph[i]->data]; // Colors used by adjacent nodes
        }
        color[i] = getRandomColor(available_colors, degree);
    }
}