//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0;
    int computer_score = 0;
    int choice;
    int random_number;

    // Seed for random number generator
    srand(time(NULL));

    // Game loop
    while (player_score < 5 && computer_score < 5) {
        printf("Your score: %d\n", player_score);
        printf("Computer score: %d\n", computer_score);

        // Player's turn
        printf("Your turn! Choose rock, paper, or scissors:\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You chose rock.\n");
        } else if (choice == 2) {
            printf("You chose paper.\n");
        } else if (choice == 3) {
            printf("You chose scissors.\n");
        } else {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        // Computer's turn
        random_number = rand() % 3;

        if (random_number == 0) {
            printf("Computer chose rock.\n");
        } else if (random_number == 1) {
            printf("Computer chose paper.\n");
        } else {
            printf("Computer chose scissors.\n");
        }

        // Determine winner
        if (choice == random_number) {
            printf("It's a tie! Try again.\n");
        } else if ((choice == 1 && random_number == 2) ||
                   (choice == 2 && random_number == 1) ||
                   (choice == 3 && random_number == 0)) {
            printf("You win! Your score: %d\n", ++player_score);
        } else {
            printf("Computer wins! Computer score: %d\n", ++computer_score);
        }
    }

    // Game over
    if (player_score == 5) {
        printf("You win the game! Congratulations!\n");
    } else {
        printf("Computer wins the game. Better luck next time!\n");
    }

    return 0;
}