//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

void adventure(int choice);

void introduction() {
    printf("Welcome to the Adventure Game!\n");
    printf("You find yourself lost in a dark forest.\n");
    printf("What would you like to do?\n");
    printf("1. Explore the forest\n");
    printf("2. Build a fire\n");
    printf("3. Climb a tree\n");
    printf("4. Exit Game\n");
}

void explore() {
    printf("You wander deeper into the forest...\n");
    printf("1. Encounter a wild animal\n");
    printf("2. Find a treasure\n");
    printf("3. Get lost\n");
    printf("4. Go back\n");
}

void buildFire() {
    printf("You built a cozy fire!\n");
    printf("1. Gather food\n");
    printf("2. Sing a song\n");
    printf("3. Sleep by the fire\n");
    printf("4. Go back\n");
}

void climbTree() {
    printf("You climbed a tall tree and have a great view!\n");
    printf("1. Signal for help\n");
    printf("2. Jump down safely\n");
    printf("3. Get stuck!\n");
    printf("4. Go back\n");
}

void adventure(int choice) {
    switch (choice) {
        case 1:
            explore();
            break;
        case 2:
            buildFire();
            break;
        case 3:
            climbTree();
            break;
        case 4:
            printf("Thank you for playing! Goodbye!\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            introduction();
            return;
    }

    int new_choice;
    printf("Make your choice: ");
    scanf("%d", &new_choice);
    adventure(new_choice);
}

int main() {
    introduction();
    int choice;
    printf("Make your choice: ");
    scanf("%d", &choice);
    adventure(choice);
    return 0;
}