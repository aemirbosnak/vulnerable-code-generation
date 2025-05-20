//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 6
int rollDice() {
    return rand() % 6 + 1;
}

// Function to print out the fortune based on the given number
void printFortune(int num) {
    switch(num) {
        case 1:
            printf("You will have a lucky day today.\n");
            break;
        case 2:
            printf("A new opportunity is coming your way.\n");
            break;
        case 3:
            printf("You will meet someone special today.\n");
            break;
        case 4:
            printf("Success is in your near future.\n");
            break;
        case 5:
            printf("You will face a challenge, but overcome it.\n");
            break;
        case 6:
            printf("You will receive good news soon.\n");
            break;
        default:
            printf("Invalid number.\n");
            break;
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator with current time
    int num;
    char playAgain;

    // Loop until user decides to quit
    do {
        // Roll the dice
        num = rollDice();

        // Print out the fortune
        printFortune(num);

        // Ask user if they want to play again
        printf("Do you want to roll the dice again? (y/n): ");
        scanf(" %c", &playAgain);

    } while(playAgain == 'y' || playAgain == 'Y');

    return 0;
}