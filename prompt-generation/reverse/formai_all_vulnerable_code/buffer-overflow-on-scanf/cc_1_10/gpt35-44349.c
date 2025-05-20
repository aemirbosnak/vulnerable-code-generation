//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// function to clear the screen
void clearScreen() {
    system("clear");
}

// function to generate random number within a range
int randomNumber(int min, int max) {
    int num = (rand() % (max - min)) + min;
    return num;
}

// function to display the haunted house
void displayHouse(bool hasGhost) {
    clearScreen();
    printf("\n");
    printf("   _____\n");
    printf("  /     \\\n");
    printf(" | () () |\n");
    printf("  \\  ^  /\n");
    printf("   ||||| \n");

    if (hasGhost) {
        printf("   ##### \n");
        printf("   #   # \n");
        printf("   # o # \n");
        printf("   #   # \n");
        printf("  ### ###\n");
    }

    printf("\n");
}

// function to simulate the haunted house
void simulateHouse(int numSteps) {
    srand(time(NULL));
    bool hasGhost = false;
    int i;

    for (i = 0; i < numSteps; i++) {
        int randNum = randomNumber(1, 10);

        if (randNum == 1 && !hasGhost) {
            hasGhost = true;
            printf("You have stirred up something...\n");
        } else if (randNum == 10 && hasGhost) {
            hasGhost = false;
            printf("The ghost has left the building...\n");
        }

        displayHouse(hasGhost);
        printf("Step %d of %d\n", i+1, numSteps);
        printf("Press Enter to continue...\n");
        getchar();
    }

    printf("Simulation complete.\n");
}

int main() {
    int numSteps;

    printf("Welcome to the Haunted House Simulator\n");
    printf("Enter the number of steps you want to take through the house: ");
    scanf("%d", &numSteps);

    simulateHouse(numSteps);

    return 0;
}