//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a list of rooms in the haunted house
    int rooms[] = {0, 1, 2, 3, 4, 5};
    int num_rooms = sizeof(rooms) / sizeof(rooms[0]);

    // Print the title of the haunted house simulator
    printf("The Sherlock Holmes Haunted House Simulator\n");

    // Create a list of objects in the haunted house
    int objects[] = {0, 0, 0, 0, 0, 0};
    int num_objects = sizeof(objects) / sizeof(objects[0]);

    // Print the list of objects in the haunted house
    printf("Objects in the haunted house:\n");
    for (int i = 0; i < num_objects; i++) {
        if (objects[i] == 0) {
            printf("- ");
        } else {
            printf("- A mysterious object #%d\n", i);
        }
    }

    // Print the list of rooms in the haunted house
    printf("\nRooms in the haunted house:\n");
    for (int i = 0; i < num_rooms; i++) {
        printf("- Room #%d\n", i);
    }

    // Choose a room to enter
    int chosen_room = rand() % num_rooms;
    printf("You enter Room #%d.\n", chosen_room);

    // Check for objects in the room
    int object_count = 0;
    for (int i = 0; i < num_objects; i++) {
        if (objects[i] == 0) {
            printf("You find a mysterious object #%d.\n", i);
            objects[i] = 1;
            object_count++;
        }
    }

    // Check for exits in the room
    int exit_count = 0;
    if (chosen_room == 0) {
        printf("You find an exit to the left.\n");
        exit_count++;
    } else if (chosen_room == 1) {
        printf("You find an exit to the right.\n");
        exit_count++;
    } else if (chosen_room == 2) {
        printf("You find an exit to the top.\n");
        exit_count++;
    } else if (chosen_room == 3) {
        printf("You find an exit to the bottom.\n");
        exit_count++;
    } else if (chosen_room == 4) {
        printf("You find an exit to the front.\n");
        exit_count++;
    } else if (chosen_room == 5) {
        printf("You find an exit to the back.\n");
        exit_count++;
    }

    // Print the list of objects found in the room
    printf("\nObjects in your possession:\n");
    for (int i = 0; i < object_count; i++) {
        printf("- A mysterious object #%d\n", i);
    }

    // Print the list of exits in the room
    printf("\nExits from this room:\n");
    if (exit_count > 0) {
        for (int i = 0; i < exit_count; i++) {
            printf("- An exit to %s\n", (i + 1)? "the" : "a");
        }
    } else {
        printf("There are no exits from this room.\n");
    }

    // Continue exploring the haunted house
    printf("\nDo you want to continue exploring the haunted house? (y/n): ");
    char response;
    scanf(" %c", &response);
    while (response!= 'y' && response!= 'n') {
        printf("Invalid response. Do you want to continue exploring the haunted house? (y/n): ");
        scanf(" %c", &response);
    }
    if (response == 'y') {
        printf("You continue exploring the haunted house.\n");
    } else {
        printf("You decide to leave the haunted house.\n");
    }

    return 0;
}