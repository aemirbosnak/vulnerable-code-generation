//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Custom delay function to create a sense of anticipation
void delay(int milliseconds) {
    long pause;
    clock_t now, then;

    pause = milliseconds * (CLOCKS_PER_SEC / 1000);
    now = then = clock();
    while ((now - then) < pause) now = clock();
}

// Function to generate a random integer within a specified range
int getRand(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Main function to simulate a haunted house experience
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Define the possible events that can occur in the haunted house
    char *events[] = {
        "You hear a creaking sound.",
        "You see a shadowy figure in the distance.",
        "You feel a cold spot on your neck.",
        "You hear a faint whisper.",
        "You feel a tap on your shoulder.",
        "You see a door slowly opening.",
        "You hear a loud crash.",
        "You feel a cold breeze.",
        "You see a ghost!",
        "You escape the haunted house!"
    };

    // Define the probability of each event occurring
    int probabilities[] = {
        10, // Creaking sound
        10, // Shadowy figure
        10, // Cold spot
        10, // Faint whisper
        10, // Tap on shoulder
        10, // Door opening
        10, // Loud crash
        10, // Cold breeze
        10, // Ghost
        1  // Escape
    };

    // Initialize the variables to track the user's progress through the haunted house
    int currentRoom = 1;
    int numEvents = sizeof(events) / sizeof(char *);

    // Loop until the user escapes the haunted house or encounters a ghost
    while (currentRoom <= numEvents && currentRoom != numEvents - 1) {
        // Generate a random event
        int eventIndex = getRand(0, numEvents - 1);

        // Print the event to the console
        printf("%s\n", events[eventIndex]);

        // Check if the event is the "Escape" event
        if (eventIndex == numEvents - 1) {
            printf("You escaped the haunted house!\n");
            break;
        }

        // Check if the event is the "Ghost" event
        if (eventIndex == numEvents - 2) {
            printf("You encountered a ghost!\n");
            break;
        }

        // Delay for a brief period to create a sense of suspense
        delay(500);

        // Increment the current room number
        currentRoom++;
    }

    return 0;
}