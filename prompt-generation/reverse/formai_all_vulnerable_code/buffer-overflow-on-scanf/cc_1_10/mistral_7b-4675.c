//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100005

typedef struct {
    int val;
    bool taken;
} Item;

void init(Item arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i].val = 0;
        arr[i].taken = false;
    }
}

int partition(Item arr[], int n) {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        if (!arr[i].taken) {
            if (abs(sum1 - sum2) < abs(sum1 + arr[i].val - sum2)) {
                sum1 += arr[i].val;
                arr[i].taken = true;
            } else {
                sum2 += arr[i].val;
                arr[i].taken = true;
            }
        }
    }
    return sum1 - sum2;
}

int main() {
    int n;
    scanf("%d", &n);

    Item arr[MAX_N];
    init(arr, n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].val);
    }

    int min_diff = partition(arr, n);
    printf("Minimum difference: %d\n", min_diff);

    return 0;
}