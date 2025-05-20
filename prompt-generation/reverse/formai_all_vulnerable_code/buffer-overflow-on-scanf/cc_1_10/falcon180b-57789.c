//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define NUM_MINES 3

char board[BOARD_SIZE][BOARD_SIZE];
char hidden_board[BOARD_SIZE][BOARD_SIZE];
int num_mines_left;

void init_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
            hidden_board[i][j] = (i == 0 || j == 0 || i == BOARD_SIZE - 1 || j == BOARD_SIZE - 1)? 'X' : (rand() % 2)? '*' : '.';
        }
    }
    num_mines_left = NUM_MINES;
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int reveal_cell(int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return -1;
    }

    if (hidden_board[x][y] == '*') {
        num_mines_left--;
        return 1;
    } else if (hidden_board[x][y] == '.') {
        return 0;
    } else {
        return -1;
    }
}

int count_adjacent_mines(int x, int y) {
    int count = 0;
    if (x > 0 && hidden_board[x - 1][y] == '*') {
        count++;
    }
    if (x < BOARD_SIZE - 1 && hidden_board[x + 1][y] == '*') {
        count++;
    }
    if (y > 0 && hidden_board[x][y - 1] == '*') {
        count++;
    }
    if (y < BOARD_SIZE - 1 && hidden_board[x][y + 1] == '*') {
        count++;
    }
    return count;
}

void play_game() {
    int x, y, result;
    char choice;

    init_board();
    print_board(board);

    while (1) {
        printf("Enter your move (row col): ");
        scanf("%d %d", &x, &y);

        result = reveal_cell(x, y);
        if (result == -1) {
            printf("Invalid move.\n");
        } else if (result == 1) {
            printf("You hit a mine! Game over.\n");
            break;
        } else {
            printf("Revealed cell: %c\n", hidden_board[x][y]);

            if (hidden_board[x][y] == '.') {
                if (count_adjacent_mines(x, y) == 0) {
                    for (int i = 0; i < BOARD_SIZE; i++) {
                        for (int j = 0; j < BOARD_SIZE; j++) {
                            if (i == x && j == y) {
                                board[i][j] = '.';
                            } else if (hidden_board[i][j] == '.') {
                                board[i][j] = '*';
                            }
                        }
                    }
                }
            }
        }

        if (result == 0 || result == 1) {
            printf("Current board:\n");
            print_board(board);

            if (result == 0) {
                printf("Do you want to continue? (y/n) ");
                scanf(" %c", &choice);
                if (choice!= 'y') {
                    break;
                }
            }
        }
    }

    printf("Game over.\n");
}

int main() {
    srand(time(NULL));
    play_game();
    return 0;
}