//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY ' '

void print_board(char board[3][3]) {
    printf("Current board:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

void initialize_board(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = EMPTY;
        }
    }
}

int check_winner(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY)
            return board[i][0];

        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY)
            return board[0][i];
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY)
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY)
        return board[0][2];

    return 0; // No winner yet!
}

int is_board_full(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY)
                return 0; // Found an empty spot
        }
    }
    return 1; // Board is full
}

void player_move(char board[3][3]) {
    int row, col;
    while (1) {
        printf("Enter your move (row and column, 0-2): ");
        scanf("%d %d", &row, &col);
        
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == EMPTY) {
            board[row][col] = PLAYER_X;
            break; // Valid move, exit the loop
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
}

void ai_move(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PLAYER_O;
                if (check_winner(board) == PLAYER_O) {
                    printf("AI places O at (%d, %d)\n", i, j);
                    return;
                } else {
                    board[i][j] = EMPTY; // Reset the move
                }
            }
        }
    }

    // If no winning move is found, place in the first empty spot
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PLAYER_O;
                printf("AI places O at (%d, %d)\n", i, j);
                return;
            }
        }
    }
}

int main() {
    char board[3][3];
    initialize_board(board);
    
    printf("Welcome to Tic Tac Toe!\n");
    print_board(board);

    while (1) {
        player_move(board);
        print_board(board);
        
        if (check_winner(board) == PLAYER_X) {
            printf("Congratulations! You win!\n");
            break;
        }

        if (is_board_full(board)) {
            printf("It's a draw! No more moves left.\n");
            break;
        }

        ai_move(board);
        print_board(board);

        if (check_winner(board) == PLAYER_O) {
            printf("Oh no! The AI wins! Better luck next time!\n");
            break;
        }

        if (is_board_full(board)) {
            printf("It's a draw! No more moves left.\n");
            break;
        }
    }

    printf("Thank you for playing Tic Tac Toe! Have a great day!\n");
    return 0;
}