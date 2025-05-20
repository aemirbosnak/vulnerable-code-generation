//GPT-4o-mini DATASET v1.0 Category: Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5
#define NAME_LENGTH 50

typedef struct {
    char description[100];
    int treasure;
    int monster;
} Room;

void display_intro();
void create_rooms(Room rooms[]);
void explore(Room rooms[], int *current_room, int *total_treasure);
void encounter_monster(int *total_treasure);
void display_status(int total_treasure);

int main() {
    srand(time(NULL));
    
    Room rooms[MAX_ROOMS];
    int current_room = 0;
    int total_treasure = 0;

    display_intro();
    create_rooms(rooms);
    
    while (1) {
        explore(rooms, &current_room, &total_treasure);
        display_status(total_treasure);
        
        char choice;
        printf("\nDo you want to continue exploring? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N') {
            printf("Thank you for playing! You found a total of %d treasure units.\n", total_treasure);
            break;
        }
    }
    
    return 0;
}

void display_intro() {
    printf("Welcome to the Dungeon Adventure!\n");
    printf("You will explore a series of rooms, collecting treasures and fighting monsters.\n");
    printf("Good luck!\n\n");
}

void create_rooms(Room rooms[]) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        snprintf(rooms[i].description, sizeof(rooms[i].description), "You are in room %d.", i + 1);
        rooms[i].treasure = rand() % 10; // Random treasure between 0-9
        rooms[i].monster = rand() % 2;   // Random chance of monster (0 or 1)
    }
}

void explore(Room rooms[], int *current_room, int *total_treasure) {
    // Display room description
    printf("\n%s\n", rooms[*current_room].description);
    
    // Collect treasure
    if (rooms[*current_room].treasure > 0) {
        printf("You found %d treasure units!\n", rooms[*current_room].treasure);
        *total_treasure += rooms[*current_room].treasure;
        rooms[*current_room].treasure = 0; // Treasure is now collected
    } else {
        printf("There's no treasure in this room.\n");
    }
    
    // Handle monster encounter
    if (rooms[*current_room].monster) {
        encounter_monster(total_treasure);
    }

    // Change room
    *current_room = (*current_room + 1) % MAX_ROOMS; // Cycle through rooms
}

void encounter_monster(int *total_treasure) {
    printf("A monster appears! You need to defeat it.\n");
    char action;
    printf("Do you want to fight the monster (f) or run away (r)? ");
    scanf(" %c", &action);
    
    if (action == 'f' || action == 'F') {
        if (rand() % 2) {
            printf("You defeated the monster! You lose some treasure in the battle.\n");
            *total_treasure -= 2; // Lose some treasure
            if (*total_treasure < 0) {
                *total_treasure = 0; // Ensure total treasure doesn't go negative
            }
        } else {
            printf("You were defeated by the monster! Be careful next time.\n");
        }
    } else {
        printf("You run away safely!\n");
    }
}

void display_status(int total_treasure) {
    printf("Current treasure total: %d\n", total_treasure);
}