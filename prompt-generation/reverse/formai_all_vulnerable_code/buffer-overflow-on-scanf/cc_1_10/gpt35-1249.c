//FormAI DATASET v1.0 Category: Table Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_choice, computer_choice, round = 0, player_score = 0, computer_score = 0;
    srand(time(NULL)); // seed the random number generator
    
    printf("Welcome to the C Table Game!\n");
    printf("Rules: Choose between 1 and 3 inclusive. The one who chooses the highest number wins the round.\n");
    printf("The winner of the game is the first to reach 5 points. Good luck!\n\n");
    
    while (player_score < 5 && computer_score < 5) {
        round++;
        printf("Round %d\n", round);
        printf("Enter your choice (1-3): ");
        scanf("%d", &player_choice);
        
        // check if player's choice is valid
        while (player_choice < 1 || player_choice > 3) {
            printf("Invalid choice. Enter again (1-3): ");
            scanf("%d", &player_choice);
        }
        
        computer_choice = rand() % 3 + 1;
        printf("Computer chose: %d\n", computer_choice);
        
        // compare choices and update scores
        if (player_choice == computer_choice) {
            printf("This round is a tie.\n");
        } else if (player_choice > computer_choice) {
            printf("You win this round.\n");
            player_score++;
        } else {
            printf("Computer wins this round.\n");
            computer_score++;
        }
        
        printf("Current score: You %d : %d Computer\n\n", player_score, computer_score);
    }
    
    // determine winner and display results
    if (player_score > computer_score) {
        printf("Congratulations! You won the game.\n");
    } else {
        printf("Sorry, you lost the game.\n");
    }
    printf("Final score: You %d : %d Computer\n", player_score, computer_score);
    
    return 0;
}