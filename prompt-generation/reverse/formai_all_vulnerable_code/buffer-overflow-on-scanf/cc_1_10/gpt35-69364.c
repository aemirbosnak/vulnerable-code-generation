//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_STRENGTH 100
#define MAX_DEVICES 10

void initializeDevices(int devices[][MAX_DEVICES]);
void updatePlayerStrength(int playerStrength[], int devices[][MAX_DEVICES], int playerCount);
void displayPlayerStrength(int playerStrength[], int playerCount);
void findWinners(int playerStrength[], int playerCount, int winners[]);

int main()
{
    int devices[MAX_PLAYERS][MAX_DEVICES];
    int playerStrength[MAX_PLAYERS] = { 0 };
    int winners[MAX_PLAYERS] = { 0 };
    int playerCount;

    srand(time(NULL));

    printf("Welcome to Wi-Fi Signal Strength Analyzer!\n");
    printf("Enter the number of players (1-4): ");
    scanf("%d", &playerCount);

    if (playerCount < 1 || playerCount > MAX_PLAYERS)
    {
        printf("Invalid number of players. Program will now exit.\n");
        exit(0);
    }

    initializeDevices(devices);
    updatePlayerStrength(playerStrength, devices, playerCount);
    displayPlayerStrength(playerStrength, playerCount);
    findWinners(playerStrength, playerCount, winners);

    printf("The winners are player(s): ");
    for (int i = 0; i < playerCount; i++)
    {
        if (winners[i] == 1)
        {
            printf("%d ", i + 1);
        }
    }

    return 0;
}

void initializeDevices(int devices[][MAX_DEVICES])
{
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        for (int j = 0; j < MAX_DEVICES; j++)
        {
            devices[i][j] = rand() % MAX_STRENGTH;
        }
    }
}

void updatePlayerStrength(int playerStrength[], int devices[][MAX_DEVICES], int playerCount)
{
    int deviceCount = MAX_DEVICES / playerCount;
    int deviceIndex = 0;

    for (int i = 0; i < playerCount; i++)
    {
        for (int j = 0; j < deviceCount; j++)
        {
            playerStrength[i] += devices[i][deviceIndex];
            deviceIndex++;
        }
    }
}

void displayPlayerStrength(int playerStrength[], int playerCount)
{
    printf("Player Strengths:\n");
    for (int i = 0; i < playerCount; i++)
    {
        printf("Player %d: %d\n", i + 1, playerStrength[i]);
    }
}

void findWinners(int playerStrength[], int playerCount, int winners[])
{
    int maxStrength = 0;

    for (int i = 0; i < playerCount; i++)
    {
        if (playerStrength[i] > maxStrength)
        {
            maxStrength = playerStrength[i];
        }
    }

    for (int i = 0; i < playerCount; i++)
    {
        if (playerStrength[i] == maxStrength)
        {
            winners[i] = 1;
        }
    }
}