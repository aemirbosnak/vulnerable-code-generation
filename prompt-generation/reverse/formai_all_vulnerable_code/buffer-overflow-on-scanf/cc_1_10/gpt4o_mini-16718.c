//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_LEVEL 10
#define MAX_NUM 9

// Function prototypes
void generateSequence(int sequence[], int level);
void displaySequence(int sequence[], int level);
bool getPlayerInput(int sequence[], int level);
void clearScreen();

int main() {
    int level;
    int sequence[MAX_LEVEL];
    
    srand((unsigned int)time(NULL)); // Seed for random number generation

    printf("Welcome to the Memory Game!\n");
    printf("You need to remember and recall a sequence of numbers.\n");
    printf("Let's see how far you can go!\n");

    for (level = 1; level <= MAX_LEVEL; level++) {
        generateSequence(sequence, level);
        displaySequence(sequence, level);
        
        if (!getPlayerInput(sequence, level)) {
            printf("Incorrect! Game Over. You reached Level %d.\n", level - 1);
            break;
        }

        printf("Correct! Moving to Level %d...\n\n", level);
    }
    
    if (level > MAX_LEVEL) {
        printf("Congratulations! You've completed all levels!\n");
    }

    return 0;
}

void generateSequence(int sequence[], int level) {
    for (int i = 0; i < level; i++) {
        sequence[i] = rand() % (MAX_NUM + 1); // Generate number between 0 and MAX_NUM
    }
}

void displaySequence(int sequence[], int level) {
    clearScreen();
    printf("Level %d:\n", level);
    
    for (int i = 0; i < level; i++) {
        printf("%d ", sequence[i]);
        fflush(stdout);
        sleep(1); // Pause for 1 second to display each number
    }
    
    printf("\nNow it's your turn!\n");
    sleep(2); // Wait for 2 seconds before clearing the console
    clearScreen();
}

bool getPlayerInput(int sequence[], int level) {
    int userInput[MAX_LEVEL];
    
    printf("Please enter the sequence (separated by spaces): ");
    for (int i = 0; i < level; i++) {
        scanf("%d", &userInput[i]);
    }

    for (int i = 0; i < level; i++) {
        if (userInput[i] != sequence[i]) {
            return false; // Return false if input does not match sequence
        }
    }
    
    return true; // All inputs are correct
}

void clearScreen() {
    // Clear the console using ANSI escape code (works on Linux/Unix)
    printf("\033[H\033[J");
}