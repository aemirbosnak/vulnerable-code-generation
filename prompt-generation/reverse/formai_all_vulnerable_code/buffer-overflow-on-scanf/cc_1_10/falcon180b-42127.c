//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to generate a random number
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to search for a specific value in an array
int search_array(int arr[], int n, int val) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1; // Value not found
}

int main() {
    int n, i, val, pos;
    int arr[100];

    // Generate a random array of integers
    srand(time(NULL));
    for (i = 0; i < 100; i++) {
        arr[i] = rand_num(1, 100);
    }

    // Print the array
    printf("Random array: ");
    for (i = 0; i < 100; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Get user input for value to search
    printf("Enter a value to search: ");
    scanf("%d", &val);

    // Search for the value in the array
    pos = search_array(arr, 100, val);

    // Print the result
    if (pos == -1) {
        printf("Value not found\n");
    } else {
        printf("Value found at position %d\n", pos);
    }

    return 0;
}