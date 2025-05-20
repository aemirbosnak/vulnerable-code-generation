//Falcon-180B DATASET v1.0 Category: Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_score = 0;
    int computer_score = 0;
    char choice;

    while (1) {
        printf("Player Score: %d\nComputer Score: %d\n", player_score, computer_score);
        printf("Choose rock, paper or scissors: ");
        scanf("%c", &choice);

        if (choice!= 'r' && choice!= 'p' && choice!='s') {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        int computer_choice = rand() % 3;

        if (computer_choice == 0) {
            computer_choice = 'r';
        } else if (computer_choice == 1) {
            computer_choice = 'p';
        } else {
            computer_choice ='s';
        }

        printf("Computer chooses: %c\n", computer_choice);

        if (choice == computer_choice) {
            printf("It's a tie!\n");
        } else if ((choice == 'r' && computer_choice == 'p') ||
                   (choice == 'p' && computer_choice =='s') ||
                   (choice =='s' && computer_choice == 'r')) {
            printf("You win!\n");
            player_score++;
        } else {
            printf("You lose!\n");
            computer_score++;
        }

        if (player_score == 5 || computer_score == 5) {
            printf("Game over! Player score: %d Computer score: %d\n", player_score, computer_score);
            break;
        }
    }

    return 0;
}