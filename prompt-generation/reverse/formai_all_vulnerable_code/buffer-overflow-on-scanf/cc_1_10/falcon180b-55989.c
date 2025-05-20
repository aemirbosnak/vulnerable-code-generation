//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_NUMBERS 75

typedef struct {
    int numbers[MAX_NUMBERS];
    int num_called;
} Card;

void init_card(Card* card) {
    for (int i = 0; i < MAX_NUMBERS; i++) {
        card->numbers[i] = i + 1;
    }
    card->numbers[MAX_NUMBERS - 1] = 0;
    card->num_called = 0;
}

void print_card(Card* card) {
    printf("Card:\n");
    for (int i = 0; i < MAX_NUMBERS; i++) {
        if (card->numbers[i] == 0) {
            printf(" ");
        } else {
            printf("%d ", card->numbers[i]);
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int num_cards;
    printf("How many cards do you want to play with? ");
    scanf("%d", &num_cards);

    Card cards[num_cards];

    for (int i = 0; i < num_cards; i++) {
        init_card(&cards[i]);
    }

    int num_players;
    printf("How many players are there? ");
    scanf("%d", &num_players);

    int winner = -1;

    while (winner == -1) {
        for (int i = 0; i < num_cards; i++) {
            print_card(&cards[i]);
        }

        int num_called = 0;
        while (num_called < MAX_NUMBERS) {
            int num = rand() % MAX_NUMBERS + 1;
            for (int i = 0; i < num_cards; i++) {
                if (cards[i].numbers[num] == 0) {
                    cards[i].numbers[num] = 1;
                    num_called++;
                    break;
                }
            }
        }

        for (int i = 0; i < num_players; i++) {
            int is_winner = 1;
            for (int j = 0; j < MAX_NUMBERS; j++) {
                if (cards[i].numbers[j] == 0) {
                    is_winner = 0;
                    break;
                }
            }
            if (is_winner) {
                winner = i;
                break;
            }
        }
    }

    printf("Player %d wins!\n", winner + 1);

    return 0;
}