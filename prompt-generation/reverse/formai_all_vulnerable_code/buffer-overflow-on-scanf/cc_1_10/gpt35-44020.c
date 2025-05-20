//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);
void print_array(int arr[], int n);

int main() {
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);
    
    int arr[length];
    srand(time(NULL));
    for(int i = 0; i < length; i++) {
        arr[i] = rand() % 100;
    }
    
    printf("Before sorting: ");
    print_array(arr, length);
    
    quick_sort(arr, 0, length-1);
    
    printf("After sorting: ");
    print_array(arr, length);
    
    return 0;
}

void quick_sort(int arr[], int low, int high) {
    if(low < high) {
        int partition_index = partition(arr, low, high);
        quick_sort(arr, low, partition_index - 1);
        quick_sort(arr, partition_index + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for(int j = low; j <= high-1; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}