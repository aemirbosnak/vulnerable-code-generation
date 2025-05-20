//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[20];
    int room = 1;

    printf("Welcome to the Adventure Game!\n");
    printf("What is your name? ");
    scanf("%s", name);
    printf("Welcome, %s, to Room 1.\n", name);

    while (room != -1) {
        if (room == 1) {
            printf("You are in Room 1.\n");
            printf("What would you like to do? (go to Room 2, go to Room 3, quit) ");
            char action[20];
            scanf("%s", action);
            if (strcmp(action, "go to Room 2") == 0) {
                printf("You are now in Room 2.\n");
                room = 2;
            } else if (strcmp(action, "go to Room 3") == 0) {
                printf("You are now in Room 3.\n");
                room = 3;
            } else if (strcmp(action, "quit") == 0) {
                printf("Goodbye, %s!\n", name);
                room = -1;
            } else {
                printf("I don't understand that command, %s.\n", name);
            }
        } else if (room == 2) {
            printf("You are in Room 2.\n");
            printf("What would you like to do? (go back to Room 1, quit) ");
            char action[20];
            scanf("%s", action);
            if (strcmp(action, "go back to Room 1") == 0) {
                printf("You are now in Room 1.\n");
                room = 1;
            } else if (strcmp(action, "quit") == 0) {
                printf("Goodbye, %s!\n", name);
                room = -1;
            } else {
                printf("I don't understand that command, %s.\n", name);
            }
        } else if (room == 3) {
            printf("You are in Room 3.\n");
            printf("What would you like to do? (go back to Room 1, look around, quit) ");
            char action[20];
            scanf("%s", action);
            if (strcmp(action, "go back to Room 1") == 0) {
                printf("You are now in Room 1.\n");
                room = 1;
            } else if (strcmp(action, "look around") == 0) {
                printf("You see a key in the corner of the room.\n");
            } else if (strcmp(action, "quit") == 0) {
                printf("Goodbye, %s!\n", name);
                room = -1;
            } else {
                printf("I don't understand that command, %s.\n", name);
            }
        }
    }

    return 0;
}