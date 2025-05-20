//Falcon-180B DATASET v1.0 Category: Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_score = 0;
    int computer_score = 0;
    int choice;
    int dice_result;
    char play_again;

    do {
        printf("Welcome to the game of chance!\n");
        printf("You will roll a dice and the computer will roll a dice.\n");
        printf("Whoever gets the highest number wins!\n");
        printf("Do you want to play? (y/n): ");
        scanf("%c", &play_again);

        if (play_again == 'y' || play_again == 'Y') {
            printf("Rolling dice...\n");
            dice_result = rand() % 6 + 1;
            printf("You rolled a %d!\n", dice_result);

            do {
                printf("The computer is rolling a dice...\n");
                computer_score = rand() % 6 + 1;
            } while (computer_score == dice_result);

            printf("The computer rolled a %d!\n", computer_score);

            if (computer_score > dice_result) {
                printf("You lose this round.\n");
            } else if (computer_score < dice_result) {
                printf("You win this round!\n");
                player_score++;
            } else {
                printf("It's a tie.\n");
            }

            printf("Score: You - %d, Computer - %d\n", player_score, computer_score);
        } else {
            printf("Thanks for playing!\n");
        }

        printf("Do you want to play again? (y/n): ");
        scanf("%c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}