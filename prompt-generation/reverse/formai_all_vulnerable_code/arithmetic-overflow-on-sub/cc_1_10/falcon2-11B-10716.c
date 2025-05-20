//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum Directions {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

enum States {
    EMPTY,
    X,
    O
};

typedef struct {
    int row;
    int col;
    enum States state;
} Cell;

typedef struct {
    Cell board[3][3];
    enum Directions direction;
} Game;

void init_game(Game* game) {
    game->direction = UP;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            game->board[i][j].state = EMPTY;
        }
    }
}

void display_board(Game* game) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            switch (game->board[i][j].state) {
                case EMPTY:
                    printf("   ");
                    break;
                case X:
                    printf("X   ");
                    break;
                case O:
                    printf("O   ");
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

void update_board(Game* game) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            switch (game->board[i][j].state) {
                case EMPTY:
                    game->board[i][j].state = EMPTY;
                    break;
                case X:
                    game->board[i][j].state = EMPTY;
                    break;
                case O:
                    game->board[i][j].state = EMPTY;
                    break;
            }
        }
    }
}

bool is_cell_empty(Game* game, int row, int col) {
    return game->board[row][col].state == EMPTY;
}

bool is_game_over(Game* game) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game->board[i][j].state == EMPTY) {
                return false;
            }
            if (game->board[i][j].state!= EMPTY &&
                game->board[i][j].state == game->board[(i+1)%3][j].state &&
                game->board[i][j].state == game->board[(i+2)%3][j].state) {
                return true;
            }
            if (game->board[i][j].state!= EMPTY &&
                game->board[i][j].state == game->board[i][(j+1)%3].state &&
                game->board[i][j].state == game->board[i][(j+2)%3].state) {
                return true;
            }
        }
    }
    return false;
}

void make_move(Game* game, int row, int col, enum States state) {
    game->board[row][col].state = state;
    if (game->direction == UP) {
        game->direction = RIGHT;
    } else if (game->direction == RIGHT) {
        game->direction = DOWN;
    } else if (game->direction == DOWN) {
        game->direction = LEFT;
    } else if (game->direction == LEFT) {
        game->direction = UP;
    }
}

int main() {
    Game game;
    init_game(&game);

    printf("Welcome to Tic Tac Toe!n");
    printf("Please choose a direction to make your move:n");
    printf("1. Up\n2. Right\n3. Down\n4. Left\n");
    int direction;
    scanf("%d", &direction);

    while (!is_game_over(&game)) {
        display_board(&game);
        printf("Make your move:\n");
        int row, col;
        scanf("%d %d", &row, &col);

        if (is_cell_empty(&game, row, col)) {
            if (direction == UP) {
                if (row == 0) {
                    row = 2;
                } else if (row == 1) {
                    row = 1;
                } else {
                    row--;
                }
            } else if (direction == RIGHT) {
                if (col == 2) {
                    col = 0;
                } else if (col == 1) {
                    col = 1;
                } else {
                    col++;
                }
            } else if (direction == DOWN) {
                if (row == 2) {
                    row = 0;
                } else if (row == 1) {
                    row = 2;
                } else {
                    row++;
                }
            } else if (direction == LEFT) {
                if (col == 0) {
                    col = 2;
                } else if (col == 1) {
                    col = 1;
                } else {
                    col--;
                }
            }

            make_move(&game, row, col, X);
            display_board(&game);
            printf("X wins!\n");
            break;
        } else if (is_cell_empty(&game, row, col)) {
            if (direction == UP) {
                if (row == 0) {
                    row = 2;
                } else if (row == 1) {
                    row = 1;
                } else {
                    row--;
                }
            } else if (direction == RIGHT) {
                if (col == 2) {
                    col = 0;
                } else if (col == 1) {
                    col = 1;
                } else {
                    col++;
                }
            } else if (direction == DOWN) {
                if (row == 2) {
                    row = 0;
                } else if (row == 1) {
                    row = 2;
                } else {
                    row++;
                }
            } else if (direction == LEFT) {
                if (col == 0) {
                    col = 2;
                } else if (col == 1) {
                    col = 1;
                } else {
                    col--;
                }
            }

            make_move(&game, row, col, O);
            display_board(&game);
            printf("O wins!\n");
            break;
        } else {
            printf("Cell already taken!\n");
        }

        printf("Make another move:\n");
        direction = scanf("%d", &direction);
    }

    return 0;
}