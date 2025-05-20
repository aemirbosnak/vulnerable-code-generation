//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define NUM_CARDS 6
#define MATCH 1
#define NOT_MATCH 0
#define TURN_TIME 5000 // 5 seconds

typedef struct {
    int row;
    int col;
    int value;
    int is_revealed;
} Card;

Card deck[NUM_CARDS];
int num_revealed_cards = 0;
int num_matches = 0;
int player_score = 0;

void init_deck() {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        deck[i].row = i / COLS;
        deck[i].col = i % COLS;
        deck[i].value = i + 1;
        deck[i].is_revealed = 0;
    }
}

void print_deck() {
    int i;
    for (i = 0; i < NUM_CARDS; i++) {
        if (deck[i].is_revealed) {
            printf(" %d ", deck[i].value);
        } else {
            printf(" X ");
        }
    }
    printf("\n");
}

void reveal_card(int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        int card_index = row * COLS + col;
        if (deck[card_index].is_revealed) {
            printf("Card is already revealed.\n");
        } else {
            deck[card_index].is_revealed = 1;
            num_revealed_cards++;
            if (deck[card_index].value == deck[card_index + 1].value) {
                num_matches++;
                player_score += 10;
            } else {
                player_score -= 5;
            }
            printf("Score: %d\n", player_score);
            print_deck();
            if (num_revealed_cards == NUM_CARDS) {
                printf("Game over.\n");
                exit(0);
            }
        }
    } else {
        printf("Invalid position.\n");
    }
}

int main() {
    srand(time(NULL));
    init_deck();
    printf("Welcome to Memory Game!\n\n");
    print_deck();
    int choice;
    while (1) {
        printf("Enter your choice (row col): ");
        scanf("%d %d", &choice, &choice);
        reveal_card(choice % ROWS, choice % COLS);
        usleep(TURN_TIME);
    }
    return 0;
}