//MISTRAL-7B DATASET v1.0 Category: Network Topology Mapper ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define WIDTH 30
#define HEIGHT 10

typedef struct {
    char ip[16];
    int x, y;
} Node;

Node nodes[MAX_NODES];
int n;
int matrix[MAX_NODES][MAX_NODES];

void print_topology() {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("%-15s", nodes[i].ip);
        for (j = 0; j < n; j++) {
            if (matrix[i][j])
                printf("%c", j == i ? ' ' : '-');
            else
                printf("%c", j == i ? ' ' : ' ');
        }
        printf("\n");
    }
}

void place_nodes() {
    int i;
    for (i = 0; i < n; i++) {
        nodes[i].x = i % WIDTH * (WIDTH + 2) + 1;
        nodes[i].y = i / WIDTH * (HEIGHT + 2) + 1;
    }
}

int main() {
    int i, j, k;
    char line[100];

    printf("Enter number of nodes and connections:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter IP address and connections for node %d:\n", i + 1);
        scanf("%s", nodes[i].ip);
        for (j = 0; j < n; j++) {
            if (i == j)
                continue;
            printf("Is there a connection between %s and %s? (y/n)\n", nodes[i].ip, nodes[j].ip);
            scanf("%s", line);
            if (strcmp(line, "y") == 0) {
                printf("Enter the weight of the connection: ");
                scanf("%d", &k);
                matrix[i][j] = matrix[j][i] = k;
            } else {
                matrix[i][j] = matrix[j][i] = 0;
            }
        }
    }

    place_nodes();
    printf("\nNetwork Topology:\n");
    print_topology();

    return 0;
}