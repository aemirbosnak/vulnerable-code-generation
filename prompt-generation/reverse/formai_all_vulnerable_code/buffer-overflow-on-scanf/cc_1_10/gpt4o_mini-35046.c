//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 5

const char* rooms[NUM_ROOMS] = {
    "Dark Living Room",
    "Spooky Kitchen",
    "Creepy Basement",
    "Haunted Bedroom",
    "Ghostly Attic"
};

void printWelcome() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are about to explore a strange and frightening house.\n");
    printf("Choose wisely, for danger lurks in every corner...\n\n");
}

void printChoices(int room) {
    printf("\nYou are in the %s.\n", rooms[room]);
    printf("What would you like to do?\n");
    printf("1. Explore the room\n");
    printf("2. Move to another room\n");
    printf("3. Exit the haunted house\n");
}

void exploreRoom(int room) {
    srand(time(0)); // Seed for random function
    int outcome = rand() % 3; // Random outcome (0, 1, or 2)
    
    if (outcome == 0) {
        printf("You found a treasure chest! You are a lucky explorer!\n");
    } else if (outcome == 1) {
        printf("You were scared by a spooky ghost! RUN!\n");
    } else {
        printf("The room is quiet, but you feel a chill...\n");
    }
}

int main() {
    int choice;
    int currentRoom = 0;

    printWelcome();
    
    while(1) {
        printChoices(currentRoom);
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                exploreRoom(currentRoom);
                break;
            case 2:
                currentRoom = (currentRoom + 1) % NUM_ROOMS; // Cycle through rooms
                printf("You moved to the %s.\n", rooms[currentRoom]);
                break;
            case 3:
                printf("Thank you for playing! You have escaped the haunted house.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}