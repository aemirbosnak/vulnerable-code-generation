//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // Seeds the random number generator with current time

    int player_score = 0;
    int computer_score = 0;
    int tie_score = 0;
    
    printf("Welcome to Rock-Paper-Scissors game!\n");

    while(1) { // Loops until user quits the game

        int player_choice, computer_choice;

        printf("\nSelect your move:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("4. Quit game\n");

        printf("Your choice: ");
        scanf("%d", &player_choice);

        if(player_choice == 4) { // End game if user quits
            printf("\nThanks for playing!\n");
            break;
        }

        if(player_choice < 1 || player_choice > 3) {
            printf("\nInvalid choice! Please try again.\n");
            continue;
        }

        computer_choice = rand() % 3 + 1; // Generate random choice for computer

        printf("Computer chose ");

        switch(computer_choice) {
            case 1: printf("Rock\n"); break;
            case 2: printf("Paper\n"); break;
            case 3: printf("Scissors\n"); break;
        }

        if(player_choice == computer_choice) {
            printf("It's a tie!\n");
            tie_score += 1;
        }
        else if(player_choice == 1 && computer_choice == 3) {
            printf("You won!\n");
            player_score += 1;
        }
        else if(player_choice == 2 && computer_choice == 1) {
            printf("You won!\n");
            player_score += 1;
        }
        else if(player_choice == 3 && computer_choice == 2) {
            printf("You won!\n");
            player_score += 1;
        }
        else {
            printf("You lost!\n");
            computer_score += 1;
        }

        printf("\nScoreboard: \n");
        printf("Player: %d\n", player_score);
        printf("Computer: %d\n", computer_score);
        printf("Ties: %d\n", tie_score);
    }

    return 0;
}