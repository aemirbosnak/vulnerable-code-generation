//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum map size
#define MAX_MAP_SIZE 100

// Define the structure for each coordinate in the map
typedef struct {
    int x;
    int y;
} Coordinate;

// Define the structure for the A* pathfinding node
typedef struct Node {
    Coordinate position;        // The coordinate of the node
    struct Node *parent;        // The parent node
    int f;                      // The combined cost of g and h
    int g;                      // The cost from the start node to this node
    int h;                      // The estimated cost from this node to the end node
    int open;                   // Whether this node is in the open list or not
    int closed;                 // Whether this node is in the closed list or not
    int obstacle;               // Whether this node is an obstacle or not
} Node;

// Define the map
Node map[MAX_MAP_SIZE][MAX_MAP_SIZE];

// Define the function to calculate the Euclidean distance between two coordinates
int euclidean_distance(Coordinate start, Coordinate end) {
    return (int) sqrt(pow((start.x - end.x), 2) + pow((start.y - end.y), 2));
}

// Define the function to get the neighboring nodes of a given node
Node *get_neighbors(Node *current_node, Coordinate end) {
    int x = current_node->position.x;
    int y = current_node->position.y;
    Node *neighbors[8];
    int i, j;
    for (i = x-1; i <= x+1; i++) {
        for (j = y-1; j <= y+1; j++) {
            if (i < 0 || i >= MAX_MAP_SIZE) continue;
            if (j < 0 || j >= MAX_MAP_SIZE) continue;
            if (i == x && j == y) continue;
            if (map[i][j].obstacle) continue;
            neighbors[(i-x+1)*3+(j-y+1)] = &map[i][j];
        }
    }
    return *neighbors;
}

// Define the function to find the node with the lowest f value in the open list
Node *get_lowest_f_node() {
    Node *lowest_f_node = NULL;
    int lowest_f = __INT_MAX__;
    int i, j;
    for (i = 0; i < MAX_MAP_SIZE; i++) {
        for (j = 0; j < MAX_MAP_SIZE; j++) {
            if (!map[i][j].open) continue;
            if (map[i][j].f < lowest_f) {
                lowest_f_node = &map[i][j];
                lowest_f = map[i][j].f;
            }
        }
    }
    return lowest_f_node;
}

// Define the function to calculate the A* path
Node *a_star_path(Coordinate start, Coordinate end) {
    // Initialize the map
    int i, j;
    for (i = 0; i < MAX_MAP_SIZE; i++) {
        for (j = 0; j < MAX_MAP_SIZE; j++) {
            map[i][j].position.x = i;
            map[i][j].position.y = j;
            map[i][j].parent = NULL;
            map[i][j].f = __INT_MAX__;
            map[i][j].g = __INT_MAX__;
            map[i][j].h = euclidean_distance(map[i][j].position, end);
            map[i][j].open = 0;
            map[i][j].closed = 0;
            map[i][j].obstacle = 0;
        }
    }
    // Set the start node
    Node *start_node = &map[start.x][start.y];
    start_node->g = 0;
    start_node->f = start_node->h;
    start_node->open = 1;
    // Set the end node
    Node *end_node = &map[end.x][end.y];
    end_node->g = __INT_MAX__;
    end_node->f = __INT_MAX__;
    // Set the obstacles (just for demonstration purposes)
    map[1][1].obstacle = 1;
    map[2][1].obstacle = 1;
    map[3][1].obstacle = 1;
    map[4][1].obstacle = 1;
    map[5][1].obstacle = 1;
    // Start the A* algorithm
    Node *current_node;
    while ((current_node = get_lowest_f_node()) != NULL) {
        current_node->open = 0;
        current_node->closed = 1;
        if (current_node == end_node) {
            return current_node;
        }
        Node *neighbor;
        for (neighbor = get_neighbors(current_node, end); neighbor; neighbor++) {
            if (neighbor->closed) continue;
            int tentative_g = current_node->g + euclidean_distance(current_node->position, neighbor->position);
            if (!neighbor->open || tentative_g < neighbor->g) {
                neighbor->parent = current_node;
                neighbor->g = tentative_g;
                neighbor->f = neighbor->g + neighbor->h;
                if (!neighbor->open) {
                    neighbor->open = 1;
                }
            }
        }
    }
    // Return NULL if no path was found
    return NULL;
}

// Define the function to print the A* path
void print_path(Node *end_node) {
    if (end_node == NULL) {
        printf("No path found!\n");
        return;
    }
    int path_length = 0;
    Node *node;
    for (node = end_node; node; node = node->parent) {
        path_length++;
    }
    Coordinate path[path_length];
    int i;
    for (i = 0, node = end_node; node; i++, node = node->parent) {
        path[i] = node->position;
    }
    printf("Path (%d steps):\n", path_length);
    for (i = path_length-1; i >= 0; i--) {
        printf("(%d, %d)\n", path[i].x, path[i].y);
    }
}

// Define the main function
int main() {
    Coordinate start = {0, 0};
    Coordinate end = {9, 9};
    Node *end_node = a_star_path(start, end);
    print_path(end_node);
    return 0;
}