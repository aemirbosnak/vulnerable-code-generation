//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char* room_name;
    char* description;
    char* direction;
    char* verb;
    char* noun;

    room_name = "Kitchen";
    description = "You are in the kitchen. There is a refrigerator, a sink, and a stove.";
    direction = "Go to the living room.";
    verb = "get";
    noun = "key";

    printf("You are in the %s.\n", room_name);
    printf("%s\n", description);
    printf("What do you want to do?\n");

    while (1) {
        scanf("%s %s", verb, noun);
        if (!strcmp(verb, "go")) {
            if (!strcmp(noun, "north")) {
                printf("You walk to the north.\n");
                printf("%s\n", description);
            } else if (!strcmp(noun, "south")) {
                printf("You walk to the south.\n");
                printf("%s\n", description);
            } else if (!strcmp(noun, "east")) {
                printf("You walk to the east.\n");
                printf("%s\n", description);
            } else if (!strcmp(noun, "west")) {
                printf("You walk to the west.\n");
                printf("%s\n", description);
            } else {
                printf("I don't understand that direction.\n");
            }
        } else if (!strcmp(verb, "get")) {
            if (!strcmp(noun, "key")) {
                printf("You get the key.\n");
            } else {
                printf("I don't understand that noun.\n");
            }
        } else {
            printf("I don't understand that verb.\n");
        }

        printf("What do you want to do?\n");
    }

    return 0;
}