//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5

void print_bingo_card(int card[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

void generate_bingo_card(int card[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            card[i][j] = rand() % 15 + 1;
        }
    }
}

int is_valid_bingo(int card[MAX_ROWS][MAX_COLS], int row, int col) {
    int count = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (card[i][j] == card[row][col]) {
                count++;
            }
        }
    }
    return count == 5;
}

void mark_bingo_card(int card[MAX_ROWS][MAX_COLS], int row, int col) {
    card[row][col] = -1;
}

int main() {
    srand(time(NULL));
    int bingo_card[MAX_ROWS][MAX_COLS];
    generate_bingo_card(bingo_card);
    printf("Your Bingo card:\n");
    print_bingo_card(bingo_card);

    int player_row, player_col;
    printf("Enter your row and column number: ");
    scanf("%d %d", &player_row, &player_col);

    if (is_valid_bingo(bingo_card, player_row, player_col)) {
        printf("Bingo! You won!\n");
    } else {
        printf("Sorry, you did not win.\n");
    }

    return 0;
}