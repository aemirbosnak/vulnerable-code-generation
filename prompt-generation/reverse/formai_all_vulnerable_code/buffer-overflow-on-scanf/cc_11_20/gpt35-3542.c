//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message
    printf("Welcome to the Peaceful Fortune Teller!\n");
    
    // Seed the random generator with the current time
    srand(time(NULL));
    
    // Declare variables for user input and generated numbers
    int userNumber, fortuneNumber;
    
    // Prompt the user for a number between 1 and 10
    printf("Please enter a number between 1 and 10: ");
    scanf("%d", &userNumber);
    
    // Generate a random number between 1 and 10 for the fortune
    fortuneNumber = rand() % 10 + 1;
    
    // Print the fortune
    switch(fortuneNumber) {
        case 1:
            printf("Your future looks bright!\n");
            break;
        case 2:
            printf("Be patient, good things come to those who wait.\n");
            break;
        case 3:
            printf("Take a chance and good things will happen!\n");
            break;
        case 4:
            printf("Beware of those who seek to cause you harm.\n");
            break;
        case 5:
            printf("You will soon experience great joy!\n");
            break;
        case 6:
            printf("Your dreams will come true if you work hard and believe in yourself.\n");
            break;
        case 7:
            printf("Take a moment to reflect on your life and appreciate all the good things.\n");
            break;
        case 8:
            printf("A new opportunity is just around the corner!\n");
            break;
        case 9:
            printf("Your kindness will be rewarded in unexpected ways.\n");
            break;
        case 10:
            printf("Stay true to yourself and you will succeed.\n");
            break;
        default:
            // In case something goes wrong with the random generator
            printf("Something went wrong. Please try again later.\n");
            break;
    }
    
    // Calculate and display the difference between the user's number and the fortune number
    int difference = abs(userNumber - fortuneNumber);
    printf("Your number: %d\nFortune number: %d\nDifference: %d\n", userNumber, fortuneNumber, difference);
    
    return 0;
}