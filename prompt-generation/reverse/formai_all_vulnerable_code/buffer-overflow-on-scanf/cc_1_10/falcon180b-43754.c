//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer on a quest to find the\n");
    printf("legendary treasure hidden deep within a mysterious cave.\n");
    printf("Are you ready to begin your journey? (y/n)\n");
}

void cave() {
    int choice;
    printf("You find yourself standing at the entrance of a dark cave.\n");
    printf("The air is chilly and damp, and the only light comes from\n");
    printf("the flickering torch you hold in your hand.\n");
    printf("There are two paths leading deeper into the cave:\n");
    printf("one to the left and one to the right.\n");
    printf("Which path do you choose? (l/r)\n");
    scanf("%c", &choice);

    switch (choice) {
        case 'l':
            printf("You take the path to the left and continue deeper into the cave.\n");
            break;
        case 'r':
            printf("You take the path to the right and continue deeper into the cave.\n");
            break;
        default:
            printf("Invalid choice. Game over.\n");
            exit(0);
    }
}

void treasure() {
    printf("Congratulations! You have found the legendary treasure!\n");
    printf("It is a chest filled with gold, jewels, and other precious items.\n");
    printf("You feel a sense of accomplishment and satisfaction as you\n");
    printf("gaze upon your hard-earned reward.\n");
    printf("Thank you for playing the Text-Based Adventure Game.\n");
}

int main() {
    srand(time(NULL));
    int choice;

    intro();
    scanf("%c", &choice);

    if (choice == 'y') {
        cave();
    } else {
        printf("Thank you for playing the Text-Based Adventure Game.\n");
        return 0;
    }

    return 0;
}