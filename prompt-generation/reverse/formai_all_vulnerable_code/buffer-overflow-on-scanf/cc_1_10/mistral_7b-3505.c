//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void print_array(int arr[], int size) {
    int i;
    printf("Array elements are:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int min_jumps(int arr[], int size) {
    int jumps = 1, max_reach = arr[0], i = 0, steps = 0;

    if (size == 0 || size == 1) {
        return 0;
    }

    while (i < size) {
        steps++;

        max_reach = (i + arr[i]) > (max_reach) ? (i + arr[i]) : max_reach;

        if (i == max_reach) {
            jumps++;
            if (arr[i] > 0) {
                max_reach = i + arr[i];
            } else {
                i = max_reach;
            }
        } else {
            i++;
        }
    }

    return jumps;
}

int main() {
    int arr[MAX_SIZE], size, i;

    printf("Enter the size of the array:\n");
    scanf("%d", &size);

    printf("Enter %d integers:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    print_array(arr, size);

    printf("Minimum number of jumps to reach the end of the array is %d\n", min_jumps(arr, size));

    return 0;
}