//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_MONSTERS 5
#define ITEM_NAMES 3
#define MAX_ITEM_DESC 64

typedef struct {
    char name[MAX_ITEM_DESC];
    char description[MAX_ITEM_DESC];
} Item;

typedef struct {
    char name[MAX_ITEM_DESC];
    char scareDescription[MAX_ITEM_DESC];
} Monster;

typedef struct {
    char name[MAX_ITEM_DESC];
    Item items[ITEM_NAMES];
    Monster monsters[MAX_MONSTERS];
    int itemCount;
    int monsterCount;
} Room;

Room hauntedHouse[MAX_ROOMS];
int totalRooms = 0;

void initializeRooms() {
    // Room 1
    strcpy(hauntedHouse[0].name, "Creepy Hallway");
    strcpy(hauntedHouse[0].items[0].name, "Old Portrait");
    strcpy(hauntedHouse[0].items[0].description, "A dusty portrait of a grim-looking man.");
    strcpy(hauntedHouse[0].monsters[0].name, "Ghostly Figure");
    strcpy(hauntedHouse[0].monsters[0].scareDescription, "The figure suddenly hovers closer to you!");
    hauntedHouse[0].itemCount = 1;
    hauntedHouse[0].monsterCount = 1;

    // Room 2
    strcpy(hauntedHouse[1].name, "Spooky Basement");
    strcpy(hauntedHouse[1].items[0].name, "Rusty Key");
    strcpy(hauntedHouse[1].items[0].description, "An old key that seems important.");
    strcpy(hauntedHouse[1].monsters[0].name, "Vampire Bat");
    strcpy(hauntedHouse[1].monsters[0].scareDescription, "A bat swoops down from the ceiling!");
    hauntedHouse[1].itemCount = 1;
    hauntedHouse[1].monsterCount = 1;

    // Add additional rooms as needed...
    totalRooms = 2;
}

void exploreRoom(int roomIndex) {
    Room *room = &hauntedHouse[roomIndex];
    
    printf("Welcome to the %s!\n", room->name);
    
    // List items in the room
    for (int i = 0; i < room->itemCount; i++) {
        printf("You see: %s - %s\n", room->items[i].name, room->items[i].description);
    }

    // List monsters in the room
    for (int i = 0; i < room->monsterCount; i++) {
        printf("Beware of: %s - %s\n", room->monsters[i].name, room->monsters[i].scareDescription);
    }
}

void configureHauntedHouse() {
    int rooms, monsters, items;
    printf("Enter number of rooms (1-%d): ", MAX_ROOMS);
    scanf("%d", &rooms);
    totalRooms = rooms > MAX_ROOMS ? MAX_ROOMS : rooms;

    for (int i = 0; i < totalRooms; i++) {
        printf("Configuring Room %d:\n", i + 1);
        printf("Enter number of monsters (1-%d): ", MAX_MONSTERS);
        scanf("%d", &monsters);
        hauntedHouse[i].monsterCount = monsters > MAX_MONSTERS ? MAX_MONSTERS : monsters;

        printf("Enter number of items (1-%d): ", ITEM_NAMES);
        scanf("%d", &items);
        hauntedHouse[i].itemCount = items > ITEM_NAMES ? ITEM_NAMES : items;
        
        printf("Enter room name: ");
        scanf(" %[^\n]", hauntedHouse[i].name); // Read string with spaces
        
        for(int j = 0; j < items; j++) {
            printf("Enter Item %d name: ", j + 1);
            scanf(" %[^\n]", hauntedHouse[i].items[j].name);
            printf("Enter Item %d description: ", j + 1);
            scanf(" %[^\n]", hauntedHouse[i].items[j].description);
        }
        
        for(int j = 0; j < monsters; j++) {
            printf("Enter Monster %d name: ", j + 1);
            scanf(" %[^\n]", hauntedHouse[i].monsters[j].name);
            printf("Enter Monster %d scare description: ", j + 1);
            scanf(" %[^\n]", hauntedHouse[i].monsters[j].scareDescription);
        }
    }
}

int main() {
    srand(time(NULL));
    
    printf("Welcome to the Haunted House Simulator!\n");
    
    configureHauntedHouse();
    
    for (int i = 0; i < totalRooms; i++) {
        exploreRoom(i);
        printf("\n");
    }
    
    printf("Thank you for playing! Beware of the shadows...\n");
    return 0;
}