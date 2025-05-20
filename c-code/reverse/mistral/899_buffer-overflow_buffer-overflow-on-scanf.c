#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void room1() {
    printf("You are in room 1. There is a door to the north and a door to the east.\n");
    char choice[10];
    scanf("%s", choice);
    if (strcmp(choice, "north") == 0) {
        room2();
    } else if (strcmp(choice, "east") == 0) {
        room3();
    } else {
        printf("Invalid input. Try again.\n");
        room1();
    }
}

void room2() {
    printf("You are in room 2. There is a door to the south.\n");
    printf("You find a key here. You can now open the locked door in room 1.\n");
    printf("Type 'continue' to go back to room 1 or 'quit' to end the game.\n");
    char choice[10];
    scanf("%s", choice);
    if (strcmp(choice, "continue") == 0) {
        room1();
    } else if (strcmp(choice, "quit") == 0) {
        printf("Game over.\n");
    } else {
        printf("Invalid input. Try again.\n");
        room2();
    }
}

void room3() {
    printf("You are in room 3. There is a door to the west.\n");
    printf("This room is a dead end. Type 'back' to go back to room 1 or 'quit' to end the game.\n");
    char choice[10];
    scanf("%s", choice);
    if (strcmp(choice, "back") == 0) {
        room1();
    } else if (strcmp(choice, "quit") == 0) {
        printf("Game over.\n");
    } else {
        printf("Invalid input. Try again.\n");
        room3();
    }
}

int main() {
    room1();
    return 0;
}
