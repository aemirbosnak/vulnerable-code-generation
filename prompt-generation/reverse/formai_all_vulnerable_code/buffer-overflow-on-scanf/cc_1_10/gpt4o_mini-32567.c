//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BOARD_SIZE 4
#define TOTAL_TILES (BOARD_SIZE * BOARD_SIZE)
#define MAX_TRIES 3

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE], char values[TOTAL_TILES]);
void shuffle(char array[TOTAL_TILES]);
void display_board(const char board[BOARD_SIZE][BOARD_SIZE], bool revealed[BOARD_SIZE][BOARD_SIZE]);
bool check_match(char board[BOARD_SIZE][BOARD_SIZE], char first, char second);
bool all_matched(bool revealed[BOARD_SIZE][BOARD_SIZE]);

int main() {
    srand(time(NULL));
    char board[BOARD_SIZE][BOARD_SIZE];
    char values[TOTAL_TILES] = {'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D',
                                  'E', 'E', 'F', 'F', 'G', 'G', 'H', 'H'};
    bool revealed[BOARD_SIZE][BOARD_SIZE] = {false};

    initialize_board(board, values);
  
    int tries = 0;
    while (tries < MAX_TRIES) {
        display_board(board, revealed);
        
        int first_x, first_y, second_x, second_y;
        printf("Enter coordinates for the first tile (row column): ");
        scanf("%d %d", &first_x, &first_y);
        printf("Enter coordinates for the second tile (row column): ");
        scanf("%d %d", &second_x, &second_y);

        if (check_match(board, board[first_x][first_y], board[second_x][second_y])) {
            revealed[first_x][first_y] = true;
            revealed[second_x][second_y] = true;
            printf("It's a match!\n");
        } else {
            printf("Not a match. Try again!\n");
            tries++;
        }

        if (all_matched(revealed)) {
            display_board(board, revealed);
            printf("Congratulations! You have matched all tiles.\n");
            return 0;
        }
    }

    printf("You've used all your tries. Game Over!\n");
    return 0;
}

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE], char values[TOTAL_TILES]) {
    shuffle(values);
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = values[i * BOARD_SIZE + j];
        }
    }
}

void shuffle(char array[TOTAL_TILES]) {
    for (int i = TOTAL_TILES - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void display_board(const char board[BOARD_SIZE][BOARD_SIZE], bool revealed[BOARD_SIZE][BOARD_SIZE]) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%c ", board[i][j]);
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

bool check_match(char board[BOARD_SIZE][BOARD_SIZE], char first, char second) {
    return first == second;
}

bool all_matched(bool revealed[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!revealed[i][j]) return false;
        }
    }
    return true;
}