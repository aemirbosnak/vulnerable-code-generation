//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int randNum(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int num1, num2, operation, result;
    char choice;

    // Seed the random number generator with the current time
    srand(time(NULL));

    do {
        // Prompt the user for two numbers and an operation
        printf("Enter two numbers and an operation (+, -, *, /): ");
        scanf("%d %d %c", &num1, &num2, &operation);

        // Perform the operation and display the result
        switch (operation) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0) {
                    printf("Error: division by zero\n");
                } else {
                    result = num1 / num2;
                }
                break;
            default:
                printf("Invalid operation\n");
                result = 0;
        }

        printf("Result: %d\n", result);

        // Ask the user if they want to continue
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}