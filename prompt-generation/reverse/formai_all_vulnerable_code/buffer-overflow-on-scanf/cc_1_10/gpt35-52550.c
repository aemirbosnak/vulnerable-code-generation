//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intro();
void forest();
void dungeon();
void ending();

int main() {
    intro();
    return 0;
}

void intro() {
    printf("Welcome to the Adventure Game!\n");
    printf("You find yourself in a dark forest, and you can't remember how you got here.\n");
    printf("You see a path to your left and a path to your right.\n");
    printf("Which path do you take? (left or right)\n");
    char choice[10];
    scanf("%s", choice);
    if (strcmp(choice, "left") == 0) {
        forest();
    } else if (strcmp(choice, "right") == 0) {
        dungeon();
    } else {
        printf("Invalid choice. Please try again.\n");
        intro();
    }
}

void forest() {
    printf("You chose the left path and entered the forest.\n");
    printf("As you walk deeper into the forest, you hear strange noises.\n");
    printf("You come across a clearing, where you see a powerful wizard.\n");
    printf("The wizard offers to help you find your way home.\n");
    printf("Do you trust him? (yes or no)\n");
    char choice[10];
    scanf("%s", choice);
    if (strcmp(choice, "yes") == 0) {
        ending();
    } else if (strcmp(choice, "no") == 0) {
        printf("The wizard becomes angry and casts a spell on you.\n");
        printf("You wake up in a dungeon.\n");
        dungeon();
    } else {
        printf("Invalid choice. Please try again.\n");
        forest();
    }
}

void dungeon() {
    printf("You chose the right path and entered a dungeon.\n");
    printf("You hear the sound of footsteps coming down the hallway.\n");
    printf("You hide behind a door and see a guard walking by.\n");
    printf("Do you attack the guard or try to sneak past him? (attack or sneak)\n");
    char choice[10];
    scanf("%s", choice);
    if (strcmp(choice, "attack") == 0) {
        printf("You attack the guard and take his key.\n");
        printf("You unlock the door and find yourself outside.\n");
        ending();
    } else if (strcmp(choice, "sneak") == 0) {
        printf("You successfully sneak past the guard and find a key.\n");
        printf("You unlock the door and find yourself outside.\n");
        ending();
    } else {
        printf("Invalid choice. Please try again.\n");
        dungeon();
    }
}

void ending() {
    printf("Congratulations! You have found your way home.\n");
    printf("Thanks for playing the Adventure Game!\n");
}