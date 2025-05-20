//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 5
#define MAX_NAME_LENGTH 50
#define MAX_COLORS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int r, g, b;
    char hex[8];
} Player;

void rgbToHex(int r, int g, int b, char* hex) {
    snprintf(hex, 8, "#%02X%02X%02X", r, g, b);
}

void printLeaderboard(Player players[], int count) {
    printf("\n--- Color Code Leaderboard ---\n");
    for (int i = 0; i < count; i++) {
        printf("%s: R:%d G:%d B:%d Hex:%s\n", 
               players[i].name, players[i].r, players[i].g, players[i].b, players[i].hex);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int playerCount = 0;

    printf("Welcome to the Multiplayer Color Code Converter!\n");
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    
    if (playerCount > MAX_PLAYERS) playerCount = MAX_PLAYERS;
    
    // Getting player names
    for (int i = 0; i < playerCount; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    // Color Input Loop
    int continueGame = 1;
    while (continueGame) {
        for (int i = 0; i < playerCount; i++) {
            printf("\n%s, enter RGB values (0-255):\n", players[i].name);
            printf("R: ");
            scanf("%d", &players[i].r);
            printf("G: ");
            scanf("%d", &players[i].g);
            printf("B: ");
            scanf("%d", &players[i].b);
            
            // Convert to Hex
            rgbToHex(players[i].r, players[i].g, players[i].b, players[i].hex);
            printf("%s's Hex Color Code: %s\n", players[i].name, players[i].hex);
        }

        // Print Leaderboard
        printLeaderboard(players, playerCount);

        // Ask if players want to continue
        printf("\nDo you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &continueGame);
    }

    printf("Thank you for playing the Color Code Converter!\n");

    return 0;
}