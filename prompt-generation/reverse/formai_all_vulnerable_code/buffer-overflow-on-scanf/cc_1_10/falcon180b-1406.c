//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int board[ROWS][COLS];
int num_matches = 0;

void init_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = -1; // -1 indicates empty space
        }
    }
}

void place_card(int row, int col) {
    int card_value;
    srand(time(NULL));
    card_value = rand() % 13 + 1; // generate a random card value between 1 and 12
    board[row][col] = card_value;
}

void print_board() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%3d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_match(int row, int col) {
    int card_value = board[row][col];
    int matches = 0;

    // check if there is a match in the same row
    for (int i = 0; i < COLS; i++) {
        if (board[row][i] == card_value && i!= col) {
            matches++;
        }
    }

    // check if there is a match in the same column
    for (int i = 0; i < ROWS; i++) {
        if (board[i][col] == card_value && i!= row) {
            matches++;
        }
    }

    return matches;
}

int main() {
    int i, j, matches;
    init_board();
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            place_card(i, j);
        }
    }
    print_board();

    int player_row, player_col;
    printf("Enter your row: ");
    scanf("%d", &player_row);
    printf("Enter your column: ");
    scanf("%d", &player_col);

    while (1) {
        system("clear");
        print_board();
        matches = check_match(player_row, player_col);
        if (matches == 2) {
            printf("You found a match!\n");
            num_matches++;
        } else {
            printf("No match found.\n");
        }

        if (num_matches == 8) {
            printf("You win!\n");
            break;
        }

        printf("Enter your next move (row, column): ");
        scanf("%d %d", &player_row, &player_col);
    }

    return 0;
}