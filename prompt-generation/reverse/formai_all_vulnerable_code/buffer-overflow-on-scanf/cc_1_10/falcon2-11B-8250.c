//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the haunted house
typedef struct {
    char name[50];
    int size;
    int rooms;
    char *type;
} HauntedHouse;

// Define the structure for the room
typedef struct {
    char name[50];
    int size;
    int furniture;
} Room;

// Define the structure for the furniture
typedef struct {
    char name[50];
    int size;
} Furniture;

// Function to print the haunted house
void printHouse(HauntedHouse *hh) {
    printf("Haunted House: %s\n", hh->name);
    printf("Size: %d\n", hh->size);
    printf("Rooms: %d\n", hh->rooms);
    printf("Type: %s\n", hh->type);
}

// Function to print the room
void printRoom(Room *room) {
    printf("Room: %s\n", room->name);
    printf("Size: %d\n", room->size);
    printf("Furniture: %d\n", room->furniture);
}

// Function to print the furniture
void printFurniture(Furniture *furn) {
    printf("Furniture: %s\n", furn->name);
    printf("Size: %d\n", furn->size);
}

// Function to add a room to the haunted house
void addRoom(HauntedHouse *hh, Room *room) {
    hh->rooms++;
    hh->size += room->size;
}

// Function to add furniture to a room
void addFurniture(Room *room, Furniture *furn) {
    room->furniture++;
    room->size += furn->size;
}

// Function to create a haunted house
HauntedHouse *createHouse(char *name, int size, int rooms, char *type) {
    HauntedHouse *hh = malloc(sizeof(HauntedHouse));
    if (hh == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(hh->name, name);
    hh->size = size;
    hh->rooms = rooms;
    strcpy(hh->type, type);
    return hh;
}

// Function to create a room
Room *createRoom(char *name, int size, int furniture) {
    Room *room = malloc(sizeof(Room));
    if (room == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(room->name, name);
    room->size = size;
    room->furniture = furniture;
    return room;
}

// Function to create furniture
Furniture *createFurniture(char *name, int size) {
    Furniture *furn = malloc(sizeof(Furniture));
    if (furn == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(furn->name, name);
    furn->size = size;
    return furn;
}

// Function to print the main menu
void printMenu() {
    printf("1. Create a haunted house\n");
    printf("2. Create a room\n");
    printf("3. Create furniture\n");
    printf("4. Add a room to a haunted house\n");
    printf("5. Add furniture to a room\n");
    printf("6. Print the haunted house\n");
    printf("7. Exit\n");
}

// Function to create a haunted house
HauntedHouse *createHouse1() {
    HauntedHouse *hh = createHouse("Haunted House", 1000, 5, "Old Mansion");
    if (hh == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    return hh;
}

// Function to create a room
Room *createRoom1() {
    Room *room = createRoom("Room 1", 500, 3);
    if (room == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    return room;
}

// Function to create furniture
Furniture *createFurniture1() {
    Furniture *furn = createFurniture("Furniture 1", 200);
    if (furn == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    return furn;
}

// Function to add a room to the haunted house
void addRoom1() {
    HauntedHouse *hh = createHouse1();
    if (hh == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    Room *room = createRoom1();
    if (room == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    addRoom(hh, room);
    printHouse(hh);
}

// Function to add furniture to a room
void addFurniture1() {
    Room *room = createRoom1();
    if (room == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    Furniture *furn = createFurniture1();
    if (furn == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    addFurniture(room, furn);
    printRoom(room);
}

// Function to print the haunted house
void printHouse1() {
    HauntedHouse *hh = createHouse1();
    if (hh == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printHouse(hh);
}

// Function to print the room
void printRoom1() {
    Room *room = createRoom1();
    if (room == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printRoom(room);
}

// Function to print the furniture
void printFurniture1() {
    Furniture *furn = createFurniture1();
    if (furn == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printFurniture(furn);
}

// Main function
int main() {
    printMenu();
    int choice;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: createHouse1(); break;
            case 2: createRoom1(); break;
            case 3: createFurniture1(); break;
            case 4: addRoom1(); break;
            case 5: addFurniture1(); break;
            case 6: printHouse1(); break;
            case 7: exit(0); break;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}