//FormAI DATASET v1.0 Category: Table Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Defining the constants
#define ROWS 3
#define COLUMNS 3
#define MIN_MOVES 0
#define MAX_MOVES 8

// Defining the board
char board[ROWS][COLUMNS];

// Defining the players
char player1 = 'X';
char player2 = 'O';

// Function for printing the board
void print_board() {
    printf("\n");
    printf("\t %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("\t---|---|---\n");
    printf("\t %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("\t---|---|---\n");
    printf("\t %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function for checking if a position is empty or not
bool check_empty(int row, int column) {
    if (board[row][column] == ' ')
        return true;
    else
        return false;
}

// Function for checking if there is a winner
bool is_winner(char player) {
    int i;
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }
    for (i = 0; i < COLUMNS; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// Function for checking if the game is tied
bool is_tied() {
    int i;
    int j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

// Function for playing the game
void play_game() {
    int row;
    int column;
    int move_counter = 0;
    char player = player1;
    bool game_over = false;
    srand(time(0));
    int random_number = rand() % 2 + 1;
    if (random_number == 1)
        player = player1;
    else
        player = player2;
    while (!game_over) {
        print_board();
        printf("Player %c's turn\n", player);
        printf("Enter the row and column where you want to place your mark\n");
        scanf("%d %d", &row, &column);
        while (row < 0 || column < 0 || row > ROWS - 1 || column > COLUMNS - 1 || !check_empty(row, column)) {
            printf("Invalid move. Enter the row and column where you want to place your mark\n");
            scanf("%d %d", &row, &column);
        }
        board[row][column] = player;
        move_counter++;
        if (is_winner(player)) {
            print_board();
            printf("Player %c wins!\n", player);
            game_over = true;
        }
        else if (is_tied()) {
            print_board();
            printf("It's a tie!\n");
            game_over = true;
        }
        else if (move_counter == MAX_MOVES) {
            print_board();
            printf("It's a tie!\n");
            game_over = true;
        }
        else {
            if (player == player1)
                player = player2;
            else
                player = player1;
        }
    }
}

// Main function
int main() {
    int choice;
    printf("|----------------------------------------|\n");
    printf("|                                        |\n");
    printf("|            Welcome to Tic Tac Toe       |\n");
    printf("|                                        |\n");
    printf("|----------------------------------------|\n\n");
    
    do
    {
        printf("|----------------------------------------|\n");
        printf("|                Main Menu               |\n");
        printf("|----------------------------------------|\n");
        printf("|                                        |\n");
        printf("|           1. Play Tic Tac Toe           |\n");
        printf("|           2. Exit                       |\n");
        printf("|                                        |\n");
        printf("|----------------------------------------|\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                // Play the game
                printf("\nGet ready to play!\n\n");
                printf("The game board is as follows:\n\n");
                printf("\t 0 | 1 | 2\n");
                printf("\t---|---|---\n");
                printf("\t 3 | 4 | 5\n");
                printf("\t---|---|---\n");
                printf("\t 6 | 7 | 8\n\n");
                printf("Player 1 is X and Player 2 is O\n\n");
                printf("Press any key to continue\n");
                getchar();
                play_game();
                break;
            case 2:
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again\n");
        }
    } while(choice != 2);
    return 0;
}