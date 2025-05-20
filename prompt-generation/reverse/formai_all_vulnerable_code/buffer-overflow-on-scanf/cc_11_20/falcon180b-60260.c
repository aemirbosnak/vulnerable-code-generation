//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0, computer_score = 0;
    char player_choice, computer_choice;
    int i = 0;

    while (1) {
        system("clear");
        printf("\n");
        printf("ROCK, PAPER, SCISSORS\n");
        printf("---------------------\n");
        printf("Player Score: %d\n", player_score);
        printf("Computer Score: %d\n", computer_score);
        printf("\n");

        printf("Enter your choice: ");
        scanf("%c", &player_choice);

        srand(time(0));
        int rand_num = rand() % 3;

        if (rand_num == 0) {
            computer_choice = 'r';
        } else if (rand_num == 1) {
            computer_choice = 'p';
        } else {
            computer_choice ='s';
        }

        if (player_choice == computer_choice) {
            printf("It's a tie!\n");
        } else if ((player_choice == 'r' && computer_choice =='s') ||
                   (player_choice =='s' && computer_choice == 'p') ||
                   (player_choice == 'p' && computer_choice == 'r')) {
            printf("You win!\n");
            player_score++;
        } else {
            printf("You lose!\n");
            computer_score++;
        }

        if (player_score == 5) {
            printf("\nPlayer wins!\n");
            break;
        } else if (computer_score == 5) {
            printf("\nComputer wins!\n");
            break;
        }

        i++;
        if (i == 10) {
            printf("\nIt's a draw!\n");
            break;
        }
    }

    return 0;
}