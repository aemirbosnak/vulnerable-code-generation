//Falcon2-11B DATASET v1.0 Category: Classical Circuit Simulator ; Style: innovative
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    printf("Enter the number of nodes in the circuit: ");
    scanf("%d", &n);

    int i, j, k;
    int* adj[n+1];
    int* in[n+1];
    int* out[n+1];

    printf("Enter the adjacency matrix for the circuit:\n");
    for (i = 0; i <= n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
        in[i] = (int*)malloc(n * sizeof(int));
        out[i] = (int*)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    printf("Enter the input vector for the circuit:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &in[i][0]);
    }

    printf("Enter the output vector for the circuit:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &out[i][0]);
    }

    // Calculate the output vector
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                if (adj[i][j] == 1) {
                    out[i][j] += in[j][k] * adj[i][k];
                }
            }
        }
    }

    // Print the output vector
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", out[i][j]);
        }
        printf("\n");
    }

    return 0;
}