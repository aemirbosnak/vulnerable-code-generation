#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 6
#define COORD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];
int player = 0;

void print_board() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf("%c ", board[i][j] != '\0' ? board[i][j] : '.');
        }
        printf("\n");
    }
}

void set_cell(int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        return;
    }
    board[x][y] = player ? 'X' : 'O';
    player = !player;
}

int main() {
    char input[COORD_SIZE];
    while (1) {
        print_board();
        printf("Enter your move (x y): ");
        fgets(input, COORD_SIZE, stdin);
        sscanf(input, "%d %d", &input[0] - '0', &input[1] - '0');
        set_cell(input[0] - 1, input[1] - 1);
    }
    return 0;
}
