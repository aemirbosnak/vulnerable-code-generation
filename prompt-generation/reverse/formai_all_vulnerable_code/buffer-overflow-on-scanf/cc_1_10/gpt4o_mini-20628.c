//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_OPTIONS 3

typedef struct {
    char *description;
    int isHaunted;
    int options[MAX_OPTIONS];
} Room;

typedef struct {
    char *name;
    int health;
    int currentRoom;
} Player;

Room createRoom(char *description, int isHaunted) {
    Room room;
    room.description = description;
    room.isHaunted = isHaunted;
    for (int i = 0; i < MAX_OPTIONS; i++) {
        room.options[i] = -1; // Initialize options to -1 (no connection)
    }
    return room;
}

void displayRoom(Room room) {
    printf("You are in: %s\n", room.description);
    if (room.isHaunted) {
        printf("Oh no! This room feels haunted...\n");
    }
}

void displayOptions(Room room) {
    printf("You can go to:\n");
    for (int i = 0; i < MAX_OPTIONS; i++) {
        if (room.options[i] != -1) {
            printf("Option %d: Room %d\n", i, room.options[i]);
        }
    }
}

int getPlayerChoice() {
    int choice;
    printf("Choose an option (0-%d): ", MAX_OPTIONS - 1);
    scanf("%d", &choice);
    return choice;
}

void movePlayer(Player *player, Room rooms[], int choice) {
    if (choice >= 0 && choice < MAX_OPTIONS && rooms[player->currentRoom].options[choice] != -1) {
        player->currentRoom = rooms[player->currentRoom].options[choice];
        printf("Moving to Room %d...\n", player->currentRoom);
    } else {
        printf("Invalid choice! You remain in Room %d.\n", player->currentRoom);
    }
}

void updatePlayerHealth(Player *player, Room room) {
    if (room.isHaunted) {
        player->health -= rand() % 10 + 1; // Decrease health randomly
        printf("You are scared! Health is now: %d\n", player->health);
    }
    if (player->health < 0) {
        printf("You have succumbed to your fears! Game Over.\n");
        exit(0);
    }
}

int main() {
    srand(time(NULL));

    Room rooms[MAX_ROOMS] = {
        createRoom("A dimly-lit hallway", 1),
        createRoom("An old dusty library", 0),
        createRoom("A musty bedroom", 1),
        createRoom("An eerie kitchen", 1),
        createRoom("A cold cellar", 0),
        createRoom("A creepy bathroom", 1),
        createRoom("An abandoned living room", 0),
        createRoom("A dark basement", 1),
        createRoom("A haunted attic", 1),
        createRoom("A secret passage", 0)
    };

    // Connecting rooms
    rooms[0].options[0] = 1;
    rooms[0].options[1] = 2;
    rooms[0].options[2] = 3;

    rooms[1].options[0] = 0;
    rooms[1].options[1] = 4;
    rooms[1].options[2] = 5;

    rooms[2].options[0] = 0;
    rooms[2].options[1] = 3;
    rooms[2].options[2] = 6;

    rooms[3].options[0] = 0;
    rooms[3].options[1] = 7;
    rooms[3].options[2] = 2;

    rooms[4].options[0] = 1;
    rooms[4].options[1] = 5;
    rooms[4].options[2] = -1; // no third option

    rooms[5].options[0] = 1;
    rooms[5].options[1] = 3;
    rooms[5].options[2] = 8;

    // Initializing player
    Player player;
    player.name = "Explorer";
    player.health = 100;
    player.currentRoom = 0;

    printf("Welcome to the Haunted House Simulator, %s!\n", player.name);
    
    // Game loop
    while (player.health > 0) {
        displayRoom(rooms[player.currentRoom]);
        displayOptions(rooms[player.currentRoom]);
        
        int choice = getPlayerChoice();
        movePlayer(&player, rooms, choice);
        updatePlayerHealth(&player, rooms[player.currentRoom]);
    }

    return 0;
}