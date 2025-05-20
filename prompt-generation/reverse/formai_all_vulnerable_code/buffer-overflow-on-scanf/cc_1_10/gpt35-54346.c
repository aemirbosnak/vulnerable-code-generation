//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ROWS = 3, COLS = 3;
char board[3][3];
char human = 'X';
char computer = 'O';

// function prototypes
void initialize_board();
void print_board();
int validate_move(int, int);
int check_winner();
void human_turn();
void computer_turn();

int main() {
    int turn = 0;
    srand(time(NULL));
    initialize_board();
    printf("\n\n*******************\n");
    printf("Let's play Tic Tac Toe!\n");
    printf("Human = X, Computer = O\n");
    printf("*******************\n\n");
    while (turn <= ROWS * COLS) {
        if (turn % 2 == 0) {
            human_turn();
        } else {
            computer_turn();
        }
        print_board();
        if (check_winner() != 0) {
            printf("**** GAME OVER ****\n");
            break;
        }
        turn++;
    }
    return 0;
}

void initialize_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    printf("   1   2   3\n");
    printf("------------\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        printf("------------\n");
    }
}

int validate_move(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Invalid move. Row and Column should be between 1-3\n");
        return 0;
    } else if (board[row][col] != ' ') {
        printf("Invalid move. Already occupied. Try again\n");
        return 0;
    }
    return 1;
}

int check_winner() {
    // check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == human) {
                printf("Human wins!\n");
                return 1;
            } else if (board[i][0] == computer) {
                printf("Computer wins!\n");
                return -1;
            }
        }
    }
    // check columns
    for (int i = 0; i < COLS; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == human) {
                printf("Human wins!\n");
                return 1;
            } else if (board[0][i] == computer) {
                printf("Computer wins!\n");
                return -1;
            }
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == human) {
            printf("Human wins!\n");
            return 1;
        } else if (board[0][0] == computer) {
            printf("Computer wins!\n");
            return -1;
        }
    } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == human) {
            printf("Human wins!\n");
            return 1;
        } else if (board[0][2] == computer) {
            printf("Computer wins!\n");
            return -1;
        }
    }
    return 0;
}

void human_turn() {
    int row, col, valid = 0;
    printf("Human turn: Enter row and column (e.g. 1 2): ");
    do {
        scanf("%d %d", &row, &col);
        row--;
        col--;
        valid = validate_move(row, col);
    } while (!valid);
    board[row][col] = human;
    printf("Human put %c in [%d,%d]\n\n", human, row+1, col+1);
}

void computer_turn() {
    int row, col, valid = 0;
    printf("Computer turn: ");
    do {
        row = rand() % 3;
        col = rand() % 3;
        valid = validate_move(row, col);
    } while (!valid);
    board[row][col] = computer;
    printf("Computer put %c in [%d,%d]\n\n", computer, row+1, col+1);
}