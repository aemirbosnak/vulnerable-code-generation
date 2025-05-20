//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declare variables
    int choice;
    int player_score = 0;
    int computer_score = 0;
    srand(time(NULL));
    printf("Welcome to the ultimate game of Rock, Paper, Scissors!\n");
    
    // Game Loop
    while(1) {
        // User input
        printf("\nEnter your choice: \n");
        printf("1 - Rock\n2 - Paper\n3 - Scissors\n");
        scanf("%d", &choice);
        if (choice < 1 || choice > 3) {
            printf("Invalid input! Please choose a number between 1 and 3.\n");
            continue;
        }
        
        // Computer's choice
        int computer_choice = (rand() % 3) + 1;
        if (computer_choice == 1) {
            printf("The computer chose Rock.\n");
        } else if (computer_choice == 2) {
            printf("The computer chose Paper.\n");
        } else {
            printf("The computer chose Scissors.\n");
        }
        
        // Comparison and score assignment
        if (choice == 1 && computer_choice == 2) { // Rock vs Paper
            computer_score++;
            printf("Computer wins!\n");
        } else if (choice == 1 && computer_choice == 3) { // Rock vs Scissors
            player_score++;
            printf("You win!\n");
        } else if (choice == 2 && computer_choice == 1) { // Paper vs Rock
            player_score++;
            printf("You win!\n");
        } else if (choice == 2 && computer_choice == 3) { // Paper vs Scissors
            computer_score++;
            printf("Computer wins!\n");
        } else if (choice == 3 && computer_choice == 1) { // Scissors vs Rock
            computer_score++;
            printf("Computer wins!\n");
        } else if (choice == 3 && computer_choice == 2) { // Scissors vs Paper
            player_score++;
            printf("You win!\n");
        } else { // Same choices
            printf("It's a tie!\n");
        }
        
        // Scoreboard
        printf("SCOREBOARD:\nPlayer: %d\nComputer: %d\n", player_score, computer_score);
        
        // Victory condition
        if (player_score == 5 || computer_score == 5) { // First to 5 wins!
            if (player_score > computer_score) {
                printf("\nGAME OVER! You win!\n");
            } else {
                printf("\nGAME OVER! The computer wins!\n");
            }
            break; // End game loop
        }
    }
    
    return 0;
}