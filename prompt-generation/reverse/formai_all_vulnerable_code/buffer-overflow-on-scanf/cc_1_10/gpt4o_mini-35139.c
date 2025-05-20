//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void startGame();
void displayInstructions();
void firstRoom();
void secondRoom();
void secretTreasure();
void makeChoice(const char *option1, const char *option2, void (*fn1)(), void (*fn2)());

int main() {
    startGame();
    return 0;
}

void startGame() {
    printf("Welcome to the Invasive Adventure!\n");
    printf("You find yourself in a mysterious dungeon. Your goal is to discover the hidden treasure!\n");
    displayInstructions();
    firstRoom();
}

void displayInstructions() {
    printf("\nInstructions:\n");
    printf("1. Navigate through rooms.\n");
    printf("2. Make choices that will lead you closer to the treasure or to your doom!\n");
    printf("3. Type 'quit' to exit the game at any time.\n\n");
}

void firstRoom() {
    char choice[50];
    printf("You're in the first room. There is a door to the left and another door to the right.\n");
    printf("Choose your direction (left/right): ");
    scanf("%s", choice);
    
    if (strcmp(choice, "left") == 0) {
        secondRoom();
    } else if (strcmp(choice, "right") == 0) {
        printf("You have stumbled into a pit of snakes! Game Over.\n");
        exit(0);
    } else if (strcmp(choice, "quit") == 0) {
        exit(0);
    } else {
        printf("Invalid choice! Try again.\n");
        firstRoom();
    }
}

void secondRoom() {
    char choice[50];
    printf("You've entered the second room. There is a chest here.\n");
    printf("Do you want to open the chest or leave the room? (open/leave): ");
    scanf("%s", choice);
    
    if (strcmp(choice, "open") == 0) {
        secretTreasure();
    } else if (strcmp(choice, "leave") == 0) {
        printf("You decided to leave the room. You find a safe path back to the beginning.\n");
        firstRoom();
    } else if (strcmp(choice, "quit") == 0) {
        exit(0);
    } else {
        printf("Invalid choice! Try again.\n");
        secondRoom();
    }
}

void secretTreasure() {
    char choice[50];
    printf("Congratulations! You've opened the chest and found a map.\n");
    printf("You can either follow the map to the hidden treasure or ignore it. (follow/ignore): ");
    scanf("%s", choice);
    
    if (strcmp(choice, "follow") == 0) {
        printf("You followed the map and found the hidden treasure! You've won the game!\n");
        exit(0);
    } else if (strcmp(choice, "ignore") == 0) {
        printf("Ignoring the map was a grave mistake! You exit the room and wander aimlessly.\n");
        firstRoom();
    } else if (strcmp(choice, "quit") == 0) {
        exit(0);
    } else {
        printf("Invalid choice! Try again.\n");
        secretTreasure();
    }
}