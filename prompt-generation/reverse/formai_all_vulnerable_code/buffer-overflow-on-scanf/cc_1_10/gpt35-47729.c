//FormAI DATASET v1.0 Category: Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

int row, col;
char game_board[ROW][COL];

void initialize_board() {
    int i,j;
    for (i=0; i<ROW; i++) {
        for (j=0; j<COL; j++) {
            game_board[i][j] = '-';
        }
    }
}

void display_board() {
    int i,j;
    for (i=0; i<ROW; i++) {
        for (j=0; j<COL; j++) {
            printf("%c ", game_board[i][j]);
        }
        printf("\n");
    }
    printf("----------------------\n");
}

void player_move(char player) {
    printf("Player %c's turn\n", player);
    printf("Enter row and column number where you want to place '%c': ", player);
    scanf("%d %d", &row, &col);
    if (game_board[row][col] != '-') {
        printf("Invalid move. Try again.\n");
        player_move(player);
    } else {
        game_board[row][col] = player;
        display_board();
    }
}

char check_win() {
    int i,j;
    // Check rows
    for (i=0; i<ROW; i++) {
        if (game_board[i][0] == game_board[i][1] && game_board[i][1] == game_board[i][2]) {
            return game_board[i][0];
        }
    }
    // Check columns
    for (j=0; j<COL; j++) {
        if (game_board[0][j] == game_board[1][j] && game_board[1][j] == game_board[2][j]) {
            return game_board[0][j];
        }
    }
    // Check diagonals
    if (game_board[0][0] == game_board[1][1] && game_board[1][1] == game_board[2][2]) {
        return game_board[0][0];
    }
    if (game_board[0][2] == game_board[1][1] && game_board[1][1] == game_board[2][0]) {
        return game_board[0][2];
    }
    return '-';
}

int main() {
    char player1 = 'X', player2 = 'O';
    char winner = '-';
    int turn, total_turns = 0;
    
    printf("Welcome to Tic Tac Toe!\n");
    initialize_board();
    display_board();
    
    for (turn=1; turn<=9; turn++) {
        if (turn % 2 == 1) {
            player_move(player1);
        } else {
            player_move(player2);
        }
        total_turns++;
        winner = check_win();
        if (winner != '-') {
            printf("Congratulations, player %c wins the game!\n", winner);
            break;
        } else if (total_turns == 9) {
            printf("The game is a tie!\n");
            break;
        }
    }
    
    return 0;
}