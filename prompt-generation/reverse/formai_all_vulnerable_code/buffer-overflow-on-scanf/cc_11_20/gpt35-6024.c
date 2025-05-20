//FormAI DATASET v1.0 Category: Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int player_choice, computer_choice;

    printf("Welcome to the game of rock-paper-scissors!\n");

    while(1) {
        printf("\nEnter your choice (1 for rock, 2 for paper, 3 for scissors): ");
        scanf("%d", &player_choice);

        // Input validation
        if(player_choice < 1 || player_choice > 3) {
            printf("Invalid input, try again!\n");
            continue;
        }

        // Generate random computer choice
        srand(time(NULL));
        computer_choice = rand() % 3 + 1;

        printf("You chose %d and computer chose %d\n", player_choice, computer_choice);

        // Result calculation
        if(player_choice == computer_choice) {
            printf("It's a tie!\n");
        }
        else if((player_choice == 1 && computer_choice == 3) ||
                (player_choice == 2 && computer_choice == 1) ||
                (player_choice == 3 && computer_choice == 2)) {
            printf("You win!\n");
        }
        else {
            printf("You lose!\n");
        }

        printf("Do you want to play again? (1 for yes, 0 for no): ");
        scanf("%d", &player_choice);

        if(player_choice == 0) {
            break;
        }
    }

    printf("Thank you for playing!\n");
    return 0;
}