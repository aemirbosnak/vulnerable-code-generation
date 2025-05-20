//Code Llama-13B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: introspective
// A* Pathfinding Algorithm Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

// Structure for a node in the graph
typedef struct node {
    int x; // x-coordinate
    int y; // y-coordinate
    int g; // distance from starting node
    int h; // distance from goal node
    int f; // total distance (g + h)
    struct node *parent; // pointer to parent node
} node_t;

// Structure for a graph
typedef struct graph {
    node_t **nodes; // 2D array of nodes
    int width; // width of the graph
    int height; // height of the graph
} graph_t;

// Function to create a graph
graph_t *create_graph(int width, int height) {
    graph_t *graph = malloc(sizeof(graph_t));
    graph->width = width;
    graph->height = height;
    graph->nodes = malloc(width * height * sizeof(node_t *));
    for (int i = 0; i < width * height; i++) {
        graph->nodes[i] = malloc(sizeof(node_t));
        graph->nodes[i]->x = i % width;
        graph->nodes[i]->y = i / width;
        graph->nodes[i]->g = INT_MAX;
        graph->nodes[i]->h = INT_MAX;
        graph->nodes[i]->f = INT_MAX;
        graph->nodes[i]->parent = NULL;
    }
    return graph;
}

// Function to set the start and goal nodes
void set_start_goal(graph_t *graph, int start_x, int start_y, int goal_x, int goal_y) {
    graph->nodes[start_x + start_y * graph->width]->g = 0;
    graph->nodes[start_x + start_y * graph->width]->f = 0;
    graph->nodes[goal_x + goal_y * graph->width]->h = 0;
}

// Function to calculate the heuristic distance between two nodes
int heuristic(node_t *node1, node_t *node2) {
    return abs(node1->x - node2->x) + abs(node1->y - node2->y);
}

// Function to calculate the total distance between two nodes
int total_distance(node_t *node1, node_t *node2) {
    return node1->g + heuristic(node1, node2);
}

// Function to search for the shortest path
void search(graph_t *graph) {
    node_t *current = graph->nodes[0];
    while (current->f != 0) {
        node_t *neighbor = NULL;
        for (int i = 0; i < 4; i++) {
            int x = current->x + i % 2;
            int y = current->y + i / 2;
            if (x >= 0 && x < graph->width && y >= 0 && y < graph->height) {
                neighbor = graph->nodes[x + y * graph->width];
                if (neighbor->g > current->g + 1) {
                    neighbor->g = current->g + 1;
                    neighbor->f = total_distance(neighbor, graph->nodes[graph->width * graph->height - 1]);
                    neighbor->parent = current;
                }
            }
        }
        current = neighbor;
    }
}

// Function to print the path
void print_path(graph_t *graph) {
    node_t *current = graph->nodes[graph->width * graph->height - 1];
    while (current->parent != NULL) {
        printf("(%d, %d) -> ", current->x, current->y);
        current = current->parent;
    }
    printf("(%d, %d)\n", current->x, current->y);
}

int main() {
    srand(time(NULL));
    int width = 10;
    int height = 10;
    graph_t *graph = create_graph(width, height);
    set_start_goal(graph, 0, 0, width - 1, height - 1);
    search(graph);
    print_path(graph);
    return 0;
}