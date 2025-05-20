//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int num1, num2, choice;
    double result;

    srand(time(NULL)); // Initialize random seed

    // Generate two random numbers between 1 and 100
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;

    printf("Welcome to the Math Exercise Program!\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            result = num1 + num2;
            printf("The result is: %.2f\n", result);
            break;
        case 2:
            result = num1 - num2;
            printf("The result is: %.2f\n", result);
            break;
        case 3:
            result = num1 * num2;
            printf("The result is: %.2f\n", result);
            break;
        case 4:
            if(num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                result = num1 / num2;
                printf("The result is: %.2f\n", result);
            }
            break;
        default:
            printf("Invalid choice. Please choose a valid operation.\n");
    }

    return 0;
}