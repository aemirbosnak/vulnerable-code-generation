//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of rooms and some messages
#define NUM_ROOMS 5
const char *rooms[] = {"Library", "Basement", "Hallway", "Attic", "Dining Room"};
const char *spooky_events[] = {
    "A ghost whispers your name!",
    "You hear eerie laughter echoing.",
    "A cold breeze sends chills down your spine.",
    "A shadow flits past your vision!",
    "Something crawls across the floor."
};

// Function to clear the screen
void clear_screen() {
    system("clear");
}

// Function to pick a random spooky event
const char* get_random_event() {
    return spooky_events[rand() % (sizeof(spooky_events)/sizeof(spooky_events[0]))];
}

// Function to print a room description
void print_room(int room_index) {
    clear_screen();
    printf("You are in the %s.\n", rooms[room_index]);
    printf("What will you do?\n");
    printf("1. Explore the room.\n");
    printf("2. Move to another room.\n");
    printf("3. Leave the haunted house.\n");
}

// Function to handle room exploration
void explore_room() {
    clear_screen();
    printf("%s\n", get_random_event());
    printf("You feel a sudden urge to leave...\n");
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user input
}

// Function to navigate through the haunted house
int navigate_house() {
    int current_room = 0;
    int choice;

    while (1) {
        print_room(current_room);
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);
        getchar(); // Clear buffer

        switch (choice) {
            case 1:
                explore_room();
                break;
            case 2:
                current_room = (current_room + 1) % NUM_ROOMS; // Move to next room
                break;
            case 3:
                clear_screen();
                printf("You have escaped the haunted house!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    clear_screen();
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Are you brave enough to explore?\n\n");

    navigate_house();
    
    printf("Thanks for playing!\n");
    return 0;
}