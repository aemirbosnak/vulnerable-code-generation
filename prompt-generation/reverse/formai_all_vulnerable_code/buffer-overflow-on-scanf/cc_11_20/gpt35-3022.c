//FormAI DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int count = 0, data[10], i, guess;

    while (count < 10) {
        int repeat = 0;
        int random_num = rand() % 100;

        for (i = 0; i < count; i++) {
            if (data[i] == random_num) {
                repeat = 1;
                break;
            }
        }

        if (repeat == 0) {
            data[count] = random_num;
            count++;
        }
    }

    printf("Welcome to the Guess the Number game!\n\n");
    printf("The computer has chosen 10 unique random numbers between 0 and 99.\n");
    printf("Try to guess one of them!\n\n");

    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        int correct_guess = 0;
        for (i = 0; i < 10; i++) {
            if (data[i] == guess) {
                printf("Congratulations! You have guessed one of the numbers!\n");
                printf("The number was %d\n", data[i]);
                correct_guess = 1;
                break;
            }
        }

        if (correct_guess == 0) {
            printf("Sorry, that is not one of the numbers.\n");
        }

        printf("\nDo you want to play again? (y/n): ");
        char play_again;
        scanf(" %c", &play_again);

        if (play_again == 'n') {
            printf("Thanks for playing! Goodbye.\n");
            break;
        }
        else if (play_again != 'y') {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }

    return 0;
}