//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcomeMessage() {
    printf("=====================================\n");
    printf("         Welcome to Dice Roller      \n");
    printf("=====================================\n");
    printf("Roll virtual dice and let the fate decide!\n\n");
}

void rollDice(int sides) {
    int roll = (rand() % sides) + 1;
    printf("You rolled a %d on a %d-sided die!\n", roll, sides);
}

void multipleRolls(int sides, int rolls) {
    if (rolls <= 0) {
        printf("Invalid number of rolls. Please roll at least once.\n");
        return;
    }

    printf("Rolling a %d-sided die %d times:\n", sides, rolls);
    for (int i = 0; i < rolls; i++) {
        rollDice(sides);
    }
}

void drawDiceFace(int roll, int sides) {
    printf("\nDisplaying the face of a %d-sided die with outcome %d:\n", sides, roll);
    switch (roll) {
        case 1:
            printf(" _______\n");
            printf("|       |\n");
            printf("|   O   |\n");
            printf("|       |\n");
            printf(" ------- \n");
            break;
        case 2:
            printf(" _______\n");
            printf("| O     |\n");
            printf("|       |\n");
            printf("|     O |\n");
            printf(" ------- \n");
            break;
        case 3:
            printf(" _______\n");
            printf("| O     |\n");
            printf("|   O   |\n");
            printf("|     O |\n");
            printf(" ------- \n");
            break;
        case 4:
            printf(" _______\n");
            printf("| O   O |\n");
            printf("|       |\n");
            printf("| O   O |\n");
            printf(" ------- \n");
            break;
        case 5:
            printf(" _______\n");
            printf("| O   O |\n");
            printf("|   O   |\n");
            printf("| O   O |\n");
            printf(" ------- \n");
            break;
        case 6:
            printf(" _______\n");
            printf("| O   O |\n");
            printf("| O   O |\n");
            printf("| O   O |\n");
            printf(" ------- \n");
            break;
        default:
            printf("Invalid die face.\n");
            break;
    }
}

void exitProgram() {
    printf("=====================================\n");
    printf("         Thank you for playing!     \n");
    printf("=====================================\n");
    exit(0);
}

int main() {
    srand(time(NULL));
    int sides, rolls;

    welcomeMessage();

    while (1) {
        printf("Enter the number of sides on the die (6, 8, 10, 20, etc.) or 0 to exit: ");
        scanf("%d", &sides);
        
        if (sides == 0) {
            exitProgram();
        } else if (sides < 2) {
            printf("Please enter a valid number of sides.\n");
            continue;
        }

        printf("How many times would you like to roll the %d-sided die? ", sides);
        scanf("%d", &rolls);
        
        multipleRolls(sides, rolls);
        
        int lastRoll = (rand() % sides) + 1;  // a random roll for the face display
        drawDiceFace(lastRoll, sides);
        
        printf("\nPress Enter to continue or type 'exit' to quit: ");
        char buffer[10];
        scanf("%s", buffer);
        if (buffer[0] == 'e' || buffer[0] == 'E') {
            exitProgram();
        }
    }

    return 0;
}