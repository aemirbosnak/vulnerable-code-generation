//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 6
#define MAX_MONSTERS 3
#define MAX_TREASURES 2

typedef struct {
    int room_id;
    char description[100];
    int has_monster;
    int monster_strength;
    int treasure_value;
} Room;

void initialize_rooms(Room rooms[]) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].room_id = i + 1;
        sprintf(rooms[i].description, "You are in room %d. It's dark and creepy!", rooms[i].room_id);
        rooms[i].has_monster = rand() % 2;
        rooms[i].monster_strength = rooms[i].has_monster ? (rand() % 10 + 1) : 0;
        rooms[i].treasure_value = (rand() % 2) ? (rand() % 50 + 10) : 0;
    }
}

void print_room_description(Room room) {
    printf("%s\n", room.description);
    if (room.has_monster) {
        printf("A monster appears! It has a strength of %d.\n", room.monster_strength);
    }
    if (room.treasure_value > 0) {
        printf("You found a treasure worth %d gold coins!\n", room.treasure_value);
    }
}

int main() {
    srand(time(NULL));
    Room rooms[MAX_ROOMS];
    int current_room = 0;
    int total_treasure = 0;
    int player_alive = 1;

    initialize_rooms(rooms);

    printf("Welcome to Dungeon Escape!\n");
    
    while (player_alive && current_room < MAX_ROOMS) {
        print_room_description(rooms[current_room]);

        if (rooms[current_room].has_monster) {
            printf("Do you want to fight the monster? (y/n): ");
            char choice;
            scanf(" %c", &choice);
            if (choice == 'y') {
                printf("You chose to fight!\n");
                // Simple combat system
                int player_strength = rand() % 10 + 1;
                printf("You attack with strength %d. ", player_strength);
                if (player_strength >= rooms[current_room].monster_strength) {
                    printf("You defeated the monster!\n");
                    total_treasure += rooms[current_room].treasure_value;
                } else {
                    printf("The monster defeated you! Game over.\n");
                    player_alive = 0;
                }
            } else {
                printf("You avoided the monster and escaped to the next room.\n");
            }
        } else {
            total_treasure += rooms[current_room].treasure_value;
            if (rooms[current_room].treasure_value > 0) {
                printf("You took the treasure!\n");
            } else {
                printf("There's nothing here but darkness.\n");
            }
        }

        current_room++;
        if (current_room < MAX_ROOMS) {
            printf("\nMoving to the next room...\n");
        }
    }

    if (player_alive) {
        printf("Congratulations! You escaped the dungeon with %d gold coins!\n", total_treasure);
    } else {
        printf("You didn't make it out alive. Better luck next time!\n");
    }

    return 0;
}