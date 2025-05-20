//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CARDS 75
#define MAX_NUMBERS 75

typedef struct {
    char name[20];
    int card[MAX_CARDS];
} Player;

void generateCard(int card[MAX_CARDS]) {
    srand(time(NULL));
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

void playBingo(Player players[MAX_PLAYERS], int numbers[MAX_NUMBERS]) {
    for (int i = 0; i < MAX_NUMBERS; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    for (int i = 0; i < MAX_PLAYERS; i++) {
        for (int j = 0; j < MAX_CARDS; j++) {
            if (players[i].card[j] == numbers[i]) {
                printf("%s got a bingo!\n", players[i].name);
                return;
            }
        }
    }

    printf("No one got a bingo.\n");
}

int main() {
    Player players[MAX_PLAYERS];
    int numbers[MAX_NUMBERS];

    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        generateCard(players[i].card);
    }

    for (int i = 0; i < MAX_NUMBERS; i++) {
        numbers[i] = rand() % MAX_NUMBERS + 1;
    }

    playBingo(players, numbers);

    return 0;
}