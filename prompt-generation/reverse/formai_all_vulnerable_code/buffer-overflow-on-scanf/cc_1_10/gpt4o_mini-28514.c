//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define ROOM_COUNT 6
#define MAX_NAME_LENGTH 50
#define MAX_GHOSTS 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    int fearLevel;
} Player;

typedef struct {
    char description[256];
} Room;

void initializeRooms(Room rooms[]) {
    strcpy(rooms[0].description, "You step into a dusty old parlor filled with cobwebs. A chilling breeze makes you shudder.");
    strcpy(rooms[1].description, "The kitchen is dark and slightly warm; suddenly, a pot clanks on the floor.");
    strcpy(rooms[2].description, "A narrow hallway stretches out before you, echoing with distant whispers.");
    strcpy(rooms[3].description, "You enter a bedroom that looks as if it hasn't been used in decades. The bed is neatly made.");
    strcpy(rooms[4].description, "An old library filled with ancient books greets you. One book suddenly flies off the shelf!");
    strcpy(rooms[5].description, "A cold cellar filled with barrels that seem to breathe. You feel eyes watching you.");
}

void displayRoom(Room *room) {
    printf("\n%s\n", room->description);
}

void scarePlayer(Player *player) {
    int scareChance = rand() % 10;
    if (scareChance < 5) {
        player->fearLevel += 10;
        printf("You feel a shiver run down your spine...\n");
    } else {
        printf("It's eerily quiet...\n");
    }
}

void displayFearLevel(Player *player) {
    printf("Your fear level: %d\n", player->fearLevel);
}

void exploreRoom(Player *player, Room rooms[], int *currentRoom) {
    char choice;
    displayRoom(&rooms[*currentRoom]);
    scarePlayer(player);
    displayFearLevel(player);

    printf("Do you want to move to another room? (y/n): ");
    scanf(" %c", &choice);
    
    if (choice == 'y') {
        *currentRoom = (*currentRoom + 1) % ROOM_COUNT;  // Move to the next room
    }
}

int main() {
    Player player;
    Room rooms[ROOM_COUNT];
    int currentRoom = 0;

    srand(time(NULL));
    
    // Initialize player
    player.fearLevel = 0;
    printf("Welcome to the Haunted House Simulator!\n");
    printf("What is your name, brave soul? ");
    scanf("%s", player.name);

    // Initialize rooms
    initializeRooms(rooms);

    while (player.fearLevel < 100) {
        printf("\nCurrent Room: %d\n", currentRoom + 1);
        exploreRoom(&player, rooms, &currentRoom);
    }

    printf("\nYou succumbed to your fear...\n");
    printf("Game Over, brave %s!\n", player.name);

    return 0;
}