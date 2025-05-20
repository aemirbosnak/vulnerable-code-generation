//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

char board[3][3];
char player = 'X';
int moves = 0;

void init_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '_';
        }
    }
}

void print_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int check_win(char p) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p) {
            return 1;
        }
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p) {
            return 1;
        }
    }
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p) {
        return 1;
    }
    if (board[0][2] == p && board[1][1] == p && board[2][0] == p) {
        return 1;
    }
    return 0;
}

void player_move() {
    int x, y;
    printf("Enter row and column (1-3) for player %c: ", player);
    scanf("%d %d", &x, &y);
    x--;
    y--;
    if (board[x][y] == '_') {
        board[x][y] = player;
        moves++;
    } else {
        printf("Invalid move, try again.\n");
        player_move();
    }
}

void computer_move() {
    int x, y;
    printf("Computer's move:\n");
    do {
        x = rand() % 3;
        y = rand() % 3;
    } while (board[x][y] != '_');
    board[x][y] = 'O';
    moves++;
}

void play_game() {
    while (moves < 9) {
        if (player == 'X') {
            player_move();
            if (check_win(player)) {
                printf("Congratulations, %c wins!\n", player);
                return;
            }
            player = 'O';
        } else {
            computer_move();
            if (check_win('O')) {
                printf("Sorry, computer wins.\n");
                return;
            }
            player = 'X';
        }
        print_board();
    }
    printf("Draw game.\n");
}

int main() {
    printf("Welcome to Tic Tac Toe game!\n");
    init_board();
    print_board();
    play_game();
    return 0;
}