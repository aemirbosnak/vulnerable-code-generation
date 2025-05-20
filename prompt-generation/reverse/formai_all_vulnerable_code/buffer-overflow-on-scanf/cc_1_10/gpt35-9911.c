//FormAI DATASET v1.0 Category: Graph representation ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

// structure to represent a node in the graph
struct node {
    int vertex;
    struct node* next;
};

// function to add an edge to the graph
void add_edge(struct node** graph, int u, int v) {
    // add edge from u to v
    struct node* n1 = (struct node*)malloc(sizeof(struct node));
    n1->vertex = v;
    n1->next = graph[u];
    graph[u] = n1;

    // add edge from v to u
    struct node* n2 = (struct node*)malloc(sizeof(struct node));
    n2->vertex = u;
    n2->next = graph[v];
    graph[v] = n2;
}

// function to print the graph
void print_graph(struct node** graph, int n) {
    int i;
    for(i=0; i<n; i++) {
        printf("Vertex %d: ", i);
        struct node* current = graph[i];
        while(current != NULL) {
            printf("%d ", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

// the main function
int main() {

    // prompt the user for the number of vertices in the graph
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    // create the graph
    struct node** graph = (struct node**)malloc(sizeof(struct node*) * n);
    int i;
    for(i=0; i<n; i++) {
        graph[i] = NULL;
    }
    int u, v;
    char c;
    printf("Enter the edges of the graph in the format \"u,v\" (enter Q to quit):\n");
    while(1) {
        scanf("%d%c%d", &u, &c, &v);
        if(c == 'Q') break;
        add_edge(graph, u, v);
    }

    // print the graph
    printf("\nThe graph is:\n");
    print_graph(graph, n);

    return 0;
}