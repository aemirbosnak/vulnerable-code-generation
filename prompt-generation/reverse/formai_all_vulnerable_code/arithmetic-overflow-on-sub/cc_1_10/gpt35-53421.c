//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_GHOSTS 5

typedef struct Room {
    int number;
    bool visited;
    bool has_ghost;
} Room;

Room haunted_house[MAX_ROOMS];
int current_room;

void generate_ghosts() {
    srand(time(0));
    int ghost_count = rand() % MAX_GHOSTS + 1;

    for (int i = 0; i < ghost_count; i++) {
        int ghost_room = rand() % MAX_ROOMS;
        haunted_house[ghost_room].has_ghost = true;
    }
}

void print_room_status() {
    printf("You are in room #%d.\n", current_room+1);

    if (haunted_house[current_room].has_ghost) {
        printf("There is a ghost in this room!\n");
    } else {
        printf("This room seems safe.\n");
    }

    haunted_house[current_room].visited = true;
}

void move_to_room(int room_number) {
    if (room_number >= MAX_ROOMS || room_number < 0) {
        printf("Invalid room number.\n");
        return;
    }

    current_room = room_number;
    print_room_status();
}

void game_loop() {
    while(true) {
        int choice;

        printf("\nWhat would you like to do?\n");
        printf("1. Move to a different room.\n");
        printf("2. Quit the game.\n");
        printf("Choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int room_number;
                printf("\nEnter room number: ");
                scanf("%d", &room_number);
                move_to_room(room_number-1);
                break;
            }
            case 2: {
                printf("\nThanks for playing!\n");
                return;
            }
            default: {
                printf("\nInvalid choice.\n");
                break;
            }
        }
    }
}

int main() {
    printf("Welcome to the Haunted House Simulator!\n\n");
    generate_ghosts();
    move_to_room(0);
    game_loop();
    return 0;
}