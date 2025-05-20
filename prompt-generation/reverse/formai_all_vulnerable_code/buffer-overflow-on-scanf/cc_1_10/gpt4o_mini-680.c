//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: minimalist
#include <stdio.h>

#define SIZE 3
#define EMPTY ' '
#define PLAYER_X 'X'
#define PLAYER_O 'O'

char board[SIZE][SIZE];
char current_player;

void init_board() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = EMPTY;
}

void print_board() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("  ");
        for (int j = 0; j < SIZE; j++) {
            printf("%c", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("  ---------\n");
        }
    }
    printf("\n");
}

int check_winner() {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == current_player && board[i][1] == current_player && board[i][2] == current_player)
            return 1;
        if (board[0][i] == current_player && board[1][i] == current_player && board[2][i] == current_player)
            return 1;
    }
    if (board[0][0] == current_player && board[1][1] == current_player && board[2][2] == current_player)
        return 1;
    if (board[0][2] == current_player && board[1][1] == current_player && board[2][0] == current_player)
        return 1;
    return 0;
}

int is_board_full() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == EMPTY) return 0;
    return 1;
}

void switch_player() {
    current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

void player_move() {
    int row, col;
    printf("Player %c, enter row and column (0, 1, or 2): ", current_player);
    scanf("%d %d", &row, &col);
    while (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != EMPTY) {
        printf("Invalid move. Try again: ");
        scanf("%d %d", &row, &col);
    }
    board[row][col] = current_player;
}

void ai_move() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = current_player;
                if (check_winner()) return;
                board[i][j] = EMPTY;
            }
        }
    }
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
                if (check_winner()) {
                    board[i][j] = current_player;
                    return;
                }
                board[i][j] = EMPTY;
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = current_player;
                return;
            }
        }
    }
}

void play_game() {
    init_board();
    current_player = PLAYER_X;
    
    while (1) {
        print_board();
        if (current_player == PLAYER_X) {
            player_move();
        } else {
            ai_move();
        }

        if (check_winner()) {
            print_board();
            printf("Player %c wins!\n", current_player);
            break;
        }

        if (is_board_full()) {
            print_board();
            printf("The game is a draw.\n");
            break;
        }

        switch_player();
    }
}

int main() {
    play_game();
    return 0;
}