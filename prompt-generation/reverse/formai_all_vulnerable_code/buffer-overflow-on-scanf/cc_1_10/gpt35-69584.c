//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void printIntro();
void printHelp();
void printWin();
void printLose();
int getChoice(int min, int max);

int main() {
    // Initialize game variables
    int coins = 0;
    int health = 3;
    int sword = 0;

    // Print game intro
    printIntro();

    // Main game loop
    while (health > 0 && coins < 5 && sword == 0) {
        printf("\nWhat do you want to do?\n");
        printf("1. Search for coins\n");
        printf("2. Fight monster (health: %d)\n", health);
        printf("3. Search for sword\n");
        printf("4. Help\n");
        int choice = getChoice(1, 4);

        switch (choice) {
            case 1:
                printf("\nYou found a coin!\n");
                coins++;
                break;
            case 2:
                if (sword == 1) {
                    printf("\nYou defeated the monster with your sword!\n");
                    printf("You win!\n");
                    printWin();
                    return 0;
                } else {
                    printf("\nYou need a sword to defeat the monster, search for one!\n");
                    health--;
                }
                break;
            case 3:
                printf("\nYou found a sword!\n");
                sword = 1;
                break;
            case 4:
                printHelp();
                break;
        }
    }

    // Game over
    printf("\nYou lose!\n");
    printLose();
    return 0;
}

// Function definitions
void printIntro() {
    printf("Welcome to the adventure game!\n");
    printf("Your goal is to collect 5 coins and defeat the monster.\n");
}

void printHelp() {
    printf("Help:\n");
    printf("Search for coins to collect them.\n");
    printf("Search for a sword to defeat the monster.\n");
    printf("Fight the monster once you have a sword.\n");
}

void printWin() {
    printf("     /\\_/\\  \n");
    printf("    / o o \\ \n");
    printf("   (   \"   )\n");
    printf("    \\~(*)~/ \n");
    printf("     / ^ \\  \n");
    printf("Congratulations, you won!\n");
}

void printLose() {
    printf("/\\_/\\     <<\"\" YELLOW \"\"< \n");
    printf("( o.o )    <<\"\"  BELL\"\"< \n");
    printf(" > ^ <     <<\"\"    \"\"  \n");
    printf("Better luck next time!\n");
}

int getChoice(int min, int max) {
    int choice;
    do {
        printf("Enter your choice (%d-%d): ", min, max);
        scanf("%d", &choice);
        if (choice < min || choice > max) {
            printf("Invalid choice!\n");
        }
    } while (choice < min || choice > max);
    return choice;
}