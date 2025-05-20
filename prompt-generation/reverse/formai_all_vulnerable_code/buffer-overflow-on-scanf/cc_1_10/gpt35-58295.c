//FormAI DATASET v1.0 Category: Spam Detection System ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_LEN 100
#define SPAM_COUNT 3
#define PLAYER_COUNT 2

char spamWords[SPAM_COUNT][MAX_LEN] = {
    "buy now", "limited time offer", "make money fast"
};

typedef struct {
    char name[MAX_LEN];
    int score;
    int spamCount;
} Player;

void initializePlayers(Player *players, int count) {
    for(int i=0; i<count; i++) {
        printf("Enter name for player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
        players[i].spamCount = 0;
    }
}

void displayPlayers(Player *players, int count) {
    printf("Player\t\tScore\tSpam Count\n");
    for(int i=0; i<count; i++) {
        printf("%s\t\t%d\t%d\n", players[i].name, players[i].score, players[i].spamCount);
    }
}

void startGame(Player *players, int count) {
    char message[MAX_LEN];
    int randomIndex;

    for(int i=0; i<3; i++) {
        printf("\nRound %d\n", i+1);
        printf("------------------------------------------------------\n");
        printf("Enter the message: ");
        scanf(" %[^\n]s", message);

        for(int j=0; j<count; j++) {
            for(int k=0; k<SPAM_COUNT; k++) {
                if(strstr(message, spamWords[k]) != NULL) {
                    players[j].spamCount++;
                    printf("Spam Detected! Penalty for %s\n", players[j].name);
                    break;
                }
            }
            if(strstr(message, players[j].name) != NULL) {
                players[j].score++;
                printf("%s is mentioned in the message! Point for %s\n", players[j].name, players[j].name);
            }
            else {
                randomIndex = rand() % count; //random player selected
                players[randomIndex].score++;
                printf("%s is not mentioned in the message! Point for %s\n", players[j].name, players[randomIndex].name);
            }
        }
        printf("------------------------------------------------------\n");
        displayPlayers(players, count);
    }
}

int main() {
    srand(time(NULL));
    Player players[PLAYER_COUNT];
    printf("Welcome to the Spam Detection Game!\n\n");
    printf("Instructions:\n1. You will be given a message and you have to detect if it contains spam words.\n");
    printf("2. If spam is detected, there will be a penalty.\n");
    printf("3. If your name is mentioned in the message, you get a point.\n");
    printf("4. If someone else's name is mentioned, a random player gets a point.\n");
    initializePlayers(players, PLAYER_COUNT);
    printf("\nLet's start the game!\n");
    startGame(players, PLAYER_COUNT);
    printf("\nThe game has ended!\n");
    displayPlayers(players, PLAYER_COUNT);
    return 0;
}