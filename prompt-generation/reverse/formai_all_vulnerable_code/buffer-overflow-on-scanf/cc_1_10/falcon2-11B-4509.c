//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char player_name[50];
char* inventory = NULL;

int main() {
    char input[50];
    char command[50];
    char* room_names[4] = {"Kitchen", "Living Room", "Bedroom", "Hallway"};
    char* room_descriptions[4] = {"The kitchen is where you can prepare meals.",
    "The living room is where you can relax and watch TV.",
    "The bedroom is where you can sleep.",
    "The hallway connects all the rooms."};
    char* items[4] = {"Fork", "Remote Control", "Pillow", "Door Key"};
    int item_num = 0;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", player_name);
    printf("Welcome %s!\n", player_name);

    printf("You find yourself in the hallway.\n");
    printf("You can go to the %s, %s, %s or %s.\n", room_names[0], room_names[1], room_names[2], room_names[3]);
    printf("What do you want to do?\n");

    while (1) {
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        } else if (strncmp(input, "go ", 3) == 0) {
            strncpy(command, input + 3, 50);
            command[strlen(command) - 1] = '\0';
            for (int i = 0; i < 4; i++) {
                if (strcmp(command, room_names[i]) == 0) {
                    printf("You go to the %s.\n", room_names[i]);
                    break;
                }
            }
        } else if (strcmp(input, "inventory") == 0) {
            printf("You have %s.\n", items[item_num]);
            item_num++;
            if (item_num == 4) {
                item_num = 0;
            }
        } else {
            printf("I'm sorry, I don't understand that command.\n");
        }
        printf("What do you want to do?\n");
    }

    return 0;
}