//FormAI DATASET v1.0 Category: Checkers Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int board[8][8] = {
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {2, 0, 2, 0, 2, 0, 2, 0},
    {0, 2, 0, 2, 0, 2, 0, 2},
    {2, 0, 2, 0, 2, 0, 2, 0}
};

int turn = 1;
int game_over = 0;

void print_board();
int check_move(int x1, int y1, int x2, int y2);
int make_move(int x1, int y1, int x2, int y2);

int main() {
    while (!game_over) {
        print_board();
        printf("It is player %d's turn!\n", turn);
        int x1, y1, x2, y2;
        printf("Enter x1, y1, x2, y2: ");
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (!check_move(x1, y1, x2, y2)) {
            printf("Invalid move!\n");
        } else {
            if (!make_move(x1, y1, x2, y2)) {
                printf("Invalid move!\n");
            } else {
                if (turn == 1) {
                    turn = 2;
                } else {
                    turn = 1;
                }
            }
        }
    }
    printf("Game over!\n");
    return 0;
}

void print_board() {
    printf("\n-- --- --- --- --- --- --- --- -\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 0) {
                printf("|   ");
            } else if (board[i][j] == 1) {
                printf("| a ");
            } else if (board[i][j] == 2) {
                printf("| b ");
            } else if (board[i][j] == 3) {
                printf("| A ");
            } else if (board[i][j] == 4) {
                printf("| B ");
            }
        }
        printf("|\n");
        printf("-- --- --- --- --- --- --- --- -\n");
    }
}

int check_move(int x1, int y1, int x2, int y2) {
    if (x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7 || x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7) {
        return 0;
    }
    if (board[x1][y1] == 0 || board[x2][y2] != 0) {
        return 0;
    }
    if (turn == 1) {
        if (board[x1][y1] == 1 && x2 > x1) {
            return 0;
        }
        if (board[x1][y1] == 2) {
            if (x2 != x1 + 1 || (y2 != y1 + 1 && y2 != y1 - 1)) {
                return 0;
            }
        } else {
            if ((x2 != x1 + 1 || (y2 != y1 + 1 && y2 != y1 - 1)) && (x2 != x1 + 2 || (y2 != y1 + 2 && y2 != y1 - 2))) {
                return 0;
            }
            if (x2 == x1 + 2 && y2 == y1 + 2) {
                if (board[x1 + 1][y1 + 1] != 2) {
                    return 0;
                } else {
                    board[x1 + 1][y1 + 1] = 0;
                }
            }
            if (x2 == x1 + 2 && y2 == y1 - 2) {
                if (board[x1 + 1][y1 - 1] != 2) {
                    return 0;
                } else {
                    board[x1 + 1][y1 - 1] = 0;
                }
            }
        }
    } else {
        if (board[x1][y1] == 2 && x2 < x1) {
            return 0;
        }
        if (board[x1][y1] == 1) {
            if (x2 != x1 - 1 || (y2 != y1 + 1 && y2 != y1 - 1)) {
                return 0;
            }
        } else {
            if ((x2 != x1 - 1 || (y2 != y1 + 1 && y2 != y1 - 1)) && (x2 != x1 - 2 || (y2 != y1 + 2 && y2 != y1 - 2))) {
                return 0;
            }
            if (x2 == x1 - 2 && y2 == y1 + 2) {
                if (board[x1 - 1][y1 + 1] != 1) {
                    return 0;
                } else {
                    board[x1 - 1][y1 + 1] = 0;
                }
            }
            if (x2 == x1 - 2 && y2 == y1 - 2) {
                if (board[x1 - 1][y1 - 1] != 1) {
                    return 0;
                } else {
                    board[x1 - 1][y1 - 1] = 0;
                }
            }
        }
    }
    return 1;
}

int make_move(int x1, int y1, int x2, int y2) {
    if (board[x1][y1] == 1 && x2 == 7) {
        board[x2][y2] = 3;
    } else if (board[x1][y1] == 2 && x2 == 0) {
        board[x2][y2] = 4;
    } else {
        board[x2][y2] = board[x1][y1];
    }
    board[x1][y1] = 0;
    if (turn == 1) {
        if (x2 == 0) {
            game_over = 1;
        }
    } else {
        if (x2 == 7) {
            game_over = 1;
        }
    }
    return 1;
}