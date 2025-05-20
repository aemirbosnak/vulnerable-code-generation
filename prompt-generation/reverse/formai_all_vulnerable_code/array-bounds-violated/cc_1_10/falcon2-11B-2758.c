//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    srand(time(0)); // seed random number generator
    int num_rooms = rand() % 10 + 1; // generate random number of rooms
    int num_ghosts = rand() % 5 + 1; // generate random number of ghosts
    int num_traps = rand() % 3 + 1; // generate random number of traps
    
    // initialize room variables
    int rooms[num_rooms];
    for (int i = 0; i < num_rooms; i++) {
        rooms[i] = rand() % 100 + 1; // generate random room number
    }
    
    // initialize ghost variables
    int ghosts[num_ghosts];
    for (int i = 0; i < num_ghosts; i++) {
        ghosts[i] = rand() % 100 + 1; // generate random ghost number
    }
    
    // initialize trap variables
    int traps[num_traps];
    for (int i = 0; i < num_traps; i++) {
        traps[i] = rand() % 100 + 1; // generate random trap number
    }
    
    // initialize player variables
    int player_health = 100; // start with full health
    int player_room = rand() % num_rooms; // start in a random room
    
    // game loop
    while (player_health > 0) {
        printf("You are in room %d.\n", player_room);
        
        // check for traps
        for (int i = 0; i < num_traps; i++) {
            if (rooms[player_room + traps[i]] == 10) { // trap found
                player_health -= 10; // player loses 10 health
                printf("You triggered a trap!\n");
                break; // exit trap loop
            }
        }
        
        // check for ghosts
        for (int i = 0; i < num_ghosts; i++) {
            if (rooms[player_room + ghosts[i]] == 10) { // ghost found
                player_health -= 10; // player loses 10 health
                printf("You encountered a ghost!\n");
                break; // exit ghost loop
            }
        }
        
        // move to a new room
        player_room = rand() % num_rooms;
        
        // check if player has won
        if (player_room == 0) {
            printf("You escaped the haunted house!\n");
            break;
        }
    }
    
    return 0;
}