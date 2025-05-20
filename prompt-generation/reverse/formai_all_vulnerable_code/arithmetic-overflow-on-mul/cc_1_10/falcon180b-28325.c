//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: shape shifting
// Shape Shifting Style C Arithmetic Program

#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice, num1, num2, result;

    printf("Welcome to the Shape Shifting Style C Arithmetic Program!\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1: // Addition
            printf("Enter two numbers to add:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 + num2;
            printf("The result is: %d\n", result);
            break;
        case 2: // Subtraction
            printf("Enter two numbers to subtract:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 - num2;
            printf("The result is: %d\n", result);
            break;
        case 3: // Multiplication
            printf("Enter two numbers to multiply:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 * num2;
            printf("The result is: %d\n", result);
            break;
        case 4: // Division
            printf("Enter two numbers to divide:\n");
            scanf("%d %d", &num1, &num2);
            if(num2 == 0) {
                printf("Cannot divide by zero!\n");
            } else {
                result = num1 / num2;
                printf("The result is: %d\n", result);
            }
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

// End of Shape Shifting Style C Arithmetic Program