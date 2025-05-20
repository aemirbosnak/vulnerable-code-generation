//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

void bucket_sort(int arr[], int n) {
    int i, j, k;
    int *bucket[MAX_SIZE];

    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = NULL;
    }

    for (i = 0; i < n; i++) {
        k = arr[i] * MAX_SIZE;
        if (bucket[k] == NULL) {
            bucket[k] = (int *) malloc(sizeof(int));
            *bucket[k] = arr[i];
        } else {
            int *temp = (int *) realloc(bucket[k], sizeof(int) * 2);
            if (temp == NULL) {
                printf("Memory error\n");
                exit(1);
            }
            bucket[k] = temp;
            *(bucket[k] + 1) = arr[i];
        }
    }

    i = 0;
    for (j = 0; j < MAX_SIZE; j++) {
        if (bucket[j]!= NULL) {
            for (k = 0; k < *(bucket[j] + 1); k++) {
                arr[i++] = *(bucket[j] + k);
            }
            free(bucket[j]);
            bucket[j] = NULL;
        }
    }
}

int main() {
    int i, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}