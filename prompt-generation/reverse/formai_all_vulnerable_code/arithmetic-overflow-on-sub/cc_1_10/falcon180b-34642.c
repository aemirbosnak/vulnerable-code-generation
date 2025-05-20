//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 1000
#define MAX_VALUE 100

int main() {
    int num_elements;
    int *numbers;
    int i;

    srand(time(NULL));

    // Prompt user for number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    // Allocate memory for array of integers
    numbers = (int *)malloc(num_elements * sizeof(int));

    // Populate array with random integers
    for (i = 0; i < num_elements; i++) {
        numbers[i] = rand() % MAX_VALUE;
    }

    // Sort array in descending order
    for (i = 0; i < num_elements - 1; i++) {
        for (int j = i + 1; j < num_elements; j++) {
            if (numbers[i] < numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    // Initialize variables for greedy algorithm
    int sum = 0;
    int current_sum = 0;

    // Apply greedy algorithm to find maximum sum
    for (i = 0; i < num_elements; i++) {
        current_sum += numbers[i];
        if (current_sum > sum) {
            sum = current_sum;
        }
    }

    // Print results
    printf("The maximum sum is: %d\n", sum);

    // Free memory
    free(numbers);

    return 0;
}