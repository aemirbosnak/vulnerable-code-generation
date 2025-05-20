//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROOM 100
#define MAX_WORDS 100
#define MAX_NAME 10
#define MAX_COMMAND 10

typedef struct {
    char name[MAX_NAME];
    int room;
    char commands[MAX_COMMAND][MAX_WORDS];
} Room;

int main() {
    Room rooms[MAX_ROOM];
    int num_rooms = 0;

    printf("Welcome to the Text Adventure Game!\n");
    printf("Please choose an adventure:\n");

    printf("1. Save the princess\n");
    printf("2. Defeat the dragon\n");
    printf("3. Escape the haunted castle\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You are in the princess's castle. You can go to the garden or the throne room.\n");
            printf("1. Garden\n");
            printf("2. Throne room\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            break;
        case 2:
            printf("You are in the dragon's lair. You can fight the dragon or try to escape.\n");
            printf("1. Fight the dragon\n");
            printf("2. Escape\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            break;
        case 3:
            printf("You are in the haunted castle. You can explore the tower or the dungeon.\n");
            printf("1. Tower\n");
            printf("2. Dungeon\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            break;
    }

    // Your code for the rest of the game goes here

    return 0;
}