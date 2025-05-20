//FormAI DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 50

// Function to generate a random integer within a given range
int generate_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to search an array for a specified element
int search_array(int arr[], int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int i, n, x, index, array[ARRAY_SIZE];
    srand(time(NULL)); // Seed the random number generator

    // Generate random integers to populate the array
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = generate_random_number(1, 100);
    }

    printf("Enter a number to search for: ");
    scanf("%d", &x);

    index = search_array(array, ARRAY_SIZE, x);

    if (index != -1) {
        printf("The number %d was found at position %d in the array.\n", x, index);
    } else {
        printf("The number %d was not found in the array.\n", x);
    }

    // Clear the array for security reasons
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = 0;
    }

    // Securely overwrite variables before exiting
    n = x = index = 0;

    return 0;
}