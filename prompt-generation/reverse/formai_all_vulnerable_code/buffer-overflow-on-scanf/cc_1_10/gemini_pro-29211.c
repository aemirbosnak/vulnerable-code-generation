//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS BOARD_SIZE * BOARD_SIZE / 2

#define EASY 1
#define MEDIUM 2
#define HARD 3

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    int value;
    Position position;
    int revealed;
} Card;

Card *board;
int difficulty;
int num_guesses;
int num_matches;

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i * BOARD_SIZE + j].revealed) {
                printf("%2d ", board[i * BOARD_SIZE + j].value);
            } else {
                printf("## ");
            }
        }
        printf("\n");
    }
}

void set_difficulty(int d) {
    difficulty = d;
    switch (difficulty) {
        case EASY:
            num_guesses = 20;
            break;
        case MEDIUM:
            num_guesses = 15;
            break;
        case HARD:
            num_guesses = 10;
            break;
    }
}

void create_board() {
    int values[NUM_PAIRS];
    for (int i = 0; i < NUM_PAIRS; i++) {
        values[i] = i + 1;
    }

    board = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(Card));
    int index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int value = values[rand() % NUM_PAIRS];
            board[index].value = value;
            board[index].position.row = i;
            board[index].position.col = j;
            board[index].revealed = 0;
            index++;
        }
    }
}

void shuffle_board() {
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        int r1 = rand() % (BOARD_SIZE * BOARD_SIZE);
        int r2 = rand() % (BOARD_SIZE * BOARD_SIZE);

        Card temp = board[r1];
        board[r1] = board[r2];
        board[r2] = temp;
    }
}

void reveal_card(int row, int col) {
    board[row * BOARD_SIZE + col].revealed = 1;
}

int check_match(int row1, int col1, int row2, int col2) {
    return board[row1 * BOARD_SIZE + col1].value == board[row2 * BOARD_SIZE + col2].value;
}

int main() {
    srand(time(NULL));

    int difficulty;
    printf("Choose difficulty (1-3): ");
    scanf("%d", &difficulty);
    set_difficulty(difficulty);

    create_board();
    shuffle_board();

    while (num_guesses > 0) {
        print_board();

        int row1, col1, row2, col2;
        printf("Enter two cards to flip: ");
        scanf("%d %d %d %d", &row1, &col1, &row2, &col2);

        reveal_card(row1, col1);
        reveal_card(row2, col2);

        if (check_match(row1, col1, row2, col2)) {
            printf("Match!\n");
            num_matches++;
        } else {
            printf("No match!\n");
            board[row1 * BOARD_SIZE + col1].revealed = 0;
            board[row2 * BOARD_SIZE + col2].revealed = 0;
            num_guesses--;
        }

        if (num_matches == NUM_PAIRS) {
            printf("Congratulations! You won!\n");
            break;
        } else if (num_guesses == 0) {
            printf("Game over! You lose!\n");
        }
    }

    free(board);
    return 0;
}