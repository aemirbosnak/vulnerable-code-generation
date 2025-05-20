//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10
#define MAX_NUMBERS 75

typedef struct {
    int num;
    char called;
} BingoNumber;

typedef struct {
    BingoNumber numbers[MAX_NUMBERS];
    int numCards;
} BingoCard;

typedef struct {
    BingoCard card;
    int score;
} Player;

void initBingoCard(BingoCard* card) {
    int i;

    for (i = 0; i < MAX_NUMBERS; i++) {
        card->numbers[i].num = i + 1;
        card->numbers[i].called = 0;
    }

    card->numCards = 0;
}

void addNumber(BingoNumber* num, int value) {
    num->num = value;
    num->called = 0;
}

void printBingoCard(BingoCard* card) {
    int i, j;

    for (i = 0; i < card->numCards; i++) {
        for (j = 0; j < MAX_NUMBERS; j++) {
            if (card->numbers[j].num == i + 1) {
                printf("%d ", i + 1);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

void markNumber(BingoNumber* num, int value) {
    if (num->num == value) {
        num->called = 1;
    }
}

int checkWin(BingoCard* card) {
    int i, j;
    int wins = 0;

    for (i = 0; i < MAX_NUMBERS; i++) {
        if (card->numbers[i].called) {
            wins++;

            if (wins == 5) {
                return 1;
            }
        }
    }

    return 0;
}

void playBingo(Player* players, int numPlayers, int numCards) {
    int i, j;
    int value;
    int wins = 0;

    srand(time(NULL));

    for (i = 0; i < numCards; i++) {
        value = rand() % MAX_NUMBERS + 1;

        for (j = 0; j < numPlayers; j++) {
            markNumber(&players[j].card.numbers[value - 1], value);
        }
    }

    while (wins < numPlayers) {
        printf("Calling number: %d\n", rand() % MAX_NUMBERS + 1);

        for (i = 0; i < numPlayers; i++) {
            if (checkWin(&players[i].card)) {
                printf("Player %d wins!\n", i + 1);
                wins++;
            }
        }
    }
}

int main() {
    int numPlayers;
    int numCards;

    printf("Enter number of players: ");
    scanf("%d", &numPlayers);

    printf("Enter number of cards per player: ");
    scanf("%d", &numCards);

    Player players[MAX_PLAYERS];

    for (int i = 0; i < numPlayers; i++) {
        initBingoCard(&players[i].card);
        players[i].score = 0;
    }

    playBingo(players, numPlayers, numCards);

    return 0;
}