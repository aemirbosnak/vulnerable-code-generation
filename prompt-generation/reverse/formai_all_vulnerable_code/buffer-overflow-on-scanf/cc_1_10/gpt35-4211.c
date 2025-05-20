//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NODE 20

// Function that maps the network topology
void mapTopology(char graph[MAX_NODE][MAX_NODE], int size) {
    int i, j, k;

    printf("\nNetwork Topology:\n");
    for (i = 0; i < size; i++) {
        printf("| %c |", i + 65);
        for (j = 0; j < size; j++) {
            if (graph[i][j] == 1) {
                printf("----");
                printf("| %c |", j + 65);
                graph[i][j] = 0;
                graph[j][i] = 0;
            }
            else {
                printf("   ");
                printf(" |   ");
            }
        }
        printf("\n");
        for (k = 0; k < size; k++) {
            printf("----");
        }
        printf("\n");
    }
}

int main() {
    char graph[MAX_NODE][MAX_NODE];
    int size, i, j;
    printf("Enter the number of nodes in your network topology: ");
    scanf("%d", &size);

    printf("\nEnter your network topology matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    mapTopology(graph, size);
   
    return 0;
}