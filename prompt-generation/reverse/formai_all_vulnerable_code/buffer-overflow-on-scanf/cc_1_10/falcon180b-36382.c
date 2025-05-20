//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CARDS 100
#define MAX_CALLS 75

typedef struct {
    char name[20];
    int card[MAX_CARDS];
    int calls;
} Player;

void generateCard(Player* player) {
    srand(time(0));
    for(int i=0;i<MAX_CARDS;i++) {
        player->card[i] = rand()%75 + 1;
    }
}

void printCard(Player* player) {
    for(int i=0;i<MAX_CARDS;i++) {
        printf("%d ",player->card[i]);
    }
    printf("\n");
}

void markCard(Player* player, int num) {
    for(int i=0;i<MAX_CARDS;i++) {
        if(player->card[i] == num) {
            player->card[i] = 0;
        }
    }
}

int checkWin(Player* player) {
    int win = 0;
    for(int i=0;i<MAX_CARDS;i++) {
        if(player->card[i]!= 0) {
            win = 0;
            break;
        }
    }
    if(win == 1) {
        printf("%s has won the game!\n",player->name);
    }
    return win;
}

void playBingo(Player* players, int numPlayers) {
    int win = 0;
    int callCount = 0;
    while(win == 0 && callCount < MAX_CALLS) {
        int num = rand()%75 + 1;
        printf("Calling %d...\n",num);
        for(int i=0;i<numPlayers;i++) {
            markCard(players+i,num);
            printCard(players+i);
            if(checkWin(players+i) == 1) {
                win = 1;
            }
        }
        callCount++;
    }
    if(win == 0) {
        printf("No winner after %d calls.\n",callCount);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int numPlayers;
    printf("Enter number of players (max %d): ",MAX_PLAYERS);
    scanf("%d",&numPlayers);
    for(int i=0;i<numPlayers;i++) {
        printf("Enter name for player %d: ",i+1);
        scanf("%s",players[i].name);
        generateCard(players+i);
    }
    playBingo(players,numPlayers);
    return 0;
}