//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000
#define PI 3.14159265358979323846

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int arr[], int low, int high) {
    int i = low, j = high;
    int pivot = arr[(low + high) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    if (low < j)
        quick_sort(arr, low, j);
    if (i < high)
        quick_sort(arr, i, high);
}

int main() {
    int arr[MAX_SIZE], n;
    char input[MAX_SIZE];
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &arr[n]);
    quick_sort(arr, 0, n - 1);
    int index = binary_search(arr, n, arr[n]);
    if (index == -1)
        printf("Element not found!");
    else
        printf("Element found at index %d!", index);
    return 0;
}

int binary_search(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}