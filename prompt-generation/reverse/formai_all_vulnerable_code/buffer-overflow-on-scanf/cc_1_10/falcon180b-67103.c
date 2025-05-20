//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10
#define MAX_NUMBERS 75

typedef struct {
    int numbers[MAX_NUMBERS];
    int num_called;
} BingoCard;

void generate_card(BingoCard *card) {
    for (int i = 0; i < MAX_NUMBERS; i++) {
        card->numbers[i] = rand() % 15 + 1;
    }
}

void print_card(BingoCard *card) {
    for (int i = 0; i < MAX_NUMBERS; i++) {
        printf("%d ", card->numbers[i]);
    }
    printf("\n");
}

int compare_cards(BingoCard *card1, BingoCard *card2) {
    for (int i = 0; i < MAX_NUMBERS; i++) {
        if (card1->numbers[i]!= card2->numbers[i]) {
            return card1->numbers[i] - card2->numbers[i];
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));

    int num_players;
    printf("Enter number of players: ");
    scanf("%d", &num_players);

    BingoCard cards[num_players];
    for (int i = 0; i < num_players; i++) {
        generate_card(&cards[i]);
    }

    int num_called = 0;
    while (num_called < MAX_NUMBERS) {
        int num = rand() % 15 + 1;
        for (int i = 0; i < num_players; i++) {
            if (cards[i].numbers[num_called] == num) {
                cards[i].numbers[num_called] = -1;
            }
        }
        printf("Called number: %d\n", num);
        num_called++;
    }

    for (int i = 0; i < num_players; i++) {
        int score = 0;
        for (int j = 0; j < MAX_NUMBERS; j++) {
            if (cards[i].numbers[j]!= -1) {
                score++;
            }
        }
        printf("Player %d score: %d\n", i+1, score);
    }

    return 0;
}