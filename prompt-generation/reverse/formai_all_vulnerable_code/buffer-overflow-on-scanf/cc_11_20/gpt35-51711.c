//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Introduction
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself in a dark forest.\n");
    printf("The goal of the game is to find your way out of the forest.\n");

    int choice, steps = 0;

    // Loop for game
    while (choice != 3) {
        printf("You have taken %d steps.\n", steps);
        printf("What would you like to do?\n");
        printf("1. Go left\n");
        printf("2. Go right\n");
        printf("3. Quit game\n");
        scanf("%d", &choice);

        // Random event
        srand(time(NULL));
        int event = rand() % 3;

        if (choice == 1) {
            steps++;
            printf("You go left.\n");

            // Random event
            if (event == 0) {
                printf("Oh no! You stumbled and twisted your ankle.\n");
                printf("You can't move for the next turn.\n");
                continue;
            }
            else if (event == 1) {
                printf("You found a trail! It leads out of the forest.\n");
                printf("You have won the game!\n");
                break;
            }
            else if (event == 2) {
                printf("You come across a bear.\n");
                printf("You have to fight it to get by.\n");
                printf("You take 3 damage, but you defeat the bear.\n");
                steps++;
            }
        }
        else if (choice == 2) {
            steps++;
            printf("You go right.\n");

            // Random event
            if (event == 0) {
                printf("You stumble across a treasure chest!\n");
                printf("You found a map leading to the way out of the forest.\n");
                steps += 2;
            }
            else if (event == 1) {
                printf("You come across a river.\n");
                printf("You can either swim across, or find a bridge.\n");
                printf("What do you do? (1. Swim, 2. Find bridge)\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("You successfully swim across the river.\n");
                }
                else if (choice == 2) {
                    printf("You find a bridge and cross safely.\n");
                }
                else {
                    printf("Invalid option.\n");
                }
            }
            else if (event == 2) {
                printf("You come across a group of bandits.\n");
                printf("They demand all of your valuables.\n");
                printf("What do you do? (1. Give valuables, 2. Fight)\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("You give them your valuables and they let you pass.\n");
                }
                else if (choice == 2) {
                    printf("You fight the bandits and take 2 damage, but you win.\n");
                    steps++;
                }
                else {
                    printf("Invalid option.\n");
                }
            }
        }
        else if (choice == 3) {
            printf("Exiting game.\n");
        }
        else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}