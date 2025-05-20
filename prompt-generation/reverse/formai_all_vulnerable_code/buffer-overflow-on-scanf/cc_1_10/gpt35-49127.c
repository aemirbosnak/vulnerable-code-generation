//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {

    int currentYear, yearOfBirth, yearsInFuture, yearsInPast;

    printf("Welcome to the Time Travel Simulator!\n\n");

    printf("What year is it now?\n");
    scanf("%d", &currentYear);
    printf("You entered: %d\n\n", currentYear);

    printf("What is your year of birth?\n");
    scanf("%d", &yearOfBirth);
    printf("You entered: %d\n\n", yearOfBirth);

    yearsInFuture = 0;
    yearsInPast = 0;
    
    if (currentYear < yearOfBirth) { // Can't time travel to future if you aren't born yet
        printf("ERROR: You cannot time travel to the future if you haven't been born yet!\n");
        return 1;
    }

    while (currentYear > yearOfBirth) { 
        currentYear--;
        yearsInPast++; // Count years traveled to the past
    }

    printf("You have traveled %d years into the past!\n", yearsInPast);

    printf("How many years into the future would you like to travel?\n");
    scanf("%d", &yearsInFuture);
    printf("You entered: %d\n\n", yearsInFuture);

    printf("Traveling...\n\n");

    // Animate traveling to future
    for (int i = 0; i < 5; i++) {
        printf("...\n");
        system("sleep 1");
    }

    currentYear += yearsInFuture;
    
    printf("\nYou have arrived in the year %d!\n", currentYear);

    return 0;
}