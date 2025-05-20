//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAX_PLAYERS 4

typedef struct
{
    char name[20];
    int score;
    char public_key;
} player;

void setup_players(player* players, int num_players);
void print_scores(player* players, int num_players);
void encrypt_scores(player* players, int num_players, char public_key);

int main(void) 
{
   int num_players = 0;
   player players[MAX_PLAYERS];

   printf("Welcome to the Public-Key Algorithm Implementation Example Game!\n");
   printf("Please enter the number of players (between 2 and 4): ");
   scanf("%d", &num_players);

   if(num_players < 2 || num_players > 4)
   {
       printf("Invalid number of players.\n");
       return 1;
   }

   setup_players(players, num_players);

   print_scores(players, num_players);

   encrypt_scores(players, num_players, 'K');

   print_scores(players, num_players);

   printf("Thanks for playing!\n");

   return 0;
}

void setup_players(player* players, int num_players)
{
    for(int i = 0; i < num_players; i++)
    {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
}

void print_scores(player* players, int num_players)
{
    printf("Scores:\n");
    for(int i = 0; i < num_players; i++)
    {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

void encrypt_scores(player* players, int num_players, char public_key)
{
    for(int i = 0; i < num_players; i++)
    {
        players[i].public_key = public_key;
        players[i].score = players[i].score ^ public_key;
    }
}