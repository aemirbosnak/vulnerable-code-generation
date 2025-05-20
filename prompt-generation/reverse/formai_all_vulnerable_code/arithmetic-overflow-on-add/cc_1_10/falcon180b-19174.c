//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void create_bucket(int arr[], int n, int max_val) {
    int i;
    for (i = 0; i <= max_val; i++) {
        arr[i] = 0;
    }
}

void insert_element(int arr[], int n, int element) {
    int index = element % n;
    arr[index]++;
}

void create_array(int arr[], int n, int max_val) {
    int i;
    for (i = 0; i < n; i++) {
        int element = rand() % max_val;
        insert_element(arr, n, element);
    }
}

void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int n) {
    int i, j;
    int max_val = arr[0];
    create_bucket(arr, n, max_val);
    for (i = 0; i < n; i++) {
        int index = arr[i] % n;
        arr[index] += arr[i];
    }
    for (i = n - 1, j = 0; i >= 0; i--) {
        arr[i] += arr[i + 1];
    }
    for (i = 0; i < n; i++) {
        arr[i] = arr[i] / n;
    }
}

int main() {
    int n = 10, i;
    int arr[MAX_SIZE];
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    create_array(arr, n, MAX_SIZE);
    printf("Before Sorting:\n");
    print_array(arr, n);
    bucket_sort(arr, n);
    printf("After Sorting:\n");
    print_array(arr, n);
    return 0;
}