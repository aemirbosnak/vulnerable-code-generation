//FormAI DATASET v1.0 Category: Memory Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

typedef struct {
    int x;
    int y;
} Point;

void print_board(int board[BOARD_SIZE][BOARD_SIZE], int show_hidden);
int get_number_of_pairs();
int get_random_number(int min, int max);
void shuffle_board(int board[BOARD_SIZE][BOARD_SIZE]);
void play_game(int board[BOARD_SIZE][BOARD_SIZE], int number_of_pairs);
int make_guess(int board[BOARD_SIZE][BOARD_SIZE], Point guess, int *remaining_pairs);

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int number_of_pairs;

    srand(time(NULL));

    number_of_pairs = get_number_of_pairs();
    shuffle_board(board);
    play_game(board, number_of_pairs);

    return 0;
}

void print_board(int board[BOARD_SIZE][BOARD_SIZE], int show_hidden) {
    int i, j;

    printf("   ");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }

    printf("\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d: ", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == -1 || (show_hidden && board[i][j] > -1)) {
                printf("%d ", board[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int get_number_of_pairs() {
    int number_of_pairs;

    do {
        printf("Enter number of pairs: ");
        scanf("%d", &number_of_pairs);
    } while (number_of_pairs < 1 || number_of_pairs > (BOARD_SIZE * BOARD_SIZE) / 2);

    return number_of_pairs;
}

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void shuffle_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j, k, l;
    int number_of_pairs;
    int card_value;
    int pairs_placed = 0;
    int available_positions[BOARD_SIZE * BOARD_SIZE];
    int number_of_available_positions = BOARD_SIZE * BOARD_SIZE;

    // Initialize board to all -1
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = -1;
            available_positions[i * BOARD_SIZE + j] = i * BOARD_SIZE + j;
        }
    }

    number_of_pairs = (BOARD_SIZE * BOARD_SIZE) / 2;

    while (pairs_placed < number_of_pairs) {
        card_value = get_random_number(1, number_of_pairs);

        for (i = 0; i < 2; i++) {
            number_of_available_positions--;

            if (!number_of_available_positions) {
                // No more room on the board
                return;
            }

            l = get_random_number(0, number_of_available_positions);
            k = available_positions[l];

            // Remove this index from the available positions
            available_positions[l] = available_positions[number_of_available_positions];

            board[k / BOARD_SIZE][k % BOARD_SIZE] = card_value;
        }

        pairs_placed++;
    }
}

void play_game(int board[BOARD_SIZE][BOARD_SIZE], int number_of_pairs) {
    Point guess1, guess2;
    int remaining_pairs = number_of_pairs;
    int guess_result;

    while (remaining_pairs) {
        printf("\n\nRemaining pairs: %d\n", remaining_pairs);
        print_board(board, 0);

        printf("Enter first guess (x y): ");
        scanf("%d %d", &guess1.x, &guess1.y);

        guess_result = make_guess(board, guess1, &remaining_pairs);

        if (remaining_pairs == 0) {
            printf("Congratulations, you win!\n");
            break;
        }

        if (guess_result == 0) {
            printf("Incorrect guess, try again...\n");

            printf("Enter second guess (x y): ");
            scanf("%d %d", &guess2.x, &guess2.y);

            guess_result = make_guess(board, guess2, &remaining_pairs);

            if (guess_result == 0) {
                printf("Sorry, incorrect guess...\n");
            }
        }
    }
    printf("Game over, thank you for playing!\n");
}

int make_guess(int board[BOARD_SIZE][BOARD_SIZE], Point guess, int *remaining_pairs) {
    int card_value;
    int i, j;

    i = guess.x;
    j = guess.y;

    if (board[i][j] < 0) {
        printf("Sorry, please try again...\n");
        return -1;
    }

    card_value = board[i][j];
    board[i][j] = -2;

    print_board(board, 1);

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == card_value && (i != guess.x || j != guess.y)) {
                board[i][j] = -2;

                print_board(board, 1);

                (*remaining_pairs)--;

                return 1;
            }
        }
    }

    return 0;
}