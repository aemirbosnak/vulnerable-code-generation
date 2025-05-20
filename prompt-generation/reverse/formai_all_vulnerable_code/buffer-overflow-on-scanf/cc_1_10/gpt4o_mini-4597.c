//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5

typedef enum {
    EMPTY,
    GHOST,
    TRAP,
    TREASURE
} RoomType;

typedef struct {
    int id;
    RoomType type;
    char *description;
} Room;

void initializeRooms(Room rooms[]);
void displayRoom(Room room);
void encounterEvent(Room room);
void displayMenu();
int selectAction();
void playAgain();

int main() {
    Room rooms[MAX_ROOMS];
    int currentRoom;

    srand(time(0));
    initializeRooms(rooms);

    printf("Welcome to the Haunted House Simulator!\n");
    
    do {
        currentRoom = rand() % MAX_ROOMS;  // Randomly select a room
        displayRoom(rooms[currentRoom]);
        encounterEvent(rooms[currentRoom]);
        
        displayMenu();
        int action = selectAction();

        if (action == 1) {
            printf("You bravely explore further into the haunted house...\n");
        } else if (action == 2) {
            printf("You decide to leave the haunted house... perhaps another day!\n");
            break;
        }

    } while (1);

    playAgain();
    return 0;
}

void initializeRooms(Room rooms[]) {
    rooms[0] = (Room){0, GHOST, "A gloomy room with cobwebs and an eerie chill."};
    rooms[1] = (Room){1, TRAP, "A dark room that seems to close in around you."};
    rooms[2] = (Room){2, TREASURE, "A glimmering room filled with treasures and secrets."};
    rooms[3] = (Room){3, EMPTY, "An empty room with nothing but the sound of the wind."};
    rooms[4] = (Room){4, GHOST, "A room filled with shadows and whispers of the undead."};
}

void displayRoom(Room room) {
    printf("\nYou have entered room %d.\n", room.id);
    printf("%s\n", room.description);
}

void encounterEvent(Room room) {
    switch (room.type) {
        case GHOST:
            printf("A ghost appears before you! What will you do?\n");
            break;
        case TRAP:
            printf("You've fallen into a trap! You need to find a way out.\n");
            break;
        case TREASURE:
            printf("You've found a treasure chest! You are rich beyond your wildest dreams!\n");
            break;
        case EMPTY:
            printf("It's just an empty room... keep moving.\n");
            break;
    }
}

void displayMenu() {
    printf("\nChoose your action:\n");
    printf("1. Explore further\n");
    printf("2. Leave the haunted house\n");
}

int selectAction() {
    int action;
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &action);

    while (action < 1 || action > 2) {
        printf("Invalid choice! Please try again: ");
        scanf("%d", &action);
    }

    return action;
}

void playAgain() {
    char choice;
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        main();
    } else {
        printf("Thank you for playing! Goodbye!\n");
    }
}