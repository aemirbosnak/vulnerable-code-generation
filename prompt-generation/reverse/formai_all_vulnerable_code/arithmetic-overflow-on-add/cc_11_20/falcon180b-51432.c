//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VAL 100
#define MAX_SIZE 50

int main() {
    int i, j, n, max_sum;
    int arr[MAX_SIZE];
    int incl[MAX_SIZE];
    int excl[MAX_SIZE];
    int *inc, *exc;
    int sum = 0;
    int max_excl_sum = 0;
    int max_incl_sum = 0;

    srand(time(NULL));

    n = rand() % MAX_SIZE + 1;

    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX_VAL + 1;
    }

    for (i = 0; i < n; i++) {
        excl[i] = arr[i];
    }

    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            incl[j] += arr[i];
        }
    }

    inc = incl;
    exc = excl;

    for (i = 0; i < n; i++) {
        if (arr[i] > max_sum) {
            max_sum = arr[i];
        }
    }

    for (i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > max_excl_sum) {
            max_excl_sum = sum;
        }
    }

    for (i = 0; i < n; i++) {
        sum -= arr[i];
        sum += *inc;
        if (sum > max_incl_sum) {
            max_incl_sum = sum;
        }
        inc++;
    }

    printf("Maximum sum of non-overlapping subarrays: %d\n", max_incl_sum);
    printf("Maximum sum of overlapping subarrays: %d\n", max_excl_sum);

    return 0;
}