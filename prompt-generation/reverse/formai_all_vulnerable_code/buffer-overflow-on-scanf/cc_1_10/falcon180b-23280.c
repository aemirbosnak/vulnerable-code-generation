//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: random
/*
 * C Arithmetic Example Program
 * Written by [Your Name Here]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100
#define MIN_VALUE -100
#define MAX_VALUE 100

// Function prototypes
void generate_random_numbers(int numbers[], int size);
void print_numbers(int numbers[], int size);
int sum_of_even_numbers(int numbers[], int size);
double average(int numbers[], int size);

int main() {
    int numbers[MAX_NUMBERS];
    int size;

    printf("Enter the number of random numbers you want to generate (between 1 and %d): ", MAX_NUMBERS);
    scanf("%d", &size);

    if (size < 1 || size > MAX_NUMBERS) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_NUMBERS);
        return 1;
    }

    srand(time(NULL));
    generate_random_numbers(numbers, size);
    print_numbers(numbers, size);

    printf("The sum of even numbers is: %d\n", sum_of_even_numbers(numbers, size));
    printf("The average of all numbers is: %.2f\n", average(numbers, size));

    return 0;
}

void generate_random_numbers(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        numbers[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
}

void print_numbers(int numbers[], int size) {
    printf("Random numbers:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int sum_of_even_numbers(int numbers[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (numbers[i] % 2 == 0) {
            sum += numbers[i];
        }
    }
    return sum;
}

double average(int numbers[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return (double) sum / size;
}