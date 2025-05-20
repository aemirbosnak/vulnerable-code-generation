//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 10
#define MAX_PLAYERS 4

typedef struct {
    char name[30];
    int position;
    int turn;
} Player;

void initializePlayers(Player players[], int numPlayers);
void displayTable(Player players[], int numPlayers);
void movePlayer(Player *player);
int rollDice();

int main() {
    int numPlayers;
    Player players[MAX_PLAYERS];

    printf("Welcome to the C Table Game!\n");
    printf("Enter number of players (2-4): ");
    scanf("%d", &numPlayers);
    
    if (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Please restart the game.\n");
        return 1;
    }

    // Initialize players
    initializePlayers(players, numPlayers);
    
    // Game loop
    while (1) {
        for (int i = 0; i < numPlayers; i++) {
            if (players[i].position >= TABLE_SIZE) {
                printf("%s has reached the end of the table and wins!\n", players[i].name);
                return 0;
            }

            players[i].turn++;
            printf("\n%s's turn (Turn %d):\n", players[i].name, players[i].turn);
            displayTable(players, numPlayers);
            movePlayer(&players[i]);
        }
    }
    
    return 0;
}

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].position = 0;
        players[i].turn = 0;
    }
}

void displayTable(Player players[], int numPlayers) {
    printf("Table: ");
    for (int i = 0; i < TABLE_SIZE; i++) {
        int found = 0;
        for (int j = 0; j < numPlayers; j++) {
            if (players[j].position == i) {
                printf("[%s] ", players[j].name);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("[ ] ");
        }
    }
    printf("\n");
}

void movePlayer(Player *player) {
    int diceValue = rollDice();
    printf("%s rolls a %d!\n", player->name, diceValue);
    player->position += diceValue;
    
    if (player->position >= TABLE_SIZE) {
        player->position = TABLE_SIZE; // Ensure the position does not exceed TABLE_SIZE
    }
}

int rollDice() {
    return (rand() % 6) + 1; // Generates a random number between 1 and 6
}