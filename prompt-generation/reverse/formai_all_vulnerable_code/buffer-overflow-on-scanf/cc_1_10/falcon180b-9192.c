//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int *arr;
int n;

void init_array(int size) {
    arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX;
    }
    n = size;
}

void print_array() {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void bucket_sort() {
    int *bucket = (int *)malloc(MAX * sizeof(int));
    for (int i = 0; i < MAX; i++) {
        bucket[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }
    for (int i = 0; i < MAX; i++) {
        bucket[i] += bucket[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        arr[bucket[arr[i]] - 1] = arr[i];
        bucket[arr[i]]--;
    }
}

int main() {
    srand(time(NULL));
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    init_array(size);
    print_array();
    bucket_sort();
    print_array();
    return 0;
}