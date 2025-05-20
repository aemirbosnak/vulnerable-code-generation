//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro();
void game();
void story();
void options();
void combat();

int main() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    intro();
    game();
    return 0;
}

void intro() {
    printf("In this game, you are a brave adventurer on a quest to find the legendary treasure of the lost city.\n");
    printf("You will encounter many challenges along the way, including dangerous creatures, treacherous terrain, and puzzling riddles.\n");
    printf("Use your wits and your courage to overcome these obstacles and claim the treasure as your own!\n");
}

void game() {
    int choice;
    printf("What would you like to do?\n");
    printf("1. Start the adventure\n");
    printf("2. Quit\n");
    scanf("%d", &choice);

    if (choice == 1) {
        story();
        options();
        combat();
    } else if (choice == 2) {
        printf("Thanks for playing!\n");
        exit(0);
    } else {
        printf("Invalid choice.\n");
        game();
    }
}

void story() {
    printf("You begin your journey in a small village at the edge of the forest.\n");
    printf("The villagers tell you of the lost city and its treasure, but warn you of the dangers that lie ahead.\n");
    printf("Undeterred, you set out into the forest, determined to claim the treasure for yourself.\n");
}

void options() {
    int choice;
    printf("What would you like to do?\n");
    printf("1. Continue the adventure\n");
    printf("2. Save game\n");
    printf("3. Load game\n");
    scanf("%d", &choice);

    if (choice == 1) {
        game();
    } else if (choice == 2) {
        printf("Game saved.\n");
    } else if (choice == 3) {
        printf("Game loaded.\n");
    } else {
        printf("Invalid choice.\n");
        options();
    }
}

void combat() {
    int enemy;
    int player;
    int result;

    printf("You encounter a fierce monster!\n");
    printf("What would you like to do?\n");
    printf("1. Attack\n");
    printf("2. Defend\n");
    scanf("%d", &player);

    enemy = rand() % 10 + 1;
    result = player - enemy;

    if (result > 0) {
        printf("You defeat the monster!\n");
    } else if (result < 0) {
        printf("The monster defeats you.\n");
        exit(0);
    } else {
        printf("It's a draw.\n");
    }
}