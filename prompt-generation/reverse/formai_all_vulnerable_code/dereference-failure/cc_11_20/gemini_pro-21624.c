//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 10
#define MAX_EVENTS 5

typedef struct {
    int room;
    int event;
} Event;

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the haunted house
    Event events[NUM_ROOMS][MAX_EVENTS];

    // Populate the haunted house with events
    for (int i = 0; i < NUM_ROOMS; i++) {
        for (int j = 0; j < MAX_EVENTS; j++) {
            events[i][j].room = rand() % NUM_ROOMS;
            events[i][j].event = rand() % 5;
        }
    }

    // Simulate the haunted house
    int current_room = 0;
    while (1) {
        // Get the current events
        Event* current_events = events[current_room];

        // Print the current room
        printf("You are in room %d.\n", current_room);

        // Print the current events
        for (int i = 0; i < MAX_EVENTS; i++) {
            Event event = current_events[i];
            switch (event.event) {
                case 0:
                    printf("You hear a creaking sound.\n");
                    break;
                case 1:
                    printf("You see a shadow moving in the corner of your eye.\n");
                    break;
                case 2:
                    printf("You feel a cold breeze on your neck.\n");
                    break;
                case 3:
                    printf("You hear a faint whisper.\n");
                    break;
                case 4:
                    printf("You feel a hand on your shoulder.\n");
                    break;
            }
        }

        // Get the user's input
        printf("What do you want to do?\n");
        printf("1. Move to another room\n");
        printf("2. Quit\n");
        int choice;
        scanf("%d", &choice);

        // Move to another room
        if (choice == 1) {
            int new_room;
            printf("Which room do you want to move to?\n");
            scanf("%d", &new_room);
            current_room = new_room;
        }

        // Quit the game
        else if (choice == 2) {
            break;
        }
    }

    return 0;
}