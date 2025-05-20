//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ITEMS 5

// List of clues used during the game
char* clues[MAX_ITEMS] = {
    "A mysterious sound echoes through the halls",
    "You spot an old diary with a strange inscription",
    "The doors creak as a cold breeze blows past",
    "A ghostly figure appears, then disappears in a flash",
    "A spooky message is scrawled on the wall in blood"
};

// List of rooms with their descriptions and which clues they hold
struct Room {
    char* name;
    char* description;
    int clueIndex;
};

struct Room rooms[] = {
    {"Foyer", "You stand in a grand foyer with a chandelier overhead", 0},
    {"Library", "You enter a room lined with shelves of old books", 1},
    {"Dining Room", "You see a table set for a lavish dinner party", 2},
    {"Sitting Room", "You find a room with plush armchairs and a fireplace", 3},
    {"Bedroom", "You step into a bedroom with a large four-poster bed", 4}
};

// Declare helper functions
void printRoom(struct Room room);
int getRandomIndex(int current, bool* usedIndices);

int main() {
    srand(time(0)); // Initialize random seed with current time

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are trapped inside a haunted house and must find a way out.\n\n");

    int currentRoomIndex = 0;
    bool usedIndices[MAX_ITEMS] = { false }; // Keep track of clues found

    while(true) {
        printRoom(rooms[currentRoomIndex]);

        if(!usedIndices[rooms[currentRoomIndex].clueIndex]) { // If clue not found yet
            printf("\nYou find a clue: %s\n\n", clues[rooms[currentRoomIndex].clueIndex]);
            usedIndices[rooms[currentRoomIndex].clueIndex] = true;
        }

        printf("Where would you like to go next?\n");
        printf("0: Foyer\n1: Library\n2: Dining Room\n3: Sitting Room\n4: Bedroom\n");
        int choice;
        scanf("%d", &choice);

        if(choice < 0 || choice > 4) { // Invalid choice
            printf("Invalid input. Please select a number between 0 and 4.\n\n");
            continue;
        }
        else if(choice == currentRoomIndex) { // Already in that room
            printf("You are already in the %s.\n\n", rooms[currentRoomIndex].name);
            continue;
        }
        else {
            currentRoomIndex = getRandomIndex(currentRoomIndex, usedIndices); // Jump randomly to new room
        }

        if(usedIndices[0] && usedIndices[1] && usedIndices[2] && usedIndices[3] && usedIndices[4]) { // If all clues found
            printf("\nCongratulations! You found all the clues and escaped the haunted house!\n");
            break;
        }
    }

    return 0;
}

// Print the name and description of a room
void printRoom(struct Room room) {
    printf("You are now in the %s.\n", room.name);
    printf("%s\n", room.description);
}

// Get a random index for a new room that hasn't been visited yet
int getRandomIndex(int current, bool* usedIndices) {
    int randomIndex;
    do {
        randomIndex = rand() % MAX_ITEMS;
    } while(randomIndex == current || usedIndices[randomIndex]); // Continue if already visited
    return randomIndex;
}