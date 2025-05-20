//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define TOTAL_PAIRS (SIZE * SIZE) / 2

char board[SIZE][SIZE];
char revealed[SIZE][SIZE];
int attempts;

void initialize_board();
void shuffle_board();
void print_board();
void reveal_card(int x, int y);
int check_match(int x1, int y1, int x2, int y2);
int is_complete();
void play_game();

int main() {
    initialize_board();
    shuffle_board();
    play_game();
    return 0;
}

void initialize_board() {
    char letters[] = "ABCDEFGH";
    int index = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = letters[index];
            revealed[i][j] = ' ';
            index += (index < TOTAL_PAIRS) ? 1 : 0;
            if (index >= TOTAL_PAIRS) index = 0;
        }
    }
}

void shuffle_board() {
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int r1 = rand() % SIZE;
            int c1 = rand() % SIZE;
            int r2 = rand() % SIZE;
            int c2 = rand() % SIZE;

            char temp = board[r1][c1];
            board[r1][c1] = board[r2][c2];
            board[r2][c2] = temp;
        }
    }
}

void print_board() {
    printf("\nMemory Game Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", revealed[i][j]);
        }
        printf("\n");
    }
    printf("\nAttempts: %d\n", attempts);
}

void reveal_card(int x, int y) {
    revealed[x][y] = board[x][y];
}

int check_match(int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

int is_complete() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void play_game() {
    int x1, y1, x2, y2;
    attempts = 0;

    while (!is_complete()) {
        print_board();
        printf("Enter coordinates of the first card (row and column): ");
        scanf("%d %d", &x1, &y1);
        reveal_card(x1, y1);
        print_board();

        printf("Enter coordinates of the second card (row and column): ");
        scanf("%d %d", &x2, &y2);
        reveal_card(x2, y2);
        print_board();

        attempts++;

        if (!check_match(x1, y1, x2, y2)) {
            printf("No match!\n");
            revealed[x1][y1] = ' ';
            revealed[x2][y2] = ' ';
        } else {
            printf("Match found!\n");
        }
    }

    printf("Congratulations! You've matched all pairs in %d attempts!\n", attempts);
}