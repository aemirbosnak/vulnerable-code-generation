//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, k, l, m;
    int a[100][100];
    int b[100][100];
    int c[100][100];

    int **p;
    int **q;
    int **r;

    int sum;

    printf("Enter number of rows and columns\n");
    scanf("%d%d", &n, &m);

    printf("Enter elements of first matrix\n");

    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of second matrix\n");

    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    p = (int **)malloc(n*sizeof(int *));
    q = (int **)malloc(n*sizeof(int *));
    r = (int **)malloc(n*sizeof(int *));

    for(i=0; i<n; i++) {
        p[i] = (int *)malloc(m*sizeof(int));
        q[i] = (int *)malloc(m*sizeof(int));
        r[i] = (int *)malloc(m*sizeof(int));
    }

    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            c[i][j] = 0;
        }
    }

    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            for(k=0; k<m; k++) {
                sum = 0;
                for(l=0; l<m; l++) {
                    sum += a[i][l]*b[l][k];
                }
                c[i][j] += sum*b[k][j];
            }
        }
    }

    printf("Product of matrices:\n");

    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}