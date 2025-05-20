//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms in the haunted house
#define MAX_ROOMS 10

// Define the structure of a room
typedef struct {
    char name[50];
    int is_haunted;
    int is_visited;
} Room;

// Initialize the haunted house with random rooms
void init_house(Room house[MAX_ROOMS]) {
    srand(time(NULL));
    for (int i = 0; i < MAX_ROOMS; i++) {
        house[i].is_haunted = rand() % 2;
        house[i].is_visited = 0;
        sprintf(house[i].name, "Room %d", i + 1);
    }
}

// Print the current state of the haunted house
void print_house(Room house[MAX_ROOMS]) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (house[i].is_haunted) {
            printf("%s is haunted!\n", house[i].name);
        } else {
            printf("%s is not haunted.\n", house[i].name);
        }
    }
}

// Allow the player to move between rooms
void move(Room house[MAX_ROOMS], int current_room) {
    printf("Where do you want to go? ");
    scanf("%d", &current_room);
    if (current_room >= 1 && current_room <= MAX_ROOMS) {
        if (!house[current_room - 1].is_visited) {
            house[current_room - 1].is_visited = 1;
            if (house[current_room - 1].is_haunted) {
                printf("You feel a chill down your spine as you enter the haunted room.\n");
            } else {
                printf("You enter the room and find nothing unusual.\n");
            }
        } else {
            printf("You've already been in this room.\n");
        }
    } else {
        printf("Invalid room number.\n");
    }
}

// Main function
int main() {
    Room house[MAX_ROOMS];
    init_house(house);

    int current_room = 1;
    while (1) {
        print_house(house);
        move(house, current_room);
    }

    return 0;
}