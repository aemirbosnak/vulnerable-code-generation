//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: immersive
#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    float num1, num2, result;

    printf("Welcome to the C Scientific Calculator\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Trigonometric functions\n");
    printf("6. Logarithmic functions\n");
    printf("7. Exponential functions\n");
    printf("Select the desired operation: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nEnter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
            result = num1 + num2;
            printf("Result: %.2f\n", result);
            break;
        case 2:
            // code for subtraction operation
            break;
        case 3:
            // code for multiplication operation
            break;
        case 4:
            // code for division operation
            break;
        case 5:
            // code for trigonometric functions
            break;
        case 6:
            // code for logarithmic functions
            break;
        case 7:
            // code for exponential functions
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}