//Falcon-180B DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_ROUNDS 5
#define MAX_SCORE 100

typedef struct {
    char name[50];
    int score;
} Player;

void initialize(Player players[]) {
    int i;
    for(i=0;i<MAX_PLAYERS;i++) {
        players[i].score=0;
        sprintf(players[i].name,"Player %d",i+1);
    }
}

void print_scores(Player players[], int num_players) {
    int i;
    printf("\nScores:\n");
    for(i=0;i<num_players;i++) {
        printf("%s: %d\n",players[i].name,players[i].score);
    }
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int num_players, num_rounds;
    printf("Welcome to the game!\n");
    printf("How many players will be playing? (up to %d): ",MAX_PLAYERS-1);
    scanf("%d",&num_players);
    initialize(players);
    printf("The players are:\n");
    print_scores(players,num_players);
    printf("\nLet's start the game!\n");
    int i, j, winner;
    for(i=0;i<MAX_ROUNDS;i++) {
        printf("\nRound %d:\n",i+1);
        for(j=0;j<num_players-1;j++) {
            winner=rand()%2;
            if(winner==0) {
                players[j].score+=10;
                printf("%s wins!\n",players[j].name);
            } else {
                players[j+1].score+=10;
                printf("%s wins!\n",players[j+1].name);
            }
        }
        print_scores(players,num_players);
    }
    printf("\nThe game is over!\n");
    printf("The final scores are:\n");
    print_scores(players,num_players);
    return 0;
}