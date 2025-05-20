#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROOM_SIZE 100

void print_room(char room[]) {
    printf("\n%s\n", room);
}

int main() {
    char room[ROOM_SIZE];
    char key[ROOM_SIZE];
    char input[ROOM_SIZE];

    strcpy(room, "Welcome to the Treasure Hunt! You are in room 1. To move to another room, enter the room number.\n");
    strcpy(key, "123456789");

    while (1) {
        print_room(room);
        printf("> ");
        scanf("%s", input);

        if (strcmp(input, key) == 0) {
            strcpy(room, "Congratulations! You found the treasure in room 10. Game over.\n");
            break;
        } else {
            sprintf(room, "Incorrect input. Try again.\n");
        }
    }

    return 0;
}
