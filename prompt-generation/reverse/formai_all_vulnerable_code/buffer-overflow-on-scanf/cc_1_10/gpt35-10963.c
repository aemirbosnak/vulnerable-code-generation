//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to Time Travel Simulator!\n");
    printf("Please choose an option:\n");
    printf("1. Travel to the past\n");
    printf("2. Travel to the future\n");
    int option;
    scanf("%d", &option);

    if (option == 1) {
        printf("You have chosen to travel to the past!\n");
        printf("Please enter a year between 1900 and 2021:\n");
        int year;
        scanf("%d", &year);

        if (year < 1900 || year > 2021) {
            printf("Invalid year. Please select a year between 1900 and 2021.\n");
            return 1;
        }

        printf("Traveling to the year %d...\n", year);

        int current_year = 2021;
        int years_travelled = current_year - year;

        if (years_travelled == 0) {
            printf("You're already here!\n");
        } else {
            printf("You have travelled %d years back in time!\n", years_travelled);
        }
    } else if (option == 2) {
        printf("You have chosen to travel to the future!\n");
        printf("Please enter a year between 2022 and 2100:\n");
        int year;
        scanf("%d", &year);

        if (year < 2022 || year > 2100) {
            printf("Invalid year. Please select a year between 2022 and 2100.\n");
            return 1;
        }

        printf("Traveling to the year %d...\n", year);

        int current_year = 2021;
        int years_travelled = year - current_year;

        if (years_travelled == 0) {
            printf("You're already here!\n");
        } else {
            printf("You have travelled %d years into the future!\n", years_travelled);
        }
    } else {
        printf("Invalid option. Please select 1 or 2.\n");
        return 1;
    }

    printf("Thank you for using Time Travel Simulator! Enjoy your journey!\n");
    return 0;
}