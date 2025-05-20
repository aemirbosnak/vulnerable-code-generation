//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5
#define MAX_GHOSTS 3

typedef struct {
    int id;
    int is_haunted;
    int treasure;
} Room;

void initialize_rooms(Room rooms[]) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].id = i + 1;
        rooms[i].is_haunted = rand() % 2; // Randomly haunted or not
        rooms[i].treasure = rand() % 100; // Random treasure value
    }
}

void enter_room(Room *room) {
    printf("You have entered Room %d.\n", room->id);
    
    if (room->is_haunted) {
        printf("A ghost appears! Boo!\n");
        printf("You must escape!\n");
    } else {
        printf("This room is peaceful. You find treasures worth %d coins!\n", room->treasure);
    }
}

void escape() {
    printf("You quickly escape the haunted house!\n");
    exit(0);
}

void haunted_house_simulator() {
    Room rooms[MAX_ROOMS];
    initialize_rooms(rooms);

    int current_room = 0;
    char choice;

    while (1) {
        enter_room(&rooms[current_room]);

        if (rooms[current_room].is_haunted) {
            printf("Do you want to (e)scape or go to another room (1-4)? ");
        } else {
            printf("Do you want to (c)ontinue or go to another room (1-4)? ");
        }
        
        scanf(" %c", &choice);
        
        if (choice == 'e' || choice == 'E') {
            escape();
        } else if (choice >= '1' && choice <= '4') {
            current_room = choice - '1'; // Update the current room (0-indexed)
            if (current_room >= MAX_ROOMS) {
                printf("Invalid room selection!\n");
                current_room = 0; // Reset to room 1
            }
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    printf("Welcome to the Haunted House Simulator!\n");
    haunted_house_simulator();
    return 0;
}