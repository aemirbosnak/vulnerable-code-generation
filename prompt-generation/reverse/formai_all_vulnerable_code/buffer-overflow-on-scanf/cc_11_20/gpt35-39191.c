//FormAI DATASET v1.0 Category: Table Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw_table(int table[]) {
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", table[1], table[2], table[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", table[4], table[5], table[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", table[7], table[8], table[9]);
    printf("     |     |     \n");
}

int check_win(int table[], char symbol) {
    if (table[1] == symbol && table[2] == symbol && table[3] == symbol) return 1;
    else if (table[4] == symbol && table[5] == symbol && table[6] == symbol) return 1;
    else if (table[7] == symbol && table[8] == symbol && table[9] == symbol) return 1;
    else if (table[1] == symbol && table[4] == symbol && table[7] == symbol) return 1;
    else if (table[2] == symbol && table[5] == symbol && table[8] == symbol) return 1;
    else if (table[3] == symbol && table[6] == symbol && table[9] == symbol) return 1;
    else if (table[1] == symbol && table[5] == symbol && table[9] == symbol) return 1;
    else if (table[3] == symbol && table[5] == symbol && table[7] == symbol) return 1;
    else return 0;
}

int main() {
    int table[10] = {'0','1','2','3','4','5','6','7','8','9'};
    int choice, computer_choice, player_turn = 1, turn_count = 0, game_over = 0;
    char player_symbol, computer_symbol;
    
    srand(time(0)); // seed for random number generator
    
    printf("Welcome to the Brave Tic Tac Toe Game!\n");
    printf("Please choose your symbol (X/O): ");
    scanf("%c", &player_symbol);
    fflush(stdin);
    computer_symbol = (player_symbol == 'X') ? 'O' : 'X'; // computer chooses opposite of player
    
    printf("You will be playing as %c.\n", player_symbol);
    printf("The computer will be playing as %c.\n", computer_symbol);
    printf("Here is the table:\n");
    draw_table(table);
    
    // game loop
    while (!game_over) {
        if (player_turn) {
            printf("It's your turn. Please choose a cell: ");
            scanf("%d", &choice);
            fflush(stdin);
            if (table[choice] == 'X' || table[choice] == 'O') {
                printf("That cell is taken. Please choose again.\n");
                continue; // player must choose again
            }
            table[choice] = player_symbol;
            turn_count++;
            printf("You chose cell number %d.\n", choice);
            draw_table(table);
            if (check_win(table, player_symbol)) {
                printf("Congratulations, you won!\n");
                game_over = 1;
            }
            else if (turn_count == 9) {
                printf("It's a tie!\n");
                game_over = 1;
            }
            player_turn = 0; // switch to computer's turn
        }
        else {
            printf("It's the computer's turn.\n");
            do {
                computer_choice = rand() % 9 + 1;
            } while (table[computer_choice] == 'X' || table[computer_choice] == 'O');
            table[computer_choice] = computer_symbol;
            turn_count++;
            printf("The computer chose cell number %d.\n", computer_choice);
            draw_table(table);
            if (check_win(table, computer_symbol)) {
                printf("Sorry, the computer won.\n");
                game_over = 1;
            }
            else if (turn_count == 9) {
                printf("It's a tie!\n");
                game_over = 1;
            }
            player_turn = 1; // switch to player's turn
        }
    }
    
    printf("Thanks for playing! Goodbye.\n");
    return 0;
}