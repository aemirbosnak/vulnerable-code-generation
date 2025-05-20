//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void print_intro() {
    printf("========================================\n");
    printf("          WELCOME TO THE DUNGEON       \n");
    printf("========================================\n");
    printf("You find yourself in a dark and eerie dungeon,\n");
    printf("filled with hidden treasures and dangerous monsters.\n");
    printf("Your goal is to explore the dungeon, find the treasure,\n");
    printf("and escape alive!\n");
    printf("========================================\n");
}

void print_choices() {
    printf("\nWhat would you like to do?\n");
    printf("1. Explore the left corridor\n");
    printf("2. Explore the right corridor\n");
    printf("3. Check your inventory\n");
    printf("4. Exit the game\n");
}

int main() {
    char input[MAX_INPUT_LENGTH];
    int choice;
    int treasure_found = 0;
    int monster_encountered = 0;

    print_intro();

    while (1) {
        print_choices();
        
        printf("Enter your choice: ");
        fgets(input, MAX_INPUT_LENGTH, stdin);
        
        // Check for valid integer input
        if (sscanf(input, "%d", &choice) != 1) {
            printf("Please enter a valid number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                if (monster_encountered) {
                    printf("A monster appears! You must fight!\n");
                    printf("You have no weapons and the monster scares you away!\n");
                    printf("You run back to safety.\n");
                    monster_encountered = 0; // Reset monster encounter
                } else {
                    printf("You stroll down the left corridor.\n");
                    if (!treasure_found && rand() % 2) {
                        printf("You find a hidden treasure chest!\n");
                        printf("You take the gold!\n");
                        treasure_found = 1;
                    } else {
                        printf("It's just a dark corridor with nothing special.\n");
                    }
                }
                break;
            case 2:
                printf("You wander into the right corridor...\n");
                if (rand() % 3 == 0) {
                    printf("A wild monster jumps out at you!\n");
                    printf("You don't have a weapon! You can only escape!\n");
                    monster_encountered = 1;
                } else {
                    printf("You find a dusty old pile of bones...\n");
                    if (!treasure_found) {
                        printf("While examining, you discover a hidden gem!\n");
                        printf("You have collected the precious gem!\n");
                        treasure_found = 1;
                    } else {
                        printf("Nothing of interest here.\n");
                    }
                }
                break;
            case 3:
                printf("You check your inventory...\n");
                if (treasure_found) {
                    printf("You have found a treasure! Congratulations!\n");
                } else {
                    printf("Your inventory is empty, keep searching!\n");
                }
                break;
            case 4:
                printf("Thanks for playing! Goodbye!\n");
                exit(0);
            default:
                printf("Please select a valid option.\n");
        }
    }

    return 0;
}