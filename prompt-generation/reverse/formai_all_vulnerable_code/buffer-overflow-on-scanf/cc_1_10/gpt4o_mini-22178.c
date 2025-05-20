//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3    // Configurable size of the board (3 for classic Tic Tac Toe)
#define EMPTY ' ' // Empty cell character

typedef struct {
    char board[SIZE][SIZE];
    char player1;  // Player 1 symbol
    char player2;  // Player 2 symbol
} Game;

void initialize_board(Game *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            game->board[i][j] = EMPTY;
        }
    }
}

void print_board(Game *game) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", game->board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            for (int j = 0; j < SIZE; j++) {
                printf("---");
                if (j < SIZE - 1) printf("|");
            }
            printf("\n");
        }
    }
    printf("\n");
}

int check_winner(Game *game) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if (game->board[i][0] == game->board[i][1] && game->board[i][1] == game->board[i][2] && game->board[i][0] != EMPTY) 
            return game->board[i][0];
        if (game->board[0][i] == game->board[1][i] && game->board[1][i] == game->board[2][i] && game->board[0][i] != EMPTY) 
            return game->board[0][i];
    }
    // Check diagonals
    if (game->board[0][0] == game->board[1][1] && game->board[1][1] == game->board[2][2] && game->board[0][0] != EMPTY) 
        return game->board[0][0];
    if (game->board[0][2] == game->board[1][1] && game->board[1][1] == game->board[2][0] && game->board[0][2] != EMPTY) 
        return game->board[0][2];
    
    return 0; // No winner
}

int is_draw(Game *game) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (game->board[i][j] == EMPTY) return 0; // Not a draw
        }
    }
    return 1; // It's a draw
}

void player_move(Game *game, char player) {
    int x, y;
    do {
        printf("Player %c, enter your move (row and column): ", player);
        scanf("%d %d", &x, &y);
        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || game->board[x][y] != EMPTY) {
            printf("Invalid move, try again.\n");
        }
    } while (x < 0 || x >= SIZE || y < 0 || y >= SIZE || game->board[x][y] != EMPTY);
    
    game->board[x][y] = player;
}

int ai_move(Game *game, char ai_player) {
    // Simple AI: Random move
    int x, y;
    do {
        x = rand() % SIZE;
        y = rand() % SIZE;
    } while (game->board[x][y] != EMPTY);
    
    game->board[x][y] = ai_player;
    printf("AI played at (%d, %d)\n", x, y);
    return 1;
}

int main() {
    Game game;
    game.player1 = 'X';
    game.player2 = 'O';
    char current_player;
    char winner = 0;

    initialize_board(&game);
    current_player = game.player1; // Player 1 starts

    while (1) {
        print_board(&game);
        if (current_player == game.player1) {
            player_move(&game, current_player);
        } else {
            ai_move(&game, current_player);
        }
        
        winner = check_winner(&game);
        if (winner) {
            print_board(&game);
            printf("Player %c wins!\n", winner);
            break;
        }
        
        if (is_draw(&game)) {
            print_board(&game);
            printf("It's a draw!\n");
            break;
        }
        
        current_player = (current_player == game.player1) ? game.player2 : game.player1; // Switch player
    }

    return 0;
}