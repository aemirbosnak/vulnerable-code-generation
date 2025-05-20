//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int num1, num2, result, choice;
    char play_again;

    srand(time(NULL)); // Seed the random number generator with current time

    do {
        printf("Welcome to the Exciting World of Arithmetic!\n\n");
        printf("Please choose an operation:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers to add:\n");
                scanf("%d %d", &num1, &num2);
                result = num1 + num2;
                printf("The result is %d.\n\n", result);
                break;
            case 2:
                printf("Enter two numbers to subtract:\n");
                scanf("%d %d", &num1, &num2);
                result = num1 - num2;
                printf("The result is %d.\n\n", result);
                break;
            case 3:
                printf("Enter two numbers to multiply:\n");
                scanf("%d %d", &num1, &num2);
                result = num1 * num2;
                printf("The result is %d.\n\n", result);
                break;
            case 4:
                printf("Enter two numbers to divide:\n");
                scanf("%d %d", &num1, &num2);
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n\n");
                } else {
                    result = num1 / num2;
                    printf("The result is %d.\n\n", result);
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}