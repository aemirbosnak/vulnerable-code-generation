//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the intro message
void printIntro() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Are you brave enough to explore the haunted house?\n");
    printf("Enter 'Y' for Yes and 'N' for No: ");
}

// Function to generate random number within a range
int generateRandomNumber(int min, int max) {
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

// Function to simulate a creepy sound
void creepySound() {
    int num = generateRandomNumber(1, 3);
    switch (num) {
        case 1: 
            printf("You hear a faint whisper...\n");
            break;
        case 2:
            printf("You hear footsteps...\n");
            break;
        case 3:
            printf("You hear a blood-curdling scream...\n");
            break;
    }
}

// Function to simulate a jump scare
void jumpScare() {
    printf("BOO!\n");
}

// Function to simulate a ghost sighting
void ghostSighting() {
    printf("You see a ghost floating in front of you...\n");
}

// Function to simulate a creepy event
void creepyEvent() {
    int num = generateRandomNumber(1, 3);
    switch (num) {
        case 1: 
            creepySound();
            break;
        case 2:
            jumpScare();
            break;
        case 3:
            ghostSighting();
            break;
    }
}

int main() {
    // Seed the random number generator
    srand(time(0));
    
    // Print the intro message
    printIntro();
    
    // Read the user's response
    char response;
    scanf("%c", &response);
    
    // If the user wants to play
    if (response == 'Y') {
        printf("You enter the haunted house...\n");
        printf("As you walk through the hallway, the lights flicker...\n");
        printf("You hear a door creak open...\n");
        
        int numRooms = generateRandomNumber(3, 5);
        
        for (int i = 1; i <= numRooms; i++) {
            printf("You enter room %d...\n", i);
            creepyEvent();
        }
        
        printf("You emerge from the haunted house, shaken but unharmed...\n");
    } 
    // If the user doesn't want to play
    else {
        printf("Goodbye.\n");
    }
    
    return 0;
}