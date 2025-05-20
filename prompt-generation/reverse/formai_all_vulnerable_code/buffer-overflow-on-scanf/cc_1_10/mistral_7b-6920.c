//MISTRAL-7B DATASET v1.0 Category: Haunted House Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROOM_COUNT 5

typedef struct {
    char name[50];
    int scare_level;
} Room;

Room rooms[ROOM_COUNT] = {
    {"Entrance Hall", 2},
    {"Dining Room", 5},
    {"Library", 3},
    {"Bedroom", 1},
    {"Attic", 10}
};

void print_room_description(Room room) {
    printf("\nYou are now in the %s.\n", room.name);
    if (room.scare_level > 0) {
        printf("You feel a chill run down your spine.\n");
    }
}

void enter_room(int room_number) {
    Room room = rooms[room_number];
    print_room_description(room);
}

int main() {
    srand(time(NULL));

    int current_room = 0;
    int total_scares = 0;

    printf("Welcome to the Haunted House!\n");

    while (1) {
        enter_room(current_room);

        int roll_dice = rand() % 6 + 1;
        int room_scares = rooms[current_room].scare_level;

        total_scares += roll_dice;
        printf("You rolled a %d. This room adds %d scares.\n", roll_dice, room_scares);

        if (total_scares >= 10) {
            printf("You've had enough scares for one night! Game Over.\n");
            break;
        }

        int choice;
        printf("Do you want to explore another room? (y/n): ");
        scanf("%d", &choice);

        if (choice == 'n') {
            printf("You leave the haunted house, shaken but alive.\n");
            break;
        } else if (choice != 'y') {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        int next_room = rand() % ROOM_COUNT;
        printf("You decide to explore the %s instead.\n", rooms[next_room].name);
        current_room = next_room;
    }

    return 0;
}