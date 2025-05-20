//Falcon-180B DATASET v1.0 Category: Table Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_score = 0;
    int computer_score = 0;
    char choice;
    int roll;
    int player_choice;
    int computer_choice;

    // Roll dice
    roll = rand() % 6 + 1;

    // Player's turn
    printf("You rolled a %d.\n", roll);
    do {
        printf("Do you want to roll again? (y/n): ");
        scanf("%c", &choice);
    } while (choice!= 'n');

    // Computer's turn
    computer_roll:
        computer_score += roll;
        printf("Computer rolled a %d. Computer's score is now %d.\n", roll, computer_score);

        if (computer_score >= 21) {
            printf("Computer wins!\n");
            return 0;
        }

        do {
            printf("Do you want to roll again? (y/n): ");
            scanf("%c", &choice);
        } while (choice!= 'n');

    // Player's turn
    player_roll:
        player_score += roll;
        printf("Your score is now %d.\n", player_score);

        if (player_score >= 21) {
            printf("You win!\n");
            return 0;
        }

        do {
            printf("Do you want to roll again? (y/n): ");
            scanf("%c", &choice);
        } while (choice!= 'n');

    // Determine winner
    if (player_score > computer_score) {
        printf("You win!\n");
    } else if (computer_score > player_score) {
        printf("Computer wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}