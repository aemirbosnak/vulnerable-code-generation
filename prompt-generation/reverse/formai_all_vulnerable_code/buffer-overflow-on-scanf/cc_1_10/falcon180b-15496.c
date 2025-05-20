//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;

    printf("Welcome to the Haunted House!\n");
    printf("You find yourself in a dimly lit room with three doors.\n");
    printf("Which door will you choose?\n");
    printf("1. The door on the left\n2. The door in the middle\n3. The door on the right\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You open the door on the left and step inside.\n");
            printf("The room is filled with cobwebs and dust.\n");
            printf("Suddenly, a ghost appears before you!\n");
            printf("Do you:\n");
            printf("1. Run away\n2. Stay and fight\n");
            scanf("%d", &choice);

            if(choice == 1) {
                printf("You run away as fast as you can.\n");
            } else if(choice == 2) {
                printf("You bravely fight the ghost.\n");
                printf("After a long battle, you emerge victorious!\n");
            }
            break;

        case 2:
            printf("You open the door in the middle and step inside.\n");
            printf("The room is dark and eerie.\n");
            printf("Suddenly, a vampire appears before you!\n");
            printf("Do you:\n");
            printf("1. Offer your blood\n2. Fight the vampire\n");
            scanf("%d", &choice);

            if(choice == 1) {
                printf("You offer your blood to the vampire.\n");
                printf("The vampire accepts and lets you live.\n");
            } else if(choice == 2) {
                printf("You bravely fight the vampire.\n");
                printf("After a long battle, you emerge victorious!\n");
            }
            break;

        case 3:
            printf("You open the door on the right and step inside.\n");
            printf("The room is filled with strange artifacts.\n");
            printf("Suddenly, a mummy appears before you!\n");
            printf("Do you:\n");
            printf("1. Unwrap the mummy\n2. Run away\n");
            scanf("%d", &choice);

            if(choice == 1) {
                printf("You unwrap the mummy.\n");
                printf("To your surprise, the mummy comes to life!\n");
                printf("The mummy chases you out of the room.\n");
            } else if(choice == 2) {
                printf("You run away as fast as you can.\n");
            }
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}