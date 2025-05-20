//Falcon-180B DATASET v1.0 Category: Table Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    int i, j, count = 0, max_count = 0;
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int player_guess;
    char play_again;

    srand(time(NULL));

    printf("Welcome to the Table Game!\n");

    while (1) {
        printf("The numbers are shuffled. Guess a number between 1 and %d:\n", SIZE);
        scanf("%d", &player_guess);

        if (player_guess < 1 || player_guess > SIZE) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        for (i = 0; i < SIZE; i++) {
            if (arr[i] == player_guess) {
                count++;
                break;
            }
        }

        if (count == 0) {
            printf("Sorry, the number is not in the table.\n");
        } else {
            printf("Congratulations! You guessed the number in %d tries.\n", count);
            if (count > max_count) {
                max_count = count;
            }
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);

        if (play_again == 'n') {
            break;
        }

        count = 0;
        for (i = 0; i < SIZE; i++) {
            arr[i] = i + 1;
        }
        max_count = 0;
    }

    printf("Thanks for playing! Your highest score was %d.\n", max_count);

    return 0;
}