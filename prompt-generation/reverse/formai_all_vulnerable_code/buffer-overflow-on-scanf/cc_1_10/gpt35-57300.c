//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get the current date and time
void get_current_time(struct tm *current_time) {
    time_t t = time(NULL);
    *current_time = *localtime(&t);
}

// Function to print the current date and time
void print_current_time(struct tm *current_time) {
    printf("Current Date and Time: %02d/%02d/%04d %02d:%02d:%02d\n",
            current_time->tm_mday, current_time->tm_mon + 1, current_time->tm_year + 1900,
            current_time->tm_hour, current_time->tm_min, current_time->tm_sec);
}

int main() {
    struct tm current_time;

    // Get the current date and time
    get_current_time(&current_time);

    // Print the current date and time
    print_current_time(&current_time);

    // Prompt the user to enter a year to travel to
    int year;
    printf("Enter a year to travel to: ");
    scanf("%d", &year);

    // Check if the year is valid
    if (year < current_time.tm_year + 1900) {
        printf("Sorry, time travel to the past is not possible.\n");
        exit(EXIT_FAILURE);
    }

    // Calculate the number of seconds between the current date and the travel date
    time_t current_date_seconds = mktime(&current_time);
    current_time.tm_year = year - 1900;
    time_t travel_date_seconds = mktime(&current_time);
    double difference = difftime(travel_date_seconds, current_date_seconds);

    // Print the number of seconds between the current date and the travel date
    printf("Traveling to %d...\n", year);
    printf("Time difference: %.0f seconds\n", difference);

    // Wait for 2 seconds
    sleep(2);

    // Update the current time to the travel date time
    current_time = *localtime(&travel_date_seconds);

    // Print the travel date and time
    print_current_time(&current_time);

    return 0;
}