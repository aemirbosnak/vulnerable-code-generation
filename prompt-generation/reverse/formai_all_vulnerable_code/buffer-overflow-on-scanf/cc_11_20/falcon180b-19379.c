//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_score = 0;
    int computer_score = 0;
    int choice;
    int computer_choice;
    int round_number = 1;
    int game_over = 0;

    while (!game_over) {
        printf("Round %d\n", round_number);
        printf("Choose rock, paper or scissors: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 3) {
            printf("Invalid choice. Please choose 1, 2 or 3.\n");
            continue;
        }

        computer_choice = rand() % 3 + 1;

        if (choice == computer_choice) {
            printf("It's a tie!\n");
        } else if ((choice == 1 && computer_choice == 2) ||
                   (choice == 2 && computer_choice == 1) ||
                   (choice == 3 && computer_choice == 2) ||
                   (choice == 2 && computer_choice == 3)) {
            printf("You win!\n");
            player_score++;
        } else {
            printf("You lose!\n");
            computer_score++;
        }

        round_number++;

        if (player_score == 5 || computer_score == 5) {
            game_over = 1;
        }
    }

    if (player_score == computer_score) {
        printf("It's a tie game!\n");
    } else if (player_score > computer_score) {
        printf("You win the game!\n");
    } else {
        printf("You lose the game!\n");
    }

    return 0;
}