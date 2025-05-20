//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: optimized
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *time_ptr;
    int year, month, day, hour, minute, second;
    char user_input;

    // Get current time
    current_time = time(NULL);
    time_ptr = localtime(&current_time);

    // Store current time values
    year = time_ptr->tm_year + 1900;
    month = time_ptr->tm_mon + 1;
    day = time_ptr->tm_mday;
    hour = time_ptr->tm_hour;
    minute = time_ptr->tm_min;
    second = time_ptr->tm_sec;

    printf("Welcome to the Time Travel Simulator!\n\n");

    do {
        // Display current time and ask user for time travel input
        printf("Current time: %02d/%02d/%d %02d:%02d:%02d\n", month, day, year, hour, minute, second);
        printf("Enter number of years to travel (positive for future, negative for past): ");
        scanf("%d", &user_input);

        // Update time_ptr with user input
        time_ptr->tm_year += user_input;
        current_time = mktime(time_ptr);
        time_ptr = localtime(&current_time);

        // Retrieve new time values
        year = time_ptr->tm_year + 1900;
        month = time_ptr->tm_mon + 1;
        day = time_ptr->tm_mday;
        hour = time_ptr->tm_hour;
        minute = time_ptr->tm_min;
        second = time_ptr->tm_sec;

        printf("You have traveled to: %02d/%02d/%d %02d:%02d:%02d\n\n", month, day, year, hour, minute, second);

        // Ask user if they want to travel again
        printf("Do you want to travel again? (Y/N) ");
        scanf(" %c", &user_input);

    } while (user_input == 'Y' || user_input == 'y');

    printf("\nThank you for using the Time Travel Simulator!\n");

    return 0;
}