//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: visionary
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //initialize variables
    int current_year = 2021;
    int target_year;

    //get target year from user
    printf("Welcome to the Time Travel Simulator!\nPlease enter your desired year (between 0 and 9999): ");
    scanf("%d", &target_year);

    //check if target year is valid
    if(target_year < 0 || target_year > 9999)
    {
        printf("Invalid year! Please enter a year between 0 and 9999.\n");
        return 0;
    }

    //check if target year is in the past or future
    bool is_past = target_year < current_year;

    //calculate difference in years
    int year_diff = abs(target_year - current_year);

    //assume time travel takes 1 second per year (for simplicity)
    printf("You are travelling %d years into the %s.\n", year_diff, is_past ? "past" : "future");
    printf("Please wait while we transport you...\n");
    for(int i = 0; i < year_diff; i++)
    {
        printf("Travelling %d/%d years...\n", i+1, year_diff);
        sleep(1); //wait 1 second (UNIX command)
    }

    //greet the time traveller
    printf("\nWelcome to the year %d!\n", target_year);

    //random event generator
    srand(time(NULL));
    int event = rand() % 3; //generate a random number between 0 and 2

    switch(event)
    {
        case 0:
            printf("There's a bright light in the sky, followed by a loud noise. You look up to see a spaceship hovering above you.\n");
            break;
        case 1:
            printf("You see a news headline: 'Scientists discover cure for cancer'.\n");
            break;
        case 2:
            printf("There's a sudden earthquake. You look around and everything seems to be shaking. When it's over, you realize that you're standing in the middle of a desolate wasteland.\n");
            break;
    }

    return 0;
}