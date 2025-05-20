//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: portable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4
#define MAX_ATTEMPTS 10

typedef struct {
    int row;
    int col;
} Position;

char board[SIZE][SIZE];
bool revealed[SIZE][SIZE];

void shuffle_board() {
    int i, j, k, l;
    char temp;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            k = rand() % SIZE;
            l = rand() % SIZE;

            temp = board[i][j];
            board[i][j] = board[k][l];
            board[k][l] = temp;
        }
    }
}

void print_board() {
    int i, j;

    printf("  ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    for (i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%c ", board[i][j]);
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
}

bool is_valid_position(Position position) {
    return position.row >= 0 && position.row < SIZE && position.col >= 0 && position.col < SIZE;
}

bool is_match(Position position1, Position position2) {
    return board[position1.row][position1.col] == board[position2.row][position2.col];
}

bool is_game_over() {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (!revealed[i][j]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    srand(time(NULL));

    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = 'A' + rand() % 26;
            revealed[i][j] = false;
        }
    }

    shuffle_board();

    int attempts = 0;

    while (!is_game_over() && attempts < MAX_ATTEMPTS) {
        Position position1, position2;

        print_board();

        printf("Enter the row and column of the first card (e.g. 1 2): ");
        scanf("%d %d", &position1.row, &position1.col);

        position1.row--;
        position1.col--;

        if (!is_valid_position(position1)) {
            printf("Invalid position. Please try again.\n");
            continue;
        }

        revealed[position1.row][position1.col] = true;

        printf("Enter the row and column of the second card (e.g. 1 2): ");
        scanf("%d %d", &position2.row, &position2.col);

        position2.row--;
        position2.col--;

        if (!is_valid_position(position2)) {
            printf("Invalid position. Please try again.\n");
            continue;
        }

        revealed[position2.row][position2.col] = true;

        if (is_match(position1, position2)) {
            printf("Match!\n");
        } else {
            printf("No match. Please try again.\n");
            revealed[position1.row][position1.col] = false;
            revealed[position2.row][position2.col] = false;
            attempts++;
        }
    }

    if (is_game_over()) {
        printf("Congratulations! You won the game.\n");
    } else {
        printf("Game over. You ran out of attempts.\n");
    }

    return 0;
}