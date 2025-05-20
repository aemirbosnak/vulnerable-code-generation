//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10
#define MAX_NUMBERS 75

typedef struct {
    char name[20];
    int card[MAX_CARDS];
} Player;

void generateCard(int card[MAX_CARDS]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        card[i] = rand() % MAX_NUMBERS + 1;
    }
}

void printCard(int card[MAX_CARDS]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        printf("%d ", card[i]);
    }
    printf("\n");
}

int checkBingo(int card[MAX_CARDS], int num) {
    for (int i = 0; i < MAX_CARDS; i++) {
        if (card[i] == num) {
            return 1;
        }
    }
    return 0;
}

void playBingo(Player players[MAX_PLAYERS], int nums[MAX_NUMBERS]) {
    srand(time(NULL));
    for (int i = 0; i < MAX_PLAYERS; i++) {
        generateCard(players[i].card);
    }

    int currentNum = 1;
    while (currentNum <= MAX_NUMBERS) {
        printf("Current number: %d\n", currentNum);
        for (int i = 0; i < MAX_PLAYERS; i++) {
            printCard(players[i].card);
        }

        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (checkBingo(players[i].card, currentNum)) {
                printf("%s won!\n", players[i].name);
                break;
            }
        }

        if (currentNum == MAX_NUMBERS) {
            printf("No winner.\n");
        }

        currentNum++;
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Enter number of players (1-10): ");
    scanf("%d", &numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
    }

    playBingo(players, NULL);

    return 0;
}