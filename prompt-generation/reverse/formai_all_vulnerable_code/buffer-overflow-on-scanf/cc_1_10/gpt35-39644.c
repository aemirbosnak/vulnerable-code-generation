//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>

void clearScreen() {
    system("clear||cls");
}

// function to wait for user input
void waitForInput() {
    printf("\n\nPress Enter to continue...");
    getchar();
    clearScreen();
}

// function to show intro
void showIntro() {
    printf("Welcome to the Adventure Game\n\n");
    printf("You wake up in a mysterious forest, surrounded by tall trees and strange creatures.\n");
    printf("You must find a way out of the forest before it's too late.\n\n");
    waitForInput();
}

// function to show menu
void showMenu() {
    printf("What would you like to do?\n\n");
    printf("1. Go North\n");
    printf("2. Go East\n");
    printf("3. Go South\n");
    printf("4. Go West\n");
    printf("5. Quit Game\n\n");
}

// function to get user's choice
int getUserChoice() {
    int choice;
    printf("> ");
    scanf("%d", &choice);
    return choice;
}

// function to handle user's choice
void handleUserChoice(int choice, int *x, int *y) {
    switch(choice) {
        case 1:
            *y += 1;
            printf("You went North.\n");
            break;
        case 2:
            *x += 1;
            printf("You went East.\n");
            break;
        case 3:
            *y -= 1;
            printf("You went South.\n");
            break;
        case 4:
            *x -= 1;
            printf("You went West.\n");
            break;
        case 5:
            printf("Quitting game...\n");
            exit(0);
            break;
        default:
            printf("Invalid input. Please try again.\n");
            break;
    }
}

int main() {
    int x = 0, y = 0;
    
    clearScreen();
    showIntro();
    
    while (1) {
        printf("Your current location: (%d, %d)\n", x, y);
        showMenu();
        int choice = getUserChoice();
        handleUserChoice(choice, &x, &y);
        waitForInput();
    }
    
    return 0;
}