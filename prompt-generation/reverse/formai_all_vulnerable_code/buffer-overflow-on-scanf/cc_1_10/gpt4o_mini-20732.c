//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: shape shifting
#include <stdio.h>     // Standard I/O for printing and reading input
#include <stdlib.h>    // For rand() and srand()
#include <time.h>      // For random seed initialization
#include <string.h>    // For string manipulations

// Function prototypes
int rollDice(int sides);
void displayShape(int sides, int result);
void clearBuffer();
void introduction();

int main() {
    srand(time(NULL)); // Seed the random number generator
    int choice;
    
    introduction();
    
    do {
        printf("\nChoose the type of dice you want to roll:\n");
        printf("1. 4-sided\n");
        printf("2. 6-sided\n");
        printf("3. 8-sided\n");
        printf("4. 10-sided\n");
        printf("5. 12-sided\n");
        printf("6. 20-sided\n");
        printf("7. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        
        int sides = 0;
        
        switch(choice) {
            case 1: sides = 4; break;
            case 2: sides = 6; break;
            case 3: sides = 8; break;
            case 4: sides = 10; break;
            case 5: sides = 12; break;
            case 6: sides = 20; break;
            case 7: printf("Exiting the program. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n"); continue;
        }
        
        if (sides > 0) {
            int result = rollDice(sides);
            printf("You rolled a %d on a %d-sided die!\n", result, sides);
            displayShape(sides, result);
        }
        
    } while (choice != 7);
    
    return 0;
}

// Function to roll the dice
int rollDice(int sides) {
    return rand() % sides + 1; // Generate random number between 1 and sides
}

// Function to display a shape based on the rolled dice result
void displayShape(int sides, int result) {
    printf("Here's a shape representation of your roll:\n");
    
    if (sides == 4) {
        printf("  *  \n");
        if (result == 1) { 
            printf(" * * \n");
            printf(" *   \n");
        } else if (result == 2) { 
            printf(" * * \n");
            printf("     \n");
        } else if (result == 3) { 
            printf(" *   \n");
            printf(" * * \n");
        } else { // result == 4
            printf(" * * \n");
            printf(" * * \n");
        }
        printf("  *  \n");
    }
    
    else if (sides == 6) {
        printf(" _______ \n");
        printf("|       |\n");
        for (int i = 0; i < 3; i++) {
            if (result > 3 && i == 2) printf("|   *   |\n");
            else printf("|       |\n");
        }
        printf("|_______|\n");
    }
    
    else if (sides == 8) {
        for (int i = 0; i < result; i++) {
            printf("* ");
        }
        printf("\n");
    }
    
    else if (sides == 10) {
        printf("Result: %d (Triangle)\n", result);
        for (int i = 1; i <= result; i++) {
            for (int j = 0; j < i; j++) {
                printf("* ");
            }
            printf("\n");
        }
    }
    
    else if (sides == 12) {
        printf("Rolling a D12... Result: \n");
        for (int i = 0; i < result; i++) {
            printf("~ ");
        }
        printf("\n");
    }
    
    else if (sides == 20) {
        printf("Rolling a D20...\n");
        printf("Result: %d\n", result);
        for (int i = 1; i <= result; i++) {
            printf("# ");
        }
        printf("\n");
    }
}

// Function to clear input buffer
void clearBuffer() {
    while (getchar() != '\n'); // Clears the input buffer
}

// Friendly introduction to the program
void introduction() {
    printf("Welcome to the Shape-Shifting Dice Roller!\n");
    printf("Roll different types of dice and see their unique shapes!\n");
    printf("Let's have some fun with numbers!\n");
}