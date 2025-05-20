//FormAI DATASET v1.0 Category: Binary Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 20

int convertBinaryToDecimal(char binary[])
{
    int decimal = 0;
    int base = 1;
    int length = strlen(binary);

    for (int i = length - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            decimal += base;
        }

        base *= 2;
    }

    return decimal;
}

void printConverted(int players, int* converted, int currentTurn)
{
    for (int i = 0; i < players; i++)
    {
        if (i == currentTurn)
        {
            printf("You converted %d to decimal: %d \n", converted[i], convertBinaryToDecimal(converted[i]));
        }
        else
        {
            printf("Player %d converted %d to decimal: %d \n", i + 1, converted[i], convertBinaryToDecimal(converted[i]));
        }
    }
}

int main()
{
    int players, currentTurn = 0;

    printf("Welcome to the Binary Converter game!\n");
    printf("How many players will be playing? (Minimum 2): ");
    scanf("%d", &players);

    if (players < 2)
    {
        printf("Not enough players. Exiting...\n");
        exit(0);
    }

    int* converted = (int*)malloc(sizeof(int) * players);

    while (1)
    {
        printf("\nPlayer %d's turn\n", currentTurn + 1);
        printf("Enter a binary number (up to %d digits): ", MAX_INPUT_SIZE);

        char* binary = (char*)malloc(sizeof(char) * MAX_INPUT_SIZE);
        scanf("%s", binary);

        // check if string is binary
        int isBinary = 1;
        for (int i = 0; i < strlen(binary); i++)
        {
            if (binary[i] != '0' && binary[i] != '1')
            {
                isBinary = 0;
                break;
            }
        }

        if (!isBinary)
        {
            printf("Invalid input. Please enter a binary number.\n");
            continue;
        }

        converted[currentTurn] = atoi(binary);
        free(binary);
        currentTurn = (currentTurn + 1) % players;

        printf("\n");

        if (currentTurn == 0)
        {
            printConverted(players, converted, currentTurn);
        }

        // ask if users want to play again
        char* playAgain = (char*)malloc(sizeof(char) * 10);
        printf("\nDo you want to play again? (y/n): ");
        scanf("%s", playAgain);
        if (tolower(*playAgain) == 'n')
        {
            break;
        }
        free(playAgain);
    }

    free(converted);
    printf("\nThanks for playing!");
    return 0;
}