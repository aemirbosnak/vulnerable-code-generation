//Falcon-180B DATASET v1.0 Category: Table Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 5

typedef struct {
    char name[20];
    int score;
} Player;

void initPlayers(Player players[]) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].score = 0;
        sprintf(players[i].name, "Player %d", i + 1);
    }
}

void printScore(Player players[], int numPlayers) {
    printf("=== SCOREBOARD ===\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int rollDice() {
    return rand() % 6 + 1;
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    initPlayers(players);
    int numPlayers = 0;
    char input[20];

    while (numPlayers < MAX_PLAYERS) {
        printf("Enter your name: ");
        scanf("%s", input);
        for (int i = 0; i < numPlayers; i++) {
            if (strcmp(players[i].name, input) == 0) {
                printf("%s is already playing!\n", input);
            }
        }
        strcpy(players[numPlayers].name, input);
        numPlayers++;
    }

    int round = 1;
    while (round <= MAX_ROUNDS) {
        for (int i = 0; i < numPlayers; i++) {
            printf("%s's turn (round %d): ", players[i].name, round);
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                players[i].score += rollDice() + rollDice();
            } else if (choice == 2) {
                players[i].score += 3 * rollDice();
            } else {
                players[i].score -= rollDice();
            }
        }
        printScore(players, numPlayers);
        round++;
    }

    printf("=== GAME OVER ===\n");
    return 0;
}