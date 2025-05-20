//Falcon-180B DATASET v1.0 Category: Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operation, result;
    char playAgain;

    srand(time(0)); // Seed the random number generator with the current time
    num1 = rand() % 100 + 1; // Generate a random number between 1 and 100
    num2 = rand() % 100 + 1; // Generate another random number between 1 and 100

    do {
        printf("Welcome to the Math Game!\n\n");
        printf("You have %d and %d. What would you like to do?\n", num1, num2);
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
        scanf("%d", &operation);

        switch (operation) {
            case 1:
                result = num1 + num2;
                printf("The result is %d.\n", result);
                break;
            case 2:
                result = num1 - num2;
                printf("The result is %d.\n", result);
                break;
            case 3:
                result = num1 * num2;
                printf("The result is %d.\n", result);
                break;
            case 4:
                if (num2 == 0) {
                    printf("Error: Cannot divide by zero.\n");
                } else {
                    result = num1 / num2;
                    printf("The result is %d.\n", result);
                }
                break;
            default:
                printf("Invalid operation. Please try again.\n");
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}