//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<math.h>
#include<limits.h>
#include<stdbool.h>

#define MAX_PLAYERS 4
#define MAX_STR_LEN 100
#define MAX_NUM_ROUNDS 5

//Structure for a player
typedef struct player {
    char name[MAX_STR_LEN];
    int score;
} Player;

//Structure for a round
typedef struct round {
    int num_questions;
    char questions[MAX_NUM_ROUNDS][MAX_STR_LEN];
    char answers[MAX_NUM_ROUNDS][MAX_STR_LEN];
} Round;

//Function to initialize a round
void init_round(Round *round, int num_questions) {
    round->num_questions = num_questions;
    for (int i = 0; i < num_questions; i++) {
        sprintf(round->questions[i], "Question %d: ", i+1);
        sprintf(round->answers[i], "Answer %d: ", i+1);
    }
}

//Function to play a round
void play_round(Round *round, Player *players, int num_players) {
    for (int i = 0; i < round->num_questions; i++) {
        printf("%s ", round->questions[i]);
        for (int j = 0; j < num_players; j++) {
            char answer[MAX_STR_LEN];
            scanf("%s", answer);
            if (strcmp(answer, round->answers[i]) == 0) {
                players[j].score++;
            }
        }
        printf("\n");
    }
}

//Function to display the scores
void display_scores(Player *players, int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

//Main function
int main() {
    srand(time(NULL));
    int num_players = rand() % MAX_PLAYERS + 2;
    Player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        sprintf(players[i].name, "Player %d", i+1);
        players[i].score = 0;
    }
    Round round;
    init_round(&round, rand() % MAX_NUM_ROUNDS + 1);
    play_round(&round, players, num_players);
    display_scores(players, num_players);
    return 0;
}