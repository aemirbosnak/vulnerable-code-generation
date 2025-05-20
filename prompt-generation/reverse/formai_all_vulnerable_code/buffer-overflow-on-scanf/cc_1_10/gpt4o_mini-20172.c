//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcomeMessage();
void simulateDiceRoll(int rolls);
void displayDice(int die1, int die2);
void playAgain();

int main() {
    welcomeMessage();
    
    // To ensure different random results every time
    srand(time(NULL));
    
    int rolls;
    do {
        printf("\nHow many times would you like to roll the dice? ");
        scanf("%d", &rolls);
        
        if (rolls < 1) {
            printf("You need to roll at least once! Let's try again.\n");
            continue; // Restart the loop to ask for input again
        }

        simulateDiceRoll(rolls);
        playAgain();
        
    } while (1); // Infinite loop to allow repeated gameplay
    return 0;
}

void welcomeMessage() {
    printf("====================================\n");
    printf("          Welcome to the Dice       \n");
    printf("             Roller Game!           \n");
    printf("====================================\n");
    printf("In this game, you can roll the dice as many times as you wish!\n\n");
}

void simulateDiceRoll(int rolls) {
    printf("\nRolling the dice %d time(s)...\n", rolls);
    for (int i = 0; i < rolls; i++) {
        int die1 = (rand() % 6) + 1; // Random number between 1 and 6
        int die2 = (rand() % 6) + 1; // Another random number between 1 and 6

        displayDice(die1, die2); // Show the rolled values
    }
}

void displayDice(int die1, int die2) {
    printf("You rolled: [%d] and [%d]\n", die1, die2);
    printf("  _______   _______\n");
    printf(" /       \\ /       \\\n");
    
    // First die
    switch (die1) {
        case 1: printf("|    *    |"); break;
        case 2: printf("| *     * |"); break;
        case 3: printf("| *   *   |"); break;
        case 4: printf("| * * * * |"); break;
        case 5: printf("| * * *   |"); break;
        case 6: printf("| * * * * |"); break;
    }
    
    printf("   ");
    
    // Second die
    switch (die2) {
        case 1: printf("|    *    |"); break;
        case 2: printf("| *     * |"); break;
        case 3: printf("| *   *   |"); break;
        case 4: printf("| * * * * |"); break;
        case 5: printf("| * * *   |"); break;
        case 6: printf("| * * * * |"); break;
    }
    
    printf("\n \\_______/ \\_______/\n\n");
}

void playAgain() {
    char choice;
    printf("Would you like to roll again? (y/n): ");
    scanf(" %c", &choice);
    
    if (choice == 'n' || choice == 'N') {
        printf("Thanks for playing! Goodbye!\n");
        exit(0);
    } else if (choice != 'y' && choice != 'Y') {
        printf("Invalid choice, please choose 'y' or 'n'. Let's continue!\n");
    }
}