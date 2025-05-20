//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm * time_info;
    char year_string[5];

    // Get current year and convert to string
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(year_string, sizeof(year_string), "%Y", time_info);

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Current year: %s\n\n", year_string);

    int user_year;

    // Get user input for year
    printf("Enter a year to time travel to:");
    scanf("%d", &user_year);

    // Check if user inputs a valid year
    while (user_year < atoi(year_string)) {
        printf("Sorry, you can't travel back in time to a year that has already happened.\n");
        printf("Enter a year to time travel to:");
        scanf("%d", &user_year);
    }

    // Time travel simulation
    printf("\nPreparing to travel to %d...\n\n", user_year);

    int i;
    for (i = atoi(year_string); i <= user_year; i++) {
        printf("Current year: %d\n", i);
        sleep(1); // delay for 1 second
    }

    printf("\nWelcome to the year %d!\n", user_year);

    // Display historical events in user's chosen year
    switch (user_year) {
        case 2022:
            printf("\nIn %d, the FIFA World Cup will be held in Qatar.", user_year);
            break;
        case 2030:
            printf("\nIn %d, the United Nations will aim to achieve the Sustainable Development Goals.", user_year);
            break;
        case 2060:
            printf("\nIn %d, the first colony on Mars will be established.", user_year);
            break;
        default:
            printf("\nNo significant events occured in %d.", user_year);
    }

    printf("\n\nThank you for using the Time Travel Simulator!");

    return 0;
}