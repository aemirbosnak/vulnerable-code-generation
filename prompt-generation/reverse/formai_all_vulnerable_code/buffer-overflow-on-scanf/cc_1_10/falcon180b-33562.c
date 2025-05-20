//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int num1, num2, result, choice;
    char play_again;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Loop until the user decides to quit
    do {
        // Display the menu
        printf("Welcome to the Math Game!\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected operation
        switch (choice) {
            case 1:
                // Addition
                num1 = rand_num(1, 10);
                num2 = rand_num(1, 10);
                result = num1 + num2;
                printf("Solve this problem: %d + %d = ", num1, num2);
                printf("%d\n", result);
                break;
            case 2:
                // Subtraction
                num1 = rand_num(1, 10);
                num2 = rand_num(1, 10);
                result = num1 - num2;
                printf("Solve this problem: %d - %d = ", num1, num2);
                printf("%d\n", result);
                break;
            case 3:
                // Multiplication
                num1 = rand_num(1, 10);
                num2 = rand_num(1, 10);
                result = num1 * num2;
                printf("Solve this problem: %d x %d = ", num1, num2);
                printf("%d\n", result);
                break;
            case 4:
                // Division
                num1 = rand_num(1, 10);
                num2 = rand_num(1, 10);
                result = num1 / num2;
                printf("Solve this problem: %d / %d = ", num1, num2);
                printf("%d\n", result);
                break;
            case 5:
                printf("Thanks for playing! See you next time!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        // Ask the user if they want to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}