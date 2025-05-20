//FormAI DATASET v1.0 Category: Memory Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void init_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j, cnt = 1;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = cnt++;
        }
    }
    board[BOARD_SIZE - 1][BOARD_SIZE - 1] = 0;
}

void shuffle_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    srand(time(NULL));
    int i, j;
    for (i = BOARD_SIZE - 1; i > 0; i--) {
        for (j = BOARD_SIZE - 1; j > 0; j--) {
            int r = rand() % (i + 1);
            int c = rand() % (j + 1);
            int temp = board[i][j];
            board[i][j] = board[r][c];
            board[r][c] = temp;
        }
    }
}

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                printf("   ");
            } else {
                printf("%2d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int find_empty(int board[BOARD_SIZE][BOARD_SIZE], int *row, int *col) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                *row = i;
                *col = j;
                return 1;
            }
        }
    }
    return 0;
}

int get_move() {
    char c;
    do {
        printf("Enter move (U/D/L/R): ");
        scanf("%c", &c);
    } while (c != 'U' && c != 'u' && c != 'D' && c != 'd' && c != 'L' && c != 'l' && c != 'R' && c != 'r');
    fflush(stdin);
    switch (c) {
        case 'U':
        case 'u':
            return 1;
        case 'D':
        case 'd':
            return 2;
        case 'L':
        case 'l':
            return 3;
        case 'R':
        case 'r':
            return 4;
    }
    return -1;
}

int make_move(int board[BOARD_SIZE][BOARD_SIZE], int move) {
    int row, col;
    int empty_found = find_empty(board, &row, &col);
    int r, c;
    switch (move) {
        case 1: // up
            r = row - 1;
            c = col;
            break;
        case 2: // down
            r = row + 1;
            c = col;
            break;
        case 3: // left
            r = row;
            c = col - 1;
            break;
        case 4: // right
            r = row;
            c = col + 1;
            break;
        default:
            return 0;
    }
    if (r >= 0 && r < BOARD_SIZE && c >= 0 && c < BOARD_SIZE) {
        int temp = board[row][col];
        board[row][col] = board[r][c];
        board[r][c] = temp;
        return 1;
    }
    return 0;
}

int is_solved(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j, cnt = 1;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != cnt && (i != BOARD_SIZE - 1 || j != BOARD_SIZE - 1)) {
                return 0;
            }
            cnt++;
        }
    }
    return 1;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    init_board(board);
    shuffle_board(board);
    printf("Welcome to the Memory Game!\n");
    printf("The goal of the game is to arrange the numbers from 1 to %d in ascending order.\n", BOARD_SIZE * BOARD_SIZE - 1);
    printf("Use the following moves to rearrange the numbers:\n");
    printf("U - Up\n");
    printf("D - Down\n");
    printf("L - Left\n");
    printf("R - Right\n");
    printf("To quit press 'Q' or 'q'.\n");
    char c;
    int move;
    do {
        printf("\n");
        print_board(board);
        move = get_move();
        if (move == -1) {
            printf("Invalid move!\n");
        } else {
            if (!make_move(board, move)) {
                printf("Move not possible!\n");
            }
        }
        if (is_solved(board)) {
            printf("Congratulations, you have solved the Memory Game!\n");
            break;
        }
        c = getchar();
    } while (c != 'Q' && c != 'q');
    printf("Thank you for playing!\n");
    return 0;
}