//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 2

typedef struct Player
{
    char name[20];
    int score;
    int pos;
} Player;

void initializePlayers(Player *players, int numPlayers)
{
    for (int i = 0; i < numPlayers; i++)
    {
        players[i].name[0] = '\0';
        players[i].score = 0;
        players[i].pos = 0;
    }
}

void displayPlayers(Player *players, int numPlayers)
{
    for (int i = 0; i < numPlayers; i++)
    {
        printf("%s: %d, position: %d\n", players[i].name, players[i].score, players[i].pos);
    }
}

int main()
{
    Player players[MAX_Players];
    initializePlayers(players, MAX_Players);

    // Game loop
    while (1)
    {
        // Get player inputs
        char move;
        int targetPos;

        // Display current players' positions
        displayPlayers(players, MAX_Players);

        // Make move
        printf("Enter move (forward/back): ");
        scanf("%c", &move);

        // Validate move
        if (move != 'f' && move != 'b')
        {
            printf("Invalid move.\n");
            continue;
        }

        // Get target position
        printf("Enter target position: ");
        scanf("%d", &targetPos);

        // Move player
        for (int i = 0; i < MAX_Players; i++)
        {
            if (players[i].name[0] != '\0')
            {
                if (players[i].pos == targetPos)
                {
                    players[i].score++;
                    printf("%s has reached the target position and scored a point!\n", players[i].name);
                }
                else if (move == 'f')
                {
                    players[i].pos++;
                }
                else if (move == 'b')
                {
                    players[i].pos--;
                }
            }
        }

        // Check if game is over
        if (players[0].score >= 5 || players[1].score >= 5)
        {
            printf("Game over! Winner: %s\n", players[0].name);
            break;
        }
    }

    return 0;
}