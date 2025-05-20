//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NUMBERS 100

int main() {
    int num_of_numbers, i, j;
    double numbers[MAX_NUMBERS];
    int choice;
    int sum = 0;
    double product = 1;
    double average = 0;

    srand(time(NULL));

    // Ask the user how many numbers they want to add
    printf("Enter the number of numbers you want to add: ");
    scanf("%d", &num_of_numbers);

    // Get the numbers from the user
    for(i = 0; i < num_of_numbers; i++) {
        numbers[i] = rand() % 100;
        sum += numbers[i];
    }

    // Calculate the average
    average = (double)sum / num_of_numbers;

    // Ask the user what arithmetic operation they want to perform
    printf("Enter the arithmetic operation you want to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            // Addition
            printf("The sum of the numbers is: %d\n", sum);
            break;
        case 2:
            // Subtraction
            printf("The difference between the numbers is: %d\n", sum);
            break;
        case 3:
            // Multiplication
            product = 1;
            for(i = 0; i < num_of_numbers; i++) {
                product *= numbers[i];
            }
            printf("The product of the numbers is: %lf\n", product);
            break;
        case 4:
            // Division
            printf("The result of the division is: %lf\n", ((double)sum / num_of_numbers));
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}