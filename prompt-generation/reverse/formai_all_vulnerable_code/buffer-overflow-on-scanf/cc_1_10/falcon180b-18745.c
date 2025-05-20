//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Recursive function to calculate factorial
int factorial(int n);

int main() {

    int num1, num2, choice;

    // Menu-driven program to perform arithmetic operations
    do {
        printf("\n\nMENU\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Factorial\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: // Addition
                printf("\nEnter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("%.0f + %.0f = %.0f\n", num1, num2, num1 + num2);
                break;
            case 2: // Subtraction
                printf("\nEnter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("%.0f - %.0f = %.0f\n", num1, num2, num1 - num2);
                break;
            case 3: // Multiplication
                printf("\nEnter two numbers: ");
                scanf("%d %d", &num1, &num2);
                printf("%.0f * %.0f = %.0f\n", num1, num2, num1 * num2);
                break;
            case 4: // Division
                printf("\nEnter two numbers: ");
                scanf("%d %d", &num1, &num2);
                if(num2!= 0) {
                    printf("%.0f / %.0f = %.2f\n", num1, num2, (float)num1 / (float)num2);
                } else {
                    printf("Division by zero is not allowed!\n");
                }
                break;
            case 5: // Factorial
                printf("\nEnter a number: ");
                scanf("%d", &num1);
                printf("Factorial of %d = %d\n", num1, factorial(num1));
                break;
            case 6: // Exit
                printf("\nExiting...\n");
                break;
            default: // Invalid choice
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice!= 6);

    return 0;
}

// Recursive function to calculate factorial
int factorial(int n) {
    if(n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}