//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    char name[20];
    printf("What is your name? ");
    scanf("%s", name);
    printf("Welcome to the Haunted House, %s!\n", name);
    printf("You find yourself in a dark and eerie hallway.\n");
    printf("There are three doors in front of you.\n");
    printf("Which one do you choose?\n");
    printf("1. Door on the left\n");
    printf("2. Door in the middle\n");
    printf("3. Door on the right\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("You open the door on the left and step inside.\n");
            printf("The room is filled with cobwebs and dust.\n");
            printf("Suddenly, a ghostly figure appears before you!\n");
            printf("Do you:\n");
            printf("1. Run away\n");
            printf("2. Stay and fight\n");
            scanf("%d", &choice);
            if(choice == 1) {
                printf("You run away as fast as you can.\n");
            } else {
                printf("You bravely fight the ghost.\n");
            }
            break;
        case 2:
            printf("You open the door in the middle and step inside.\n");
            printf("The room is filled with strange artifacts and potions.\n");
            printf("Suddenly, a witch appears before you!\n");
            printf("Do you:\n");
            printf("1. Try to reason with her\n");
            printf("2. Attack her with a potion\n");
            scanf("%d", &choice);
            if(choice == 1) {
                printf("You try to reason with the witch, but she curses you and turns you into a frog.\n");
            } else {
                printf("You grab a potion and throw it at the witch, defeating her.\n");
            }
            break;
        case 3:
            printf("You open the door on the right and step inside.\n");
            printf("The room is filled with creepy dolls and toys.\n");
            printf("Suddenly, a possessed doll comes to life and attacks you!\n");
            printf("Do you:\n");
            printf("1. Fight back with a toy sword\n");
            printf("2. Try to reason with the doll\n");
            scanf("%d", &choice);
            if(choice == 1) {
                printf("You grab a toy sword and fight back against the possessed doll.\n");
            } else {
                printf("You try to reason with the doll, but it doesn't listen and continues to attack you.\n");
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
    return 0;
}