//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    //Initialize variables to hold current date and time
    time_t current_time;
    struct tm *current_time_info;
    char time_buffer[80];

    //Get the current time
    time(&current_time);
    current_time_info = localtime(&current_time);

    //Print the current time
    strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", current_time_info);
    printf("Current Date and Time: %s\n", time_buffer);

    //Initialize variables to hold the simulated date and time
    time_t simulated_time;
    struct tm *simulated_time_info;
    char simulated_time_buffer[80];

    //Ask user to input the simulated year
    int simulated_year;
    printf("Enter the year you would like to simulate: ");
    scanf("%d", &simulated_year);

    //Set the simulated year
    simulated_time_info = current_time_info;
    simulated_time_info->tm_year = simulated_year - 1900;

    //Ask user to input the simulated month
    int simulated_month;
    printf("Enter the month you would like to simulate: ");
    scanf("%d", &simulated_month);

    //Set the simulated month
    simulated_time_info->tm_mon = simulated_month - 1;

    //Ask user to input the simulated day
    int simulated_day;
    printf("Enter the day you would like to simulate: ");
    scanf("%d", &simulated_day);

    //Set the simulated day
    simulated_time_info->tm_mday = simulated_day;

    //Ask user to input the simulated hour
    int simulated_hour;
    printf("Enter the hour you would like to simulate (in 24-hour format): ");
    scanf("%d", &simulated_hour);

    //Set the simulated hour
    simulated_time_info->tm_hour = simulated_hour;

    //Ask user to input the simulated minute
    int simulated_minute;
    printf("Enter the minute you would like to simulate: ");
    scanf("%d", &simulated_minute);

    //Set the simulated minute
    simulated_time_info->tm_min = simulated_minute;

    //Set the seconds of the simulated time to be zero
    simulated_time_info->tm_sec = 0;

    //Convert the simulated time to time_t format
    simulated_time = mktime(simulated_time_info);

    //Print the simulated time
    strftime(simulated_time_buffer, sizeof(simulated_time_buffer), "%Y-%m-%d %H:%M:%S", simulated_time_info);
    printf("Simulated Date and Time: %s\n", simulated_time_buffer);

    //Calculate the difference between current time and simulated time in seconds
    int time_difference = difftime(simulated_time, current_time);

    //If the simulated time is in the past, print a message and exit
    if (time_difference < 0) {
        printf("You have travelled back in time! Please choose a time in the future.\n");
        exit(0);
    }

    //Print the time difference in hours, minutes and seconds
    int remaining_time = time_difference;
    int hours = remaining_time / 3600;
    remaining_time = remaining_time % 3600;
    int minutes = remaining_time / 60;
    remaining_time = remaining_time % 60;
    int seconds = remaining_time;

    printf("Time difference: %02d:%02d:%02d\n", hours, minutes, seconds);

    return 0;
}