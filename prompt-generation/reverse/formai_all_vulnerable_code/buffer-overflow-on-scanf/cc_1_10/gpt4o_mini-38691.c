//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function prototypes
void initializeArray(int *arr, int size);
void printArray(const int *arr, int size);
int sumArray(const int *arr, int size);
float averageArray(const int *arr, int size);
int findMax(const int *arr, int size);
int findMin(const int *arr, int size);

int main() {
    srand(time(NULL));
    int array[MAX_SIZE];
    int size;
    
    printf("Enter the number of elements you want in the array (1 - %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size < 1 || size > MAX_SIZE) {
        printf("Size must be between 1 and %d\n", MAX_SIZE);
        return 1;
    }

    // Initialize array with random integers
    initializeArray(array, size);
    
    // Display array
    printf("Initialized Array:\n");
    printArray(array, size);
    
    // Calculate and display sum
    int sum = sumArray(array, size);
    printf("Sum of array elements: %d\n", sum);
    
    // Calculate and display average
    float average = averageArray(array, size);
    printf("Average of array elements: %.2f\n", average);
    
    // Find and display max and min
    int max = findMax(array, size);
    int min = findMin(array, size);
    printf("Maximum element is: %d\n", max);
    printf("Minimum element is: %d\n", min);
    
    return 0;
}

void initializeArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

void printArray(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sumArray(const int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

float averageArray(const int *arr, int size) {
    int sum = sumArray(arr, size);
    return (float)sum / size;
}

int findMax(const int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMin(const int *arr, int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}