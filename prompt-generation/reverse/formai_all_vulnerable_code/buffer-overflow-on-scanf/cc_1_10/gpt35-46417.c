//FormAI DATASET v1.0 Category: Dice Roller ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice();
void printDice(int);
void printLine();

int main() {
    int diceNum;

    printf("How many dice do you want to roll?\n");
    scanf("%d", &diceNum);
    printf("\n");

    srand(time(NULL));

    for (int i = 0; i < diceNum; i++) {
        int dice = rollDice();
        printDice(dice);
    }

    printLine();
    printf("Total: %d\n", diceNum);

    return 0;
}

int rollDice() {
    return rand() % 6 + 1;
}

void printDice(int dice) {
    switch (dice) {
        case 1:
            printf(" _____ \n");
            printf("|     |\n");
            printf("|  o  |\n");
            printf("|_____|");
            break;
        case 2:
            printf(" _____ \n");
            printf("|o    |\n");
            printf("|     |\n");
            printf("|____o|");
            break;
        case 3:
            printf(" _____ \n");
            printf("|o    |\n");
            printf("|  o  |\n");
            printf("|____o|");
            break;
        case 4:
            printf(" _____ \n");
            printf("|o   o|\n");
            printf("|     |\n");
            printf("|____o|");
            break;
        case 5:
            printf(" _____ \n");
            printf("|o   o|\n");
            printf("|  o  |\n");
            printf("|____o|");
            break;
        case 6:
            printf(" _____ \n");
            printf("|o   o|\n");
            printf("|o   o|\n");
            printf("|____o|");
            break;
    }

    printf("\n");
}

void printLine() {
    printf("_________________________________________________\n");
}