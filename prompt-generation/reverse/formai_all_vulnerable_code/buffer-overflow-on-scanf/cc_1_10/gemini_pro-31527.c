//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 3

typedef struct {
    int x;
    int y;
} Move;

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char turn;
} Game;

bool is_valid_move(Game *game, Move move) {
    return move.x >= 0 && move.x < BOARD_SIZE &&
           move.y >= 0 && move.y < BOARD_SIZE &&
           game->board[move.x][move.y] == ' ';
}

void make_move(Game *game, Move move) {
    game->board[move.x][move.y] = game->turn;
    game->turn = game->turn == 'X' ? 'O' : 'X';
}

bool is_winner(Game *game) {
    int i, j;
    
    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        if (game->board[i][0] != ' ' &&
            game->board[i][0] == game->board[i][1] &&
            game->board[i][1] == game->board[i][2]) {
            return true;
        }
    }
    
    // Check columns
    for (j = 0; j < BOARD_SIZE; j++) {
        if (game->board[0][j] != ' ' &&
            game->board[0][j] == game->board[1][j] &&
            game->board[1][j] == game->board[2][j]) {
            return true;
        }
    }
    
    // Check diagonals
    if (game->board[0][0] != ' ' &&
        game->board[0][0] == game->board[1][1] &&
        game->board[1][1] == game->board[2][2]) {
        return true;
    }
    if (game->board[0][2] != ' ' &&
        game->board[0][2] == game->board[1][1] &&
        game->board[1][1] == game->board[2][0]) {
        return true;
    }
    
    return false;
}

bool is_tie(Game *game) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void print_board(Game *game) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

Move get_computer_move(Game *game) {
    int i, j;
    
    // Check if there is a winning move
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (is_valid_move(game, (Move){i, j})) {
                make_move(game, (Move){i, j});
                if (is_winner(game)) {
                    return (Move){i, j};
                }
                make_move(game, (Move){i, j});  // Undo the move
            }
        }
    }
    
    // Check if there is a blocking move
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (is_valid_move(game, (Move){i, j})) {
                make_move(game, (Move){i, j});
                if (is_winner(game)) {
                    return (Move){i, j};
                }
                make_move(game, (Move){i, j});  // Undo the move
            }
        }
    }
    
    // Play a random move
    while (true) {
        Move move = {rand() % BOARD_SIZE, rand() % BOARD_SIZE};
        if (is_valid_move(game, move)) {
            return move;
        }
    }
}

int main() {
    Game game;
    int i, j;
    
    // Initialize the game board
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            game.board[i][j] = ' ';
        }
    }
    game.turn = 'X';
    
    // Play the game
    while (true) {
        // Print the game board
        print_board(&game);
        
        // Get the player's move
        Move move;
        printf("Enter your move (row, column): ");
        scanf("%d %d", &move.x, &move.y);
        
        // Check if the player's move is valid
        if (!is_valid_move(&game, move)) {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        
        // Make the player's move
        make_move(&game, move);
        
        // Check if the player has won
        if (is_winner(&game)) {
            printf("Congratulations! You won!\n");
            break;
        }
        
        // Check if the game is a tie
        if (is_tie(&game)) {
            printf("Tie game!\n");
            break;
        }
        
        // Get the computer's move
        move = get_computer_move(&game);
        
        // Make the computer's move
        make_move(&game, move);
        
        // Check if the computer has won
        if (is_winner(&game)) {
            printf("The computer has won!");
            break;
        }
        
        // Check if the game is a tie
        if (is_tie(&game)) {
            printf("Tie game!\n");
            break;
        }
    }
    
    return 0;
}