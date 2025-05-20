//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0, dice_roll, user_choice, comp_choice, users_turn = 1;
    srand(time(NULL));  // Used to generate random dice rolls

    printf("Welcome to the Dice Game!\n");

    // Loop until one player reaches 100 points
    while (score < 100) {
        dice_roll = rand() % 6 + 1; // Roll the dice
        printf("You rolled a %d.\n", dice_roll);

        // If the user is playing
        if (users_turn) {
            printf("Enter 1 to add to your score or 2 to pass: ");
            scanf("%d", &user_choice);
            // If the user chooses to add to their score
            if (user_choice == 1) {
                score += dice_roll;
                printf("Your current score is %d.\n", score);
                // Check if the user wins
                if (score >= 100) {
                    printf("Congratulations! You won the game!\n");
                    break;
                }
            }
            // If the user chooses to pass
            else if (user_choice == 2) {
                users_turn = 0;
            }
            // If the user enters an invalid choice
            else {
                printf("Invalid choice. Please try again.\n");
            }
        }
        // If the computer is playing
        else {
            // Randomly choose whether to add to the comp's score or pass
            comp_choice = rand() % 2 + 1;
            // If the computer chooses to add to its score
            if (comp_choice == 1) {
                score += dice_roll;
                printf("The computer added %d to its score.\n", dice_roll);
                printf("The computer's current score is %d.\n", score);
                // Check if the computer wins
                if (score >= 100) {
                    printf("Sorry, the computer won the game.\n");
                    break;
                }
            }
            // If the computer chooses to pass
            else {
                users_turn = 1;
                printf("The computer has passed its turn.\n");
            }
        }
    }
    
    return 0;
}