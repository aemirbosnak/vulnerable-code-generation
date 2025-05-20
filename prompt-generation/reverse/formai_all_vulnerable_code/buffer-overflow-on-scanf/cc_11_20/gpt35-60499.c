//FormAI DATASET v1.0 Category: Table Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program is a virtual table game that is played in a medieval style.
It is a 2-player game in which each player rolls a pair of dice and moves 
his/her knight forward on the board accordingly. The first player to reach the 
opponent's castle wins the game. */

int main(void) {
    char player1_name[20], player2_name[20];  // to store player names
    int board_size;  // to store board size chosen by player
    int current_pos1 = 0, current_pos2 = 0;   // to store current positions of players
    int dice1, dice2;  // to store dice rolls for each player
    int player1_win = 0, player2_win = 0;    // to store scores
    int num_turns = 0;  // to store number of turns taken
    
    // Getting input from players
    printf("Welcome to the Medieval Table Game!\n\n");
    printf("Player 1, please enter your name: ");
    scanf("%s", player1_name);
    printf("Player 2, please enter your name: ");
    scanf("%s", player2_name);

    // Displaying instructions and getting board size choice
    printf("\n%s and %s, let's get started!\n\n", player1_name, player2_name);
    printf("Instructions: You will each take turns rolling a pair of dice.\n");
    printf("The sum of the dice rolls dictates how many spaces your knight moves.\n");
    printf("The first player to reach the opponent's castle wins the game.\n\n");
    printf("Please choose the size of the board (from 20 to 50): ");
    scanf("%d", &board_size);

    // Setting up game board with player names and castles
    printf("Here's the game board:\n\n");
    printf("   ");
    for(int i = 1; i <= board_size; i++) {
        printf("|%2d ", i);
    }
    printf("|\n");

    printf(" %s|", player1_name);
    for(int i = 1; i <= board_size; i++) {
        printf("   |");
    }
    printf("   %s|\n", player2_name);

    printf("   ");
    for(int i = 1; i <= board_size; i++) {
        printf("|__ ");
    }
    printf("|\n\n");

    // Game loop
    while(current_pos1 < board_size && current_pos2 < board_size) {
        // Player 1 turn
        num_turns++;
        printf("%s's turn (press enter to roll dice): ", player1_name);
        getchar();
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        printf("Dice roll: %d + %d = %d\n", dice1, dice2, dice1 + dice2);
        current_pos1 += dice1 + dice2;
        if(current_pos1 >= board_size) {
            current_pos1 = board_size;
            player1_win = 1;
        }

        // Displaying game board with player positions
        printf("   ");
        for(int i = 1; i <= board_size; i++) {
            printf("|%2d ", i);
        }
        printf("|\n");

        printf(" %s|", player1_name);
        for(int i = 1; i <= board_size; i++) {
            if(i == current_pos1) {
                printf(" K |");
            }
            else if(i == board_size) {
                printf(" C |");
            }
            else {
                printf("   |");
            }
        }
        printf("   %s|\n", player2_name);

        printf("   ");
        for(int i = 1; i <= board_size; i++) {
            printf("|__ ");
        }
        printf("|\n\n");

        if(player1_win) {
            break;
        }

        // Player 2 turn
        num_turns++;
        printf("%s's turn (press enter to roll dice): ", player2_name);
        getchar();
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        printf("Dice roll: %d + %d = %d\n", dice1, dice2, dice1 + dice2);
        current_pos2 += dice1 + dice2;
        if(current_pos2 >= board_size) {
            current_pos2 = board_size;
            player2_win = 1;
        }

        // Displaying game board with player positions
        printf("   ");
        for(int i = 1; i <= board_size; i++) {
            printf("|%2d ", i);
        }
        printf("|\n");

        printf(" %s|", player1_name);
        for(int i = 1; i <= board_size; i++) {
            if(i == board_size) {
                printf(" C |");
            }
            else {
                printf("   |");
            }
        }
        printf("   %s|\n", player2_name);

        printf("   ");
        for(int i = 1; i <= board_size; i++) {
            printf("|__ ");
        }
        printf("|\n\n");

        if(player2_win) {
            break;
        }
    }

    // Displaying winner and number of turns taken
    if(player1_win) {
        printf("%s wins in %d turns!\n", player1_name, num_turns);
    }
    else {
        printf("%s wins in %d turns!\n", player2_name, num_turns);
    }

    return 0;
}