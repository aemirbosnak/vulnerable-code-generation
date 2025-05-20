//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print the Tic Tac Toe board
void print_board(char board[][3]) {
    printf("\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(j==2) {
                printf(" %c \n", board[i][j]);
            } else {
                printf(" %c |", board[i][j]);
            }
        }
        if(i!=2) {
            printf("-----------\n");
        }
    }
}

// Function to check if the game is over
int game_over(char board[][3]) {
    // Check rows
    for(int i=0; i<3; i++) {
        if(board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if(board[i][0] == 'X') {
                return 1;
            } else {
                return 2;
            }
        }
    }
    
    // Check columns
    for(int i=0; i<3; i++) {
        if(board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if(board[0][i] == 'X') {
                return 1;
            } else {
                return 2;
            }
        }
    }
    
    // Check diagonals
    if(board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if(board[0][0] == 'X') {
            return 1;
        } else {
            return 2;
        }
    }
    if(board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if(board[0][2] == 'X') {
            return 1;
        } else {
            return 2;
        }
    }
    
    // Check if the board is full
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == '-') {
                return 0;
            }
        }
    }
    
    // If none of the above conditions are true, then the game is still in progress
    return -1;
}

// Function to get the computer's move
void get_computer_move(char board[][3], int *row, int *col) {
    int corner_moves[4][2] = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
    int side_moves[4][2] = {{0, 1}, {1, 0}, {1, 2}, {2, 1}};
    
    // Check if the computer can win in the next move
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == '-') {
                board[i][j] = 'O';
                if(game_over(board) == 2) {
                    *row = i;
                    *col = j;
                    return;
                } else {
                    board[i][j] = '-';
                }
            }
        }
    }
    
    // Check if the player can win in the next move
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == '-') {
                board[i][j] = 'X';
                if(game_over(board) == 1) {
                    *row = i;
                    *col = j;
                    board[i][j] = 'O';
                    return;
                } else {
                    board[i][j] = '-';
                }
            }
        }
    }
    
    // If neither the computer nor the player can win in the next move, then choose a corner if available
    for(int i=0; i<4; i++) {
        if(board[corner_moves[i][0]][corner_moves[i][1]] == '-') {
            *row = corner_moves[i][0];
            *col = corner_moves[i][1];
            return;
        }
    }
    
    // If no corners are available, then choose a side
    for(int i=0; i<4; i++) {
        if(board[side_moves[i][0]][side_moves[i][1]] == '-') {
            *row = side_moves[i][0];
            *col = side_moves[i][1];
            return;
        }
    }
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };
    int player_row, player_col, computer_row, computer_col;
    
    // Game loop
    while(true) {
        // Player's move
        printf("\nYour turn!\n");
        printf("Enter row (0-2): ");
        scanf("%d", &player_row);
        printf("Enter column (0-2): ");
        scanf("%d", &player_col);
        while(board[player_row][player_col] != '-') {
            printf("\nInvalid move! That cell is already occupied.\n");
            printf("Enter row (0-2): ");
            scanf("%d", &player_row);
            printf("Enter column (0-2): ");
            scanf("%d", &player_col);
        }
        board[player_row][player_col] = 'X';
        print_board(board);
        if(game_over(board) == 1) {
            printf("\nCongratulations! You won!\n");
            break;
        }
        if(game_over(board) == 0) {
            printf("\nGame over! It's a draw.\n");
            break;
        }
        
        // Computer's move
        printf("\nComputer's turn.\n");
        get_computer_move(board, &computer_row, &computer_col);
        board[computer_row][computer_col] = 'O';
        print_board(board);
        if(game_over(board) == 2) {
            printf("\nSorry, you lost. Better luck next time!\n");
            break;
        }
        if(game_over(board) == 0) {
            printf("\nGame over! It's a draw.\n");
            break;
        }
    }
    
    return 0;
}