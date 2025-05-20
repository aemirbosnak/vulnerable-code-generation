//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: innovative
#include <stdio.h>
#define SIZE 3

char board[SIZE][SIZE];

int check_win() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    for (i = 0; i < SIZE; i++) {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int minimax(int depth, int player) {
    int i, j, best_score, score;
    if (check_win()) {
        if (player == 1) {
            return -1;
        } else if (player == 2) {
            return 1;
        } else {
            return 0;
        }
    } else if (depth == 0) {
        return 0;
    }

    if (player == 1) {
        best_score = -1000;
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    score = minimax(depth - 1, 2);
                    board[i][j] = ' ';
                    if (score > best_score) {
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    } else {
        best_score = 1000;
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    score = minimax(depth - 1, 1);
                    board[i][j] = ' ';
                    if (score < best_score) {
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    }
}

int main() {
    int i, j, depth, move_i, move_j;
    char player;

    printf("Enter the depth of the game (1-9): ");
    scanf("%d", &depth);

    while (1) {
        printf("Enter the player (X or O): ");
        scanf(" %c", &player);

        if (player == 'X') {
            printf("You are playing as X.\n");
        } else if (player == 'O') {
            printf("You are playing as O.\n");
        } else {
            printf("Invalid player.\n");
            continue;
        }

        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                board[i][j] = ' ';
            }
        }

        while (1) {
            printf("\nCurrent board:\n");
            for (i = 0; i < SIZE; i++) {
                for (j = 0; j < SIZE; j++) {
                    printf("%c ", board[i][j]);
                }
                printf("\n");
            }

            if (player == 'X') {
                printf("Enter your move (row, column): ");
                scanf("%d %d", &move_i, &move_j);
                if (board[move_i][move_j] != ' ') {
                    printf("Invalid move.\n");
                    continue;
                }
                board[move_i][move_j] = 'X';
                if (check_win()) {
                    printf("You win!\n");
                    break;
                }
                player = 'O';
            } else {
                int best_score = -1000;
                for (i = 0; i < SIZE; i++) {
                    for (j = 0; j < SIZE; j++) {
                        if (board[i][j] == ' ') {
                            board[i][j] = 'O';
                            int score = minimax(depth, 1);
                            board[i][j] = ' ';
                            if (score > best_score) {
                                best_score = score;
                                move_i = i;
                                move_j = j;
                            }
                        }
                    }
                }
                board[move_i][move_j] = 'O';
                if (check_win()) {
                    printf("Computer wins!\n");
                    break;
                }
                player = 'X';
            }

            if (check_win()) {
                break;
            }
        }

        printf("Do you want to play again (Y/N)? ");
        scanf(" %c", &player);
        if (player == 'N') {
            break;
        }
    }

    return 0;
}