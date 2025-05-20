//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int num1, num2, operation;
    double result;
    char input[10];

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Loop until the user decides to quit
    while (1) {
        // Generate a random operation
        operation = rand() % 4;

        // Generate two random numbers
        num1 = rand() % 100;
        num2 = rand() % 100;

        // Perform the operation and store the result
        switch (operation) {
            case 0:
                result = num1 + num2;
                break;
            case 1:
                result = num1 - num2;
                break;
            case 2:
                result = num1 * num2;
                break;
            case 3:
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                    continue;
                }
                result = num1 / num2;
                break;
            default:
                printf("Error: Invalid operation.\n");
                continue;
        }

        // Print the result
        printf("Result: %.2f\n", result);

        // Ask the user if they want to continue
        printf("Do you want to continue? (y/n): ");
        scanf("%s", input);
        if (input[0] == 'n' || input[0] == 'N') {
            break;
        }
    }

    return 0;
}