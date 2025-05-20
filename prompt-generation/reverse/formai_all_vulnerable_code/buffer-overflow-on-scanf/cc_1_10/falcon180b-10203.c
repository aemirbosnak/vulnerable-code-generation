//Falcon-180B DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_ROUNDS 100
#define MAX_SCORE 100

typedef struct
{
    char name[50];
    int score;
} Player;

void initializePlayers(Player players[])
{
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        strcpy(players[i].name, "Player");
        players[i].score = 0;
    }
}

void displayScore(Player players[], int numPlayers)
{
    printf("Player\tScore\n");
    for (int i = 0; i < numPlayers; i++)
    {
        printf("%s\t%d\n", players[i].name, players[i].score);
    }
}

void playRound(Player players[], int numPlayers)
{
    int diceRoll;
    for (int i = 0; i < numPlayers; i++)
    {
        diceRoll = rand() % 6 + 1;
        players[i].score += diceRoll;
    }
}

int main()
{
    Player players[MAX_PLAYERS];
    initializePlayers(players);

    int numPlayers = 0;
    char input[50];
    printf("Enter your name: ");
    scanf("%s", input);
    strcpy(players[numPlayers].name, input);
    numPlayers++;

    while (numPlayers < MAX_PLAYERS)
    {
        printf("Enter the name of the next player: ");
        scanf("%s", input);
        strcpy(players[numPlayers].name, input);
        numPlayers++;
    }

    int numRounds = 0;
    while (numRounds < MAX_ROUNDS)
    {
        playRound(players, numPlayers);
        numRounds++;
    }

    displayScore(players, numPlayers);

    return 0;
}