//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100

void display_intro() {
    printf("=========================================\n");
    printf("       Welcome to Escape from the Dungeon!\n");
    printf("=========================================\n");
    printf("You find yourself in a dark and damp dungeon.\n");
    printf("Your goal is to find the key and escape!\n");
    printf("=========================================\n\n");
}

void display_menu() {
    printf("You can:\n");
    printf("1. Explore the room\n");
    printf("2. Examine surroundings\n");
    printf("3. Check inventory\n");
    printf("4. Quit game\n");
    printf("Choose an option (1-4): ");
}

int main() {
    char input[MAX_INPUT];
    int has_key = 0;
    int is_alive = 1;
    int choice;

    display_intro();

    while (is_alive) {
        display_menu();
        fgets(input, MAX_INPUT, stdin);
        sscanf(input, "%d", &choice);

        switch (choice) {
            case 1:
                if (has_key) {
                    printf("You unlock the door and escape the dungeon! You win!\n");
                    is_alive = 0;
                } else {
                    printf("You explore the room but find nothing useful.\n");
                }
                break;
            case 2:
                if (!has_key) {
                    printf("You examine the surroundings and find a shiny key on the floor!\n");
                    has_key = 1;
                } else {
                    printf("You have already found the key here.\n");
                }
                break;
            case 3:
                if (has_key) {
                    printf("You have a key in your inventory.\n");
                } else {
                    printf("Your inventory is empty.\n");
                }
                break;
            case 4:
                printf("Thank you for playing!\n");
                is_alive = 0;
                break;
            default:
                printf("Invalid choice! Please select a number between 1 and 4.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}