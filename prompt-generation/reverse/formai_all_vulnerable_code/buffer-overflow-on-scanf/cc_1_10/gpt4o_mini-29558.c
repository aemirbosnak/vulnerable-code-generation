//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 5
#define MAX_MONSTERS 3

typedef struct {
    char *name;
    char *description;
    int isMonsterPresent;
} Room;

typedef struct {
    char *name;
    int health;
} Monster;

void initializeRooms(Room rooms[]) {
    rooms[0].name = "Entrance Hall";
    rooms[0].description = "You are in a grand entrance hall with eerie paintings.";
    rooms[0].isMonsterPresent = rand() % 2;

    rooms[1].name = "Library";
    rooms[1].description = "Rows of dusty books surround you; whispers of the past echo.";
    rooms[1].isMonsterPresent = rand() % 2;

    rooms[2].name = "Dining Room";
    rooms[2].description = "A long table is laid out with rotten food. You feel a chill.";
    rooms[2].isMonsterPresent = rand() % 2;

    rooms[3].name = "Basement";
    rooms[3].description = "It's dark and damp here. You can hear dripping water.";
    rooms[3].isMonsterPresent = rand() % 2;

    rooms[4].name = "Attic";
    rooms[4].description = "Old furniture is tucked away; shadows loom in the corners.";
    rooms[4].isMonsterPresent = rand() % 2;
}

void displayRoom(Room room) {
    printf("You are in the %s.\n", room.name);
    printf("%s\n", room.description);
}

Monster generateMonster() {
    Monster monster;
    monster.name = "Ghost";
    monster.health = 2 + rand() % 5;  // Random health between 2 and 6
    return monster;
}

void enterRoom(Room room) {
    displayRoom(room);
    if (room.isMonsterPresent) {
        Monster monster = generateMonster();
        printf("A wild %s appeared with %d health!\n", monster.name, monster.health);
        while (monster.health > 0) {
            char action;
            printf("What will you do? (f: fight, r: run): ");
            scanf(" %c", &action);
            if (action == 'f') {
                printf("You fought the %s!\n", monster.name);
                monster.health -= 1;  // Simple fight mechanic
                printf("The %s now has %d health left.\n", monster.name, monster.health);
            } else if (action == 'r') {
                printf("You fled the room, leaving the %s behind.\n", monster.name);
                return;
            } else {
                printf("Invalid action. Choose again.\n");
            }
        }
        printf("You defeated the %s! Heroic!\n", monster.name);
    } else {
        printf("The room is empty. You can breathe easier.\n");
    }
}

int main() {
    srand(time(NULL)); // Seed for randomness
    Room rooms[NUM_ROOMS];
    initializeRooms(rooms);
    
    int currentRoomIndex = 0; // Start at the Entrance Hall
    char choice;
    
    while (1) {
        enterRoom(rooms[currentRoomIndex]);
        
        if (currentRoomIndex == NUM_ROOMS - 1) {
            printf("You have explored all the rooms. Exit the haunted house? (y/n): ");
            scanf(" %c", &choice);
            if (choice == 'y') {
                printf("You exit the haunted house, forever changed by what you experienced.\n");
                break;
            }
            currentRoomIndex = 0; // Reset to Entrance Hall
        }
        
        printf("Do you want to go to the next room? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y') {
            currentRoomIndex++;
        } else {
            printf("You decide to stay in this room. You can still explore further if you wish.\n");
        }
    }
    
    return 0;
}