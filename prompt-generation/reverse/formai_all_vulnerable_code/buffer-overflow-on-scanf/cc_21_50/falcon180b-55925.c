//Falcon-180B DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_score = 0, computer_score = 0;
    char choice;

    do {
        printf("Choose rock, paper or scissors:\n");
        scanf("%c", &choice);

        if (choice!= 'r' && choice!= 'p' && choice!='s') {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        int computer_choice = rand() % 3;

        if (computer_choice == 0) {
            printf("Computer chooses rock.\n");
        } else if (computer_choice == 1) {
            printf("Computer chooses paper.\n");
        } else {
            printf("Computer chooses scissors.\n");
        }

        if (choice == 'r' && computer_choice == 2) {
            printf("You win! Rock crushes scissors.\n");
            player_score++;
        } else if (choice == 'p' && computer_choice == 0) {
            printf("You win! Paper covers rock.\n");
            player_score++;
        } else if (choice =='s' && computer_choice == 1) {
            printf("You win! Scissors cuts paper.\n");
            player_score++;
        } else if (choice == 'r' && computer_choice == 1) {
            printf("You lose! Paper covers rock.\n");
            computer_score++;
        } else if (choice == 'p' && computer_choice == 2) {
            printf("You lose! Scissors cuts paper.\n");
            computer_score++;
        } else if (choice =='s' && computer_choice == 0) {
            printf("You lose! Rock crushes scissors.\n");
            computer_score++;
        } else {
            printf("It's a tie!\n");
        }

        printf("Score: You - %d, Computer - %d\n\n", player_score, computer_score);
    } while (player_score!= 5 && computer_score!= 5);

    if (player_score == 5) {
        printf("You win the game!\n");
    } else {
        printf("Computer wins the game!\n");
    }

    return 0;
}