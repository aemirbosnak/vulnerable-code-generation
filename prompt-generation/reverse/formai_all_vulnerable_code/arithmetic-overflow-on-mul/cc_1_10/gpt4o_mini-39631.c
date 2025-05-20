//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// A peaceful garden program to perform various arithmetic operations
// and display a serene flower garden representation.

void display_welcome_message() {
    printf("Welcome to the Peaceful Garden of Arithmetic!\n");
    printf("Here, we will plant some numbers and watch them bloom into results.\n");
    printf("Let us begin our journey into the world of calculations.\n\n");
}

void display_menu() {
    printf("Please choose an arithmetic operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Square Root\n");
    printf("7. Exit\n");
    printf("Enter your choice (1-7): ");
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0; // We return 0, just to maintain flow; however, division by zero is invalid.
    }
    return (double)a / b;
}

int modulus(int a, int b) {
    return a % b;
}

double square_root(int a) {
    if (a < 0) {
        printf("Error: Cannot compute square root of a negative number.\n");
        return -1; // Negative numbers cannot have a square root in real numbers
    }
    return sqrt(a);
}

void display_flower_garden(double result) {
    printf("\nHere is your flower garden blooming with the result:\n");
    for (int i = 0; i < (int)result; i++) {
        printf("*");
    }
    printf("\nResult: %.2f\n", result);
}

int main() {
    display_welcome_message();

    int choice;
    int num1, num2;
    double result;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        if (choice < 1 || choice > 7) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        if (choice == 7) {
            printf("Thank you for visiting the Peaceful Garden of Arithmetic!\n");
            printf("Have a serene day!\n");
            break;
        }

        printf("Enter the first number: ");
        scanf("%d", &num1);

        if (choice != 6) {
            printf("Enter the second number: ");
            scanf("%d", &num2);
        }

        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("The result of %d + %d is: ", num1, num2);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("The result of %d - %d is: ", num1, num2);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("The result of %d * %d is: ", num1, num2);
                break;
            case 4:
                result = divide(num1, num2);
                printf("The result of %d / %d is: ", num1, num2);
                break;
            case 5:
                result = modulus(num1, num2);
                printf("The result of %d %% %d is: ", num1, num2);
                break;
            case 6:
                result = square_root(num1);
                printf("The square root of %d is: ", num1);
                break;
        }

        display_flower_garden(result);
    }

    return 0;
}