//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define MAX_CHOICES 4

// Function prototypes
void display_intro();
void choose_room(int room);
void ghost_encounter();
void find_item(char *item);
int get_random_number(int max);

// Structure to hold room information
typedef struct {
    char *description;
    char *item;
    int has_ghost;
} Room;

// Simulated rooms in the haunted house
Room rooms[] = {
    {"You are in a dark, spooky living room. Shadows dance on the walls.", "a dusty lamp", 1},
    {"You enter the kitchen. The smell of something rotten fills the air.", "a bloody knife", 0},
    {"The hallway is lined with old portraits whose eyes seem to follow you.", "an old diary", 1},
    {"A strange chill fills the bedroom. The atmosphere is eerily quiet.", "a mysterious pendant", 0},
};

void display_intro() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You will explore the haunted rooms in search of treasures and to avoid ghosts!\n");
    printf("Type the number of the room you want to enter.\n\n");
}

void choose_room(int room) {
    if (room < 0 || room >= sizeof(rooms) / sizeof(Room)) {
        printf("Invalid room choice! Try again.\n");
        return;
    }

    printf("Room Description: %s\n", rooms[room].description);
    
    // Check for ghost encounter
    if (rooms[room].has_ghost) {
        ghost_encounter();
    } else {
        find_item(rooms[room].item);
    }
}

void ghost_encounter() {
    printf("A ghost appears before you!\n");
    printf("You can either (1) run away, (2) confront the ghost, or (3) hide\n");
    
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You managed to escape the ghost, but you lost your chance of finding treasures!\n");
            break;
        case 2:
            printf("Brave choice! The ghost vanishes, leaving something behind...\n");
            find_item("a mysterious key");
            break;
        case 3:
            printf("You hide in the shadows and the ghost doesn't see you. Fortune favors the brave!\n");
            break;
        default:
            printf("You've hesitated too long, the ghost got you!\n");
            exit(0);
    }
}

void find_item(char *item) {
    printf("You found %s!\n", item);
}

int get_random_number(int max) {
    return rand() % max;
}

int main() {
    srand(time(NULL));
    display_intro();

    while (1) {
        printf("\nAvailable rooms:\n");
        for (int i = 0; i < sizeof(rooms) / sizeof(Room); i++) {
            printf("%d: %s\n", i, rooms[i].description);
        }
        
        int room_choice;
        printf("Enter the number of the room you'd like to explore (or -1 to exit): ");
        scanf("%d", &room_choice);

        if (room_choice == -1) {
            printf("Thanks for playing the Haunted House Simulator!\n");
            break;
        }

        choose_room(room_choice);
    }

    return 0;
}