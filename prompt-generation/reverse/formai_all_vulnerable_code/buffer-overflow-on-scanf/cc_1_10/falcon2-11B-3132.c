//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct {
    char* name;
    char* description;
    char* action;
} Room;

Room rooms[MAX_WORDS];

void read_room(Room* room) {
    char* name;
    char* description;
    char* action;

    printf("Enter room name: ");
    scanf("%s", name);

    printf("Enter room description: ");
    scanf("%s", description);

    printf("Enter room action: ");
    scanf("%s", action);

    room->name = name;
    room->description = description;
    room->action = action;
}

void print_room(Room* room) {
    printf("Name: %s\n", room->name);
    printf("Description: %s\n", room->description);
    printf("Action: %s\n", room->action);
}

int main() {
    Room room;
    int choice;

    read_room(&room);

    do {
        print_room(&room);
        printf("Enter '1' to enter the room.\nEnter '2' to exit the game.\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You enter the room.\n");
            break;
        } else if (choice == 2) {
            printf("You exit the game.\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}