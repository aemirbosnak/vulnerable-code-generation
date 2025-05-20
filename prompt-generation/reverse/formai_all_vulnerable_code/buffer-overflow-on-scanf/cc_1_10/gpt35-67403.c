//FormAI DATASET v1.0 Category: Game ; Style: innovative
#include <stdio.h>

// function that prints out the name of the game
void printGameName() {
    printf("Welcome to the exciting game of Escape!\n");
}

// function that prints out the game instructions
void printGameInstructions() {
    printf("You are trapped in a room and you need to escape before time runs out!\n");
    printf("You can move around the room, search for clues and solve puzzles to find the key to escape.\n");
    printf("But be careful, the clock is ticking and you only have a limited amount of time!\n");
}

// function that simulates a clock ticking down
void countdown(int seconds) {
    for (int i = seconds; i > 0; i--) {
        printf("Time remaining: %d seconds\n", i);
    }
}

int main() {
    // print out the game name and instructions
    printGameName();
    printGameInstructions();
    
    // initialize variables
    int time = 60;
    int position = 1;
    int foundKey = 0;
    
    // start game loop
    while (time > 0 && !foundKey) {
        printf("You are in position %d\n", position);
        printf("What do you want to do?\n");
        printf("1. Move left\n");
        printf("2. Move right\n");
        printf("3. Search for clues\n");
        printf("4. Solve puzzle\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (position > 1) {
                    position--;
                }
                else {
                    printf("You cannot move left any further.\n");
                }
                break;
            case 2:
                if (position < 5) {
                    position++;
                }
                else {
                    printf("You cannot move right any further.\n");
                }
                break;
            case 3:
                printf("You search the room and find a clue...\n");
                printf("The clue says: 'The key is hidden behind the painting.'\n");
                break;
            case 4:
                printf("You solve the puzzle and find a key!\n");
                foundKey = 1;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
        time--;
    }
    
    // check if player won or lost
    if (foundKey) {
        printf("Congratulations! You have escaped!\n");
    }
    else {
        printf("Time's up! You are trapped forever...\n");
    }
    
    // simulate clock ticking down for dramatic effect
    countdown(time);
    
    return 0;
}