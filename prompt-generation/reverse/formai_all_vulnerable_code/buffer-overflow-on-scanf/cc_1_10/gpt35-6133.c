//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 50
#define MAX_EDGES 2500
#define MAX_COLORS 5

int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
int vertices[MAX_VERTICES];
int colors[MAX_VERTICES];
int num_vertices;
int num_edges;

int get_rand_color()
{
    return rand() % MAX_COLORS;
}

int get_node_degree(int node)
{
    int degree = 0;
    int i;
    for (i = 0; i < num_vertices; i++) {
        if (adjacency_matrix[node][i]) {
            degree++;
        }
    }
    return degree;
}

int choose_node_with_max_degree()
{
    int max_degree = 0;
    int max_degree_node = -1;
    int i;
    for (i = 0; i < num_vertices; i++) {
        if (vertices[i] && get_node_degree(i) > max_degree) {
            max_degree = get_node_degree(i);
            max_degree_node = i;
        }
    }
    return max_degree_node;
}

void color_node(int node)
{
    int allowed_colors[MAX_COLORS] = { 1 };
    int i;
    for (i = 0; i < num_vertices; i++) {
        if (adjacency_matrix[node][i] && colors[i] != -1) {
            allowed_colors[colors[i]] = 0;
        }
    }
    for (i = 0; i < MAX_COLORS; i++) {
        if (allowed_colors[i]) {
            colors[node] = i;
            return;
        }
    }
}

void color_nodes()
{
    int i;
    int node;
    for (i = 0; i < num_vertices; i++) {
        node = choose_node_with_max_degree();
        vertices[node] = 0;
        color_node(node);
    }
}

void initialize()
{
    int i, j;
    for (i = 0; i < num_vertices; i++) {
        vertices[i] = 1;
        colors[i] = -1;
        for (j = 0; j < num_vertices; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }
}

void generate_graph()
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < num_vertices; i++) {
        for (j = i + 1; j < num_vertices && num_edges < MAX_EDGES; j++) {
            if (rand() % 2) {
                adjacency_matrix[i][j] = 1;
                adjacency_matrix[j][i] = 1;
                num_edges++;
            }
        }
    }
}

void print_graph()
{
    int i, j;
    printf("\n");
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_colors()
{
    int i;
    for (i = 0; i < num_vertices; i++) {
        printf("Node %d color: %d\n", i, colors[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter number of vertices (maximum %d): ", MAX_VERTICES);
    scanf("%d", &num_vertices);
    initialize();
    generate_graph();
    print_graph();
    color_nodes();
    print_colors();
    return 0;
}