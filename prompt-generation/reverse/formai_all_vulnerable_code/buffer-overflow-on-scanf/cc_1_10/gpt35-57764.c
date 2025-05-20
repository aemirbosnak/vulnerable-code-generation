//FormAI DATASET v1.0 Category: Dice Roller ; Style: grateful
/*
 * This is a Dice Roller program written in C language.
 * It is a command line program that allows user to roll dice from 1 to 6 sides.
 * It can be used to play different board games, RPGs, and more.
 * The program was created with gratitude for all the fun that games can bring into our lives.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int diceSides; // variable for the number of sides of the dice
    int repeat; // variable for the number of times to roll the dice
    int rollResult; // variable for the result of the roll
    char cont; // variable for user's choice to continue rolling or not
    
    srand((unsigned int)time(NULL)); // set the seed for the rand function to current time
    
    printf("Welcome to the Dice Roller program!\n");
    printf("This program allows you to roll dice from 1 to 6 sides.\n");
    
    do {
        printf("\nPlease choose the number of sides of the dice (1-6): ");
        scanf("%d", &diceSides); // read user's input
        
        // check if the input is valid
        if (diceSides < 1 || diceSides > 6) {
            printf("Invalid input! Please enter a number from 1 to 6.\n");
            continue; // start again the loop
        }
        
        printf("Please enter the number of times to roll the dice: ");
        scanf("%d", &repeat); // read user's input
        
        // check if the input is valid
        if (repeat < 1) {
            printf("Invalid input! Please enter a positive number.\n");
            continue; // start again the loop
        }
        
        // roll the dice the specified number of times
        printf("\nRolling the dice %d time(s)...\n", repeat);
        for (int i = 1; i <= repeat; i++) {
            rollResult = rand() % diceSides + 1;
            printf("Roll %d: %d\n", i, rollResult);
        }
        
        // ask user if they want to continue rolling
        printf("\nDo you want to roll again? (y/n): ");
        scanf(" %c", &cont); // note: there is a space before %c to consume the newline character
        
        // repeat the loop if the user enters 'y'
    } while (cont == 'y' || cont == 'Y');
    
    printf("Thanks for using the Dice Roller program! Have a great day.\n");
    
    return 0;
}