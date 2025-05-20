//Falcon-180B DATASET v1.0 Category: Educational ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MIN_VALUE 1
#define MAX_VALUE 100

int main() {
    int arr[MAX_SIZE];
    int size;
    int sum = 0;
    int average;
    int min_val;
    int max_val;
    int count = 0;
    int i;

    // Get array size from user
    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Check if array size is valid
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid array size.\n");
        exit(1);
    }

    // Initialize array with random values
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        arr[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    // Calculate sum, minimum, maximum, and average of array elements
    for (i = 0; i < size; i++) {
        sum += arr[i];
        if (arr[i] < min_val || i == 0) {
            min_val = arr[i];
        }
        if (arr[i] > max_val || i == 0) {
            max_val = arr[i];
        }
    }
    average = sum / size;

    // Print array elements, sum, minimum, maximum, and average
    printf("Array elements:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Sum: %d\n", sum);
    printf("Minimum: %d\n", min_val);
    printf("Maximum: %d\n", max_val);
    printf("Average: %.2f\n", average);

    return 0;
}