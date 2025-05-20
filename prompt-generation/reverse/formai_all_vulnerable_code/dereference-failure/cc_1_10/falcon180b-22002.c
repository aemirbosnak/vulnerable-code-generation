//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

void bucket_sort(int arr[], int n) {
    int i, j, k, max, min, range, *temp;
    int *bucket[MAX];

    for(i = 0; i < MAX; i++) {
        bucket[i] = NULL;
    }

    max = arr[0];
    min = arr[0];

    for(i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    range = max - min + 1;

    for(i = 0; i < n; i++) {
        k = (arr[i] - min) * MAX / range;
        if(bucket[k] == NULL) {
            bucket[k] = malloc(sizeof(int));
            bucket[k][0] = arr[i];
        }
        else {
            temp = realloc(bucket[k], sizeof(int) * (j + 1));
            bucket[k] = temp;
            bucket[k][j] = arr[i];
        }
    }

    for(i = 0; i < MAX; i++) {
        if(bucket[i]!= NULL) {
            for(j = 0; j < (int)sizeof(bucket[i]) / sizeof(bucket[i][0]); j++) {
                arr[j * MAX + i] = bucket[i][j];
            }
            free(bucket[i]);
            bucket[i] = NULL;
        }
    }
}

int main() {
    int n, i, max, min, range;
    int *arr;

    srand(time(NULL));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = malloc(sizeof(int) * n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    min = arr[0];

    for(i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    range = max - min + 1;

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}