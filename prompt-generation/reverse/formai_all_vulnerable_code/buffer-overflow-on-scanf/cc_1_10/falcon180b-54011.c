//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_CARDS 100
#define MAX_BINGO_NUMBERS 75
#define MAX_PLAYERS 10

typedef struct {
    int numbers[MAX_BINGO_NUMBERS];
    int currentNumber;
    int wins;
} BingoCard;

typedef struct {
    char name[20];
    BingoCard card;
} Player;

int generateBingoCard(BingoCard *card) {
    int i;
    for (i = 0; i < MAX_BINGO_NUMBERS; i++) {
        card->numbers[i] = rand() % 75 + 1;
    }
    card->currentNumber = 1;
    return 0;
}

int checkBingo(BingoCard *card, int num) {
    int i;
    for (i = 0; i < MAX_BINGO_NUMBERS; i++) {
        if (card->numbers[i] == num) {
            card->numbers[i] = 0;
            card->wins++;
            return 1;
        }
    }
    return 0;
}

int main() {
    int i, j, num, playerWins[MAX_PLAYERS] = {0};
    char input[20];
    srand(time(NULL));
    BingoCard cards[MAX_BINGO_CARDS];
    Player players[MAX_PLAYERS];

    printf("Welcome to the Happy Bingo Game!\n");
    printf("How many players will be playing? ");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", input);
        strcpy(players[i].name, input);
        generateBingoCard(&players[i].card);
    }

    int currentNumber = 1;
    while (1) {
        for (i = 0; i < num; i++) {
            if (checkBingo(&players[i].card, currentNumber)) {
                printf("%s wins with %d numbers!\n", players[i].name, players[i].card.wins);
                playerWins[i]++;
                break;
            }
        }
        if (i == num) {
            currentNumber++;
        }
        if (currentNumber > MAX_BINGO_NUMBERS) {
            break;
        }
    }

    for (i = 0; i < num; i++) {
        printf("Player %s has %d wins.\n", players[i].name, playerWins[i]);
    }

    return 0;
}