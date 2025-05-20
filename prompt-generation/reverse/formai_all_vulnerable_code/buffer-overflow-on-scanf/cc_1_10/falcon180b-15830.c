//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10
#define MAX_NUMBERS 75

typedef struct {
    char name[50];
    int card[MAX_CARDS];
} Player;

void generateCard(Player* player) {
    for (int i = 0; i < MAX_CARDS; i++) {
        player->card[i] = rand() % MAX_NUMBERS + 1;
    }
}

void printCard(Player* player) {
    for (int i = 0; i < MAX_CARDS; i++) {
        printf("%d ", player->card[i]);
    }
    printf("\n");
}

void callNumber(int number) {
    printf("Called number: %d\n", number);
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int numPlayers;

    printf("Enter number of players: ");
    scanf("%d", &numPlayers);

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        generateCard(&players[i]);
    }

    int calledNumbers[MAX_NUMBERS];
    memset(calledNumbers, 0, sizeof(calledNumbers));

    int currentNumber = 1;
    while (currentNumber <= MAX_NUMBERS) {
        if (currentNumber % 15 == 0 && currentNumber!= 75) {
            printf("Bingo!\n");
            break;
        } else if (currentNumber % 5 == 0 && currentNumber!= 75) {
            printf("Line!\n");
        }
        int found = 0;
        for (int i = 0; i < numPlayers; i++) {
            for (int j = 0; j < MAX_CARDS; j++) {
                if (players[i].card[j] == currentNumber) {
                    printCard(&players[i]);
                    found = 1;
                    break;
                }
            }
            if (found) break;
        }
        if (!found) {
            callNumber(currentNumber);
            currentNumber++;
        }
    }

    return 0;
}