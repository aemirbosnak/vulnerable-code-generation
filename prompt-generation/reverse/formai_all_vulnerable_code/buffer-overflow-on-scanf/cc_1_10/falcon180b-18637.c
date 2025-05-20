//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_NUMBERS 24

typedef struct {
    int rows;
    int cols;
    int numbers[MAX_NUMBERS];
} bingo_card_t;

void initialize_card(bingo_card_t* card) {
    srand(time(NULL));
    card->rows = rand() % MAX_ROWS + 1;
    card->cols = rand() % MAX_COLS + 1;
    for (int i = 0; i < MAX_NUMBERS; i++) {
        card->numbers[i] = rand() % MAX_NUMBERS + 1;
    }
}

void print_card(bingo_card_t* card) {
    printf("Bingo Card:\n");
    for (int i = 0; i < card->rows; i++) {
        for (int j = 0; j < card->cols; j++) {
            printf("%d ", card->numbers[i * card->cols + j]);
        }
        printf("\n");
    }
}

int main() {
    int players;
    printf("How many players? ");
    scanf("%d", &players);

    bingo_card_t* cards = malloc(players * sizeof(bingo_card_t));

    printf("Generating Bingo Cards...\n");
    for (int i = 0; i < players; i++) {
        initialize_card(&cards[i]);
    }

    int current_number = 1;
    while (current_number <= MAX_NUMBERS) {
        printf("\nCurrent Number: %d\n", current_number);
        for (int i = 0; i < players; i++) {
            bingo_card_t* card = &cards[i];
            for (int j = 0; j < card->rows * card->cols; j++) {
                if (card->numbers[j] == current_number) {
                    printf("Player %d has %d\n", i+1, current_number);
                }
            }
        }
        current_number++;
    }

    printf("\nGame Over!\n");

    return 0;
}