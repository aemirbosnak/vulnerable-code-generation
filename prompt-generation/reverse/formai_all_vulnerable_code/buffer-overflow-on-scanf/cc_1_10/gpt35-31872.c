//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

enum PlayerType {ROMEO, JULIET, AUDIENCE};
enum ActionType {MUSIC, DANCE, TALK};
int points[3] = {0,0,0};

void playAction(enum ActionType actionType, enum PlayerType playerType);
void printPoints();
void declareWinner();

int main()
{
    char player1Name[20], player2Name[20];
    printf("Welcome to the Romeo and Juliet game!\n");

    printf("Enter the name of player 1 (Romeo): ");
    scanf("%s", player1Name);
    printf("Enter the name of player 2 (Juliet): ");
    scanf("%s", player2Name);

    srand(time(0)); // Seed the random number generator

    int rounds = 3; // Number of rounds
    for(int i=1; i<=rounds; i++)
    {
        printf("\nRound %d:\n", i);

        enum ActionType action1 = rand()%3;
        enum ActionType action2 = rand()%3;

        printf("%s chooses to ", player1Name);
        playAction(action1, ROMEO);

        printf("%s chooses to ", player2Name);
        playAction(action2, JULIET);

        printf("\n");
        printPoints();
    }

    declareWinner();

    return 0;
}

void playAction(enum ActionType actionType, enum PlayerType playerType)
{
    switch(actionType)
    {
        case MUSIC:
            printf("play music.\n");

            if(playerType == ROMEO)
                points[ROMEO] += 3;
            else if(playerType == JULIET)
                points[JULIET] += 3;
            else
            {
                points[ROMEO] += 1;
                points[JULIET] += 1;
            }
            break;

        case DANCE:
            printf("dance.\n");

            if(playerType == ROMEO)
                points[JULIET] += 2;
            else if(playerType == JULIET)
                points[ROMEO] += 2;
            else
            {
                points[ROMEO] += 1;
                points[JULIET] += 1;
            }
            break;

        case TALK:
            printf("talk.\n");

            if(playerType == ROMEO)
                points[JULIET] += 1;
            else if(playerType == JULIET)
                points[ROMEO] += 1;
            else
            {
                points[ROMEO] += 1;
                points[JULIET] += 1;
            }
            break;
    }
}

void printPoints()
{
    printf("Points:\n");
    printf("  %d - Romeo\n", points[ROMEO]);
    printf("  %d - Juliet\n", points[JULIET]);
    printf("  %d - Audience\n\n", points[AUDIENCE]);
}

void declareWinner()
{
    if(points[ROMEO] > points[JULIET])
        printf("Romeo wins!\n");
    else if(points[JULIET] > points[ROMEO])
        printf("Juliet wins!\n");
    else
        printf("It's a tie!\n");
}