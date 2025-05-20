//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: cheerful
#include <stdio.h>
#include <time.h>

int main() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter a year that you want to travel to (between 1900 and 2100): ");
    
    int year, current_year;
    scanf("%d", &year);
    
    // Call time function to get current year
    time_t t = time(NULL);
    struct tm current_time = *localtime(&t);
    current_year = current_time.tm_year + 1900;
    
    // Check if year is within range
    if (year<1900 || year>2100) {
        printf("Invalid year entered. Please enter a year between 1900 and 2100.\n");
        main();
    } else if (year>current_year) {
        printf("You cannot travel to the future! Please enter a year in the past.\n");
        main();
    } else {
        int time_travel = current_year - year;
        printf("Current year: %d\n", current_year);
        printf("Year travelled to: %d\n", year);
        printf("Years travelled back in time: %d\n", time_travel);
        
        // Display some fun facts about the year
        switch (year) {
            case 1900:
                printf("Did you know that the world's population was just under 2 billion in 1900?\n");
                break;
            case 1920:
                printf("Did you know that women were granted the right to vote in the US in 1920?\n");
                break;
            case 1950:
                printf("Did you know that the first credit card was introduced in the US in 1950?\n");
                break;
            case 1980:
                printf("Did you know that the Rubik's Cube was invented in Hungary in 1980?\n");
                break;
            case 2000:
                printf("Did you know that the Y2K bug scare occurred in the year 2000?\n");
                break;
            case 2010:
                printf("Did you know that the first iPad was released in 2010?\n");
                break;
            case 2020:
                printf("Did you know that the COVID-19 pandemic started in 2020 and caused a world-wide lockdown?\n");
                break;
        }
    }
    return 0;
}