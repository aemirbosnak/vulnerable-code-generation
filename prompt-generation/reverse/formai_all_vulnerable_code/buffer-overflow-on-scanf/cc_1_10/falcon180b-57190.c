//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void hauntedHouse();

int main() {
    srand(time(0));
    int choice;

    do {
        system("clear");
        printf("Welcome to the Haunted House!\n");
        printf("Press enter to begin...\n");
        fflush(stdin);
        getchar();

        hauntedHouse();

        printf("\nDo you want to try again? (y/n): ");
        scanf("%s", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void hauntedHouse() {
    int door1, door2, door3, choice;

    printf("\nYou are standing in front of three doors.\n");
    printf("Which door do you choose?\n");
    printf("1. Door 1\n2. Door 2\n3. Door 3\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nYou open Door 1 and find...\n");
            printf("A ghost! It scares you back to the entrance.\n");
            break;
        case 2:
            printf("\nYou open Door 2 and find...\n");
            printf("A room full of candy! You eat some and feel happy.\n");
            break;
        case 3:
            printf("\nYou open Door 3 and find...\n");
            printf("A secret passage! It leads you to the end of the haunted house.\n");
            break;
        default:
            printf("\nInvalid choice. Try again.\n");
    }
}