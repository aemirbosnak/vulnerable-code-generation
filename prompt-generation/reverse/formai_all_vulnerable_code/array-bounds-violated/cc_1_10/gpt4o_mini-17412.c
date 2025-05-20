//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define BOARD_SIZE 4
#define MAX_PAIRS (BOARD_SIZE * BOARD_SIZE / 2)

typedef struct {
    char symbol;
    int revealed;
} Card;

void initialize_board(Card board[BOARD_SIZE][BOARD_SIZE]);
void shuffle_board(Card board[BOARD_SIZE][BOARD_SIZE]);
void print_board(Card board[BOARD_SIZE][BOARD_SIZE]);
int select_card();
void reveal_card(Card board[BOARD_SIZE][BOARD_SIZE], int row, int col);
int check_match(Card board[BOARD_SIZE][BOARD_SIZE], int first_row, int first_col, int second_row, int second_col);
int is_game_over(Card board[BOARD_SIZE][BOARD_SIZE]);

int main() {
    Card board[BOARD_SIZE][BOARD_SIZE];
    int first_row, first_col, second_row, second_col;
    int pairs_found = 0;

    srand(time(NULL));
    initialize_board(board);
    shuffle_board(board);

    while (!is_game_over(board)) {
        print_board(board);

        printf("Select the first card (row and column): ");
        first_row = select_card();
        first_col = select_card();

        reveal_card(board, first_row, first_col);
        print_board(board);

        printf("Select the second card (row and column): ");
        second_row = select_card();
        second_col = select_card();

        reveal_card(board, second_row, second_col);
        print_board(board);

        if (check_match(board, first_row, first_col, second_row, second_col)) {
            printf("It's a match!\n");
            pairs_found++;
        } else {
            printf("Not a match. Try again.\n");
            board[first_row][first_col].revealed = 0;
            board[second_row][second_col].revealed = 0;
        }

        sleep(1); // Pause for 1 second before the next turn
    }

    printf("Congratulations! You found all pairs in %d turns!\n", pairs_found);
    return 0;
}

void initialize_board(Card board[BOARD_SIZE][BOARD_SIZE]) {
    char symbols[MAX_PAIRS] = {'@', '#', '!', '$', '%', '^', '&', '*'};
    int index = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].symbol = symbols[index / 2];
            board[i][j].revealed = 0;
            if (index % 2 == 1) {
                index++;
            }
            index++;
        }
    }
}

void shuffle_board(Card board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < 100; i++) {
        int x1 = rand() % BOARD_SIZE;
        int y1 = rand() % BOARD_SIZE;
        int x2 = rand() % BOARD_SIZE;
        int y2 = rand() % BOARD_SIZE;

        Card temp = board[x1][y1];
        board[x1][y1] = board[x2][y2];
        board[x2][y2] = temp;
    }
}

void print_board(Card board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n--- Memory Game Board ---\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].revealed) {
                printf(" %c ", board[i][j].symbol);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
    printf("-------------------------\n");
}

int select_card() {
    int index;
    do {
        printf("Enter row (0-%d) and column (0-%d): ", BOARD_SIZE - 1, BOARD_SIZE - 1);
        scanf("%d", &index);
    } while (index < 0 || index >= BOARD_SIZE);
    return index;
}

void reveal_card(Card board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    if (board[row][col].revealed) {
        printf("Card already revealed! Try again.\n");
    } else {
        board[row][col].revealed = 1;
    }
}

int check_match(Card board[BOARD_SIZE][BOARD_SIZE], int first_row, int first_col, int second_row, int second_col) {
    return board[first_row][first_col].symbol == board[second_row][second_col].symbol;
}

int is_game_over(Card board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!board[i][j].revealed) {
                return 0;
            }
        }
    }
    return 1;
}