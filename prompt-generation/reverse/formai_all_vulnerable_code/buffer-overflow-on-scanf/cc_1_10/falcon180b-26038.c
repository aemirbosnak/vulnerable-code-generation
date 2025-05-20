//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM_DICE 6
#define NUM_SIDES 6

// Function to roll a single dice
int rollDice() {
    int roll;
    srand(time(NULL));
    roll = rand() % NUM_SIDES + 1;
    return roll;
}

// Function to roll multiple dice
void rollDiceMultiple(int numDice, int numSides) {
    int i, roll;
    for(i=0; i<numDice; i++) {
        srand(time(NULL));
        roll = rand() % numSides + 1;
        printf("%d ", roll);
    }
}

int main() {
    int choice;
    do {
        printf("\n\n1. Roll a single dice\n2. Roll multiple dice\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nRolling a single dice...\n");
                int roll = rollDice();
                printf("You rolled a %d\n", roll);
                break;
            case 2:
                printf("\nHow many dice do you want to roll? ");
                scanf("%d", &choice);
                printf("How many sides do the dice have? ");
                scanf("%d", &choice);
                rollDiceMultiple(choice, choice);
                printf("\n");
                break;
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice!= 3);
    return 0;
}