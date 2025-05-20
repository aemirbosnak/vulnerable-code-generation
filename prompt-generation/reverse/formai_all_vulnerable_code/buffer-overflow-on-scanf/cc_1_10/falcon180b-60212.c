//Falcon-180B DATASET v1.0 Category: Educational ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100
#define MAX_RANGE 1000

// Function prototypes
void generate_numbers(int numbers[], int range);
void print_numbers(int numbers[], int count);
int sum_of_odd_numbers(int numbers[], int count);

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int numbers[MAX_NUMBERS];
    int count = 0;
    int range;

    // Get the range from the user
    printf("Enter the range of the numbers: ");
    scanf("%d", &range);

    // Generate a random number of integers within the given range
    while (count < MAX_NUMBERS && range > 0) {
        numbers[count] = rand() % range;
        count++;
        range -= 10; // Decrease the range for each number generated
    }

    // Print the generated numbers
    printf("\nGenerated numbers:\n");
    print_numbers(numbers, count);

    // Calculate the sum of odd numbers
    int sum = sum_of_odd_numbers(numbers, count);

    printf("\nSum of odd numbers: %d\n", sum);

    return 0;
}

// Function to generate random numbers within the given range
void generate_numbers(int numbers[], int range) {
    for (int i = 0; i < range; i++) {
        numbers[i] = rand() % range;
    }
}

// Function to print the generated numbers
void print_numbers(int numbers[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

// Function to calculate the sum of odd numbers in the array
int sum_of_odd_numbers(int numbers[], int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        if (numbers[i] % 2!= 0) { // Check if the number is odd
            sum += numbers[i];
        }
    }
    return sum;
}