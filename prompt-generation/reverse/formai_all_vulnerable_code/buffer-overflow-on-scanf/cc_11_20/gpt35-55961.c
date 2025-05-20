//FormAI DATASET v1.0 Category: Table Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("Welcome to the C Table Game! \n\n");
    
    srand(time(0));
    
    int player_score = 0, computer_score = 0, num_dice_rolls = 0, num_players = 0;
    
    printf("How many players are there (1 or 2)? ");
    scanf("%d", &num_players);
    
    while(num_players != 1 && num_players != 2) {
        printf("Invalid input. Please enter 1 or 2: ");
        scanf("%d", &num_players);
    }
    
    if(num_players == 1) {
        printf("You are playing against the computer.\n");
    } else {
        printf("You are playing against another player.\n");
    }
    
    printf("The game will consist of 10 rounds. Each round, you will roll two dice.\n");
    printf("If the sum of the dice is even, you get 10 points. If it's odd, you get nothing.\n");
    printf("However, if both dice show the same number, you get a bonus of 20 points!\n\n");
    
    for(int round=1; round<=10; round++) {
        printf("Round %d:\n", round);

        if(num_players == 1) {
            printf("Press enter to roll the dice.");
            getchar();
            getchar();
            int player_roll1 = rand() % 6 + 1;
            int player_roll2 = rand() % 6 + 1;
            printf("You rolled a %d and a %d. ", player_roll1, player_roll2);
            int sum = player_roll1 + player_roll2;
            if(sum % 2 == 0) {
                player_score += 10;
                printf("You scored 10 points!\n");
            } else {
                printf("You scored 0 points.\n");
            }
            if(player_roll1 == player_roll2) {
                player_score += 20;
                printf("You got a bonus of 20 points for rolling doubles!\n");
            }
            
            printf("Press enter for the computer's turn.");
            getchar();

            int computer_roll1 = rand() % 6 + 1;
            int computer_roll2 = rand() % 6 + 1;
            printf("The computer rolled a %d and a %d. ", computer_roll1, computer_roll2);
            sum = computer_roll1 + computer_roll2;
            if(sum % 2 == 0) {
                computer_score += 10;
                printf("The computer scored 10 points!\n");
            } else {
                printf("The computer scored 0 points.\n");
            }
            if(computer_roll1 == computer_roll2) {
                computer_score += 20;
                printf("The computer got a bonus of 20 points for rolling doubles!\n");
            }
            
        } else {
            printf("Player 1, it's your turn. Press enter to roll the dice.");
            getchar();
            getchar();
            int player1_roll1 = rand() % 6 + 1;
            int player1_roll2 = rand() % 6 + 1;
            printf("You rolled a %d and a %d. ", player1_roll1, player1_roll2);
            int sum = player1_roll1 + player1_roll2;
            if(sum % 2 == 0) {
                player_score += 10;
                printf("You scored 10 points!\n");
            } else {
                printf("You scored 0 points.\n");
            }
            if(player1_roll1 == player1_roll2) {
                player_score += 20;
                printf("You got a bonus of 20 points for rolling doubles!\n");
            }

            printf("Player 2, it's your turn. Press enter to roll the dice.");
            getchar();
            getchar();
            int player2_roll1 = rand() % 6 + 1;
            int player2_roll2 = rand() % 6 + 1;
            printf("You rolled a %d and a %d. ", player2_roll1, player2_roll2);
            sum = player2_roll1 + player2_roll2;
            if(sum % 2 == 0) {
                computer_score += 10;
                printf("You scored 10 points!\n");
            } else {
                printf("You scored 0 points.\n");
            }
            if(player2_roll1 == player2_roll2) {
                computer_score += 20;
                printf("You got a bonus of 20 points for rolling doubles!\n");
            }
            
        }
    }
    
    printf("\n\nGame over! Here are the final scores:\n");
    
    if(num_players == 1) {
        printf("You: %d\nComputer: %d\n", player_score, computer_score);
        if(player_score > computer_score) {
            printf("You win!\n");
        } else if(player_score < computer_score) {
            printf("The computer wins!\n");
        } else {
            printf("It's a tie!\n");
        }
    } else {
        printf("Player 1: %d\nPlayer 2: %d\n", player_score, computer_score);
        if(player_score > computer_score) {
            printf("Player 1 wins!\n");
        } else if(player_score < computer_score) {
            printf("Player 2 wins!\n");
        } else {
            printf("It's a tie!\n");
        }
    }


    return 0;
}