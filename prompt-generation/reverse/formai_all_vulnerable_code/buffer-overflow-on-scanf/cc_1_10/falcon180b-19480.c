//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_NUMBERS 24

void generate_bingo_card(int card[MAX_ROWS][MAX_COLS]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            card[i][j] = rand() % MAX_NUMBERS + 1;
        }
    }
}

void print_bingo_card(int card[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int num_players, num_cards;
    printf("Welcome to the Bingo Simulator!\n");
    printf("How many players are there? ");
    scanf("%d", &num_players);
    printf("How many cards do you want to generate? ");
    scanf("%d", &num_cards);

    int cards[num_cards][MAX_ROWS][MAX_COLS];
    int i, j, k;
    for (i = 0; i < num_cards; i++) {
        generate_bingo_card(cards[i]);
    }

    printf("\nHere are the bingo cards:\n");
    for (i = 0; i < num_cards; i++) {
        printf("Player %d's card:\n", i + 1);
        print_bingo_card(cards[i]);
    }

    return 0;
}