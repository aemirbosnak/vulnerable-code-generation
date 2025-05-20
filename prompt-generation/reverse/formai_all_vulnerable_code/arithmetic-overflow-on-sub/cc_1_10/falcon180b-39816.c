//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    if (size > MAX_SIZE) {
        printf("Error: Array size must be less than or equal to %d\n", MAX_SIZE);
        return 1;
    }
    
    // Fill the array with random numbers
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
    
    // Print the array
    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Sort the array in ascending order
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    // Print the sorted array
    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Calculate the sum of the array elements
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    printf("Sum of the array elements: %d\n", sum);
    
    // Calculate the average of the array elements
    double average = (double) sum / size;
    printf("Average of the array elements: %.2f\n", average);
    
    return 0;
}