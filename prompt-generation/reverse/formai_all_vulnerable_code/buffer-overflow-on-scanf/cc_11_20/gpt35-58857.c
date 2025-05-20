//FormAI DATASET v1.0 Category: Smart home light control ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
    int bedroom_light = 0;
    int living_room_light = 0;

    printf("Hello! Welcome to the Smart Home Light Control Program.\n");

    while(1) {
        printf("Please enter the room you would like to control the light for: ");
        char room_choice;
        scanf("%c", &room_choice);
        getchar(); // clear the input buffer

        if(room_choice == 'b' || room_choice == 'B') {
            printf("You have selected bedroom.\n");
            printf("What would you like to do? (on / off / exit): ");
            char action_choice[5];
            scanf("%s", action_choice);
            getchar(); // clear the input buffer

            if(strcmp(action_choice, "on") == 0) {
                printf("Turning bedroom light on.\n");
                bedroom_light = 1;
            }
            else if(strcmp(action_choice, "off") == 0) {
                printf("Turning bedroom light off.\n");
                bedroom_light = 0;
            }
            else if(strcmp(action_choice, "exit") == 0) {
                printf("Exiting...\n");
                exit(0);
            }
            else {
                printf("Invalid input.\n");
            }

            printf("Bedroom light is currently %s.\n", (bedroom_light ? "on" : "off"));
        }
        else if(room_choice == 'l' || room_choice == 'L') {
            printf("You have selected living room.\n");
            printf("What would you like to do? (on / off / exit): ");
            char action_choice[5];
            scanf("%s", action_choice);
            getchar(); // clear the input buffer

            if(strcmp(action_choice, "on") == 0) {
                printf("Turning living room light on.\n");
                living_room_light = 1;
            }
            else if(strcmp(action_choice, "off") == 0) {
                printf("Turning living room light off.\n");
                living_room_light = 0;
            }
            else if(strcmp(action_choice, "exit") == 0) {
                printf("Exiting...\n");
                exit(0);
            }
            else {
                printf("Invalid input.\n");
            }

            printf("Living room light is currently %s.\n", (living_room_light ? "on" : "off"));
        }
        else {
            printf("Invalid input.\n");
        }
    }

    return 0;
}