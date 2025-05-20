//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0, computer_score = 0;
    int player_choice, computer_choice;
    char play_again = 'y';

    srand(time(NULL));

    while (play_again == 'y') {
        printf("Player's turn:\n");
        printf("Choose rock, paper, or scissors: ");
        scanf("%d", &player_choice);

        switch (player_choice) {
            case 1:
                printf("You chose rock.\n");
                break;
            case 2:
                printf("You chose paper.\n");
                break;
            case 3:
                printf("You chose scissors.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        int computer_pick = rand() % 3 + 1;

        if (computer_pick == 1) {
            printf("Computer chose rock.\n");
        } else if (computer_pick == 2) {
            printf("Computer chose paper.\n");
        } else {
            printf("Computer chose scissors.\n");
        }

        if (player_choice == computer_pick) {
            printf("It's a tie!\n");
        } else if ((player_choice == 1 && computer_pick == 3) ||
                   (player_choice == 2 && computer_pick == 1) ||
                   (player_choice == 3 && computer_pick == 2)) {
            printf("You win!\n");
            player_score++;
        } else {
            printf("Computer wins!\n");
            computer_score++;
        }

        printf("Score: Player %d - Computer %d\n", player_score, computer_score);
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
    }

    printf("Thanks for playing!\n");
    return 0;
}