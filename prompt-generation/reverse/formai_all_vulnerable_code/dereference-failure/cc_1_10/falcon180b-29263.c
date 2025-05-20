//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int *create_array(int n) {
    int *arr = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;
    }
    return arr;
}

void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int get_bucket_index(int *arr, int n, int max_val) {
    int max_index = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max_val) {
            max_index = i;
        }
    }
    return max_index;
}

void sort_array(int *arr, int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    int max_index = get_bucket_index(arr, n, max_val);
    int **buckets = (int **) malloc(max_index + 1 * sizeof(int *));
    for (int i = 0; i <= max_index; i++) {
        buckets[i] = (int *) malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / max_val;
        buckets[bucket_index][i] = arr[i];
    }
    int index = 0;
    for (int i = 0; i <= max_index; i++) {
        for (int j = 0; j < buckets[i][index]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }
    for (int i = 0; i < max_index + 1; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

void main() {
    int n = MAX_SIZE;
    srand(time(NULL));
    int *arr = create_array(n);
    print_array(arr, n);
    sort_array(arr, n);
    print_array(arr, n);
    free(arr);
}