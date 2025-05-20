//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, i, j, count = 0;
    int *a, *b;
    int m[10][10];
    int sum = 0;

    printf("Enter the number of activities: ");
    scanf("%d", &n);

    int *duration = (int *)malloc(n * sizeof(int));
    int *profit = (int *)malloc(n * sizeof(int));

    printf("Enter the duration and profit for each activity:\n");

    for(i = 0; i < n; i++) {
        scanf("%d %d", &duration[i], &profit[i]);
    }

    a = (int *)malloc(n * sizeof(int));
    b = (int *)malloc(n * sizeof(int));

    for(i = 0; i < n; i++) {
        a[i] = duration[i];
        b[i] = profit[i];
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(a[i] <= a[j]) {
                m[i][j] = 1;
            }
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(m[i][j] == 1 && b[j] > b[i]) {
                a[i] = a[i] + a[j];
                b[i] = b[i] + b[j];
            }
        }
    }

    printf("The optimal solution is:\n");

    for(i = 0; i < n; i++) {
        printf("Activity %d has duration %d and profit %d\n", i+1, a[i], b[i]);
    }

    printf("\nThe maximum profit is: %d\n", b[0]);

    return 0;
}