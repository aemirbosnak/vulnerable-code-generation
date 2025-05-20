//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv) {
    char name[50];
    char command[100];

    // Print welcome message
    printf("Welcome to Sherlock's Adventure!\n");
    printf("What is your name?\n");

    // Get user input for name
    scanf("%s", name);
    printf("Hello %s, welcome to 221B Baker Street!\n", name);

    // Initialize variables
    char* directions[] = {"north", "south", "east", "west", "up", "down", "left", "right"};
    int current_location = 0;
    int current_direction = 0;

    // Main loop
    while(1) {
        // Print current location
        printf("You are at %s.\n", directions[current_location]);

        // Get user input for command
        scanf("%s", command);
        char* tokens[3];
        sscanf(command, "%s %s %s", tokens[0], tokens[1], tokens[2]);

        // Handle commands
        if(strcmp(tokens[0], "look") == 0) {
            printf("You look around and see: %s.\n", directions[current_location]);
        } else if(strcmp(tokens[0], "go") == 0) {
            if(strcmp(tokens[1], "north") == 0) {
                current_location = 1;
                current_direction = 1;
                printf("You go north.\n");
            } else if(strcmp(tokens[1], "south") == 0) {
                current_location = 2;
                current_direction = 1;
                printf("You go south.\n");
            } else if(strcmp(tokens[1], "east") == 0) {
                current_location = 3;
                current_direction = 2;
                printf("You go east.\n");
            } else if(strcmp(tokens[1], "west") == 0) {
                current_location = 4;
                current_direction = 2;
                printf("You go west.\n");
            } else if(strcmp(tokens[1], "up") == 0) {
                current_location = 5;
                current_direction = 3;
                printf("You go up.\n");
            } else if(strcmp(tokens[1], "down") == 0) {
                current_location = 6;
                current_direction = 3;
                printf("You go down.\n");
            } else if(strcmp(tokens[1], "left") == 0) {
                current_location = 0;
                current_direction = 0;
                printf("You go left.\n");
            } else if(strcmp(tokens[1], "right") == 0) {
                current_location = 1;
                current_direction = 0;
                printf("You go right.\n");
            } else {
                printf("Invalid command.\n");
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}