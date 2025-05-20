//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearScreen() {
    system("cls||clear");
}

void showIntro() {
    printf("Welcome to the Interoperable Adventure Game!\n");
    printf("In this game you will explore a fantasy world and complete quests.\n");
    printf("Are you ready to start your adventure? Press any key to continue.\n");
    
    getchar();
    clearScreen();
}

void showMenu() {
    printf("What do you want to do?\n");
    printf("1. Explore the world\n");
    printf("2. Check your inventory\n");
    printf("3. Quit\n");
}

void exploreWorld() {
    printf("You are exploring the world...\n");
    printf("You come across a monster!\n");
    printf("What do you want to do?\n");
    printf("1. Fight\n");
    printf("2. Flee\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You fought bravely and defeated the monster!\n");
    } else if (choice == 2) {
        printf("You run away from the monster.\n");
    } else {
        printf("Invalid choice.\n");
    }
}

void checkInventory() {
    printf("You check your inventory...\n");
    printf("You have 10 gold coins and a sword.\n");
}

int main() {
    srand(time(NULL));
    
    showIntro();
    
    while (1) {
        showMenu();
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                exploreWorld();
                break;
            case 2:
                checkInventory();
                break;
            case 3:
                printf("Thank you for playing!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
        
        printf("Press any key to continue.\n");
        getchar();
        getchar();
        clearScreen();
    }
}