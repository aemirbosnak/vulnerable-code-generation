//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void display_menu() {
    printf("\n======= Cozy Calculator =======\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Exit\n");
    printf("==============================\n");
    printf("Choose an option: ");
}

void add_numbers() {
    double a, b;
    printf("Enter two numbers to add: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        printf("Oops! Please enter valid numbers.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    printf("The sum is: %.2lf\n", a + b);
}

void subtract_numbers() {
    double a, b;
    printf("Enter two numbers to subtract: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        printf("Oops! Please enter valid numbers.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    printf("The difference is: %.2lf\n", a - b);
}

void multiply_numbers() {
    double a, b;
    printf("Enter two numbers to multiply: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        printf("Oops! Please enter valid numbers.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    printf("The product is: %.2lf\n", a * b);
}

void divide_numbers() {
    double a, b;
    printf("Enter two numbers to divide: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        printf("Oops! Please enter valid numbers.\n");
        while (getchar() != '\n'); // Clear input buffer
        return;
    }
    if (b == 0) {
        printf("Oh no! Dividing by zero is not allowed. Let's try again.\n");
        return;
    }
    printf("The quotient is: %.2lf\n", a / b);
}

int main() {
    int choice;

    while (1) {
        display_menu();
        
        if (scanf("%d", &choice) != 1) {
            printf("Unexpected input! Please use numbers 1-5.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue; // Go back to the top of the loop
        }

        switch (choice) {
            case 1:
                add_numbers();
                break;
            case 2:
                subtract_numbers();
                break;
            case 3:
                multiply_numbers();
                break;
            case 4:
                divide_numbers();
                break;
            case 5:
                printf("Goodbye! Hope to see you again!\n");
                exit(0);
            default:
                printf("Hmm, that's not a valid option. Let's choose again!\n");
                break;
        }
    }

    return 0;
}