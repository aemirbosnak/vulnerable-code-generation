//FormAI DATASET v1.0 Category: Graph representation ; Style: protected
/*
   This is a protected style graph representation example program. It takes a graph input from the user
   and generates several graph visualizations. The program protects against buffer overflow by using dynamic
   memory allocation and checking user input size.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 50
#define MAX_EDGES 150

typedef struct Vertex {
    char label[20];
} Vertex;

typedef struct Edge {
    int fromIndex;
    int toIndex;
} Edge;

typedef struct Graph {
    int numVertices;
    int numEdges;
    Vertex* vertices[MAX_VERTICES];
    Edge* edges[MAX_EDGES];
} Graph;

void add_vertex(Graph* g, char* label);
void add_edge(Graph* g, int fromIndex, int toIndex);
void generate_dot_file(Graph* g);

int main()
{
    Graph* g = (Graph*)malloc(sizeof(Graph));
    if (g == NULL) {
        printf("Memory allocation failed, exiting program...");
        return 1;
    }

    printf("Enter the number of vertices in the graph (maximum %d): ", MAX_VERTICES);
    scanf("%d", &g->numVertices);

    if (g->numVertices <= 0 || g->numVertices > MAX_VERTICES) {
        printf("Invalid number of vertices, exiting program...");
        return 1;
    }

    printf("Enter the number of edges in the graph (maximum %d): ", MAX_EDGES);
    scanf("%d", &g->numEdges);

    if (g->numEdges <= 0 || g->numEdges > MAX_EDGES) {
        printf("Invalid number of edges, exiting program...");
        return 1;
    }

    for (int i = 0; i < g->numVertices; i++) {
        char* label = (char*)malloc(20 * sizeof(char));
        printf("Enter the label for vertex %d: ", i+1);
        scanf("%s", label);
        add_vertex(g, label);
    }

    for (int i = 0; i < g->numEdges; i++) {
        int from, to;
        printf("Enter the 'from' vertex index for edge %d: ", i+1);
        scanf("%d", &from);

        printf("Enter the 'to' vertex index for edge %d: ", i+1);
        scanf("%d", &to);

        if (from <= 0 || from > g->numVertices || to <= 0 || to > g->numVertices) {
            printf("Invalid vertex index, exiting program...");
            return 1;
        }

        add_edge(g, from-1, to-1);
    }

    generate_dot_file(g);

    printf("Graph visualizations generated successfully!");

    return 0;
}

void add_vertex(Graph* g, char* label)
{
    Vertex* v = (Vertex*)malloc(sizeof(Vertex));
    strcpy(v->label, label);
    g->vertices[g->numVertices++] = v;
}

void add_edge(Graph* g, int fromIndex, int toIndex)
{
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->fromIndex = fromIndex;
    e->toIndex = toIndex;
    g->edges[g->numEdges++] = e;
}

void generate_dot_file(Graph* g)
{
    FILE* fp = fopen("graph.dot", "w");

    if (fp == NULL) {
        printf("Unable to open file for writing, exiting program...");
        exit(1);
    }

    fprintf(fp, "digraph {\n");

    for (int i = 0; i < g->numVertices; i++) {
        fprintf(fp, "  %d [label=\"%s\"];\n", i+1, g->vertices[i]->label);
    }

    for (int i = 0; i < g->numEdges; i++) {
        fprintf(fp, "  %d -> %d;\n", g->edges[i]->fromIndex+1, g->edges[i]->toIndex+1);
    }

    fprintf(fp, "}");

    fclose(fp);

    system("dot -Tpng graph.dot -o graph.png");
}