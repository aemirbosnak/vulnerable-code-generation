//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int main() {
    int a[MAX], b[MAX], c[MAX], d[MAX];
    int i, j, k, l, m, n, o;

    printf("Enter the number of rows and columns for the matrices:");
    scanf("%d %d", &n, &m);

    printf("Enter the elements of the first matrix:");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d ", &a[i * m + j]);
        }
    }

    printf("Enter the elements of the second matrix:");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d ", &b[i * m + j]);
        }
    }

    k = n * m;
    l = n * m;
    o = n * m;

    for (i = 0; i < o; i++) {
        c[i] = 0;
        for (j = 0; j < k; j++) {
            for (int h = 0; h < l; h++) {
                if (a[h] && b[j]) {
                    c[i] += a[h] * b[j];
                }
            }
        }
    }

    printf("The product of the two matrices is:");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", c[i * m + j]);
        }
        printf("\n");
    }

    return 0;
}