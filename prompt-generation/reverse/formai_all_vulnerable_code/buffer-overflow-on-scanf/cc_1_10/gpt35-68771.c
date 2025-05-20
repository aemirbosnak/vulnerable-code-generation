//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: protected
#include <stdio.h>
#include <stdlib.h>

/*
* This program calculates the average of a set of numbers using dynamic memory allocation
* while implementing a protected style technique to ensure the program does not crash
* due to memory errors such as segmentation faults and double frees.
*/

#define MAX_NUMBERS 100

double* allocate_memory(int num);
double calculate_avg(double* numbers, int num);
void free_memory(double* numbers);

int main() {
    int num = 0;
    double* numbers = NULL;

    // Prompt user for the number of inputs
    printf("Enter the number of inputs: ");
    scanf("%d", &num);

    // Allocate memory for the numbers
    numbers = allocate_memory(num);

    // Prompt user for the numbers
    printf("Enter the numbers: ");
    for (int i = 0; i < num; i++) {
        scanf("%lf", &numbers[i]);
    }

    // Calculate the average of the numbers
    double avg = calculate_avg(numbers, num);
    printf("The average is %.2lf\n", avg);

    // Free the dynamically allocated memory
    free_memory(numbers);

    return 0;
}

/*
* Allocates memory for a set of numbers.
* Uses a protected style technique to ensure no errors occur during allocation.
*/
double* allocate_memory(int num) {
    double* numbers = NULL;
    numbers = calloc(num, sizeof(double));
    if (numbers == NULL) {
        printf("Memory allocation error: Could not allocate memory for the set of numbers.");
        exit(1);
    }

    return numbers;
}

/*
* Calculates the average of a set of numbers.
* Uses a protected style technique to ensure no errors occur during calculation.
*/
double calculate_avg(double* numbers, int num) {
    double sum = 0;
    for (int i = 0; i < num; i++) {
        sum += numbers[i];
    }

    double avg = sum / num;
    if (isnan(avg) || isinf(avg)) {
        printf("Error: Division by zero or infinity occurred! Could not calculate the average of the numbers.");
        exit(1);
    }

    return avg;
}

/*
* Frees memory previously allocated for a set of numbers.
* Uses a protected style technique to ensure no errors occur during deallocation.
*/
void free_memory(double* numbers) {
    free(numbers);
    numbers = NULL;
}