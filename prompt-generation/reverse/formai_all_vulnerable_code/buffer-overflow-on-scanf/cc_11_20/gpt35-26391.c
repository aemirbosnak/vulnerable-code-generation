//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("===============================\n");
    printf("|      HAUNTED HOUSE SIM      |\n");
    printf("===============================\n\n");

    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("\n");

    printf("Welcome, %s! You have just entered a haunted house with no way out.\n", name);
    printf("You must explore the haunted house and try to find a way out before time runs out...\n");

    printf("\nLet the game begin!\n\n");

    int time_remaining = 10; // in minutes
    int current_room = 0;
    int has_key = 0;
    int has_flashlight = 0;

    while (time_remaining > 0 && current_room != 5) {
        printf("You are currently in room %d. You have %d minutes remaining.\n", current_room+1, time_remaining);
        printf("What would you like to do?\n");
        printf("1. Go to next room\n");
        printf("2. Look for key\n");
        printf("3. Look for flashlight\n");
        printf("4. Quit game\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Go to next room
                if (current_room == 4) {
                    printf("You have found the way out of the haunted house! Congratulations, %s!\n", name);
                    return 0;
                }
                else if (current_room == 2 && !has_key) {
                    printf("You need a key to enter the next room.\n");
                }
                else if (current_room == 3 && !has_flashlight) {
                    printf("It's too dark to see anything. You need a flashlight.\n");
                }
                else {
                    current_room++;
                    printf("You have entered room %d.\n", current_room+1);
                }
                break;

            case 2: // Look for key
                if (current_room == 1) {
                    printf("You have found the key!\n");
                    has_key = 1;
                }
                else {
                    printf("There is no key in this room.\n");
                }
                break;

            case 3: // Look for flashlight
                if (current_room == 0) {
                    printf("You have found the flashlight!\n");
                    has_flashlight = 1;
                }
                else {
                    printf("There is no flashlight in this room.\n");
                }
                break;

            case 4: // Quit game
                printf("Quitting game...\n");
                return 0;

            default:
                printf("Invalid choice. Please enter a value between 1-4.\n");
                break;
        }

        time_remaining--;
        if (time_remaining == 0) {
            printf("Time's up! Sorry, %s, you didn't make it out in time.\n", name);
        }

        printf("\n");
    }

    return 0;
}