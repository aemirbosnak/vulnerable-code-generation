//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int year = 2022; // starting year
    int month = 12; // starting month
    int day = 31; // starting day
    
    printf("Welcome to the Time Travel Simulator!\n");

    while(1) {
        // get user input for how many years they would like to travel
        int years;
        printf("How many years would you like to travel? ");
        scanf("%d", &years);
        printf("\n");

        // add the years to the current year
        year += years;

        printf("You have traveled %d years into the future!\n", years);
        printf("The current year is now %d.\n\n", year);

        // get user input for how many months they would like to travel
        int months;
        printf("How many months would you like to travel? ");
        scanf("%d", &months);
        printf("\n");

        // add the months to the current month
        month += months;

        // check if month exceeds 12 (since there are 12 months in a year)
        if (month > 12) {
            year += 1; // increment year
            month -= 12; // set month back to January
        }

        printf("You have traveled %d months into the future!\n", months);
        printf("The current date is now %d/%d/%d.\n\n", month, day, year);

        // get user input for how many days they would like to travel
        int days;
        printf("How many days would you like to travel? ");
        scanf("%d", &days);
        printf("\n");

        // add the days to the current day
        day += days;

        // determine the number of days in the current month
        int days_in_month;
        switch(month) {
            case 1: days_in_month = 31; break;
            case 2: // check if it's a leap year
                    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                        days_in_month = 29;
                    } else {
                        days_in_month = 28;
                    }
                    break;
            case 3: days_in_month = 31; break;
            case 4: days_in_month = 30; break;
            case 5: days_in_month = 31; break;
            case 6: days_in_month = 30; break;
            case 7: days_in_month = 31; break;
            case 8: days_in_month = 31; break;
            case 9: days_in_month = 30; break;
            case 10: days_in_month = 31; break;
            case 11: days_in_month = 30; break;
            case 12: days_in_month = 31; break;
        }

        // check if day exceeds the number of days in the current month
        if (day > days_in_month) {
            month += 1; // increment month
            day -= days_in_month; // set day back to 1
        }

        printf("You have traveled %d days into the future!\n", days);
        printf("The current date is now %d/%d/%d.\n\n", month, day, year);

        // ask user if they want to travel again or quit the program
        char answer;
        printf("Do you want to travel again? (Y/N) ");
        scanf(" %c", &answer);
        printf("\n");

        // if the answer is not y or Y, exit the program
        if (answer != 'y' && answer != 'Y') {
            printf("Thanks for traveling with Time Travel Simulator!\n");
            break;
        }
    }

    return 0;
}