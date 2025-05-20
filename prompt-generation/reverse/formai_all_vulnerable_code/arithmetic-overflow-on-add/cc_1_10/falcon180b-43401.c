//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a multiplication table
void print_table(int num) {
    printf("\nMultiplication table for %d:\n", num);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }
}

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    int num1, num2;
    char choice;

    // Prompt the user to enter two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Prompt the user to choose an operation
    printf("Choose an operation:\n");
    printf("A. Addition\n");
    printf("B. Subtraction\n");
    printf("C. Multiplication\n");
    printf("D. Division\n");
    scanf(" %c", &choice);

    // Perform the chosen operation
    switch (choice) {
        case 'A':
            printf("Result: %d\n", num1 + num2);
            break;
        case 'B':
            printf("Result: %d\n", num1 - num2);
            break;
        case 'C':
            printf("Result: %d\n", num1 * num2);
            print_table(num1);
            break;
        case 'D':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
            } else {
                printf("Result: %.2f\n", (float)num1 / (float)num2);
            }
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}