//Falcon-180B DATASET v1.0 Category: Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int score;
    char name[20];
} Player;

void drawBoard(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d: %s - Score: %d\n", i+1, players[i].name, players[i].score);
    }
}

void playRound(Player players[], int numPlayers) {
    int roll;
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d, roll the dice!\n", i+1);
        roll = rand() % 6 + 1;
        printf("You rolled a %d!\n", roll);
        players[i].score += roll;
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int numPlayers;
    printf("How many players? ");
    scanf("%d", &numPlayers);

    Player players[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        players[i].x = 0;
        players[i].y = 0;
        players[i].score = 0;
    }

    int currentPlayer = 0;
    while (1) {
        system("clear");
        drawBoard(players, numPlayers);
        printf("\nCurrent player: %s\n", players[currentPlayer].name);

        playRound(players, numPlayers);

        currentPlayer = (currentPlayer + 1) % numPlayers;

        if (players[currentPlayer].score >= 100) {
            printf("\nPlayer %s wins!\n", players[currentPlayer].name);
            break;
        }
    }

    return 0;
}