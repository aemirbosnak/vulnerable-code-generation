//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_CARDS 25

void generate_card(int *card, int max_value) {
    int value = rand() % max_value + 1;
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (value == (i * MAX_COLS + j) + 1) {
                card[i * MAX_COLS + j] = value;
            }
        }
    }
}

void print_card(int *card) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%d ", card[i * MAX_COLS + j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int cards[MAX_CARDS];
    for (int i = 0; i < MAX_CARDS; i++) {
        generate_card(cards + i * MAX_ROWS * MAX_COLS, MAX_ROWS * MAX_COLS);
    }

    int player_score = 0;
    int computer_score = 0;

    while (player_score < 5 && computer_score < 5) {
        for (int i = 0; i < MAX_CARDS; i++) {
            int card_value = cards[i * MAX_ROWS * MAX_COLS + (MAX_ROWS - 1) * MAX_COLS + (MAX_COLS - 1)];
            if (card_value % 2 == 0) {
                player_score++;
                printf("You got a %d card!\n", card_value);
            } else {
                computer_score++;
                printf("Computer got a %d card!\n", card_value);
            }
            cards[i * MAX_ROWS * MAX_COLS + (MAX_ROWS - 1) * MAX_COLS + (MAX_COLS - 1)] = 0;
        }
    }

    if (player_score == 5) {
        printf("You win!\n");
    } else if (computer_score == 5) {
        printf("Computer wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}