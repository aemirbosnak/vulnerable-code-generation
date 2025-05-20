//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void travelToYear(int year);
void displayYearInfo(int year);

int main() {
    int year;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("You can travel to any year between 1900 and 2023.\n");
    printf("Please enter the year you want to travel to: ");
    
    if (scanf("%d", &year) != 1) {
        printf("Invalid input. Please enter a valid year.\n");
        return 1;
    }

    if (year < 1900 || year > 2023) {
        printf("Year out of bounds. Please select a year between 1900 and 2023.\n");
        return 1;
    }

    travelToYear(year);

    return 0;
}

void travelToYear(int year) {
    printf("Initiating time travel to the year: %d...\n", year);
    // Simulating a delay to mimic the time travel experience
    for (int i = 3; i > 0; i--) {
        printf("Traveling in %d...\n", i);
        sleep(1);
    }

    printf("You have arrived in the year: %d!\n", year);
    displayYearInfo(year);
}

void displayYearInfo(int year) {
    printf("Here are some interesting facts about %d:\n", year);
    
    switch (year) {
        case 1900:
            printf("- The first Zeppelin flight took place.\n");
            break;
        case 1920:
            printf("- The first radio station, KDKA, went on the air.\n");
            break;
        case 1945:
            printf("- World War II ended.\n");
            break;
        case 1969:
            printf("- Apollo 11 landed the first humans on the Moon.\n");
            break;
        case 1989:
            printf("- The Berlin Wall fell.\n");
            break;
        case 2000:
            printf("- The Y2K bug scare occurred.\n");
            break;
        case 2011:
            printf("- The final Space Shuttle mission took place.\n");
            break;
        case 2020:
            printf("- The COVID-19 pandemic changed the world.\n");
            break;
        default:
            printf("- No significant events recorded for this year.\n");
            break;
    }

    printf("Thanks for using the Time Travel Simulator. Safe travels!\n");
}