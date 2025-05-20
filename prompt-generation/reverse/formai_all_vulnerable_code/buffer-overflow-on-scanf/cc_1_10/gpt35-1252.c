//FormAI DATASET v1.0 Category: Table Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 6
#define MAX_ROUNDS 10

typedef struct {
    char name[20];
    int score;
} Player;

Player players[MAX_PLAYERS];
int numPlayers = 0;

int roll_dice() {
    return rand() % 6 + 1;
}

void add_player(char name[]) {
    strcpy(players[numPlayers].name, name);
    players[numPlayers].score = 0;
    numPlayers++;
}

void play_round() {
    int i;
    for (i = 0; i < numPlayers; i++) {
        printf("%s, it's your turn.\n", players[i].name);
        printf("Press enter to roll the dice.\n");
        getchar();
        int roll1 = roll_dice();
        int roll2 = roll_dice();
        printf("You rolled a %d and a %d for a total of %d.\n", roll1, roll2, roll1 + roll2);
        players[i].score += roll1 + roll2;
        printf("Your total score is now %d.\n", players[i].score);
    }
}

void print_scores() {
    int i;
    printf("Current Scores:\n");
    for (i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

Player get_winner() {
    int i;
    int maxScore = -1;
    int winnerIndex = -1;
    for (i = 0; i < numPlayers; i++) {
        if (players[i].score > maxScore) {
            maxScore = players[i].score;
            winnerIndex = i;
        }
    }
    return players[winnerIndex];
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Romeo and Juliet Dice Game!\n");
    printf("How many players will be playing (2-6)? ");
    scanf("%d", &numPlayers);
    if (numPlayers < 2 || numPlayers > 6) {
        printf("Invalid number of players. You must have between 2 and 6 players.\n");
        return 1;
    }
    int i;
    char name[20];
    for (i = 0; i < numPlayers; i++) {
        printf("What is the name of player %d? ", i + 1);
        scanf("%s", name);
        add_player(name);
    }
    printf("Great! Let's play %d rounds.\n", MAX_ROUNDS);
    for (i = 1; i <= MAX_ROUNDS; i++) {
        printf("\nRound %d\n", i);
        play_round();
        print_scores();
    }
    printf("\nGame over! The winner is %s with a score of %d.\n", get_winner().name, get_winner().score);
    return 0;
}