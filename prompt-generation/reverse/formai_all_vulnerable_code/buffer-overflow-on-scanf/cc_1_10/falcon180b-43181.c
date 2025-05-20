//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void start();
void intro();
void forest();
void cave();
void end();

int main() {
    int choice;
    start:
    system("clear");
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Press 1 to start the game.\n");
    scanf("%d", &choice);
    if (choice == 1) {
        intro();
    } else {
        printf("Invalid choice. Please try again.\n");
        goto start;
    }
    return 0;
}

void intro() {
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("\nWelcome, %s! You find yourself in a forest.\n", name);
    forest();
}

void forest() {
    char choice;
    system("clear");
    printf("\nYou are in a dense forest. You can see a path leading north and a river flowing east.\n");
    printf("What do you want to do?\n");
    printf("1. Go north.\n");
    printf("2. Follow the river.\n");
    scanf("%c", &choice);
    switch (choice) {
        case '1':
            cave();
            break;
        case '2':
            printf("\nYou follow the river and eventually come across a small village.\n");
            printf("The villagers welcome you and offer you food and shelter.\n");
            printf("You decide to stay for a while and learn about their culture.\n");
            system("pause");
            main();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            forest();
            break;
    }
}

void cave() {
    char choice;
    system("clear");
    printf("\nYou enter a dark cave. You can hear the sound of dripping water and see a faint light in the distance.\n");
    printf("What do you want to do?\n");
    printf("1. Go towards the light.\n");
    printf("2. Explore the cave.\n");
    scanf("%c", &choice);
    switch (choice) {
        case '1':
            end();
            break;
        case '2':
            printf("\nAs you explore the cave, you come across a hidden treasure.\n");
            printf("You take the treasure and continue your journey.\n");
            system("pause");
            main();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            cave();
            break;
    }
}

void end() {
    system("clear");
    printf("\nCongratulations! You have completed the game.\n");
    system("pause");
    exit(0);
}