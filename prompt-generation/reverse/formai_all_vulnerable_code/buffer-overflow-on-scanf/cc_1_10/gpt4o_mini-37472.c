//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BINGO_SIZE 5
#define NUMBERS 75
#define MAX_PLAYERS 5

typedef struct {
    int card[BINGO_SIZE][BINGO_SIZE];
    bool marked[BINGO_SIZE][BINGO_SIZE];
    int player_number;
} BingoCard;

void initialize_card(BingoCard *card) {
    int number;
    bool unique;
    // Initialize the random number generator
    srand(time(NULL) + card->player_number);

    for (int col = 0; col < BINGO_SIZE; col++) {
        int min_val = col * 15 + 1;
        int max_val = min_val + 14;

        for (int row = 0; row < BINGO_SIZE; row++) {
            do {
                unique = true;
                number = (rand() % (max_val - min_val + 1)) + min_val;

                // Check for uniqueness in the column
                for (int check_row = 0; check_row < row; check_row++) {
                    if (card->card[check_row][col] == number) {
                        unique = false;
                        break;
                    }
                }
            } while (!unique);

            card->card[row][col] = number;
            card->marked[row][col] = false;  // Set all to unmarked initially
        }
    }
    card->marked[BINGO_SIZE / 2][BINGO_SIZE / 2] = true; // Free space in the center
}

void print_card(BingoCard *card) {
    printf("B  I  N  G  O\n");
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card->marked[row][col]) {
                printf(" * "); // Marked with an asterisk
            } else {
                printf("%2d ", card->card[row][col]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool check_bingo(BingoCard *card) {
    // Check rows and columns
    for (int i = 0; i < BINGO_SIZE; i++) {
        if ((card->marked[i][0] && card->marked[i][1] && card->marked[i][2] &&
             card->marked[i][3] && card->marked[i][4]) || 
            (card->marked[0][i] && card->marked[1][i] && card->marked[2][i] &&
             card->marked[3][i] && card->marked[4][i])) {
            return true;
        }
    }
    // Check diagonals
    if ((card->marked[0][0] && card->marked[1][1] && card->marked[2][2] &&
         card->marked[3][3] && card->marked[4][4]) ||
        (card->marked[0][4] && card->marked[1][3] && card->marked[2][2] &&
         card->marked[3][1] && card->marked[4][0])) {
        return true;
    }
    return false;
}

void draw_number(int *drawn_numbers, int *drawn_count) {
    int number;
    bool unique;
    do {
        unique = true;
        number = rand() % NUMBERS + 1;

        // Check if number has already been drawn
        for (int i = 0; i < *drawn_count; i++) {
            if (drawn_numbers[i] == number) {
                unique = false;
                break;
            }
        }
    } while (!unique);

    drawn_numbers[*drawn_count] = number;
    (*drawn_count)++;
}

void mark_number(BingoCard *card, int number) {
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card->card[row][col] == number) {
                card->marked[row][col] = true;
            }
        }
    }
}

int main() {
    int num_players;
    BingoCard cards[MAX_PLAYERS];
    int drawn_numbers[NUMBERS] = {0};
    int drawn_count = 0;

    printf("Enter number of players (1 to 5): ");
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting.\n");
        return 1;
    }

    for (int i = 0; i < num_players; i++) {
        cards[i].player_number = i + 1;
        initialize_card(&cards[i]);
        printf("Player %d's Bingo Card:\n", cards[i].player_number);
        print_card(&cards[i]);
    }

    char continue_drawing = 'y';
    while (continue_drawing == 'y') {
        draw_number(drawn_numbers, &drawn_count);
        printf("Drawn number: %d\n", drawn_numbers[drawn_count - 1]);

        for (int i = 0; i < num_players; i++) {
            mark_number(&cards[i], drawn_numbers[drawn_count - 1]);
            if (check_bingo(&cards[i])) {
                printf("Player %d wins!\n", cards[i].player_number);
                return 0;  // End the program if there's a winner
            }
        }

        printf("Continue drawing? (y/n): ");
        scanf(" %c", &continue_drawing);
    }

    printf("Game ended without a winner.\n");
    return 0;
}