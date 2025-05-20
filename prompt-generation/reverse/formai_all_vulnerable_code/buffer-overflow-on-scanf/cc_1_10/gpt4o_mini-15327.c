//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KNIGHTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int victories;
    int defeats;
} Knight;

void printKnightStats(Knight knights[], int count) {
    printf("\n*** Stats of the Noble Knights ***\n");
    for (int i = 0; i < count; i++) {
        printf("%s - Victories: %d, Defeats: %d\n", knights[i].name, knights[i].victories, knights[i].defeats);
    }
}

void declareChampion(Knight knights[], int count) {
    int maxVictories = -1;
    char champion[MAX_NAME_LENGTH];
    
    for (int i = 0; i < count; i++) {
        if (knights[i].victories > maxVictories) {
            maxVictories = knights[i].victories;
            strcpy(champion, knights[i].name);
        }
    }
    
    printf("\n🌟 The Champion of the Tournament is: %s with %d Victories! 🌟\n", champion, maxVictories);
}

void processBattle(Knight *challenger, Knight *opponent) {
    // For simplicity, let's assume challenger always wins
    challenger->victories++;
    opponent->defeats++;
    printf("%s triumphs over %s!\n", challenger->name, opponent->name);
}

void tournament(Knight knights[], int count) {
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            processBattle(&knights[i], &knights[j]);
        }
    }
}

int main() {
    Knight knights[MAX_KNIGHTS];
    int knightCount = 0;

    // Register the knights
    printf("🛡️  Enter the names of the noble knights partaking in the tournament (type 'end' to finish):\n");
    while (knightCount < MAX_KNIGHTS) {
        char name[MAX_NAME_LENGTH];
        printf("Knight %d: ", knightCount + 1);
        scanf("%s", name);
        
        if (strcmp(name, "end") == 0) {
            break;
        }

        strncpy(knights[knightCount].name, name, MAX_NAME_LENGTH);
        knights[knightCount].victories = 0;
        knights[knightCount].defeats = 0;
        knightCount++;
    }

    // Conduct the tournament
    printf("\n⚔️  The Grand Tournament Commences! ⚔️\n");
    tournament(knights, knightCount);

    // Print the stats and declare the champion
    printKnightStats(knights, knightCount);
    declareChampion(knights, knightCount);

    return 0;
}