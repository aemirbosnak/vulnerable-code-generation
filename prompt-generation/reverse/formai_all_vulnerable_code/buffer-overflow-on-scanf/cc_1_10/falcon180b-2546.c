//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_bingo_card(int card[5][5]) {
    int i, j;

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

int is_valid_card(int card[5][5]) {
    int i, j;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            if(card[i][j] < 1 || card[i][j] > 15) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int num_cards;
    srand(time(NULL));

    printf("Welcome to the BINGO Simulator!\n");
    printf("How many cards would you like to play with? ");
    scanf("%d", &num_cards);

    int **cards = (int **) malloc(num_cards * sizeof(int *));
    for(int i = 0; i < num_cards; i++) {
        cards[i] = (int *) malloc(25 * sizeof(int));
        for(int j = 0; j < 25; j++) {
            cards[i][j] = rand() % 16 + 1;
        }
    }

    int player_wins = 0;
    int called_numbers[75] = {0};
    int num_called = 0;

    while(num_called < 75) {
        int i = rand() % 75;
        while(called_numbers[i] == 1) {
            i = rand() % 75;
        }
        called_numbers[i] = 1;
        num_called++;

        for(int j = 0; j < num_cards; j++) {
            int matches = 0;
            for(int k = 0; k < 25; k++) {
                if(cards[j][k] == i) {
                    matches++;
                }
            }
            if(matches == 5) {
                printf("Player %d wins!\n", j + 1);
                player_wins++;
            }
        }
    }

    printf("Game over!\n");
    printf("Number of cards played: %d\n", num_cards);
    printf("Number of players who won: %d\n", player_wins);

    for(int i = 0; i < num_cards; i++) {
        free(cards[i]);
    }
    free(cards);

    return 0;
}