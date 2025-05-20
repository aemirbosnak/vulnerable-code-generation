//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro() {
    printf("Welcome to the Enchanted Forest!\n");
    printf("You wake up in a beautiful meadow, surrounded by tall trees and colorful flowers.\n");
    printf("The sun is shining brightly, and you can hear birds singing in the distance.\n");
    printf("What would you like to do?\n");
}

void meadow() {
    printf("You are standing in the middle of a vast meadow, filled with wildflowers and tall grasses.\n");
    printf("To the north, you see a dense forest, while to the south lies an open field.\n");
    printf("In the distance, you can see a sparkling river flowing through the landscape.\n");
    printf("What would you like to do?\n");
}

void forest() {
    printf("You enter the enchanted forest, where the trees are so tall they seem to touch the sky.\n");
    printf("The air is cool and refreshing, and the ground is covered in a thick layer of moss.\n");
    printf("You hear the sound of a nearby waterfall, and you can see glimpses of sunlight filtering through the leaves.\n");
    printf("What would you like to do?\n");
}

void river() {
    printf("You approach the river, which is crystal clear and teeming with fish.\n");
    printf("The water is cool and refreshing, and you can feel the smooth stones under your feet.\n");
    printf("On the other side of the river, you see a small island with a mysterious cave.\n");
    printf("What would you like to do?\n");
}

void cave() {
    printf("You enter the dark and eerie cave, where the walls are covered in glowing mushrooms.\n");
    printf("The air is damp and musty, and you can hear the sound of dripping water echoing through the chamber.\n");
    printf("In the center of the cave, you see a large chest, bound with rusty chains.\n");
    printf("What would you like to do?\n");
}

int main() {
    srand(time(0));
    int choice;

    intro();

    while (1) {
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                meadow();
                break;
            case 2:
                forest();
                break;
            case 3:
                river();
                break;
            case 4:
                cave();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}