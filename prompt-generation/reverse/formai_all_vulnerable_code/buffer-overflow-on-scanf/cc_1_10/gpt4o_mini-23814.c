//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10

typedef struct {
    char name[50];
    int numAliens;
    int defenseBudget;
    float probability;
} Player;

void getInput(Player *player) {
    printf("Enter your name (max 50 characters): ");
    scanf("%s", player->name);
    printf("Enter the number of aliens invading: ");
    scanf("%d", &player->numAliens);
    printf("Enter your defense budget (in millions): ");
    scanf("%d", &player->defenseBudget);
}

float calculateProbability(int numAliens, int defenseBudget) {
    float baseProbability = 0.5; // 50% base probability
    float alienFactor = numAliens * 0.05; // each alien reduces chance by 5%
    float budgetFactor = defenseBudget * 0.1; // each million increases chance by 10%
    
    float probability = baseProbability - alienFactor + budgetFactor;
    
    if (probability < 0) {
        return 0.0; // min probability
    } else if (probability > 1) {
        return 1.0; // max probability
    }
    
    return probability;
}

void displayResults(Player players[], int playerCount) {
    printf("\nResults:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%s: Probability of defense success is %.2f%%\n", players[i].name, players[i].probability * 100);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int playerCount;
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    
    if (playerCount < 1 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players. Please restart the program.\n");
        return 1;
    }
    
    for (int i = 0; i < playerCount; i++) {
        printf("\nPlayer %d\n", i + 1);
        getInput(&players[i]);
        players[i].probability = calculateProbability(players[i].numAliens, players[i].defenseBudget);
    }
    
    displayResults(players, playerCount);
    
    // Multiplayer team play scenario
    char choice;
    printf("\nWould you like to compare team strategies? (y/n): ");
    scanf(" %c", &choice);
    
    if (choice == 'y' || choice == 'Y') {
        printf("\nTeam Comparison Results:\n");
        int team1Count = playerCount / 2;
        int team2Count = playerCount - team1Count;
        
        float team1Probability = 0.0;
        float team2Probability = 0.0;
        
        for (int i = 0; i < team1Count; i++) {
            team1Probability += players[i].probability;
        }
        
        for (int i = team1Count; i < playerCount; i++) {
            team2Probability += players[i].probability;
        }
        
        team1Probability /= team1Count;
        team2Probability /= team2Count;
        
        printf("Average Probability for Team 1: %.2f%%\n", team1Probability * 100);
        printf("Average Probability for Team 2: %.2f%%\n", team2Probability * 100);
        
        if (team1Probability > team2Probability) {
            printf("Team 1 has a better chance of defending against the invasion!\n");
        } else {
            printf("Team 2 has a better chance of defending against the invasion!\n");
        }
    }

    printf("Thank you for using the Alien Invasion Probability Calculator!\n");
    return 0;
}