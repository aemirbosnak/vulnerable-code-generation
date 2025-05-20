//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

/* This program simulates an alien invasion on a strange planet. 
The aliens come in four different colors, represented by integers 1 to 4. 
The spaces, which the aliens occupy, are represented by nodes in a graph. 
The graph is colored in such a way that no adjacent nodes have the same color. 
In this surreal world, the color of each alien determines its behaviour. */

struct Node {
    int data;
    int color;
    int degree;
    int *adj_list;
};

struct Graph {
    int V; /* number of nodes */
    struct Node **nodes;
};

int is_adjacent(struct Graph *graph, int u, int v) {
    int i;
    struct Node *node = graph->nodes[u];
    for(i=0; i<node->degree; i++) {
        if(node->adj_list[i] == v) {
            return 1;
        }
    }
    return 0;
}

void color_graph(struct Graph *graph) {
    int i, j, k, v, color;
    struct Node *node;
    int *available;
    available = (int*)malloc(graph->V * sizeof(int));
    for(i=0; i<graph->V; i++) {
        node = graph->nodes[i];
        /* initialize available colors for each node */
        for(j=0; j<graph->V; j++) {
            available[j] = 1;
        }
        /* remove colors used by adjacent nodes */
        for(j=0; j<node->degree; j++) {
            v = node->adj_list[j];
            available[graph->nodes[v]->color - 1] = 0;
        }    
        /* color the node with the first available color */
        for(j=0; j<graph->V; j++) {
            if(available[j] == 1) {
                node->color = j+1;
                break;
            }
        }
    }
    /* set alien behaviours based on color */
    for(i=0; i<graph->V; i++) {
        node = graph->nodes[i];
        color = node->color;
        if(color == 1) {
            printf("Alien %d is friendly.\n", node->data);
        }
        else if(color == 2) {
            printf("Alien %d is hostile.\n", node->data);
        }
        else if(color == 3) {
            printf("Alien %d is curious.\n", node->data);
        }
        else if(color == 4) {
            printf("Alien %d is confused.\n", node->data);
        }
    }
}

int main() {
    /* create graph */
    int i, j, V, E, u, v;
    struct Graph *graph;
    printf("\nWelcome to planet Surreal!\n");
    printf("This planet has %d sites for alien spaceships.\n", graph->V);
    printf("The aliens come in four colors, each with a different behaviour.\n");
    printf("This graph coloring problem will assign colors to each site so that no adjacent sites have the same color.\n");
    printf("Enter the number of sites for alien spaceships: ");
    scanf("%d", &V);
    printf("Enter the number of connections between sites: ");
    scanf("%d", &E);
    graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->nodes = (struct Node**)malloc(V * sizeof(struct Node*));
    for(i=0; i<V; i++) {
        graph->nodes[i] = (struct Node*)malloc(sizeof(struct Node));
        graph->nodes[i]->data = i+1;
        graph->nodes[i]->degree = 0;
        graph->nodes[i]->adj_list = (int*)malloc(V * sizeof(int));
        for(j=0; j<V; j++) {
            graph->nodes[i]->adj_list[j] = -1;
        }
    }
    printf("Enter the connections between sites, one at a time, using site numbers: ");
    for(i=0; i<E; i++) {
        scanf("%d %d", &u, &v);
        if(u<1 || v<1 || u>V || v>V) {
            printf("Invalid input. Try again.\n");
            i--;
            continue;
        }
        if(is_adjacent(graph, u-1, v-1)) {
            printf("Those sites are already connected. Try again.\n");
            i--;
            continue;
        }
        graph->nodes[u-1]->adj_list[graph->nodes[u-1]->degree] = v-1;
        graph->nodes[u-1]->degree++;
        graph->nodes[v-1]->adj_list[graph->nodes[v-1]->degree] = u-1;
        graph->nodes[v-1]->degree++;
        printf("Connection added.\n");
    }
    /* color graph */
    color_graph(graph);
    for(i=0; i<V; i++) {
        free(graph->nodes[i]->adj_list);
        free(graph->nodes[i]);
    }
    free(graph->nodes);
    free(graph);
    return 0;
}