//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

int main() {
    int n;
    int m;
    int **a;
    int i, j;
    int sum;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    a = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the number of rows to be selected: ");
    scanf("%d", &m);

    int **b = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        b[i] = (int *)malloc(n * sizeof(int));
    }

    i = 0;
    j = 0;
    sum = 0;

    while (i < n && j < m) {
        if (a[i][j] > 0) {
            b[j][i] = a[i][j];
            i++;
        } else {
            j++;
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < m; i++) {
        free(b[i]);
    }
    free(b);

    for (i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}