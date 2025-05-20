//Falcon2-11B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_STEPS 100

struct Node {
    int x;
    int y;
    int g;
    int h;
};

int cmp(const void* a, const void* b) {
    return ((struct Node*)a)->g - ((struct Node*)b)->g;
}

int main() {
    struct Node nodes[MAX_NODES];
    int num_nodes = 0;
    int num_steps = 0;
    int x_start = 0;
    int y_start = 0;
    int x_end = 0;
    int y_end = 0;
    int x_diff = 0;
    int y_diff = 0;
    int g_diff = 0;
    int h_diff = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter the starting coordinates (x, y): ");
    scanf("%d %d", &x_start, &y_start);

    printf("Enter the ending coordinates (x, y): ");
    scanf("%d %d", &x_end, &y_end);

    printf("Enter the difference in x coordinates: ");
    scanf("%d", &x_diff);

    printf("Enter the difference in y coordinates: ");
    scanf("%d", &y_diff);

    printf("Enter the difference in g coordinates: ");
    scanf("%d", &g_diff);

    printf("Enter the difference in h coordinates: ");
    scanf("%d", &h_diff);

    for (int i = 0; i < num_nodes; i++) {
        nodes[i].x = 0;
        nodes[i].y = 0;
        nodes[i].g = 0;
        nodes[i].h = 0;
    }

    nodes[0].x = x_start;
    nodes[0].y = y_start;
    nodes[0].g = 0;
    nodes[0].h = abs(x_end - x_start) + abs(y_end - y_start);

    for (int i = 1; i < num_nodes; i++) {
        nodes[i].x = x_start + i * x_diff;
        nodes[i].y = y_start + i * y_diff;
        nodes[i].g = nodes[i - 1].g + g_diff;
        nodes[i].h = nodes[i - 1].h + h_diff;
    }

    qsort(nodes, num_nodes, sizeof(struct Node), cmp);

    for (int i = 0; i < num_nodes; i++) {
        if (nodes[i].x == x_end && nodes[i].y == y_end) {
            printf("The shortest path is %d steps long.\n", num_steps);
            for (int j = 0; j < num_steps; j++) {
                printf("(%d, %d)\n", nodes[j].x, nodes[j].y);
            }
            break;
        }
    }

    return 0;
}