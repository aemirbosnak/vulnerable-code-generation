//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int x, y;
    struct node *parent;
} Node;

Node *pathfind(int start_x, int start_y, int end_x, int end_y, int width, int height, int *obstacles, int *path_len);

int main() {
    printf("Enter the dimensions of the search area (width and height): ");
    int width, height;
    scanf("%d %d", &width, &height);

    printf("Enter the starting position (x y): ");
    int start_x, start_y;
    scanf("%d %d", &start_x, &start_y);

    printf("Enter the end position (x y): ");
    int end_x, end_y;
    scanf("%d %d", &end_x, &end_y);

    int obstacles[width * height];

    // Initialize obstacles to be random 0s and 1s
    for (int i = 0; i < width * height; i++) {
        obstacles[i] = rand() % 2;
    }

    int path_len = 0;
    Node *path = pathfind(start_x, start_y, end_x, end_y, width, height, obstacles, &path_len);

    printf("The path from (%d,%d) to (%d,%d) is:\n", start_x, start_y, end_x, end_y);
    Node *cur = path;
    while (cur->parent != NULL) {
        printf("(%d,%d) -> ", cur->x, cur->y);
        cur = cur->parent;
    }
    printf("(%d,%d)\n", cur->x, cur->y);

    return 0;
}

Node *pathfind(int start_x, int start_y, int end_x, int end_y, int width, int height, int *obstacles, int *path_len) {
    // I am the searching algorithm, looking for the shortest path to your heart
    Node *start_node = malloc(sizeof(Node));
    start_node->x = start_x;
    start_node->y = start_y;
    start_node->parent = NULL;

    Node *queue[width * height];
    int queue_len = 1;
    queue[0] = start_node;

    int visited[width * height];
    for (int i = 0; i < width * height; i++) {
        visited[i] = 0;
    }

    Node *cur_node = queue[0];
    while (queue_len > 0) {
        cur_node = queue[0];
        for (int i = 1; i < queue_len; i++) {
            if (cur_node->x + cur_node->y > queue[i]->x + queue[i]->y) {
                cur_node = queue[i];
            }
        }

        // I check if I have reached your heart
        if (cur_node->x == end_x && cur_node->y == end_y) {
            Node *cur = cur_node;
            while (cur->parent != NULL) {
                (*path_len)++;
                cur = cur->parent;
            }
            Node *path = malloc((*path_len) * sizeof(Node));
            cur = cur_node;
            int i = (*path_len) - 1;
            while (cur->parent != NULL) {
                path[i] = *cur;
                i--;
                cur = cur->parent;
            }
            path[0] = *cur;
            return path;
        }

        visited[cur_node->y * width + cur_node->x] = 1;
        int neighbors_x[] = {0, -1, 1, 0};
        int neighbors_y[] = {1, 0, 0, -1};
        for (int i = 0; i < 4; i++) {
            int neighbor_x = cur_node->x + neighbors_x[i];
            int neighbor_y = cur_node->y + neighbors_y[i];
            if (neighbor_x >= 0 && neighbor_x < width && 
                neighbor_y >= 0 && neighbor_y < height &&
                visited[neighbor_y * width + neighbor_x] != 1 &&
                obstacles[neighbor_y * width + neighbor_x] != 1) {
                    Node *new_node = malloc(sizeof(Node));
                    new_node->x = neighbor_x;
                    new_node->y = neighbor_y;
                    new_node->parent = cur_node;

                    queue[queue_len] = new_node;
                    queue_len++;
                }
        }
    }
    return NULL;
}