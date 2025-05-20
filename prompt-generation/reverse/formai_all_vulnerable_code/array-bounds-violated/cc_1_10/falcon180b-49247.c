//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Function to generate a random number between 0 and n-1
int randInt(int n) {
    return rand() % n;
}

// Function to print a 2D array
void printArray(int arr[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to fill a 2D array with random numbers
void fillArray(int arr[MAX_ROWS][MAX_COLS]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            arr[i][j] = randInt(100);
        }
    }
}

int main() {
    int arr[MAX_ROWS][MAX_COLS];

    // Fill the array with random numbers
    fillArray(arr);

    // Print the original array
    printf("Original Array:\n");
    printArray(arr);

    // Rotate the array by 90 degrees
    int temp[MAX_ROWS][MAX_COLS];
    int k = 0;
    for (int i = MAX_ROWS - 1; i >= 0; i--) {
        for (int j = 0; j < MAX_COLS; j++) {
            temp[k][j] = arr[i][j];
            k++;
        }
    }
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            arr[i][j] = temp[i][j];
        }
    }

    // Print the rotated array
    printf("\nArray Rotated by 90 Degrees:\n");
    printArray(arr);

    return 0;
}