//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printIntro();
int choosePath();
void forestPath();
void riverPath();
void cavePath();
void badEnding();
void goodEnding();

int main() {
    srand(time(NULL)); // For random number generator
    int choice;
    printIntro();
    choice = choosePath();
    switch(choice) {
        case 1:
            forestPath();
            break;
        case 2:
            riverPath();
            break;
        case 3:
            cavePath();
            break;
        default:
            printf("\nInvalid choice. Game over!"); // If user enters invalid choice
            break;
    }

    return 0;
}

void printIntro() {
    printf("You wake up in a dark forest. You can’t remember how you got here,\nbut you know you need to get out.\n");
    printf("There are three paths in front of you. Which one do you choose?\n");
    printf("1. Forest path\n2. River path\n3. Cave path\n");
}

int choosePath() {
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void forestPath() {
    printf("\nYou choose the forest path.\n");
    printf("You walk for hours, but the path seems to never end.\n");
    printf("You get tired and hungry. Suddenly, you hear a strange sound.\n");
    int sound = rand() % 2;
    if(sound == 0) {
        printf("It’s just a bird.\n");
        goodEnding();
    } else {
        printf("You turn around and see a monster!\n");
        badEnding();
    }
}

void riverPath() {
    printf("\nYou choose the river path.\n");
    printf("You walk along the river, feeling the cool breeze.\n");
    printf("Suddenly, you slip and fall in the river.\n");
    int swim = rand() % 2;
    if(swim == 0) {
        printf("You manage to swim to shore safely.\n");
        goodEnding();
    } else {
        printf("The river is too strong and you drown.\n");
        badEnding();
    }
}

void cavePath() {
    printf("\nYou choose the cave path.\n");
    printf("You enter the cave and it’s pitch black.\n");
    printf("You need to light a torch to see.\n");
    int torch = rand() % 2;
    if(torch == 0) {
        printf("You light the torch and see a way out.\n");
        goodEnding();
    } else {
        printf("You can’t find the torch and get lost in the cave.\n");
        badEnding();
    }
}

void badEnding() {
    printf("\nGAME OVER!\n");
    printf("You died. You failed to escape the forest.\n");
}

void goodEnding() {
    printf("\nCONGRATULATIONS!\n");
    printf("You escaped from the forest!\n");
}