//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
A time travel simulation program that allows the user to travel to various points in history.
*/

int main()
{
    srand(time(NULL)); //initialize random seed
    
    //Display welcome message
    printf("Welcome to the Time Travel Simulator!\n");
    printf("You will be able to travel to various points in history.\n\n");

    //Get user input for year to travel to
    int year;
    printf("Enter the year you would like to travel to: ");
    scanf("%d", &year);
    
    //Check if year entered is valid
    if (year < 0) {
        printf("Invalid year entered.");
        return 0;
    }

    //Generate a random year between 0 and current year if user enters 0
    if(year == 0) {
        year = rand() % (2022 + 1 - 0) + 0;
        printf("You will be travelling to the year %d.\n\n", year);
    } else {
        printf("You will be travelling to the year %d.\n\n", year);
    }

    //Display different messages depending on the year entered
    if (year < 1500) {
        printf("Get ready to experience medieval times!\n");
    } else if (year >= 1500 && year < 1800) {
        printf("You'll be travelling to the Renaissance era!\n");
    } else if (year >= 1800 && year < 1900) {
        printf("You are going to travel back in time to the industrial revolution!\n");
    } else if (year >= 1900 && year < 2000) {
        printf("You're travelling to the 20th century! Get ready for some world-changing events.\n");
    } else {
        printf("You are going to travel to the year 20xx. The future is yours!\n");
    }

    //Simulate time travel by printing current year and then counting down to the travel year
    printf("\n\nI'm calculating the sequence for quantum entanglement... Sit tight!\n");
    printf("\nStarting countdown...");
    printf("\n%d", rand() % (2022 - year + 1) + year);
    for (int i = 5; i >= 0; i--) {
        printf("\n%d", i);
        sleep(1);
    }

    //Display message indicating arrival in year entered
    printf("\n\nCongratulations! You have successfully travelled to the year %d.\n", year);
    printf("Enjoy your journey to the past, present, or future!\n");

    return 0;
}