//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_ROOMS 5
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    int room;
    int alive;
} Player;

const char *rooms[MAX_ROOMS] = {
    "Entrance Hall", "Library", "Dining Room", 
    "Kitchen", "Attic"
};

const char *ghosts[] = {
    "a ghost in the Library!", 
    "a ghost in the Dining Room!", 
    "a ghost in the Kitchen!",
    "You are safe in the Entrance Hall.",
    "You found a secret passage in the Attic!"
};

void initializePlayers(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", i + 1);
        fgets(players[i].name, NAME_LENGTH, stdin);
        players[i].name[strcspn(players[i].name, "\n")] = '\0'; // Remove newline character
        players[i].room = 0; // Start in Entrance Hall
        players[i].alive = 1; // All players are alive at the start
    }
}

void printPlayerStatus(Player players[], int num_players) {
    printf("\nPlayer Status:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s is in %s and is %s.\n",
               players[i].name,
               rooms[players[i].room],
               players[i].alive ? "alive" : "dead");
    }
}

void movePlayer(Player *player) {
    int new_room;
    printf("%s, enter room number (0-%d): ", player->name, MAX_ROOMS - 1);
    scanf("%d", &new_room);
    
    if (new_room >= 0 && new_room < MAX_ROOMS) {
        player->room = new_room;
        printf("%s moved to %s.\n", player->name, rooms[new_room]);
    } else {
        printf("Invalid room selection!\n");
    }
}

int encounterGhost(Player *player) {
    if (strcmp(ghosts[player->room], "You are safe in the Entrance Hall.") != 0) {
        printf("%s encountered %s\n", player->name, ghosts[player->room]);
        player->alive = 0; // Player is scared to death!
        return 1; // Encounter happened
    }
    return 0; // No encounter
}

int main() {
    int num_players;
    Player players[MAX_PLAYERS];
    
    srand(time(NULL)); // Seed random number generator
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    getchar(); // Remove newline from buffer

    // Error handling for player count
    while (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players. Please enter again (1-%d): ", MAX_PLAYERS);
        scanf("%d", &num_players);
        getchar();
    }

    initializePlayers(players, num_players);
    
    while (1) {
        printPlayerStatus(players, num_players);
        
        for (int i = 0; i < num_players; i++) {
            if (players[i].alive) {
                movePlayer(&players[i]);
                if (encounterGhost(&players[i])) {
                    printf("%s has been scared to death!\n", players[i].name);
                }
            }
        }

        // Check if the game continues or ends
        int alive_count = 0;
        for (int i = 0; i < num_players; i++) {
            if (players[i].alive) alive_count++;
        }
        
        if (alive_count == 0) {
            printf("All players have been scared to death! Game Over!\n");
            break; // Exit the game
        }
        
        char choice;
        printf("Do you want to continue exploring? (y/n): ");
        getchar(); // Allow character input
        scanf("%c", &choice);
        if (choice != 'y') break;
    }

    printf("Thank you for playing!\n");
    return 0;
}