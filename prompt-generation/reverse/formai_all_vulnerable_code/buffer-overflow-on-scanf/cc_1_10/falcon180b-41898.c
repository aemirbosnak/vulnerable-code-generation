//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    printf("Welcome to the Text-Based Adventure Game!\n\n");
    printf("You find yourself in a dark forest. There are three paths in front of you.\n");
    printf("Which path do you choose?\n1. Left\n2. Middle\n3. Right\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You walk down the left path and come across a river.\n");
            printf("Do you want to cross the river?\n1. Yes\n2. No\n");
            scanf("%d", &choice);

            if(choice == 1) {
                printf("You successfully cross the river and find a treasure chest!\n");
            } else {
                printf("You turn back and take the middle path.\n");
            }
            break;

        case 2:
            printf("You walk down the middle path and find a cave.\n");
            printf("Do you want to enter the cave?\n1. Yes\n2. No\n");
            scanf("%d", &choice);

            if(choice == 1) {
                printf("You enter the cave and find a magical sword!\n");
            } else {
                printf("You turn back and take the right path.\n");
            }
            break;

        case 3:
            printf("You walk down the right path and come across a castle.\n");
            printf("Do you want to enter the castle?\n1. Yes\n2. No\n");
            scanf("%d", &choice);

            if(choice == 1) {
                printf("You enter the castle and find the princess!\n");
            } else {
                printf("You turn back and take the middle path.\n");
            }
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}