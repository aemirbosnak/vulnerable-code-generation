//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int num1, num2, choice, result;
    char play_again;

    srand(time(NULL)); // Seed the random number generator

    do {
        printf("Welcome to the Arithmetic Game!\n");
        printf("Please select a difficulty level:\n");
        printf("1. Easy\n2. Medium\n3. Hard\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You have chosen Easy level.\n");
                num1 = rand_num(1, 10);
                num2 = rand_num(1, 10);
                break;
            case 2:
                printf("You have chosen Medium level.\n");
                num1 = rand_num(10, 100);
                num2 = rand_num(10, 100);
                break;
            case 3:
                printf("You have chosen Hard level.\n");
                num1 = rand_num(100, 1000);
                num2 = rand_num(100, 1000);
                break;
            default:
                printf("Invalid choice. Exiting...\n");
                exit(0);
        }

        printf("The two numbers are: %d and %d\n", num1, num2);
        printf("Enter your answer: ");
        scanf("%d", &result);

        if (result == num1 + num2) {
            printf("Correct! You win!\n");
        } else {
            printf("Incorrect. The correct answer is %d.\n", num1 + num2);
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}