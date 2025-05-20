//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4

struct Player
{
    char name[16];
    int score;
};

void clearScreen()
{
    system("clear||cls");
}

void printHeader(char *text)
{
    clearScreen();
    printf("+----------------------------------------------------------------+\n");
    printf("| %-62s |\n", text);
    printf("+----------------------------------------------------------------+\n\n");
}

void printMenu()
{
    printHeader("MAIN MENU");

    printf("1. New Game\n");
    printf("2. View High Scores\n");
    printf("3. Quit\n\n");
}

void printScores(struct Player *players, int numPlayers)
{
    printHeader("HIGH SCORES");

    printf("NAME\t\tSCORE\n");
    printf("----\t\t-----\n");

    for (int i = 0; i < numPlayers; i++)
    {
        printf("%-16s\t%d\n", players[i].name, players[i].score);
    }

    printf("\nPress any key to continue...");
    getchar();
}

void assignRandomScores(struct Player *players, int numPlayers)
{
    for (int i = 0; i < numPlayers; i++)
    {
        players[i].score = rand() % 10000;
    }
}

void playGame(char *gameName)
{
    printHeader("NEW GAME");

    printf("Welcome to %s!\n\n", gameName);
    printf("Enter the number of players (1-4): ");

    int numPlayers;
    scanf("%d", &numPlayers);

    while (numPlayers < 1 || numPlayers > MAX_PLAYERS)
    {
        printf("Invalid number of players. Please enter a number between 1 and %d: ", MAX_PLAYERS);
        scanf("%d", &numPlayers);
    }

    struct Player players[numPlayers];

    for (int i = 0; i < numPlayers; i++)
    {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    printf("\nStarting new game with %d player(s)! Press any key to continue...", numPlayers);
    getchar();

    clearScreen();

    assignRandomScores(players, numPlayers);

    struct Player tmp;

    for (int i = 0; i < numPlayers-1; i++)
    {
        for (int j = i+1; j < numPlayers; j++)
        {
            if (players[j].score > players[i].score)
            {
                tmp = players[j];
                players[j] = players[i];
                players[i] = tmp;
            }
        }
    }

    printScores(players, numPlayers);
}

int main()
{
    int choice;

    srand(time(NULL));

    do
    {
        printMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                playGame("Awesome Game");
                break;
            case 2:
                printScores(NULL, 0);
                break;
            case 3:
                printf("\nThanks for playing!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
    while (choice != 3);

    return 0;
}