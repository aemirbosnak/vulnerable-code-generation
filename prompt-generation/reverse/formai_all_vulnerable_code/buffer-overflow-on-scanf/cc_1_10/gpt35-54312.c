//FormAI DATASET v1.0 Category: Dice Roller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int rollDice(){
    return (rand()%6)+1;
}

void printDice(int num){
    switch(num){
        case 1:
            printf(" _____\n");
            printf("|     |\n");
            printf("|  o  |\n");
            printf("|_____|");
            break;
        case 2:
            printf(" _____\n");
            printf("|o    |\n");
            printf("|     |\n");
            printf("|____o|");
            break;
        case 3:
            printf(" _____\n");
            printf("|o    |\n");
            printf("|  o  |\n");
            printf("|____o|");
            break;
        case 4:
            printf(" _____\n");
            printf("|o   o|\n");
            printf("|     |\n");
            printf("|o___o|");
            break;
        case 5:
            printf(" _____\n");
            printf("|o   o|\n");
            printf("|  o  |\n");
            printf("|o___o|");
            break;
        case 6:
            printf(" _____\n");
            printf("|o   o|\n");
            printf("|o   o|\n");
            printf("|o___o|");
            break;
    }
}

int main()
{
    srand(time(NULL));
    printf("Welcome to the Dice Roller Program!\n");
    printf("How many dice would you like to roll?\n");
    int numDice;
    scanf("%d", &numDice);
    printf("\nRolling %d Dice...\n", numDice);
    int total = 0;
    for (int i = 0; i < numDice; i++){
        int roll = rollDice();
        printDice(roll);
        total += roll;
        printf("\n");
    }
    printf("Total: %d\n", total);
    return 0;
}