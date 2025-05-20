//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A data structure to store a timestamp.
typedef struct timestamp {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} timestamp;

// A function to generate a random timestamp.
timestamp generate_random_timestamp() {
    // Get the current time.
    time_t current_time = time(NULL);

    // Convert the current time to a timestamp.
    struct tm *current_time_tm = localtime(&current_time);

    // Create a random timestamp.
    timestamp random_timestamp;
    random_timestamp.year = current_time_tm->tm_year + rand() % 100;
    random_timestamp.month = current_time_tm->tm_mon + rand() % 12;
    random_timestamp.day = current_time_tm->tm_mday + rand() % 30;
    random_timestamp.hour = current_time_tm->tm_hour + rand() % 24;
    random_timestamp.minute = current_time_tm->tm_min + rand() % 60;
    random_timestamp.second = current_time_tm->tm_sec + rand() % 60;

    // Return the random timestamp.
    return random_timestamp;
}

// A function to print a timestamp.
void print_timestamp(timestamp timestamp) {
    printf("%04d-%02d-%02d %02d:%02d:%02d\n", timestamp.year, timestamp.month, timestamp.day, timestamp.hour, timestamp.minute, timestamp.second);
}

// A function to simulate time travel.
void time_travel(timestamp start_timestamp, timestamp end_timestamp) {
    // Print the start timestamp.
    printf("Starting timestamp: ");
    print_timestamp(start_timestamp);

    // Print the end timestamp.
    printf("Ending timestamp: ");
    print_timestamp(end_timestamp);

    // Calculate the time difference between the start and end timestamps.
    int year_difference = end_timestamp.year - start_timestamp.year;
    int month_difference = end_timestamp.month - start_timestamp.month;
    int day_difference = end_timestamp.day - start_timestamp.day;
    int hour_difference = end_timestamp.hour - start_timestamp.hour;
    int minute_difference = end_timestamp.minute - start_timestamp.minute;
    int second_difference = end_timestamp.second - start_timestamp.second;

    // Print the time difference.
    printf("Time difference: %d years, %d months, %d days, %d hours, %d minutes, %d seconds\n", year_difference, month_difference, day_difference, hour_difference, minute_difference, second_difference);

    // Simulate the time travel.
    time_t start_time = mktime(&start_timestamp);
    time_t end_time = mktime(&end_timestamp);
    time_t current_time = start_time;

    while (current_time <= end_time) {
        // Print the current time.
        struct tm *current_time_tm = localtime(&current_time);
        printf("%04d-%02d-%02d %02d:%02d:%02d\n", current_time_tm->tm_year, current_time_tm->tm_mon, current_time_tm->tm_mday, current_time_tm->tm_hour, current_time_tm->tm_min, current_time_tm->tm_sec);

        // Increment the current time by one second.
        current_time++;
    }
}

// The main function.
int main() {
    // Generate a random start timestamp.
    timestamp start_timestamp = generate_random_timestamp();

    // Generate a random end timestamp.
    timestamp end_timestamp = generate_random_timestamp();

    // Simulate time travel.
    time_travel(start_timestamp, end_timestamp);

    return 0;
}