//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int csearch(int arr[], int n, int key);
void print_array(int arr[], int size);

int main() {
    int arr[MAX_SIZE], i, n, key;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int index = csearch(arr, n, key);

    if (index == -1) {
        printf("Key not present in the array.\n");
    } else {
        printf("Key found at index %d.\n", index);
    }

    printf("Array elements are: ");
    print_array(arr, n);

    return 0;
}

int csearch(int arr[], int n, int key) {
    int i;

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }

    return -1;
}

void print_array(int arr[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}