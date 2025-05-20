//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

int main() {
    int i, j;
    int arr[MAX_SIZE];
    int n;
    int min, max;
    int count[MAX_SIZE];
    int *sorted_arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sorted_arr = malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    sorted_arr[0] = arr[0];
    count[arr[0]]--;
    for (i = 1; i < n; i++) {
        if (count[arr[i]] == 0) {
            sorted_arr[i] = arr[i];
            count[arr[i]]--;
        }
    }

    for (i = 0; i < n; i++) {
        while (count[arr[i]] > 0) {
            sorted_arr[i + count[arr[i]] - 1] = arr[i];
            count[arr[i]]--;
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");

    free(sorted_arr);
    return 0;
}