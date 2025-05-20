//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_RESOURCES 5
#define MAX_TURNS 10

typedef struct {
    char name[30];
    int resources[MAX_RESOURCES];
} Player;

typedef struct {
    char name[30];
    int quantity;
} Resource;

Resource resourceTypes[MAX_RESOURCES] = {
    {"Food", 0},
    {"Water", 0},
    {"Medicine", 0},
    {"Ammunition", 0},
    {"Scrap Metal", 0}
};

void initializePlayers(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        printf("Enter name for Player %d: ", i + 1);
        fgets(players[i].name, sizeof(players[i].name), stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0; // Remove newline

        for (int j = 0; j < MAX_RESOURCES; j++) {
            players[i].resources[j] = rand() % 10; // Initialize with random resources
        }
    }
}

void displayResources(Player player) {
    printf("%s's Resources:\n", player.name);
    for (int i = 0; i < MAX_RESOURCES; i++) {
        printf("  %s: %d\n", resourceTypes[i].name, player.resources[i]);
    }
}

void gatherResources(Player *player) {
    int resourceIndex = rand() % MAX_RESOURCES;
    int gathered = rand() % 6; // Gather 0 to 5 resources
    player->resources[resourceIndex] += gathered;
    resourceTypes[resourceIndex].quantity += gathered;

    printf("%s gathered %d %s!\n", player->name, gathered, resourceTypes[resourceIndex].name);
}

void tradeResources(Player *from, Player *to) {
    int fromResource = rand() % MAX_RESOURCES;
    int toResource = rand() % MAX_RESOURCES;

    if (from->resources[fromResource] > 0) {
        from->resources[fromResource]--;
        to->resources[toResource]++;
        
        printf("%s traded 1 unit of %s to %s for 1 unit of %s!\n", 
                from->name, resourceTypes[fromResource].name, 
                to->name, resourceTypes[toResource].name);
    } else {
        printf("%s has no %s to trade!\n", from->name, resourceTypes[fromResource].name);
    }
}

void randomEvent(Player *player) {
    int event = rand() % 3;

    switch (event) {
        case 0: // Resources stolen
            if (player->resources[0] > 0) {
                player->resources[0]--;
                printf("%s was raided! Lost 1 Food!\n", player->name);
            }
            break;
        case 1: // Find resources
            gatherResources(player);
            break;
        case 2: // Nothing happens
            printf("%s had a quiet day.\n", player->name);
            break;
    }
}

void playGame() {
    Player players[MAX_PLAYERS];
    int playerCount;

    printf("Enter number of players (2 - %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    getchar(); // Clear newline from input buffer

    initializePlayers(players, playerCount);

    for (int turn = 1; turn <= MAX_TURNS; turn++) {
        printf("\n--- Turn %d ---\n", turn);

        for (int i = 0; i < playerCount; i++) {
            displayResources(players[i]);
            randomEvent(&players[i]);

            if (i + 1 < playerCount) { // Allow trading with the next player in line
                tradeResources(&players[i], &players[i + 1]);
            } else { // Last player trades with the first
                tradeResources(&players[i], &players[0]);
            }
        }
    }

    printf("\n--- Game Over! Final Resources ---\n");
    for (int i = 0; i < playerCount; i++) {
        displayResources(players[i]);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    playGame();
    return 0;
}