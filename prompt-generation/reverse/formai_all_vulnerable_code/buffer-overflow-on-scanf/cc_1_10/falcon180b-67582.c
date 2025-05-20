//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print a message with a delay
void delay(int time) {
    int i;
    for (i = 0; i < time; i++) {
        printf(".");
        fflush(stdout);
        usleep(50000); // 50ms delay
    }
}

// Function to generate a random number between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to simulate the haunted house
void haunted_house(int level) {
    // Print the current level
    printf("\nLevel %d\n", level);

    // Check if the player has reached the exit
    if (level == 5) {
        printf("Congratulations! You have escaped the haunted house.\n");
        return;
    }

    // Generate a random number of rooms
    int num_rooms = rand_int(3, 7);

    // Loop through each room
    for (int i = 1; i <= num_rooms; i++) {
        // Print the room number
        printf("Room %d:\n", i);

        // Generate a random event for the room
        int event = rand_int(1, 6);

        // Handle each event
        switch (event) {
        case 1:
            // Ghost sighting
            printf("You see a ghostly figure in the corner of the room.\n");
            delay(2000);
            break;
        case 2:
            // Creaking door
            printf("You hear a door creaking in the distance.\n");
            delay(1500);
            break;
        case 3:
            // Whispering voices
            printf("You hear whispering voices coming from the walls.\n");
            delay(2000);
            break;
        case 4:
            // Cold spot
            printf("You feel a sudden drop in temperature as you enter a cold spot.\n");
            delay(1500);
            break;
        case 5:
            // Moving object
            printf("You see an object moving on its own.\n");
            delay(2000);
            break;
        default:
            // Nothing happens
            break;
        }

        // Check if the player wants to continue or quit
        char choice;
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);

        // If the player wants to quit, break out of the loop
        if (choice == 'n') {
            break;
        }
    }

    // Recursively call the haunted_house function for the next level
    haunted_house(level + 1);
}

// Main function
int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Start the haunted house simulation
    haunted_house(1);

    return 0;
}