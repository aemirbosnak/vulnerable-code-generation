//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 75
#define MAX_CARDS 5
#define MAX_PLAYERS 10

typedef struct {
    int numbers[MAX_NUMBERS];
    int marked[MAX_NUMBERS];
    int num_marked;
} BingoCard;

void generateCard(BingoCard* card) {
    for (int i = 0; i < MAX_NUMBERS; i++) {
        card->numbers[i] = rand() % 75 + 1;
        card->marked[i] = 0;
    }
}

void printCard(BingoCard* card) {
    for (int i = 0; i < MAX_NUMBERS; i++) {
        if (i % 5 == 0) {
            printf("\n");
        }
        printf("%d ", card->numbers[i]);
    }
}

int checkWin(BingoCard* card, int num) {
    for (int i = 0; i < MAX_NUMBERS; i++) {
        if (card->numbers[i] == num) {
            card->marked[i] = 1;
            card->num_marked++;
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    BingoCard cards[MAX_PLAYERS];
    int num_players;

    printf("Welcome to Bingo!\n");
    printf("How many players? ");
    scanf("%d", &num_players);

    for (int i = 0; i < num_players; i++) {
        generateCard(&cards[i]);
        printf("Player %d's card:\n", i + 1);
        printCard(&cards[i]);
    }

    int num_called = 0;
    while (num_called < MAX_NUMBERS) {
        int num = rand() % 75 + 1;
        printf("Number called: %d\n", num);
        for (int i = 0; i < num_players; i++) {
            if (checkWin(&cards[i], num)) {
                printf("Player %d wins!\n", i + 1);
                return 0;
            }
        }
        num_called++;
    }

    printf("No winner.\n");
    return 0;
}