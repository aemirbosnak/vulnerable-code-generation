//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Room structure
typedef struct Room {
    int roomNumber;
    char* roomName;
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
    int haunted;
} Room;

// Function to create a room
Room* createRoom(int num, char* name) {
    Room* r = (Room*) malloc(sizeof(Room));
    r->roomNumber = num;
    r->roomName = name;
    r->north = NULL;
    r->south = NULL;
    r->east = NULL;
    r->west = NULL;
    // Randomly assign if room is haunted or not
    r->haunted = rand() % 2;
    return r;
}

// Function to connect rooms
void connectRooms(Room* r1, Room* r2, char* direction) {
    if (direction == "north") {
        r1->north = r2;
        r2->south = r1;
    } else if (direction == "south") {
        r1->south = r2;
        r2->north = r1;
    } else if (direction == "east") {
        r1->east = r2;
        r2->west = r1;
    } else if (direction == "west") {
        r1->west = r2;
        r2->east = r1;
    }
}

// Function to print out the map
void printMap(Room* r) {
    printf("You are in %s\n", r->roomName);
    if (r->north != NULL) {
        printf("To the north is %s\n", r->north->roomName);
    }
    if (r->south != NULL) {
        printf("To the south is %s\n", r->south->roomName);
    }
    if (r->east != NULL) {
        printf("To the east is %s\n", r->east->roomName);
    }
    if (r->west != NULL) {
        printf("To the west is %s\n", r->west->roomName);
    }
}

// Function to simulate entering a room
void enterRoom(Room* r) {
    printf("You enter the %s\n", r->roomName);
    if (r->haunted) {
        printf("The room is haunted!\n");
    }
    printf("You look around...\n");
    printf("You see...\n");
    // Add spooky items in the room
    printf("- An old dusty armchair\n");
    printf("- A cobweb-covered chandelier\n");
    printf("- A creaky wooden floor\n");
}

// Main function
int main() {
    srand(time(0)); // Initialize random seed

    // Create all the rooms
    Room* foyer = createRoom(1, "Foyer");
    Room* hallway = createRoom(2, "Hallway");
    Room* livingRoom = createRoom(3, "Living Room");
    Room* diningRoom = createRoom(4, "Dining Room");
    Room* kitchen = createRoom(5, "Kitchen");
    Room* basement = createRoom(6, "Basement");
    Room* bedroom = createRoom(7, "Bedroom");
    Room* bathroom = createRoom(8, "Bathroom");
    Room* attic = createRoom(9, "Attic");
    Room* study = createRoom(10, "Study");

    // Connect the rooms
    connectRooms(foyer, hallway, "north");
    connectRooms(hallway, livingRoom, "east");
    connectRooms(hallway, diningRoom, "west");
    connectRooms(livingRoom, kitchen, "east");
    connectRooms(basement, kitchen, "west");
    connectRooms(hallway, basement, "south");
    connectRooms(hallway, bedroom, "north");
    connectRooms(bathroom, bedroom, "west");
    connectRooms(attic, bedroom, "east");
    connectRooms(study, attic, "north");
    connectRooms(study, diningRoom, "south");

    Room* currentRoom = foyer; // Start the game in the foyer
    printf("Welcome to the Haunted House Simulator! Can you make it out alive?\n");
    while (1) {
        printMap(currentRoom); // Print the map
        enterRoom(currentRoom); // Simulate entering a room

        // Check if the room is haunted
        if (currentRoom->haunted) {
            printf("You have been scared by the ghosts in this haunted room! GAME OVER.\n");
            exit(0);
        }

        // Get user input on which direction to go
        char dir;
        printf("\nWhich direction do you want to go? (n/s/e/w): ");
        scanf("%c", &dir);
        getchar();

        // Move to the next room based on user input
        if (dir == 'n' && currentRoom->north != NULL) {
            currentRoom = currentRoom->north;
        } else if (dir == 's' && currentRoom->south != NULL) {
            currentRoom = currentRoom->south;
        } else if (dir == 'e' && currentRoom->east != NULL) {
            currentRoom = currentRoom->east;
        } else if (dir == 'w' && currentRoom->west != NULL) {
            currentRoom = currentRoom->west;
        } else {
            printf("You can't go in that direction!\n");
        }

        printf("\n");
    }

    return 0;
}