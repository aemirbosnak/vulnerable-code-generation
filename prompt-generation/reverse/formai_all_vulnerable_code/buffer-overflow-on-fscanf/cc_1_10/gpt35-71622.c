//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PLAYERS 10

typedef struct {
    char name[20];
    int age;
    double score;
} Player;

void printLeaderboard(Player players[MAX_PLAYERS], int numPlayers);
bool extractMetadata(char* fileName, Player players[MAX_PLAYERS], int *numPlayers);

int main() {
    Player players[MAX_PLAYERS];
    int numPlayers = 0;

    char* fileName = "gameData.txt";

    bool success = extractMetadata(fileName, players, &numPlayers);

    if(success) {
        printf("Metadata extracted successfully!\n");
        printLeaderboard(players, numPlayers);
    } else {
        printf("Metadata extraction failed.\n");
    }

    return 0;
}

bool extractMetadata(char* fileName, Player players[MAX_PLAYERS], int *numPlayers) {
    FILE* file = fopen(fileName, "r");

    if(file == NULL) {
        printf("Could not open file %s\n", fileName);
        return false;
    }

    int age;
    double score;
    char name[20];

    while(fscanf(file, "%s %d %lf", name, &age, &score) != EOF) {
        if(*numPlayers == MAX_PLAYERS) {
            printf("Maximum number of players exceeded.\n");
            return false;
        }

        Player player;
        strcpy(player.name, name);
        player.age = age;
        player.score = score;

        players[*numPlayers] = player;
        (*numPlayers)++;
    }

    fclose(file);
    return true;
}

void printLeaderboard(Player players[MAX_PLAYERS], int numPlayers) {
    printf("---- LEADERBOARD ----\n");

    for(int i = 0; i < numPlayers; i++) {
        printf("%d. %s - Age: %d, Score: %.2lf\n", i+1, players[i].name, players[i].age, players[i].score);
    }
}