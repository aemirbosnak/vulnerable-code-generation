//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_ROOMS 5
#define MAX_EVENT_DESCRIPTION 100
#define MAX_INPUT 10

const char* events[NUM_ROOMS] = {
    "You hear footsteps behind you, but no one is there.",
    "A door creaks open, revealing nothing but darkness.",
    "The chandeliers begin to sway, casting eerie shadows.",
    "A whisper brushes past your ear - 'Get Out...'",
    "A cold breeze sends shivers down your spine."
};

void printMenu() {
    printf("Welcome to the Haunted House!\n");
    printf("You can explore the following rooms:\n");
    for (int i = 1; i <= NUM_ROOMS; i++) {
        printf("Room %d\n", i);
    }
    printf("Type 'exit' to leave the house.\n");
}

void simulateRoom(int roomNumber) {
    printf("Entering Room %d...\n", roomNumber);
    // Simulating mysterious events in the room
    int eventIndex = rand() % NUM_ROOMS;
    printf("%s\n", events[eventIndex]);
    sleep(2); // pauses for effect
}

int main() {
    char input[MAX_INPUT];
    srand(time(NULL)); // Initialize random seed

    printMenu();

    while (1) {
        printf("Which room would you like to enter? ");
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        if (strcmp(input, "exit") == 0) {
            printf("You have chosen to leave the haunted house. Goodbye!\n");
            break;
        }

        int roomNumber = atoi(input);

        // Check if the input is a valid room number
        if (roomNumber < 1 || roomNumber > NUM_ROOMS) {
            printf("Invalid room number! Please try again.\n");
            continue;
        }

        simulateRoom(roomNumber);
        printf("\nDo you feel like you are being watched? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        while(getchar() != '\n'); // Clear the input buffer
        if (choice == 'y' || choice == 'Y') {
            printf("You don't see anyone, but... there's a feeling lingering.\n");
        } else {
            printf("It's just your imagination playing tricks on you!\n");
        }
        
        printf("\n-------------------------------------------\n");
    }

    return 0;
}