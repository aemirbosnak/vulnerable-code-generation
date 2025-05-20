//FormAI DATASET v1.0 Category: Table Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to roll a die */
int roll_die(){
    return rand() % 6 + 1;
}

int main(){
    // Set up random seed
    srand(time(NULL));

    // Initialize game variables
    int player1_score = 0;
    int player2_score = 0;
    int current_player = 1;

    // Main game loop
    while(player1_score < 100 && player2_score < 100){

        int roll = roll_die();

        // Check if player wants to roll or hold
        char choice;
        printf("Player %d: Roll (r) or Hold (h)? ", current_player);
        scanf(" %c", &choice);

        // Handle user input
        if(choice == 'r'){
            printf("Player %d rolled a %d\n", current_player, roll);

            // Add score to player's total score
            if(current_player == 1){
                player1_score += roll;
            }
            else{
                player2_score += roll;
            }

            // Switch to other player
            if(current_player == 1){
                current_player = 2;
            }
            else{
                current_player = 1;
            }

        }
        else if(choice == 'h'){
            printf("Player %d holds.\n", current_player);

            // Switch to other player
            if(current_player == 1){
                current_player = 2;
            }
            else{
                current_player = 1;
            }

        }
        else{
            printf("Invalid input. Please try again.\n");
        }

        // Print current scores
        printf("Player 1: %d\n", player1_score);
        printf("Player 2: %d\n", player2_score);
        printf("\n");
    }

    // Determine winner and print message
    if(player1_score >= 100){
        printf("Player 1 wins!\n");
    }
    else{
        printf("Player 2 wins!\n");
    }

    return 0;
}