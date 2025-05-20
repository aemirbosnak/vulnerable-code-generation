//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100

void rollDice(int numDice, int sides);
void displayMenu();
int getIntInput(const char *prompt);
void saveResultsToFile(const char *filename, int results[], int count);

int main() {
    srand(time(NULL));
    int choice;
    
    while (1) {
        displayMenu();
        choice = getIntInput("Choose an option: ");
        
        if (choice == 5) {
            printf("Exiting the dice roller. Goodbye!\n");
            break;
        }

        int numDice, sides;
        int results[MAX_DICE] = {0};
        int rollCount = 0;

        switch (choice) {
            case 1:
                numDice = getIntInput("Enter the number of dice to roll (1-100): ");
                sides = getIntInput("Enter the number of sides on the dice (3-100): ");
                rollDice(numDice, sides);
                break;
            case 2:
                numDice = getIntInput("How many dice do you want to roll? ");
                sides = getIntInput("How many sides does each die have? ");
                
                for (int i = 0; i < numDice; i++) {
                    results[rollCount++] = (rand() % sides) + 1;
                }
                
                printf("You rolled: ");
                for (int i = 0; i < rollCount; i++) {
                    printf("%d ", results[i]);
                }
                printf("\n");
                
                int saveChoice = getIntInput("Do you want to save the results to a file? (1 for Yes, 0 for No): ");
                if (saveChoice == 1) {
                    char filename[100];
                    printf("Enter the filename to save results: ");
                    scanf("%s", filename);
                    saveResultsToFile(filename, results, rollCount);
                }
                break;
            case 3:
                printf("Rolling a D20...\n");
                rollDice(1, 20);
                break;
            case 4:
                printf("Rolling a D6...\n");
                rollDice(1, 6);
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    
    return 0;
}

void rollDice(int numDice, int sides) {
    int total = 0;
    printf("Rolling %d D%d:\n", numDice, sides);
    
    for (int i = 0; i < numDice; i++) {
        int roll = (rand() % sides) + 1;
        printf("Roll %d: %d\n", i + 1, roll);
        total += roll;
    }
    
    printf("Total: %d\n", total);
}

void displayMenu() {
    printf("\n--- Dice Roller Menu ---\n");
    printf("1. Roll a custom dice\n");
    printf("2. Roll a specified number of dice\n");
    printf("3. Roll a D20\n");
    printf("4. Roll a D6\n");
    printf("5. Exit\n");
}

int getIntInput(const char *prompt) {
    int input;
    printf("%s", prompt);
    scanf("%d", &input);
    return input;
}

void saveResultsToFile(const char *filename, int results[], int count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "Roll %d: %d\n", i + 1, results[i]);
    }
    
    printf("Results saved to %s\n", filename);
    fclose(file);
}