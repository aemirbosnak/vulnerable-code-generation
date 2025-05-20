//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10

// Room struct
typedef struct Room {
    int north;
    int south;
    int east;
    int west;
    int visited;
    int has_monster;
} Room;

// Player struct
typedef struct Player {
    int x;
    int y;
    int health;
} Player;

// Function to generate a random number between two numbers
int random_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to create a new room
Room create_room(int x, int y) {
    Room room;
    room.north = -1;
    room.south = -1;
    room.east = -1;
    room.west = -1;
    room.visited = 0;
    room.has_monster = random_range(0, 1);
    return room;
}

// Function to create a new player
Player create_player() {
    Player player;
    player.x = 0;
    player.y = 0;
    player.health = 100;
    return player;
}

// Function to print a room
void print_room(Room room) {
    printf("You are in a room.\n");
    if (room.north != -1) {
        printf("There is a door to the north.\n");
    }
    if (room.south != -1) {
        printf("There is a door to the south.\n");
    }
    if (room.east != -1) {
        printf("There is a door to the east.\n");
    }
    if (room.west != -1) {
        printf("There is a door to the west.\n");
    }
    if (room.has_monster) {
        printf("There is a monster in the room!\n");
    }
}

// Function to move the player in a direction
void move_player(Player *player, int direction) {
    switch (direction) {
        case 'n':
            if (player->y > 0) {
                player->y--;
            }
            break;
        case 's':
            if (player->y < MAX_ROOMS - 1) {
                player->y++;
            }
            break;
        case 'e':
            if (player->x < MAX_ROOMS - 1) {
                player->x++;
            }
            break;
        case 'w':
            if (player->x > 0) {
                player->x--;
            }
            break;
    }
}

// Function to fight a monster
void fight_monster(Player *player) {
    int player_damage = random_range(10, 20);
    int monster_damage = random_range(10, 20);
    player->health -= monster_damage;
    printf("You attacked the monster for %d damage.\n", player_damage);
    printf("The monster attacked you for %d damage.\n", monster_damage);
    if (player->health <= 0) {
        printf("You died!\n");
        exit(0);
    }
}

// Main function
int main() {
    srand(time(NULL));

    // Create a new haunted house
    Room rooms[MAX_ROOMS][MAX_ROOMS];
    for (int i = 0; i < MAX_ROOMS; i++) {
        for (int j = 0; j < MAX_ROOMS; j++) {
            rooms[i][j] = create_room(i, j);
        }
    }

    // Create a new player
    Player player = create_player();

    // Game loop
    while (1) {
        // Print the current room
        print_room(rooms[player.x][player.y]);

        // Get the player's input
        char input;
        scanf(" %c", &input);

        // Move the player in the input direction
        move_player(&player, input);

        // Check if the player is in a room with a monster
        if (rooms[player.x][player.y].has_monster) {
            fight_monster(&player);
        }
    }

    return 0;
}