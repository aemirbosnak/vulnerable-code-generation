//Code Llama-13B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: modular
/*
 * A* Pathfinding Algorithm Example Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// Structure to represent a node in the graph
typedef struct node {
    int x;
    int y;
    int g; // Cost of reaching this node from the starting node
    int h; // Estimated cost of reaching the goal node from this node
    struct node *parent;
} Node;

// Structure to represent a graph
typedef struct graph {
    int num_nodes;
    Node **nodes;
} Graph;

// Function to create a new graph
Graph *create_graph(int num_nodes) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->nodes = (Node **)malloc(sizeof(Node *) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i] = (Node *)malloc(sizeof(Node));
        graph->nodes[i]->x = i;
        graph->nodes[i]->y = i;
        graph->nodes[i]->g = INT_MAX;
        graph->nodes[i]->h = INT_MAX;
        graph->nodes[i]->parent = NULL;
    }
    return graph;
}

// Function to find the minimum cost node in the open list
Node *find_min_cost_node(Graph *graph, Node **open_list, int *open_list_size) {
    int min_cost = INT_MAX;
    Node *min_cost_node = NULL;
    for (int i = 0; i < *open_list_size; i++) {
        Node *node = open_list[i];
        if (node->g + node->h < min_cost) {
            min_cost = node->g + node->h;
            min_cost_node = node;
        }
    }
    return min_cost_node;
}

// Function to find the neighbors of a given node
void find_neighbors(Graph *graph, Node *node, Node **neighbors, int *num_neighbors) {
    *num_neighbors = 0;
    for (int i = 0; i < graph->num_nodes; i++) {
        if (i != node->x && i != node->y) {
            neighbors[(*num_neighbors)++] = graph->nodes[i];
        }
    }
}

// Function to calculate the heuristic cost of a node
int calculate_heuristic_cost(Graph *graph, Node *node, Node *goal_node) {
    return abs(node->x - goal_node->x) + abs(node->y - goal_node->y);
}

// Function to find the path from the starting node to the goal node
void find_path(Graph *graph, Node *starting_node, Node *goal_node) {
    Node **open_list = (Node **)malloc(sizeof(Node *) * graph->num_nodes);
    int open_list_size = 1;
    open_list[0] = starting_node;
    while (open_list_size > 0) {
        Node *current_node = find_min_cost_node(graph, open_list, &open_list_size);
        if (current_node->x == goal_node->x && current_node->y == goal_node->y) {
            break;
        }
        Node **neighbors = (Node **)malloc(sizeof(Node *) * graph->num_nodes);
        int num_neighbors = 0;
        find_neighbors(graph, current_node, neighbors, &num_neighbors);
        for (int i = 0; i < num_neighbors; i++) {
            Node *neighbor = neighbors[i];
            int tentative_g = current_node->g + 1;
            if (tentative_g < neighbor->g) {
                neighbor->g = tentative_g;
                neighbor->h = calculate_heuristic_cost(graph, neighbor, goal_node);
                neighbor->parent = current_node;
            }
        }
        free(neighbors);
    }
    // Print the path from the starting node to the goal node
    Node *current_node = goal_node;
    while (current_node != starting_node) {
        printf("(%d, %d) -> ", current_node->x, current_node->y);
        current_node = current_node->parent;
    }
    printf("(%d, %d)\n", starting_node->x, starting_node->y);
}

int main() {
    Graph *graph = create_graph(9);
    Node *starting_node = graph->nodes[0];
    Node *goal_node = graph->nodes[8];
    find_path(graph, starting_node, goal_node);
    return 0;
}