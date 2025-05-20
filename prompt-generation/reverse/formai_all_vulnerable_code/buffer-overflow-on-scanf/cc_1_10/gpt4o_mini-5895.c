//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float threatLevel;
    float defenseLevel;
} Player;

void inputPlayerData(Player *player) {
    printf("Enter player name: ");
    scanf("%s", player->name);
    printf("Enter threat level (0.0 to 1.0): ");
    scanf("%f", &player->threatLevel);
    printf("Enter defense level (0.0 to 1.0): ");
    scanf("%f", &player->defenseLevel);
    printf("\n");
}

float calculateInvasionProbability(Player player) {
    return player.threatLevel * (1 - player.defenseLevel);
}

void displayPlayerProbabilities(Player players[], int count) {
    printf("\nInvasion Probability for Players:\n");
    printf("=======================================\n");
    for (int i = 0; i < count; i++) {
        float probability = calculateInvasionProbability(players[i]) * 100; // Convert to percentage
        printf("Player: %s, Invasion Probability: %.2f%%\n", players[i].name, probability);
    }
    printf("=======================================\n");
}

int compareProbabilities(const void *a, const void *b) {
    Player *playerA = (Player *)a;
    Player *playerB = (Player *)b;
    return (calculateInvasionProbability(*playerB) - calculateInvasionProbability(*playerA));
}

void sortPlayersByProbability(Player players[], int count) {
    qsort(players, count, sizeof(Player), compareProbabilities);
}

void displayLeaderboard(Player players[], int count) {
    printf("\nLeaderboard based on Invasion Probability:\n");
    printf("============================================\n");
    for (int i = 0; i < count; i++) {
        float probability = calculateInvasionProbability(players[i]) * 100; // Convert to percentage
        printf("%d. %s - Probability: %.2f%%\n", i + 1, players[i].name, probability);
    }
    printf("============================================\n");
}

int main() {
    Player players[MAX_PLAYERS];
    int playerCount = 0;
    int choice;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    
    do {
        printf("\nMenu:\n");
        printf("1. Add Player Data\n");
        printf("2. Calculate Invasion Probabilities\n");
        printf("3. Display Leaderboard\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (playerCount < MAX_PLAYERS) {
                    inputPlayerData(&players[playerCount]);
                    playerCount++;
                } else {
                    printf("Maximum player limit reached!\n");
                }
                break;
            case 2:
                if (playerCount > 0) {
                    displayPlayerProbabilities(players, playerCount);
                } else {
                    printf("No player data available. Please add players first.\n");
                }
                break;
            case 3:
                if (playerCount > 0) {
                    sortPlayersByProbability(players, playerCount);
                    displayLeaderboard(players, playerCount);
                } else {
                    printf("No player data available. Please add players first.\n");
                }
                break;
            case 4:
                printf("Exiting the program. Stay safe from aliens!\n");
                break;
            default:
                printf("Invalid choice, please select again.\n");
        }
    } while(choice != 4);

    return 0;
}