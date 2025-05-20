//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_VALUE 1000000

void bucket_sort(int arr[], int n) {
    int i, j, max_val = arr[0];
    int *bucket[MAX_VALUE];

    for (i = 0; i < MAX_VALUE; i++) {
        bucket[i] = (int *) malloc(sizeof(int) * n);
    }

    for (i = 0; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    for (i = 0; i < n; i++) {
        j = arr[i] * MAX_VALUE / max_val;
        bucket[j] = realloc(bucket[j], sizeof(int) * (++bucket[j][0]));
        bucket[j][bucket[j][0] - 1] = arr[i];
    }

    int index = 0;
    for (i = 0; i < MAX_VALUE; i++) {
        if (bucket[i]!= NULL) {
            for (j = 0; j < bucket[i][0]; j++) {
                arr[index++] = bucket[i][j];
            }
            free(bucket[i]);
        }
    }
}

int main() {
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    bucket_sort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}