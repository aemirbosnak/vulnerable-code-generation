//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_OPTIONS 3
#define HOUSE_SIZE 5

typedef struct {
    char *description;
    char *options[MAX_OPTIONS];
    int outcomes[MAX_OPTIONS];
} Room;

void initialize_rooms(Room rooms[]) {
    rooms[0].description = "You find yourself in a dark, spooky hallway. You can see three doors.";
    rooms[0].options[0] = "Enter the left door.";
    rooms[0].options[1] = "Enter the middle door.";
    rooms[0].options[2] = "Enter the right door.";
    rooms[0].outcomes[0] = 1;  // Left Door
    rooms[0].outcomes[1] = 2;  // Middle Door
    rooms[0].outcomes[2] = 3;  // Right Door

    rooms[1].description = "You've entered a room filled with cobwebs. A ghost appears!";
    rooms[1].options[0] = "Fight the ghost.";
    rooms[1].options[1] = "Run back.";
    rooms[1].options[2] = "Try to talk to the ghost.";
    rooms[1].outcomes[0] = 4;  // Fight ghost
    rooms[1].outcomes[1] = 0;  // Return to hallway
    rooms[1].outcomes[2] = 5;  // Talk to ghost

    rooms[2].description = "This room is empty except for a treasure chest.";
    rooms[2].options[0] = "Open the chest.";
    rooms[2].options[1] = "Leave it alone.";
    rooms[2].options[2] = "Look for traps.";
    rooms[2].outcomes[0] = 6;  // Open chest
    rooms[2].outcomes[1] = 0;  // Return to hallway
    rooms[2].outcomes[2] = 7;  // Check traps

    rooms[3].description = "You've stumbled into a room filled with skeletons.";
    rooms[3].options[0] = "Investigate the skeletons.";
    rooms[3].options[1] = "Run away.";
    rooms[3].options[2] = "Search for hidden items.";
    rooms[3].outcomes[0] = 8;  // Investigate skeletons
    rooms[3].outcomes[1] = 0;  // Return to hallway
    rooms[3].outcomes[2] = 9;  // Search items

    rooms[4].description = "Congratulations! You've found the exit from the haunted house!";
    rooms[4].options[0] = "Exit.";
    rooms[4].options[1] = NULL;  // No more options
    rooms[4].options[2] = NULL;  // No more options
    rooms[4].outcomes[0] = -1;   // End game
}

void display_room(Room room) {
    printf("%s\n", room.description);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        if (room.options[i] != NULL) {
            printf("%d. %s\n", i + 1, room.options[i]);
        }
    }
}

int get_player_choice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice - 1;  // Adjust for zero-based index
}

int main() {
    Room rooms[HOUSE_SIZE];
    initialize_rooms(rooms);
    
    int current_room = 0;
    while (current_room != -1) {
        display_room(rooms[current_room]);
        int choice = get_player_choice();
        if (choice >= 0 && choice < MAX_OPTIONS) {
            current_room = rooms[current_room].outcomes[choice];
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
    
    printf("You've escaped the haunted house! Thanks for playing!\n");
    return 0;
}