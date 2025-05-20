//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char name[MAX_LENGTH];
    char command[MAX_LENGTH];
    char *room = "You are in a dark room. There is a door to your left and a door to your right.";
    char *room1 = "You enter the first room. There is a chest in the middle of the room. To open it, enter the password.";
    char *room2 = "You enter the second room. There is a key on the floor. To open the chest in the first room, enter the key.";
    char *room3 = "You enter the third room. You see a sign that says \"You have won the game.\" Congratulations!";

    printf("Welcome to the adventure game! What is your name? ");
    fgets(name, MAX_LENGTH, stdin);
    printf("Hello %s! Welcome to the adventure game!\n", name);

    while (1) {
        printf("> ");
        fgets(command, MAX_LENGTH, stdin);
        command[strlen(command) - 1] = '\0'; // Remove the newline character

        if (strcmp(command, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        int i;
        for (i = 0; i < strlen(room); i++) {
            if (room[i] == command[0]) {
                printf("%s\n", room1);
                break;
            }
        }

        for (i = 0; i < strlen(room1); i++) {
            if (room1[i] == command[0]) {
                printf("%s\n", room2);
                break;
            }
        }

        for (i = 0; i < strlen(room2); i++) {
            if (room2[i] == command[0]) {
                printf("%s\n", room3);
                break;
            }
        }
    }

    return 0;
}