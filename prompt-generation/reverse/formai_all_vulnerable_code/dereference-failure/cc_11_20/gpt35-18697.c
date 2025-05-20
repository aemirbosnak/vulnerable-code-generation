//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROW 10
#define COL 10

typedef struct node {
    int x, y, f, g, h; // node coordinates, f, g, and h values
    struct node* parent; // pointer to parent node
} Node;

// A* Pathfinding Algorithm
void AStar(int map[ROW][COL], Node* start_node, Node* end_node) {
    Node* open_list[ROW * COL] = { 0 }; // list of nodes to be evaluated
    Node* closed_list[ROW * COL] = { 0 }; // list of nodes already evaluated
    int open_list_count = 0;

    // add start node to open list
    open_list[0] = start_node;
    open_list_count++;

    while (open_list_count > 0) {
        // find node with lowest f value in open list
        int min_f = open_list[0]->f;
        int min_index = 0;
        for (int i = 1; i < open_list_count; i++) {
            if (open_list[i]->f < min_f) {
                min_f = open_list[i]->f;
                min_index = i;
            }
        }

        Node* current_node = open_list[min_index];

        // remove current node from open list
        for (int i = min_index; i < open_list_count - 1; i++) {
            open_list[i] = open_list[i + 1];
        }
        open_list_count--;

        // add current node to closed list
        closed_list[current_node->x * ROW + current_node->y] = current_node;

        // found end node
        if (current_node->x == end_node->x && current_node->y == end_node->y) {
            return;
        }

        // check neighbors
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue; // current node

                int x = current_node->x + i;
                int y = current_node->y + j;
                if (x < 0 || x >= ROW || y < 0 || y >= COL) continue; // out of bounds

                Node* neighbor_node = (Node*)malloc(sizeof(Node));
                neighbor_node->x = x;
                neighbor_node->y = y;

                // check if wall
                if (map[x][y] == 1) {
                    free(neighbor_node);
                    continue;
                }

                // check if in closed list
                bool in_closed_list = false;
                if (closed_list[x * ROW + y] != NULL) {
                    in_closed_list = true;
                    free(neighbor_node);
                    continue;
                }

                // calculate f, g, and h values of neighbor node
                neighbor_node->g = current_node->g + 1;
                neighbor_node->h = abs(end_node->x - x) + abs(end_node->y - y);
                neighbor_node->f = neighbor_node->g + neighbor_node->h;

                // check if in open list
                bool in_open_list = false;
                for (int k = 0; k < open_list_count; k++) {
                    if (open_list[k]->x == x && open_list[k]->y == y) {
                        in_open_list = true;
                        // update neighbor node if better path found
                        if (neighbor_node->g < open_list[k]->g) {
                            open_list[k]->g = neighbor_node->g;
                            open_list[k]->f = neighbor_node->f;
                            open_list[k]->parent = current_node;
                        }
                        free(neighbor_node);
                        break;
                    }
                }
                if (in_open_list) continue;

                // add neighbor node to open list
                neighbor_node->parent = current_node;
                open_list[open_list_count] = neighbor_node;
                open_list_count++;
            }
        }
    }
}

// main function
int main() {
    int map[ROW][COL] = { // 0 = path, 1 = wall
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,1,0,1,0,0,0,0,0},
        {0,0,1,0,1,0,0,0,0,0},
        {0,0,1,0,1,0,0,1,0,0},
        {0,0,0,0,1,0,0,1,0,0},
        {0,1,1,1,1,0,0,1,0,0},
        {0,1,0,0,0,0,0,1,0,0},
        {0,1,0,0,0,0,0,1,0,0},
        {0,1,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,0,0,0},
    };

    Node* start_node = (Node*)malloc(sizeof(Node));
    start_node->x = 0;
    start_node->y = 0;
    start_node->g = 0;
    start_node->h = abs(ROW - 1) + abs(COL - 1);
    start_node->f = start_node->g + start_node->h;
    start_node->parent = NULL;

    Node* end_node = (Node*)malloc(sizeof(Node));
    end_node->x = ROW - 1;
    end_node->y = COL - 1;
    end_node->g = 0;
    end_node->h = 0;
    end_node->f = end_node->g + end_node->h;
    end_node->parent = NULL;

    AStar(map, start_node, end_node);

    // print path
    Node* current_node = end_node;
    while (current_node != NULL) {
        printf("(%d,%d) ", current_node->x, current_node->y);
        current_node = current_node->parent;
    }
    printf("\n");

    return 0;
}