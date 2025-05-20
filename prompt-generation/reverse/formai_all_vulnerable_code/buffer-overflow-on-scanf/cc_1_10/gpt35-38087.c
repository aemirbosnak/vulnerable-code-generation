//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to clear console screen */
void clearScreen() {
    system("clear||cls");
}

/* Function to generate random numbers in range */
int randomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/* Function to wait for user input */
void waitForInput() {
    char input[10];
    printf("Press enter to continue...");
    fgets(input, 10, stdin);
}

/* Function to print a spooky message */
void printSpookyMessage() {
    printf("You feel a chill run down your spine...\n");
    waitForInput();
    clearScreen();
}

/* Main function of the program */
int main() {
    srand(time(NULL)); // Seed random number generator
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You approach a creepy old mansion in the woods...\n");
    waitForInput();
    clearScreen();
    
    printf("You push open the creaky old doors and step inside...\n");
    printSpookyMessage();
    
    printf("You hear a faint whispering coming from upstairs...\n");
    printf("Do you investigate? (1. Yes, 2. No)\n");
    int choice;
    scanf("%d", &choice);
    clearScreen();
    
    if (choice == 1) {
        printf("You slowly climb the stairs, heart racing...\n");
        printSpookyMessage();
        
        printf("You reach the top of the stairs and see a shadowy figure...\n");
        printf("Do you approach? (1. Yes, 2. No)\n");
        scanf("%d", &choice);
        clearScreen();
        
        if (choice == 1) {
            printf("As you get closer, the figure disappears...\n");
            printSpookyMessage();
        } else {
            printf("You turn and run back down the stairs...\n");
            printSpookyMessage();
        }
    } else {
        printf("You decide it's best to leave the whispering alone...\n");
        printSpookyMessage();
    }
    
    printf("You continue through the dark mansion...\n");
    
    /* Generate random spooky events */
    int eventCount = 3;
    for (int i = 0; i < eventCount; i++) {
        int event = randomNumber(1, 3);
        switch (event) {
            case 1: // A door slams shut behind you
                printf("A door slams shut behind you...\n");
                break;
            case 2: // A cold breeze makes your hair stand on end
                printf("A cold breeze makes your hair stand on end...\n");
                break;
            case 3: // A ghostly howl echoes through the mansion
                printf("A ghostly howl echoes through the mansion...\n");
                break;
        }
        waitForInput();
        clearScreen();
    }
    
    printf("You finally reach the exit and step outside...\n");
    printf("You look back at the mansion and shudder...\n");
    printf("Thanks for playing the Haunted House Simulator!\n");
    
    return 0;
}