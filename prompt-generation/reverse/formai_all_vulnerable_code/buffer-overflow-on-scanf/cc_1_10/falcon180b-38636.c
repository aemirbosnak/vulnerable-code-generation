//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CARDS 20
#define MAX_NUMBERS 75

typedef struct {
    char name[20];
    int cards[MAX_CARDS];
} Player;

void generateCard(int card[5]) {
    for (int i = 0; i < 5; i++) {
        card[i] = rand() % MAX_NUMBERS + 1;
    }
}

void printCard(int card[5]) {
    for (int i = 0; i < 5; i++) {
        printf("%d ", card[i]);
    }
    printf("\n");
}

int checkBingo(int card[5], int numbers[MAX_NUMBERS]) {
    for (int i = 0; i < 5; i++) {
        if (card[i]!= numbers[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int numbers[MAX_NUMBERS];
    int i, j, k;

    for (i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
    }

    for (i = 0; i < MAX_NUMBERS; i++) {
        numbers[i] = rand() % MAX_NUMBERS + 1;
    }

    for (i = 0; i < MAX_PLAYERS; i++) {
        for (j = 0; j < MAX_CARDS; j++) {
            generateCard(players[i].cards + j * 5);
        }
    }

    int bingoCount = 0;
    while (bingoCount < MAX_PLAYERS) {
        for (i = 0; i < MAX_NUMBERS; i++) {
            printf("%d ", numbers[i]);
        }
        printf("\n");
        for (i = 0; i < MAX_PLAYERS; i++) {
            for (j = 0; j < MAX_CARDS; j++) {
                if (checkBingo(players[i].cards + j * 5, numbers)) {
                    printf("%s got BINGO!\n", players[i].name);
                    bingoCount++;
                    break;
                }
            }
        }
    }

    return 0;
}