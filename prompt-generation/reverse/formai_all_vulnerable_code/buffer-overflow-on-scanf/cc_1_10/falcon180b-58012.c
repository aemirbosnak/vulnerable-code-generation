//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10
#define MAX_NUMBERS 75
#define MAX_BINGO_CARDS 5

typedef struct {
    int numbers[MAX_NUMBERS];
    int count;
} BingoCard;

typedef struct {
    char name[20];
    int cards[MAX_BINGO_CARDS];
    int score;
} Player;

void generateBingoCard(BingoCard *card) {
    srand(time(NULL));
    for (int i = 0; i < MAX_NUMBERS; i++) {
        card->numbers[i] = rand() % MAX_NUMBERS + 1;
    }
    card->count = 0;
}

void printBingoCard(BingoCard *card) {
    for (int i = 0; i < MAX_NUMBERS; i++) {
        printf("%d ", card->numbers[i]);
    }
    printf("\n");
}

void markNumber(BingoCard *card, int number) {
    for (int i = 0; i < MAX_NUMBERS; i++) {
        if (card->numbers[i] == number) {
            card->numbers[i] = 0;
            card->count++;
            break;
        }
    }
}

int checkWin(BingoCard *card) {
    for (int i = 0; i < MAX_NUMBERS; i++) {
        if (card->numbers[i]!= 0) {
            return 0;
        }
    }
    return 1;
}

void playBingo(Player *players, int numPlayers, int numCards) {
    int nums[MAX_NUMBERS];
    for (int i = 0; i < numCards; i++) {
        for (int j = 0; j < MAX_NUMBERS; j++) {
            nums[j] = rand() % MAX_NUMBERS + 1;
        }
        for (int j = 0; j < numPlayers; j++) {
            for (int k = 0; k < MAX_BINGO_CARDS; k++) {
                if (players[j].cards[k] == i) {
                    for (int l = 0; l < MAX_NUMBERS; l++) {
                        markNumber(&(players[j].cards[k]), nums[l]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < numPlayers; i++) {
        for (int j = 0; j < MAX_BINGO_CARDS; j++) {
            if (checkWin(&(players[i].cards[j]))) {
                players[i].score++;
            }
        }
    }
}

int main() {
    int numPlayers, numCards;
    printf("Enter number of players: ");
    scanf("%d", &numPlayers);
    printf("Enter number of bingo cards per player: ");
    scanf("%d", &numCards);

    Player players[MAX_PLAYERS];
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        for (int j = 0; j < numCards; j++) {
            generateBingoCard(&(players[i].cards[j]));
        }
    }

    playBingo(players, numPlayers, numCards);

    for (int i = 0; i < numPlayers; i++) {
        printf("Player %s's score: %d\n", players[i].name, players[i].score);
    }

    return 0;
}