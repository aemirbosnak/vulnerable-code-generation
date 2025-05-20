//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100
#define MAX_W 10000

int n, w;
int wt[MAX_N], val[MAX_N];
int M[MAX_N + 1][MAX_W + 1];

void subset_sum(void) {
    int i, j;

    for (i = 0; i <= n; i++)
        for (j = 0; j <= w; j++)
            if (i == 0)
                M[i][j] = 0;
            else if (j < wt[i - 1])
                M[i][j] = M[i - 1][j];
            else
                M[i][j] = (val[i - 1] + M[i - 1][j - wt[i - 1]]) > M[i - 1][j] ?
                          val[i - 1] + M[i - 1][j - wt[i - 1]] :
                          M[i - 1][j];

    if (M[n][w] == w) {
        printf("Subset of sum %d is:\n", w);
        i = n;
        printf("%d", val[i]);
        j = w - wt[i];
        while (j > 0) {
            i--;
            if (i >= 0 && wt[i] <= j) {
                printf(" %d", val[i]);
                j -= wt[i];
            }
        }
        printf("\n");
    } else {
        printf("No subset of sum %d exists.\n", w);
    }
}

int main() {
    int i;

    scanf("%d%d", &n, &w);
    for (i = 0; i < n; i++) {
        scanf("%d%d", &wt[i], &val[i]);
    }

    subset_sum();

    return 0;
}