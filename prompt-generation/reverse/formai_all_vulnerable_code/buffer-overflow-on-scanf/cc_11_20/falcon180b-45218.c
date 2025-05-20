//Falcon-180B DATASET v1.0 Category: Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_score = 0;
    int computer_score = 0;
    int choice;
    int roll;
    int round = 1;
    char play_again;

    while (1) {
        printf("Round %d\n", round);
        printf("Enter your choice (1 for rock, 2 for paper, 3 for scissors): ");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("Invalid choice.\n");
                return 0;
        }

        roll = rand() % 3;
        printf("Computer chose ");
        if (roll == 0) {
            printf("rock.\n");
        } else if (roll == 1) {
            printf("paper.\n");
        } else {
            printf("scissors.\n");
        }

        if (roll == choice) {
            printf("It's a tie.\n");
        } else if ((roll == 0 && choice == 2) || (roll == 1 && choice == 3) || (roll == 2 && choice == 0)) {
            printf("You win!\n");
            player_score++;
        } else {
            printf("You lose.\n");
            computer_score++;
        }

        printf("Score: You - %d, Computer - %d\n", player_score, computer_score);

        if (player_score >= 5) {
            printf("You win the game!\n");
            break;
        } else if (computer_score >= 5) {
            printf("Computer wins the game!\n");
            break;
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
        if (play_again == 'n') {
            break;
        }
        round++;
    }

    return 0;
}