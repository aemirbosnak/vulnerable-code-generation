//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NUMBERS 1000000

// Function to generate random numbers
void generate_random_numbers(int *numbers, int num_numbers) {
    srand(time(NULL));
    for (int i = 0; i < num_numbers; i++) {
        numbers[i] = rand() % 100;
    }
}

// Function to sort the array using quicksort
void quicksort(int *numbers, int num_numbers) {
    int i = 0, j = num_numbers - 1;
    int temp;
    int pivot = numbers[num_numbers / 2];

    while (i <= j) {
        while (numbers[i] > pivot)
            i++;
        while (numbers[j] < pivot)
            j--;
        if (i <= j) {
            temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
            i++;
            j--;
        }
    }
}

// Function to calculate the median
double calculate_median(int *numbers, int num_numbers) {
    quicksort(numbers, num_numbers);
    int middle = num_numbers / 2;

    if (num_numbers % 2 == 0) {
        return (double)(numbers[middle - 1] + numbers[middle]) / 2;
    } else {
        return numbers[middle];
    }
}

int main() {
    int numbers[MAX_NUMBERS];
    int num_numbers = 0;

    // Prompt user for number of random numbers to generate
    printf("Enter the number of random numbers to generate (up to %d): ", MAX_NUMBERS);
    scanf("%d", &num_numbers);

    // Generate random numbers
    generate_random_numbers(numbers, num_numbers);

    // Calculate median
    double median = calculate_median(numbers, num_numbers);

    // Print median
    printf("The median is: %.2f\n", median);

    return 0;
}