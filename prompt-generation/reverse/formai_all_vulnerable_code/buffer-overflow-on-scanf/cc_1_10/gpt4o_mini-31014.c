//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_CARDS 10

typedef struct {
    int id;
    char name[20];
    int catnip;
} Player;

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        players[i].id = i + 1;
        snprintf(players[i].name, sizeof(players[i].name), "Player%d", players[i].id);
        players[i].catnip = 0;
    }
}

void displayPlayers(Player players[], int numPlayers) {
    printf("\nCurrent Players:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d Catnip\n", players[i].name, players[i].catnip);
    }
    printf("\n");
}

void catnipChallenge(Player *player) {
    int catnipGained = rand() % 6 + 1; // Gain between 1-6 catnip
    player->catnip += catnipGained;
    printf("%s just found a stash of catnip! +%d Catnip!\n", player->name, catnipGained);
}

void randomEvent(Player *player) {
    int event = rand() % 3;
    switch (event) {
        case 0:
            printf("%s stepped on a squeaky toy! Lost 1 Catnip!\n", player->name);
            if (player->catnip > 0) {
                player->catnip--;
            }
            break;
        case 1:
            printf("%s encountered a laser pointer! Instant dance party!\n", player->name);
            player->catnip += 2; // Fun dance gains you catnip
            break;
        case 2:
            printf("%s got distracted by a butterfly! Missed a turn!\n", player->name);
            break;
    }
}

int main() {
    srand(time(NULL));
    
    int numPlayers;
    printf("Welcome to Catastrophic Catnip Clash!\n");
    printf("Enter number of players (1 - %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    
    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players! You must be a cat in disguise...\n");
        return 1;
    }
    
    Player players[MAX_PLAYERS];
    initializePlayers(players, numPlayers);
    
    int turns = 10; // Total turns to play
    for (int turn = 1; turn <= turns; turn++) {
        printf("\n--- Turn %d ---\n", turn);
        for (int i = 0; i < numPlayers; i++) {
            printf("%s's turn!\n", players[i].name);
            int action = rand() % 2; // Random action: 0 for Catnip challenge, 1 for Random event
            
            if (action == 0) {
                catnipChallenge(&players[i]);
            } else {
                randomEvent(&players[i]);
            }
            
            displayPlayers(players, numPlayers);
        }
    }
    
    // Determine the winner
    int winnerIndex = 0;
    for (int i = 1; i < numPlayers; i++) {
        if (players[i].catnip > players[winnerIndex].catnip) {
            winnerIndex = i;
        }
    }
    
    printf("And the winner is... %s with %d Catnip! 🎉\n", players[winnerIndex].name, players[winnerIndex].catnip);
    printf("Congratulations! You've earned the title: 'Ultimate Catnip Conqueror'! 🐱\n");
    
    return 0;
}