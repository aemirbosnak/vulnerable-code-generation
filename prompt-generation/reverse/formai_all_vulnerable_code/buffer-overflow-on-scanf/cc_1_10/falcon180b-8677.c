//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 100

typedef struct {
    int x;
    int y;
} Point;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    int i;
    for(i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size) {
    int i, j;
    for(i=0; i<size-1; i++) {
        for(j=0; j<size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int arr[MAX_SIZE];
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter %d integers:\n", size);
    int i;
    for(i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Unsorted array:\n");
    printArray(arr, size);
    bubbleSort(arr, size);
    printf("Sorted array:\n");
    printArray(arr, size);
    return 0;
}