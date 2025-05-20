//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int choice;
    char input[100], answer[100];

    printf("Welcome to the Adventure Game!\n");
    printf("You are in a dark and eerie forest. What do you do?\n");
    printf("1. Walk Forward\n");
    printf("2. Walk Backward\n");
    printf("3. Check Map\n");
    printf("4. Check Inventory\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You walk forward and find a mysterious cave.\n");
            printf("Do you want to enter the cave? (yes/no)\n");
            scanf("%s", input);
            if (strcmp(input, "yes") == 0) {
                printf("You enter the cave and find a treasure chest.\n");
                printf("Do you want to open the chest? (yes/no)\n");
                scanf("%s", input);
                if (strcmp(input, "yes") == 0) {
                    printf("You open the chest and find a magic sword.\n");
                    printf("You have won the game!\n");
                } else {
                    printf("You decide not to open the chest and leave the cave.\n");
                }
            } else if (strcmp(input, "no") == 0) {
                printf("You decide not to enter the cave and continue walking.\n");
            } else {
                printf("Invalid input. Please enter either yes or no.\n");
            }
            break;
        case 2:
            printf("You walk backward and find yourself back at the start.\n");
            break;
        case 3:
            printf("You check your map and find a path to the castle.\n");
            printf("Do you want to follow the path? (yes/no)\n");
            scanf("%s", input);
            if (strcmp(input, "yes") == 0) {
                printf("You follow the path to the castle and find a chest.\n");
                printf("Do you want to open the chest? (yes/no)\n");
                scanf("%s", input);
                if (strcmp(input, "yes") == 0) {
                    printf("You open the chest and find a magic key.\n");
                    printf("You have won the game!\n");
                } else {
                    printf("You decide not to open the chest and leave the castle.\n");
                }
            } else if (strcmp(input, "no") == 0) {
                printf("You decide not to follow the path and continue walking.\n");
            } else {
                printf("Invalid input. Please enter either yes or no.\n");
            }
            break;
        case 4:
            printf("You check your inventory and find a torch.\n");
            printf("Do you want to use the torch? (yes/no)\n");
            scanf("%s", input);
            if (strcmp(input, "yes") == 0) {
                printf("You use the torch to illuminate the path ahead.\n");
            } else {
                printf("You decide not to use the torch and continue walking.\n");
            }
            break;
        case 5:
            printf("Thank you for playing the Adventure Game! Goodbye.\n");
            return 0;
        default:
            printf("Invalid input. Please enter a valid choice.\n");
            break;
    }

    printf("You continue walking until you reach a river.\n");
    printf("Do you want to cross the river? (yes/no)\n");
    scanf("%s", input);
    if (strcmp(input, "yes") == 0) {
        printf("You cross the river and find yourself in a beautiful garden.\n");
        printf("Do you want to explore the garden? (yes/no)\n");
        scanf("%s", input);
        if (strcmp(input, "yes") == 0) {
            printf("You explore the garden and find a hidden treasure.\n");
            printf("You have won the game!\n");
        } else {
            printf("You decide not to explore the garden and continue walking.\n");
        }
    } else if (strcmp(input, "no") == 0) {
        printf("You decide not to cross the river and continue walking.\n");
    } else {
        printf("Invalid input. Please enter either yes or no.\n");
    }
}