//Falcon-180B DATASET v1.0 Category: Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0, computer_score = 0, choice, result;
    char play_again;

    do {
        system("clear");
        printf("Welcome to Rock Paper Scissors!\n");
        printf("Player Score: %d\n", player_score);
        printf("Computer Score: %d\n", computer_score);

        printf("\n");
        printf("Choose one:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        scanf("%d", &choice);

        result = rand() % 3;
        if (result == 0) {
            printf("\n");
            printf("Computer chose Rock.\n");
        } else if (result == 1) {
            printf("\n");
            printf("Computer chose Paper.\n");
        } else {
            printf("\n");
            printf("Computer chose Scissors.\n");
        }

        if (choice == result) {
            printf("\n");
            printf("It's a tie!\n");
        } else if ((choice == 0 && result == 2) ||
                   (choice == 1 && result == 0) ||
                   (choice == 2 && result == 1)) {
            printf("\n");
            printf("You win!\n");
            player_score++;
        } else {
            printf("\n");
            printf("You lose!\n");
            computer_score++;
        }

        printf("\n");
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
        printf("\n");
    } while (play_again == 'y' || play_again == 'Y');

    printf("\n");
    printf("Thanks for playing! Final score: Player %d - Computer %d\n", player_score, computer_score);

    return 0;
}