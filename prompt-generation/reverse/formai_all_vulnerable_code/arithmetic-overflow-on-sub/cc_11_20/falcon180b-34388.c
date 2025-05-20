//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, m, i, j, k, l, c, d, x, y, z;
    int arr[100], brr[100];
    int profit[100][100];
    int knapSack[100][100];
    int w, wt[100];
    int max_profit = 0;
    int pos = 0;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the number of knapsacks: ");
    scanf("%d", &m);

    printf("Enter the weights and profits:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &wt[i], &profit[i][0]);
    }

    printf("Enter the capacity of each knapsack:\n");
    for (j = 0; j < m; j++) {
        scanf("%d", &w);
        knapSack[j][0] = w;
    }

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (wt[j - 1] <= knapSack[i - 1]) {
                profit[j][i] = profit[j - 1][i - 1] + profit[j - 1];
            } else {
                profit[j][i] = profit[j - 1][i];
            }
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (profit[j][i] > max_profit) {
                max_profit = profit[j][i];
                pos = j;
            }
        }
    }

    printf("Maximum profit = %d\n", max_profit);

    printf("Items included in the knapsack are:\n");
    for (k = pos, x = 0; k < n; k++) {
        if (profit[k][m - 1] == max_profit) {
            printf("%d ", k + 1);
            x++;
            if (x == w)
                break;
        }
    }

    printf("\n");

    start = clock();
    system("pause");
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("CPU Time used: %lf seconds.\n", cpu_time_used);

    return 0;
}