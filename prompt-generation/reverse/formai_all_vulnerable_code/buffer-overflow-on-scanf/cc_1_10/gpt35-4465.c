//FormAI DATASET v1.0 Category: Educational ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10

int num_players;
int scores[MAX_PLAYERS];
int current_round = 1;

void print_scores()
{
    printf("Current scores:\n");
    for (int i=0; i<num_players; i++)
        printf("Player %d: %d\n", i+1, scores[i]);
}

int roll_dice()
{
    return rand() % 6 + 1;
}

void play_round()
{
    printf("Round %d: \n", current_round);
    for (int i=0; i<num_players; i++)
    {
        printf("Player %d's turn to roll the dice. Press any key to roll...\n", i+1);
        getchar();
        int roll = roll_dice();
        scores[i] += roll;
        printf("Player %d rolled a %d.\n", i+1, roll);
    }
}

int main()
{
    srand(time(NULL));
    printf("Welcome to Dice Masters! How many players are there? (1-4): ");
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS)
    {
        printf("Invalid number of players. Please choose a number between 1 and 4.\n");
        return 1;
    }

    printf("Great! Let's start. You will play %d rounds and try to get the highest score.\n", MAX_ROUNDS);

    while (current_round <= MAX_ROUNDS)
    {
        printf("\n-------- ROUND %d --------\n", current_round);
        play_round();
        print_scores();
        current_round++;
    }

    printf("\nGame over! Final scores:\n");
    print_scores();

    int winner = 0;
    for (int i=1; i<num_players; i++)
    {
        if (scores[i] > scores[winner])
            winner = i;
    }

    printf("\nCongratulations, Player %d! You won with a score of %d!\n", winner+1, scores[winner]);

    return 0;
}