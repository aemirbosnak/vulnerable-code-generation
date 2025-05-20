//GPT-4o-mini DATASET v1.0 Category: Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcomeMessage() {
    printf("************************************************\n");
    printf("*        Welcome to the Magical Forest!       *\n");
    printf("*   Your adventure awaits. Can you find the    *\n");
    printf("*         hidden treasure? Let’s begin!        *\n");
    printf("************************************************\n");
}

void choosePath() {
    printf("\nYou are standing at a fork in the path.\n");
    printf("Do you want to go left or right? (l/r): ");
}

void leftPath() {
    printf("\nYou have chosen the left path...\n");
    printf("The path is bright and filled with singing birds!\n");

    printf("Suddenly, you encounter a friendly fox!\n");
    printf("The fox offers to share a secret about the treasure with you.\n");
    printf("Do you want to listen to the fox? (y/n): ");
}

void rightPath() {
    printf("\nYou have chosen the right path...\n");
    printf("It is dark and filled with giant mushrooms!\n");

    printf("You stumble upon a wise old owl perched on a tree.\n");
    printf("The owl has a riddle for you. Do you want to hear it? (y/n): ");
}

void encounterFox() {
    char choice;
    printf("\nYou chose to listen to the fox! [y/n]: ");
    scanf(" %c", &choice);
    if (choice == 'y') {
        printf("\nThe fox whispers: 'The treasure lies where the sun meets the river.’\n");
    } else {
        printf("\nThe fox waves goodbye and you continue your journey!\n");
    }
}

void solveRiddle() {
    char answer[20];
    printf("\nThe owl says: 'I have keys but open no locks. I have space but no room. I have a face but no eyes. What am I?' ");
    printf("\nYour answer: ");
    scanf("%s", answer);
    if (strcmp(answer, "clock") == 0) {
        printf("\nCorrect! The wise owl says: 'You are clever. The treasure awaits!'\n");
    } else {
        printf("\nWrong! The owl hoots and tells you to keep searching.\n");
    }
}

int main() {
    welcomeMessage();
    char pathChoice;

    while (1) {
        choosePath();
        scanf(" %c", &pathChoice);
        
        if (pathChoice == 'l') {
            leftPath();
            char listenChoice;
            scanf(" %c", &listenChoice);
            if (listenChoice == 'y') {
                encounterFox();
            }
            break;
        } else if (pathChoice == 'r') {
            rightPath();
            char riddleChoice;
            scanf(" %c", &riddleChoice);
            if (riddleChoice == 'y') {
                solveRiddle();
            }
            break;
        } else {
            printf("\nThat's not a valid choice! Please choose 'l' or 'r'.\n");
        }
    }

    printf("\nThank you for playing! Whatever path you took, adventure awaits!\n");
    printf("May your journey be filled with joy and laughter!\n");
    printf("************************************************\n");

    return 0;
}