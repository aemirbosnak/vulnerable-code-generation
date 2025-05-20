//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int n, m, i, j, k, p, q, r, c, s, t, u, sum, max_sum, count;
int mat[MAX][MAX], temp[MAX][MAX];

void greedy_algorithm(int mat[MAX][MAX], int n, int m)
{
    int i, j, k, p, q, r, c, s, t, u, sum, max_sum, count;
    int temp[MAX][MAX];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            temp[i][j] = mat[i][j];
        }
    }

    max_sum = 0;

    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < m; j++) {
            sum += temp[i][j];
        }
        if (sum > max_sum) {
            max_sum = sum;
        }
    }

    count = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (temp[i][j] == max_sum) {
                count++;
            }
        }
    }

    printf("\nMaximum sum is: %d\n", max_sum);
    printf("Number of cells with maximum sum: %d\n", count);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (temp[i][j] == max_sum) {
                printf("\nCell: (%d,%d)\n", i, j);
            }
        }
    }

    printf("\nThe matrix with maximum sum: \n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", temp[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, m, i, j, sum;

    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &n, &m);

    printf("\nEnter the matrix elements:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    greedy_algorithm(mat, n, m);

    return 0;
}