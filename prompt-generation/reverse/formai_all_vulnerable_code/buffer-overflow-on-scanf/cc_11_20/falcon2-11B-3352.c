//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLOR 10

int main() {
    int n, i, j, k, c, d;
    int colors[MAX_COLOR] = {0};
    int adj_matrix[MAX_COLOR][MAX_COLOR] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the adjacent vertices of vertex %d: ", i + 1);
        for (j = 0; j < n; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        colors[i] = 0;
        for (j = 0; j < n; j++) {
            if (adj_matrix[i][j] == 1) {
                colors[i] += 1;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (colors[i] == 0) {
            colors[i] = 1;
        } else {
            for (j = 0; j < n; j++) {
                if (colors[j] == 0 && (adj_matrix[i][j] == 0 || adj_matrix[i][j] == colors[j])) {
                    colors[j] = colors[i] + 1;
                }
            }
        }
    }

    printf("The coloring is as follows: ");
    for (i = 0; i < n; i++) {
        if (colors[i] == 1) {
            printf("1 ");
        } else if (colors[i] > 1) {
            printf("%d ", colors[i]);
        }
    }

    return 0;
}