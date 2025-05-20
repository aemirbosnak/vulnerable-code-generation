//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayIntroduction() {
    printf("===================================\n");
    printf("     THE DICE ROLLER OF FATE\n");
    printf("===================================\n");
    printf("Welcome, brave adventurer, to the realm of chance!\n");
    printf("Here you shall roll the sacred dice to determine your fortune.\n");
    printf("Choose wisely, for the fate of your journey lays in the hands of destiny!\n");
    printf("\n");
}

void displayInstructions() {
    printf("Instructions to the adventurer:\n");
    printf("1. Choose the number of dice you wish to roll (1-5).\n");
    printf("2. Choose the type of dice:\n");
    printf("   - D4 (Four-sided)\n");
    printf("   - D6 (Six-sided)\n");
    printf("   - D8 (Eight-sided)\n");
    printf("   - D10 (Ten-sided)\n");
    printf("   - D12 (Twelve-sided)\n");
    printf("   - D20 (Twenty-sided)\n");
    printf("3. Witness the roll and the fate that unfolds before you!\n");
    printf("4. You may roll again, or conclude your quest.\n");
    printf("\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

void rollMultipleDice(int diceCount, int sides) {
    int total = 0;
    printf("Rolling %d D%d dice...\n", diceCount, sides);
    
    for (int i = 0; i < diceCount; i++) {
        int roll = rollDice(sides);
        printf("Roll %d: %d\n", i + 1, roll);
        total += roll;
    }
    printf("Total roll: %d\n", total);
}

int main() {
    srand(time(NULL));

    displayIntroduction();
    displayInstructions();

    int diceCount, sides, continueRolling = 1;

    while (continueRolling) {
        printf("Enter the number of dice to roll (1-5): ");
        scanf("%d", &diceCount);
        
        if (diceCount < 1 || diceCount > 5) {
            printf("Nay! You may only roll between 1 and 5 dice. Try again!\n");
            continue;
        }
        
        printf("Choose your dice type:\n");
        printf("1. D4\n");
        printf("2. D6\n");
        printf("3. D8\n");
        printf("4. D10\n");
        printf("5. D12\n");
        printf("6. D20\n");
        printf("Enter your choice (1-6): ");
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: sides = 4; break;
            case 2: sides = 6; break;
            case 3: sides = 8; break;
            case 4: sides = 10; break;
            case 5: sides = 12; break;
            case 6: sides = 20; break;
            default:
                printf("Alas! That is not a valid choice.\n");
                continue;
        }

        rollMultipleDice(diceCount, sides);
        
        printf("Would you like to roll again? (1 for Yes, 0 for No): ");
        scanf("%d", &continueRolling);
    }

    printf("Thank you for partaking in this adventure!\n");
    printf("May your path be paved with glory and fortune!\n");
    return 0;
}