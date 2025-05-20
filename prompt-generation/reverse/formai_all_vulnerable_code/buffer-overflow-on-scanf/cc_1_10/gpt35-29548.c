//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clearInputBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void printLine(char c, int times) {
    for (int i = 0; i < times; i++) {
        printf("%c", c);
    }
    printf("\n");
}

void printTitle() {
    printLine('=', 60);
    printf("                    Welcome to the Haunted Mansion!              \n");
    printLine('=', 60);
}

void printOptions() {
    printf("\nPlease select your option:\n");
    printf("1. Enter the mansion\n");
    printf("2. Run away\n");
}

void enterMansion() {
    int doorChoice;
    printLine('-', 60);
    printf("You have entered the mansion. You see two doors in front of you.\n");
    printf("1. Enter the left door\n");
    printf("2. Enter the right door\n");
    scanf("%d", &doorChoice);
    clearInputBuffer();
    switch(doorChoice) {
        case 1:
            printf("You have entered the left door. You see a ghostly figure.\n");
            printf("1. Talk to the ghostly figure\n");
            printf("2. Ignore the ghostly figure and move on.\n");
            scanf("%d", &doorChoice);
            clearInputBuffer();
            if (doorChoice == 1) {
                printf("The ghostly figure tells you the story of this mansion. It used to be owned by a wealthy family, but they were all murdered by an unknown entity.\n");
                printf("The ghostly figure vanishes into thin air.\n");
            }
            else {
                printf("You move on, but you hear whispers and footsteps behind you.\n");
            }
            break;
        case 2:
            printf("You have entered the right door. You see a room full of antique furniture.\n");
            printf("1. Explore the room\n");
            printf("2. Leave the room\n");
            scanf("%d", &doorChoice);
            clearInputBuffer();
            if (doorChoice == 1) {
                printf("You find a diary hidden in one of the drawers. The diary belongs to the last surviving member of the family. It details their struggles with the unknown entity.\n");
            }
            else {
                printf("You leave the room, but you have a feeling that something is watching you.\n");
            }
            break;
        default:
            printf("Invalid choice. You are stuck in the room.\n");
            break;
    }
}

void runAway() {
    printf("You run as fast as you can the opposite direction and never look back.\n");
    printf("You have successfully escaped the haunted mansion.\n");
}

int main() {
    srand(time(NULL));
    printTitle();
    printOptions();
    int choice;
    scanf("%d", &choice);
    clearInputBuffer();
    switch(choice) {
        case 1:
            enterMansion();
            break;
        case 2:
            runAway();
            break;
        default:
            printf("Invalid choice. The game ends.\n");
            break;
    }
    return 0;
}