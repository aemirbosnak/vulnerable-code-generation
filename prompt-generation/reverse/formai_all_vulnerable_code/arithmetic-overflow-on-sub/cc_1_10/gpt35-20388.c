//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: lively
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time; /* Time library structure */
    struct tm *time_info;
    char time_string[40];

    /* Get current time */
    time(&current_time);
    time_info = localtime(&current_time);

    /* Convert time to string and print */
    strftime(time_string, sizeof(time_string), "%c", time_info);
    printf("Welcome to the Time Travel Simulator! Current date and time is: %s\n", time_string);

    int travel_year, travel_month, travel_day;

    /* Get input from user for travel date */
    printf("Enter the year you want to travel to: ");
    scanf("%d", &travel_year);
    printf("Enter the month you want to travel to (1-12): ");
    scanf("%d", &travel_month);
    printf("Enter the day you want to travel to (1-31): ");
    scanf("%d", &travel_day);

    /* Convert travel date to time structure */
    struct tm travel_time = { 0 };
    travel_time.tm_year = travel_year - 1900;
    travel_time.tm_mon = travel_month - 1;
    travel_time.tm_mday = travel_day;

    /* Convert travel time to time_t and calculate difference */
    time_t travel_date = mktime(&travel_time);
    double seconds_difference = difftime(travel_date, current_time);

    /* Check if travel date is in the past or future */
    if (seconds_difference < 0) {
        printf("Sorry, you cannot travel back in time!\n");
    }
    else if (seconds_difference == 0) {
        printf("You are already in the time you want to travel to!\n");
    }
    else {
        /* Travel to the future */
        printf("You are now traveling to %02d/%02d/%04d...\n", travel_month, travel_day, travel_year);
        printf("3... ");
        sleep(1);
        printf("2... ");
        sleep(1);
        printf("1... ");
        sleep(1);
        printf("Blast off!\n");
        printf("Congratulations! You have successfully traveled to %02d/%02d/%04d.\n", travel_month, travel_day, travel_year);
    }

    return 0;
}