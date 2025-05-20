//FormAI DATASET v1.0 Category: Dice Roller ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function declarations
int rollDice(); 
void printRoll(int roll);

// main function
int main()
{
    int totalRolls = 0, diceSum = 0, roll = 0;
    char again = ' ';
    srand(time(0)); // sets seed for random generator based on system time
    
    // welcomes user and begins loop to roll dice
    printf("Welcome to the random dice roller program!\n\n");
    do {
        roll = rollDice(); // roll dice and get result
        diceSum += roll; // add roll to sum of dice
        printRoll(roll); // print roll result
        totalRolls++; // increment total number of rolls
        printf("Would you like to roll the dice again? (Y/N)\n");
        scanf(" %c", &again); // ask user if they want to roll again
    } while (again == 'Y' || again == 'y'); // loop continues if user inputs 'Y' or 'y'
    
    // end program and output results
    printf("\nThank you for using the random dice roller program!\n");
    printf("\nTotal rolls: %d\n", totalRolls);
    printf("Sum of rolls: %d\n", diceSum);
    printf("Average roll: %.2f\n", (float)diceSum/totalRolls);
    
    return 0;
}

// function to roll dice
int rollDice()
{
    int roll = rand() % 6 + 1; // generates random number between 1-6
    return roll;
}

// function to print roll result in an irregular way
void printRoll(int roll)
{
    if (roll == 1) {
        printf(" _____ \n");
        printf("|     |\n");
        printf("|  o  |\n");
        printf("|     |\n");
        printf(" ‾‾‾‾‾ \n");
    } else if (roll == 2) {
        printf(" _____ \n");
        printf("| o   |\n");
        printf("|     |\n");
        printf("|   o |\n");
        printf(" ‾‾‾‾‾ \n");
    } else if (roll == 3) {
        printf(" _____ \n");
        printf("| o   |\n");
        printf("|  o  |\n");
        printf("|   o |\n");
        printf(" ‾‾‾‾‾ \n");
    } else if (roll == 4) {
        printf(" _____ \n");
        printf("| o o |\n");
        printf("|     |\n");
        printf("| o o |\n");
        printf(" ‾‾‾‾‾ \n");
    } else if (roll == 5) {
        printf(" _____ \n");
        printf("| o o |\n");
        printf("|  o  |\n");
        printf("| o o |\n");
        printf(" ‾‾‾‾‾ \n");
    } else {
        printf(" _____ \n");
        printf("| o o |\n");
        printf("| o o |\n");
        printf("| o o |\n");
        printf(" ‾‾‾‾‾ \n");
    }
}