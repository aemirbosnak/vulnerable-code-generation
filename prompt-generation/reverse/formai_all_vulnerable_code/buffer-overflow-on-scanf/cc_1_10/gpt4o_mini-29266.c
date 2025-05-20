//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intro();
void forest();
void cave();
void conclusion(int);
int getPlayerChoice(int numChoices);

int main() {
    intro();
    forest();
    return 0;
}

void intro() {
    printf("Welcome to the Mystical Forest Adventure!\n");
    printf("In this game, you will make choices that will lead you to different adventures.\n");
    printf("Be brave and choose wisely!\n");
    printf("Press Enter to start your journey...");
    getchar();
}

void forest() {
    int choice;
    printf("\nYou find yourself at the edge of a vast forest. You can either:\n");
    printf("1. Enter the forest.\n");
    printf("2. Walk around the forest.\n");
    printf("3. Sit and rest at the edge of the forest.\n");
    choice = getPlayerChoice(3);
    
    switch(choice) {
        case 1:
            printf("\nYou bravely step into the forest...\n");
            cave();
            break;
        case 2:
            printf("\nYou walk around the forest and discover a hidden path...\n");
            printf("You encounter a wise old owl who offers you a riddle.\n");
            printf("If you solve it, you may receive a magical token!\n");
            // Riddle or logic can be added here
            conclusion(0);
            break;
        case 3:
            printf("\nYou sit at the edge of the forest and admire the scenery.\n");
            printf("However, you feel time slipping away...\n");
            conclusion(0);
            break;
        default:
            printf("Invalid choice! You wander aimlessly until night falls.\n");
            conclusion(0);
            break;
    }
}

void cave() {
    int choice;
    printf("\nAs you walk deeper into the forest, you see a cave ahead. You can:\n");
    printf("1. Enter the cave.\n");
    printf("2. Continue exploring the forest.\n");
    printf("3. Return back to the edge.\n");
    choice = getPlayerChoice(3);
    
    switch(choice) {
        case 1:
            printf("\nYou enter the cave. It's dark and eerie...\n");
            printf("You suddenly hear a growl! It's a bear!\n");
            printf("Do you:\n");
            printf("1. Try to fight the bear.\n");
            printf("2. Run away.\n");
            choice = getPlayerChoice(2);
            if (choice == 1) {
                printf("\nYou bravely confront the bear but it overpowers you...\n");
                conclusion(1);
            } else {
                printf("\nYou escape successfully, your heart racing!\n");
                conclusion(0);
            }
            break;
        case 2:
            printf("\nYou decide to continue exploring the forest...\n");
            printf("You find a magical stream that grants you eternal wisdom.\n");
            conclusion(0);
            break;
        case 3:
            printf("\nYou return to the edge of the forest, safe but unsatisfied.\n");
            conclusion(0);
            break;
        default:
            printf("Invalid choice! You get lost in the darkness of the cave.\n");
            conclusion(1);
            break;
    }
}

void conclusion(int outcome) {
    if (outcome == 0) {
        printf("\nYou have survived your adventure! Thank you for playing.\n");
    } else {
        printf("\nUnfortunately, your adventure has come to an end. Better luck next time!\n");
    }
    printf("\nPress Enter to exit...");
    getchar();
    exit(0);
}

int getPlayerChoice(int numChoices) {
    int choice;
    printf("Enter your choice (1-%d): ", numChoices);
    scanf("%d", &choice);
    while(choice < 1 || choice > numChoices) {
        printf("Invalid choice! Please choose again (1-%d): ", numChoices);
        scanf("%d", &choice);
    }
    return choice;
}