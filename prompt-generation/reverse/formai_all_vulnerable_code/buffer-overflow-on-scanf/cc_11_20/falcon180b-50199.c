//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score = 0, computer_score = 0;
    char choice;
    int num_rounds = 0;
    int i;

    srand(time(NULL)); // Initialize random seed

    // Game loop
    while (1) {
        printf("\nRound %d\n", ++num_rounds);
        printf("Choose rock, paper, or scissors: ");
        scanf(" %c", &choice);

        // Player's choice
        if (choice == 'r' || choice == 'R') {
            printf("You chose rock.\n");
        } else if (choice == 'p' || choice == 'P') {
            printf("You chose paper.\n");
        } else if (choice =='s' || choice == 'S') {
            printf("You chose scissors.\n");
        } else {
            printf("Invalid choice. Please choose again.\n");
            continue;
        }

        // Computer's choice
        int computer_choice = rand() % 3;
        if (computer_choice == 0) {
            printf("Computer chose rock.\n");
        } else if (computer_choice == 1) {
            printf("Computer chose paper.\n");
        } else {
            printf("Computer chose scissors.\n");
        }

        // Determine winner
        if (choice == computer_choice) {
            printf("It's a tie!\n");
        } else if ((choice == 'r' || choice == 'R') && computer_choice == 2) {
            printf("You win!\n");
            player_score++;
        } else if ((choice == 'p' || choice == 'P') && computer_choice == 0) {
            printf("You win!\n");
            player_score++;
        } else {
            printf("Computer wins!\n");
            computer_score++;
        }

        // Check for game over
        if (player_score == 5 || computer_score == 5) {
            printf("\nGame over!\n");
            if (player_score == 5) {
                printf("You win!\n");
            } else {
                printf("Computer wins!\n");
            }
            break;
        }
    }

    return 0;
}