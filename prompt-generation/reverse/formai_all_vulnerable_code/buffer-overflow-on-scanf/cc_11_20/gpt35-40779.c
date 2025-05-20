//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_ROOMS 6 // number of rooms in the house
#define MAX_PLAYERS 4 // maximum number of players in the game

// struct for the player data
typedef struct {
    char name[20];
    int roomNum;
    bool hasKey;
} Player;

// struct for the room data
typedef struct {
    char name[20];
    char desc[100];
    int neighborRooms[3];
    bool hasKey;
} Room;

int main() {
    // seed the random number generator
    srand(time(NULL));
    
    // create the rooms in the house
    Room rooms[NUM_ROOMS] = {
        {"Entrance", "You are standing in the entrance of the haunted house.\nThere are doors to the north and east.", {1, 2, -1}, false},
        {"Living Room", "You are in the living room.\nThere are doors to the west, north, and east.", {0, 3, 2}, false},
        {"Kitchen", "You are in the kitchen.\nThere are doors to the west and south.", {0, -1, 4}, true},
        {"Dining Room", "You are in the dining room.\nThere are doors to the south and west.", {1, -1, 5}, false},
        {"Bedroom", "You are in the bedroom.\nThere are doors to the north and east.", {2, -1, -1}, false},
        {"Bathroom", "You are in the bathroom.\nThere are doors to the west and south.", {3, -1, -1}, false}
    };
    
    // create an array to hold the players
    Player players[MAX_PLAYERS];
    int numPlayers = 0;
    
    // prompt the user for the number of players
    printf("How many players? (1-%d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    getchar(); // consume the newline character
    
    // get the player names
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter player %d's name: ", i+1);
        fgets(players[i].name, 20, stdin);
        // remove the newline character from the end of the string
        players[i].name[strcspn(players[i].name, "\n")] = '\0';
        players[i].roomNum = rand() % NUM_ROOMS; // assign a random starting room
        players[i].hasKey = false;
    }
    
    // game loop
    bool gameOver = false;
    while (!gameOver) {
        // print the current room description for each player
        for (int i = 0; i < numPlayers; i++) {
            printf("\n--- %s's turn ---\n", players[i].name);
            printf("%s\n", rooms[players[i].roomNum].desc);
            if (rooms[players[i].roomNum].hasKey) {
                printf("There is a key in this room!\n");
            }
            // prompt the player for their action
            printf("Which direction do you want to go? (north, south, east, west): ");
            char direction[10];
            fgets(direction, 10, stdin);
            // remove the newline character from the end of the string
            direction[strcspn(direction, "\n")] = '\0';
            // move the player to the neighbor room in the chosen direction
            if (strcmp(direction, "north") == 0 && rooms[players[i].roomNum].neighborRooms[0] != -1) {
                players[i].roomNum = rooms[players[i].roomNum].neighborRooms[0];
            }
            else if (strcmp(direction, "south") == 0 && rooms[players[i].roomNum].neighborRooms[1] != -1) {
                players[i].roomNum = rooms[players[i].roomNum].neighborRooms[1];
            }
            else if (strcmp(direction, "east") == 0 && rooms[players[i].roomNum].neighborRooms[2] != -1) {
                players[i].roomNum = rooms[players[i].roomNum].neighborRooms[2];
            }
            else if (strcmp(direction, "west") == 0 && rooms[players[i].roomNum].neighborRooms[3] != -1) {
                players[i].roomNum = rooms[players[i].roomNum].neighborRooms[3];
            }
            // check if the player found a key
            if (rooms[players[i].roomNum].hasKey) {
                players[i].hasKey = true;
                rooms[players[i].roomNum].hasKey = false;
                printf("Congratulations, %s! You have found a key.\n", players[i].name);
            }
            // check if any players have reached the exit room
            if (players[i].roomNum == NUM_ROOMS - 1 && players[i].hasKey) {
                printf("Congratulations, %s! You have escaped the haunted house!\n", players[i].name);
                gameOver = true;
                break;
            }
        }
    }
    
    return 0;
}