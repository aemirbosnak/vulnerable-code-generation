//FormAI DATASET v1.0 Category: Dice Roller ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int choice, noOfDice, diceValue, total, i, j;
    srand(time(NULL)); // for generating random numbers

    printf("Welcome to the Dice Roller!\n");
    printf("Please choose the type of Dice you would like to roll:\n");
    printf("1) Four-sided Dice\n");
    printf("2) Six-sided Dice\n");
    printf("3) Eight-sided Dice\n");
    printf("4) Ten-sided Dice\n");
    printf("5) Twelve-sided Dice\n");
    printf("6) Twenty-sided Dice\n");
    printf("Enter your choice (1-6): ");
    scanf("%d",&choice);
    printf("Enter the number of dice you want to roll: ");
    scanf("%d",&noOfDice);

    switch(choice){
        case 1:
            diceValue = 4;
            break;
        case 2:
            diceValue = 6;
            break;
        case 3:
            diceValue = 8;
            break;
        case 4:
            diceValue = 10;
            break;
        case 5:
            diceValue = 12;
            break;
        case 6:
            diceValue = 20;
            break;
        default:
            printf("Invalid Choice");
            exit(0);
    }

    printf("\nYou chose to roll %d %d-sided dice:\n", noOfDice, diceValue);
    printf("The results are:\n");

    total = 0; //to store the sum of all dice values rolled
    for(i=0; i<noOfDice; i++){
        int roll = rand()%diceValue + 1; // to generate random numbers between 1 and the diceValue
        printf("|");
        for(j=0; j<roll; j++){
            printf(" # ");
        }
        for(int k=j; k<diceValue; k++){
            printf("   ");
        }
        printf("|");
        total += roll;
    }
    printf("\n");

    printf("Total value of dice: %d", total);

    return 0;
}