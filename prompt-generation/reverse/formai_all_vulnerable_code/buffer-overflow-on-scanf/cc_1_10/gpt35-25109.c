//FormAI DATASET v1.0 Category: Math exercise ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, result, guess, attempts, level;
    char playAgain = 'y';

    srand(time(NULL));

    printf("Welcome to the Math Exercise Game!\n\n");
    printf("Are you ready for a fun challenge?\n");
    printf("Enter the level of difficulty (1 = easy, 2 = medium, 3 = hard): ");
    scanf("%d", &level);

    while (playAgain == 'y') {
        switch (level) {
            case 1:
                num1 = rand() % 10;
                num2 = rand() % 10;
                result = num1 + num2;
                printf("What is %d + %d?\n", num1, num2);
                break;
            case 2:
                num1 = rand() % 100;
                num2 = rand() % 100;
                result = num1 - num2;
                printf("What is %d - %d?\n", num1, num2);
                break;
            case 3:
                num1 = rand() % 1000;
                num2 = rand() % 1000;
                result = num1 * num2;
                printf("What is %d x %d?\n", num1, num2);
                break;
            default:
                printf("Invalid Input!\n");
                return 0;
        }

        attempts = 0;
        do {
            printf("Enter your answer: ");
            scanf("%d", &guess);

            if (guess == result) {
                printf("You are correct! Congratulations!\n");
                break;
            } else {
                printf("Oops! Try again!\n");
                attempts++;
            }
        } while (attempts < 3);

        if (attempts == 3) {
            printf("You have reached the maximum number of attempts. The correct answer is %d.\n", result);
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    }

    printf("Thank you for playing the Math Exercise Game!\n");
    return 0;
}