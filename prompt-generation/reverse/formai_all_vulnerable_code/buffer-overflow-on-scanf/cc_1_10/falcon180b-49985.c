//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define NODE_COUNT 9
#define NODE_INVALID -1

int adj_matrix[NODE_COUNT][NODE_COUNT] = {
    {0, 2, 0, 0, 0, 0, 0, 4, 0},
    {2, 0, 3, 0, 0, 0, 0, 8, 5},
    {0, 3, 0, 1, 0, 0, 0, 0, 3},
    {0, 0, 1, 0, 5, 0, 0, 0, 6},
    {0, 0, 0, 5, 0, 4, 0, 0, 8},
    {0, 0, 0, 0, 4, 0, 2, 0, 2},
    {0, 0, 0, 0, 0, 2, 0, 1, 4},
    {4, 8, 0, 0, 0, 0, 1, 0, 7},
    {0, 5, 3, 6, 8, 2, 4, 7, 0}
};

void print_path(int path[], int start, int end) {
    printf("Path from node %d to node %d: ", start, end);
    for (int i = 0; i <= end; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

bool search_path(int start, int end, int path[]) {
    int queue[NODE_COUNT];
    int front = 0, rear = 0;
    int visited[NODE_COUNT] = {false};

    visited[start] = true;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];

        for (int i = 0; i < NODE_COUNT; i++) {
            if (adj_matrix[current][i] &&!visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
                path[i] = current;
            }
        }
    }

    return visited[end];
}

int main() {
    int start, end;

    printf("Enter the starting node: ");
    scanf("%d", &start);

    printf("Enter the ending node: ");
    scanf("%d", &end);

    int path[NODE_COUNT];

    if (search_path(start, end, path)) {
        print_path(path, start, end);
    } else {
        printf("No path found.\n");
    }

    return 0;
}