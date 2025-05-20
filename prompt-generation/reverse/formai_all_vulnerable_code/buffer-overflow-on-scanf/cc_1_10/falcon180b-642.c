//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a random fortune
void printFortune(int fortuneIndex) {
    switch (fortuneIndex) {
        case 0:
            printf("You will have a great day today!\n");
            break;
        case 1:
            printf("You will receive good news soon!\n");
            break;
        case 2:
            printf("You will meet someone special today!\n");
            break;
        case 3:
            printf("You will have a successful business meeting!\n");
            break;
        case 4:
            printf("You will find something you lost!\n");
            break;
        case 5:
            printf("You will have a lucky day!\n");
            break;
        case 6:
            printf("You will have a productive day!\n");
            break;
        case 7:
            printf("You will have a happy day!\n");
            break;
        case 8:
            printf("You will have a peaceful day!\n");
            break;
        case 9:
            printf("You will have a fun day!\n");
            break;
        default:
            printf("I'm sorry, I cannot predict your future.\n");
            break;
    }
}

// Main function
int main() {
    srand(time(0));
    int fortuneIndex;

    // Loop until the user wants to quit
    while (1) {
        // Print a menu
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Please select an option:\n");
        printf("1. Get a fortune\n");
        printf("2. Quit\n");

        // Get the user's choice
        scanf("%d", &fortuneIndex);

        // Exit the program if the user chooses to quit
        if (fortuneIndex == 2) {
            printf("Thank you for using the Automated Fortune Teller!\n");
            return 0;
        }

        // Generate a random fortune
        fortuneIndex = getRandomNumber(0, 9);

        // Print the fortune
        printFortune(fortuneIndex);

        // Wait for the user to press enter
        printf("Press enter to get another fortune...\n");
        getchar();
    }

    return 0;
}