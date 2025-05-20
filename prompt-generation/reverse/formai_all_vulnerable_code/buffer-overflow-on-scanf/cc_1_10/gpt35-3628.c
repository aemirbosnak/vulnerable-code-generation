//FormAI DATASET v1.0 Category: QR code generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10
#define QR_SIZE 50

void generateRandomQR(char* qrStr)
{
    char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;
    for (i = 0; i < QR_SIZE; i++)
    {
        qrStr[i] = charset[rand() % (int)(sizeof(charset) - 1)];
    }
    qrStr[i] = '\0';
}

int main()
{
    int numPlayers = 0, i, j;
    char playerNames[MAX_PLAYERS][30];
    char playerQR[MAX_PLAYERS][QR_SIZE];
    srand(time(NULL));

    // Get number of players
    do
    {
        printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
        scanf("%d", &numPlayers);
    } while (numPlayers < 1 || numPlayers > MAX_PLAYERS);

    // Get player names
    printf("\nEnter the player names:\n");
    for (i = 0; i < numPlayers; i++)
    {
        printf("Player %d: ", i + 1);
        scanf("%s", playerNames[i]);
    }

    // Generate player QR codes
    printf("\nGenerating QR codes...\n");
    for (i = 0; i < numPlayers; i++)
    {
        generateRandomQR(playerQR[i]);
        for (j = 0; j < i; j++)
        {
            if (strcmp(playerQR[i], playerQR[j]) == 0)
            {
                // Duplicate QR code found, regenerate
                generateRandomQR(playerQR[i]);
                j = -1;
            }
        }
        printf("Player %s - QR code: %s\n", playerNames[i], playerQR[i]);
    }

    return 0;
}