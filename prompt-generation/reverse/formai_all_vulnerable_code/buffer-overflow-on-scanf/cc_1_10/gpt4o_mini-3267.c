//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 5

const char *rooms[NUM_ROOMS] = {
    "haunted living room",
    "creepy attic",
    "spooky basement",
    "dark kitchen",
    "mysterious hallway"
};

const char *events[] = {
    "You encounter a spooky ghost! Run away!",
    "You find a hidden treasure chest!",
    "A cold breeze wraps around you. Is someone watching?",
    "You hear the sound of chains rattling.",
    "You see a flickering light. Investigate?"
};

void printWelcomeMessage() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Your mission: Explore the house and survive the night.\n");
    printf("Choose wisely and beware of what lurks in the shadows...\n\n");
}

void enterRoom(int roomIndex) {
    printf("You enter the %s.\n", rooms[roomIndex]);
    
    int eventIndex = rand() % (sizeof(events) / sizeof(events[0]));
    printf("%s\n", events[eventIndex]);
}

int main() {
    srand(time(0)); // Seed the random number generator
    int choice;
    char continueExploring = 'y';
    
    printWelcomeMessage();

    while (continueExploring == 'y') {
        printf("Choose a room to explore:\n");
        for (int i = 0; i < NUM_ROOMS; i++) {
            printf("%d. %s\n", i + 1, rooms[i]);
        }
        printf("Enter the number of your selected room (1-%d): ", NUM_ROOMS);
        scanf("%d", &choice);
        
        if (choice < 1 || choice > NUM_ROOMS) {
            printf("Invalid choice! Try again.\n\n");
            continue;
        }

        enterRoom(choice - 1);

        printf("Do you wish to continue exploring? (y/n): ");
        scanf(" %c", &continueExploring);
        
        if (continueExploring != 'y') {
            printf("Thank you for playing! Hope to see you again...\n");
        } else {
            printf("\nPrepare for more adventures!\n");
        }
    }

    return 0;
}