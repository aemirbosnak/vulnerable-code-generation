//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TRUE 1
#define FALSE 0

void rollDice(int numDice, int numSides) {
    int i, result = 0;
    srand(time(NULL));
    for (i = 0; i < numDice; i++) {
        result += rand() % numSides + 1;
    }
    printf("Rolling %d dice with %d sides each...\n", numDice, numSides);
    printf("The result is: %d\n", result);
}

int main() {
    int choice, numDice, numSides;
    printf("Welcome to the Dice Roller!\n");
    printf("What kind of dice would you like to roll?\n");
    printf("1. Six-sided dice\n");
    printf("2. Eight-sided dice\n");
    printf("3. Ten-sided dice\n");
    printf("4. Twelve-sided dice\n");
    printf("5. Twenty-sided dice\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            numSides = 6;
            break;
        case 2:
            numSides = 8;
            break;
        case 3:
            numSides = 10;
            break;
        case 4:
            numSides = 12;
            break;
        case 5:
            numSides = 20;
            break;
        default:
            printf("Invalid choice.\n");
            return 0;
    }
    printf("How many dice would you like to roll?\n");
    scanf("%d", &numDice);
    rollDice(numDice, numSides);
    return 0;
}