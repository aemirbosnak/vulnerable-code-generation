//FormAI DATASET v1.0 Category: Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    printf("Welcome to the Ultimate Rock-Paper-Scissors Game!\n");
    printf("To play, simply enter your move (rock, paper, or scissors) when prompted. Enter 'quit' to exit the game.\n");

    char user_input[10];
    bool play_again = true;
    int wins = 0;
    int losses = 0;
    int ties = 0;

    while (play_again){
        printf("\n");
        printf("Enter your move: ");
        scanf("%s", user_input);
        printf("\n");

        if(strcmp(user_input, "quit") == 0){
            printf("Thanks for playing! Final score - Wins: %d  Losses: %d  Ties: %d\n", wins, losses, ties);
            return 0;
        }
        else if(strcmp(user_input, "rock") == 0){
            printf("You chose rock.\n");
            int computer_move = rand() % 3; // 0 is rock, 1 is paper, 2 is scissors
            if(computer_move == 0){
                printf("Computer chose rock.\nIt's a tie!\n");
                ties++;
            }
            else if(computer_move == 1){
                printf("Computer chose paper.\nYou lose!\n");
                losses++;
            }
            else if(computer_move == 2){
                printf("Computer chose scissors.\nYou win!\n");
                wins++;
            }
        }
        else if(strcmp(user_input, "paper") == 0){
            printf("You chose paper.\n");
            int computer_move = rand() % 3; // 0 is rock, 1 is paper, 2 is scissors
            if(computer_move == 0){
                printf("Computer chose rock.\nYou win!\n");
                wins++;
            }
            else if(computer_move == 1){
                printf("Computer chose paper.\nIt's a tie!\n");
                ties++;
            }
            else if(computer_move == 2){
                printf("Computer chose scissors.\nYou lose!\n");
                losses++;
            }
        }
        else if(strcmp(user_input, "scissors") == 0){
            printf("You chose scissors.\n");
            int computer_move = rand() % 3; // 0 is rock, 1 is paper, 2 is scissors
            if(computer_move == 0){
                printf("Computer chose rock.\nYou lose!\n");
                losses++;
            }
            else if(computer_move == 1){
                printf("Computer chose paper.\nYou win!\n");
                wins++;
            }
            else if(computer_move == 2){
                printf("Computer chose scissors.\nIt's a tie!\n");
                ties++;
            }
        }
        else{
            printf("Invalid move. Try again!\n");
        }
        printf("Current score - Wins: %d  Losses: %d  Ties: %d\n", wins, losses, ties);
    }
    return 0;
}