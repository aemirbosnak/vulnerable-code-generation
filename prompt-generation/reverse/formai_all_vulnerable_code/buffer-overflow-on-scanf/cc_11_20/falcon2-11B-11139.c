//Falcon2-11B DATASET v1.0 Category: Math exercise ; Style: unmistakable
#include <stdio.h>

int main() {
    int i, j, k, n;
    int a[10][10], b[10][10], c[10][10];
    int x, y, z;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter elements of matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    printf("Enter elements of matrix C:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            x = a[i][j];
            y = b[i][j];
            z = c[i][j];
            c[i][j] = x + y + z;
        }
    }

    printf("Matrix C:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}