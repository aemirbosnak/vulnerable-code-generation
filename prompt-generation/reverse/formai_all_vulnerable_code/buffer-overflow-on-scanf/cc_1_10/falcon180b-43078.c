//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int compare(int a, int b) {
    if (a < b) {
        return -1;
    } else if (a > b) {
        return 1;
    } else {
        return 0;
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(int arr[], int n) {
    int i, j, max, min, range, index;
    int bucket[MAX_SIZE];
    for (i = 0; i < n; i++) {
        max = arr[i];
        min = arr[i];
        for (j = i + 1; j < n; j++) {
            if (arr[j] > max) {
                max = arr[j];
            }
            if (arr[j] < min) {
                min = arr[j];
            }
        }
        range = max - min + 1;
        for (j = 0; j < range; j++) {
            bucket[j] = 0;
        }
        for (j = i; j < n; j++) {
            index = arr[j] - min;
            bucket[index]++;
        }
        for (j = i; j < n; j++) {
            index = arr[j] - min;
            arr[j] = index + bucket[index];
            bucket[index]--;
        }
    }
}

int main() {
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}