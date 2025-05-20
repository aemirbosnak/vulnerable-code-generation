//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
    int current_year = 2022; // Initialize current year
    int target_year, year_difference; // Declare variables for target year and year difference
    int option; // Declare variable for user's menu option choice
    char confirm; // Declare variable to confirm time travel action

    printf("********** Time Travel Simulator **********\n");
    printf("Welcome! What would you like to do?\n");

    do {
        printf("\n1. Travel to a specific year\n");
        printf("2. Travel a number of years into the future\n");
        printf("3. Travel a number of years into the past\n");
        printf("4. Exit\n");
        printf("Please enter your choice (1-4): ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nEnter the year you want to travel to: ");
                scanf("%d", &target_year);
                year_difference = abs(current_year - target_year);
                printf("\nAre you sure you want to travel to %d? (Y/N): ", target_year);
                scanf(" %c", &confirm);
                if(confirm == 'Y' || confirm == 'y') {
                    current_year = target_year;
                    printf("\nYou have successfully travelled to %d!\n", current_year);
                } else {
                    printf("\nTime travel cancelled.\n");
                }
                break;
            case 2:
                printf("\nEnter the number of years you want to travel into the future: ");
                scanf("%d", &year_difference);
                target_year = current_year + year_difference;
                printf("\nAre you sure you want to travel %d years into the future? (Y/N): ", year_difference);
                scanf(" %c", &confirm);
                if(confirm == 'Y' || confirm == 'y') {
                    current_year = target_year;
                    printf("\nYou have successfully travelled %d years into the future to %d!\n", year_difference, current_year);
                } else {
                    printf("\nTime travel cancelled.\n");
                }
                break;
            case 3:
                printf("\nEnter the number of years you want to travel into the past: ");
                scanf("%d", &year_difference);
                target_year = current_year - year_difference;
                printf("\nAre you sure you want to travel %d years into the past? (Y/N): ", year_difference);
                scanf(" %c", &confirm);
                if(confirm == 'Y' || confirm == 'y') {
                    current_year = target_year;
                    printf("\nYou have successfully travelled %d years into the past to %d!\n", year_difference, current_year);
                } else {
                    printf("\nTime travel cancelled.\n");
                }
                break;
            case 4:
                printf("\nThank you for using the Time Travel Simulator!\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    } while(option != 4);

    return 0;
}