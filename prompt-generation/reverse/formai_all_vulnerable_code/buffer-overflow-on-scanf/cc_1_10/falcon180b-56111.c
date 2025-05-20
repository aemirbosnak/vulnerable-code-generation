//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10
#define MAX_BINGO_NUMBERS 75

typedef struct {
    int numbers[MAX_BINGO_NUMBERS];
    int num_marked;
} BingoCard;

typedef struct {
    char name[20];
    BingoCard card;
} Player;

void create_bingo_card(BingoCard *card) {
    int i;
    for (i = 0; i < MAX_BINGO_NUMBERS; i++) {
        card->numbers[i] = rand() % 100;
    }
}

int mark_number(BingoCard *card, int num) {
    int i;
    for (i = 0; i < MAX_BINGO_NUMBERS; i++) {
        if (card->numbers[i] == num) {
            card->numbers[i] = -1;
            card->numbers[i] = num;
            return 1;
        }
    }
    return 0;
}

int check_bingo(BingoCard *card) {
    int i, j;
    for (i = 0; i < MAX_BINGO_NUMBERS; i++) {
        for (j = i+1; j < MAX_BINGO_NUMBERS; j++) {
            if (card->numbers[i] == card->numbers[j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int i, j;
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    int num_players = 0;

    printf("Enter number of players (up to %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    for (i = 0; i < num_players; i++) {
        printf("Enter name of player %d: ", i+1);
        scanf("%s", players[i].name);
        create_bingo_card(&players[i].card);
    }

    int num_called = 0;
    while (num_called < MAX_BINGO_NUMBERS) {
        int num = rand() % 100;
        for (i = 0; i < num_players; i++) {
            if (mark_number(&players[i].card, num)) {
                printf("%s marked %d\n", players[i].name, num);
                num_called++;
            }
        }
    }

    printf("Game over!\n");

    for (i = 0; i < num_players; i++) {
        if (check_bingo(&players[i].card)) {
            printf("%s wins!\n", players[i].name);
        }
    }

    return 0;
}