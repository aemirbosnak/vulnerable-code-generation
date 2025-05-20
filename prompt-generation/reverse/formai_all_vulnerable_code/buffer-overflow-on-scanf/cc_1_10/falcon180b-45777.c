//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_VALUE 1000000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucket_sort(int arr[], int n) {
    int *buckets[MAX_VALUE];
    for(int i = 0; i < MAX_VALUE; i++) {
        buckets[i] = malloc(sizeof(int) * n);
    }
    for(int i = 0; i < n; i++) {
        int index = arr[i] * MAX_VALUE / MAX_VALUE;
        buckets[index][i] = arr[i];
    }
    for(int i = 0; i < MAX_VALUE; i++) {
        int j = 0;
        while(buckets[i][j]) {
            arr[j++] = buckets[i][j];
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    int n, i;
    srand(time(NULL));
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
    printf("Before sorting:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucket_sort(arr, n);
    printf("After sorting:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}