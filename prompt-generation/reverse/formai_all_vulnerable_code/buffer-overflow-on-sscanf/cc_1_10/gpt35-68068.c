//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    time_t current_time, start_time;
    struct tm * start_tm, * current_tm;
    char date_str[20], time_str[20];
    int year_diff, month_diff, day_diff, hour_diff, minute_diff, second_diff;

    // Get the current time and store it in current_time
    time(&current_time);
    current_tm = localtime(&current_time);
    strftime(time_str, sizeof(time_str), "%H:%M:%S", current_tm);
    strftime(date_str, sizeof(date_str), "%Y-%m-%d", current_tm);
    printf("Current time: %s %s\n", date_str, time_str);

    // Prompt the user to enter a time in the past
    printf("Enter a date and time in the past (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s %s", date_str, time_str);

    // Convert the user input to a time_t value
    sscanf(date_str, "%d-%d-%d", &start_tm->tm_year, &start_tm->tm_mon, &start_tm->tm_mday);
    sscanf(time_str, "%d:%d:%d", &start_tm->tm_hour, &start_tm->tm_min, &start_tm->tm_sec);
    start_tm->tm_year -= 1900;
    start_tm->tm_mon -= 1;
    start_time = mktime(start_tm);

    // Calculate the difference between the current time and the user input time
    year_diff = current_tm->tm_year - start_tm->tm_year;
    month_diff = current_tm->tm_mon - start_tm->tm_mon;
    day_diff = current_tm->tm_mday - start_tm->tm_mday;
    hour_diff = current_tm->tm_hour - start_tm->tm_hour;
    minute_diff = current_tm->tm_min - start_tm->tm_min;
    second_diff = current_tm->tm_sec - start_tm->tm_sec;

    // Print the time travel simulation results
    printf("\nTime travel simulation:\n");
    printf("=======================\n");
    printf("You have traveled %d years, %d months, %d days, %d hours, %d minutes, and %d seconds into the past.\n", year_diff, month_diff, day_diff, hour_diff, minute_diff, second_diff);

    // Display the simulation using ASCII art
    printf("\n");
    printf("    _.._     \n");
    printf("  .' .-'`    \n");
    printf(" /  /         \n");
    printf(" |  |    .-.  \n");
    printf(" \\  \\   /  |  \n");
    printf("  `-.\\ `--'`  \n");
    printf(" jgs |/`\\|     \n");
    printf("     '---'     \n");

    // Wait for a few seconds and exit the program
    sleep(3);
    return 0;
}