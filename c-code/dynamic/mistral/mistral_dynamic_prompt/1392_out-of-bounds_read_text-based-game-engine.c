#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void game() {
    char inventory[10];
    char input[20];
    char location[50];

    strcpy(location, "forest");
    printf("Welcome to the Text-Based Game Engine!\n");
    printf("You are in the %s\n", location);
    printf("Your current inventory: %s\n", inventory);
    printf("Type 'take' followed by an item in the location to add to your inventory.\n");

    while (1) {
        fgets(input, sizeof(input), stdin);
        char *token = strtok(input, " ");
        if (strcasecmp(token, "take") == 0) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                strcat(inventory, token);
                strcat(inventory, " ");
                printf("You picked up the %s.\n", token);
            } else {
                printf("There's no such item in the location.\n");
            }
        } else if (strcasecmp(token, "move") == 0) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                strcpy(location, token);
                printf("You moved to the %s\n", location);
            } else {
                printf("Please specify a location to move to.\n");
            }
        } else {
            printf("Unknown command. Try 'take' or 'move'.\n");
        }
        printf("Your current inventory: %s\n", inventory);
    }
}

int main() {
    game();
    return 0;
}
