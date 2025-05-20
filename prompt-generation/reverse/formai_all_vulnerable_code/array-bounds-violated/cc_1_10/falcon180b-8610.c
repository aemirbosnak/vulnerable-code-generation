//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000
#define MAX_VALUE 1000

void bucket_sort(int arr[], int n) {
    int i, j, max_val = 0, *bucket[n];

    for (i = 0; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    for (i = 0; i < n; i++) {
        bucket[i] = (int *)malloc(sizeof(int) * max_val + 1);
        for (j = 0; j <= max_val; j++) {
            bucket[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++) {
        bucket[arr[i]][arr[i]]++;
    }

    int k = 0;
    for (i = 0; i < n; i++) {
        if (bucket[i][0] > 0) {
            for (j = 0; j <= max_val; j++) {
                if (bucket[i][j] > 0) {
                    arr[k++] = j;
                }
            }
        }
    }
}

void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int i, n, max_val;
    srand(time(NULL));

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max_val = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}