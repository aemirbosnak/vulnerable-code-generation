//Falcon-180B DATASET v1.0 Category: Error handling ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
int *create_array(int size);
void destroy_array(int *array, int size);
int sum_array(int *array, int size);
int product_array(int *array, int size);
int average_array(int *array, int size);

int main() {
    int choice, size;

    // Initialize random seed
    srand(time(NULL));

    // Prompt user for array size
    printf("Enter array size: ");
    scanf("%d", &size);

    // Create array
    int *array = create_array(size);

    // Prompt user for operation
    printf("\nSelect operation:\n");
    printf("1. Sum\n");
    printf("2. Product\n");
    printf("3. Average\n");
    scanf("%d", &choice);

    // Perform selected operation
    switch (choice) {
        case 1:
            printf("Sum: %d\n", sum_array(array, size));
            break;
        case 2:
            printf("Product: %d\n", product_array(array, size));
            break;
        case 3:
            printf("Average: %.2f\n", average_array(array, size));
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    // Destroy array
    destroy_array(array, size);

    return 0;
}

// Create integer array of given size
int *create_array(int size) {
    int *array = (int *) malloc(size * sizeof(int));

    if (array == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    return array;
}

// Destroy integer array
void destroy_array(int *array, int size) {
    free(array);
}

// Calculate sum of integer array
int sum_array(int *array, int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    return sum;
}

// Calculate product of integer array
int product_array(int *array, int size) {
    int product = 1;

    for (int i = 0; i < size; i++) {
        product *= array[i];
    }

    return product;
}

// Calculate average of integer array
int average_array(int *array, int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    return sum / size;
}