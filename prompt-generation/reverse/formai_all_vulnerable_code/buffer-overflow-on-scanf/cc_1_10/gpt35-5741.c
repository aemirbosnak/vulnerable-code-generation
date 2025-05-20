//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random array
int* generateArray(int n) {
    int* arr = (int*)malloc(sizeof(int)*n);
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    return arr;
}

// function to display array
void displayArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// function to search for an element in array
int linearSearch(int* arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int* arr = generateArray(n);
    displayArray(arr, n);

    int x;
    printf("Enter element to search: ");
    scanf("%d", &x);

    int result = linearSearch(arr, n, x);

    if (result == -1) {
        printf("%d not found in array\n", x);
    }
    else {
        printf("%d found at index %d\n", x, result);
    }

    free(arr);
    return 0;
}