//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int main() {
    int i, j, n, count = 0;
    int arr[MAX];
    int sum = 0;
    int capacity[MAX];
    int value[MAX];

    srand(time(NULL));
    n = rand() % 100 + 1;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        capacity[i] = rand() % 100 + 1;
        value[i] = rand() % 100 + 1;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (capacity[j] > 0 && value[j] > 0) {
                if (value[j] > value[i]) {
                    value[i] = value[j];
                    capacity[j] = 0;
                }
            }
        }
    }

    printf("Knapsack using Greedy Algorithm:\n");
    for (i = 0; i < n; i++) {
        if (capacity[i] > 0) {
            printf("%d ", arr[i]);
            sum += arr[i];
            capacity[i] = 0;
        }
    }

    printf("\nTotal value of items in knapsack: %d\n", sum);

    return 0;
}