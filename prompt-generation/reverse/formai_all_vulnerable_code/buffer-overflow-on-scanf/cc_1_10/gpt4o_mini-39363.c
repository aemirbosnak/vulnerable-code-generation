//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5

const char *rooms[MAX_ROOMS] = {
    "The Enchanted Library",
    "The Creepy Attic",
    "The Blood-Red Kitchen",
    "The Ghostly Basement",
    "The Forbidden Garden"
};

const char *spooks[] = {
    "A ghost whispers in your ear.",
    "A skeleton jumps out at you!",
    "You feel a cold breeze pass by.",
    "A painting's eyes follow you...",
    "A door creaks open by itself."
};

void display_welcome() {
    printf("*************************************************\n");
    printf("     Welcome to the Haunted House Simulator!     \n");
    printf("*************************************************\n");
}

void display_instructions() {
    printf("Instructions: \n");
    printf("Navigate through the haunted house and survive the scares!\n");
    printf("Type 'enter' to move into a new room, or 'exit' to leave the house.\n");
}

void random_event() {
    int r = rand() % (sizeof(spooks) / sizeof(spooks[0]));
    printf("%s\n", spooks[r]);
}

void enter_room(int room_index) {
    printf("You step into %s...\n", rooms[room_index]);
    random_event();
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int current_room = 0;
    char command[10];

    display_welcome();
    display_instructions();
    
    while (1) {
        enter_room(current_room);
        printf("What do you want to do? (enter/exit)\n");
        scanf("%s", command);

        if (strcasecmp(command, "enter") == 0) {
            current_room = (current_room + 1) % MAX_ROOMS; // Move to the next room
        } else if (strcasecmp(command, "exit") == 0) {
            printf("Thanks for playing! You escaped the haunted house!\n");
            break;
        } else {
            printf("Invalid command. Please type 'enter' or 'exit'.\n");
        }
    }

    return 0;
}