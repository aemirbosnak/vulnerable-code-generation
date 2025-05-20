//Falcon-180B DATASET v1.0 Category: Educational ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to display a 2D array
void display_array(int arr[MAX_SIZE][MAX_SIZE]) {
    int i, j;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i, j, size;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Initialize the array with random numbers
    int arr[MAX_SIZE][MAX_SIZE];
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            arr[i][j] = rand_num(1, 100);
        }
    }

    // Display the initial array
    printf("\nInitial array:\n");
    display_array(arr);

    // Sort the array in ascending order
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1; j++) {
            if (arr[i][j] > arr[i][j + 1]) {
                int temp = arr[i][j];
                arr[i][j] = arr[i][j + 1];
                arr[i][j + 1] = temp;
            }
        }
    }

    // Display the sorted array
    printf("\nSorted array:\n");
    display_array(arr);

    return 0;
}