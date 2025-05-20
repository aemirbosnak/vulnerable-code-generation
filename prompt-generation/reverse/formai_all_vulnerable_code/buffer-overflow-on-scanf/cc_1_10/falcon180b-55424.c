//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int year, month, day, hour, minute, second;
    int time_travel_year, time_travel_month, time_travel_day, time_travel_hour, time_travel_minute, time_travel_second;
    int destination_year, destination_month, destination_day, destination_hour, destination_minute, destination_second;
    int i;
    char input[100];

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter the current date and time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", input);
    sscanf(input, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);

    printf("Please enter the year you want to travel to: ");
    scanf("%d", &time_travel_year);
    printf("Please enter the month you want to travel to (1-12): ");
    scanf("%d", &time_travel_month);
    printf("Please enter the day you want to travel to (1-31): ");
    scanf("%d", &time_travel_day);
    printf("Please enter the hour you want to travel to (0-23): ");
    scanf("%d", &time_travel_hour);
    printf("Please enter the minute you want to travel to (0-59): ");
    scanf("%d", &time_travel_minute);
    printf("Please enter the second you want to travel to (0-59): ");
    scanf("%d", &time_travel_second);

    printf("Please enter the destination date and time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", input);
    sscanf(input, "%d-%d-%d %d:%d:%d", &destination_year, &destination_month, &destination_day, &destination_hour, &destination_minute, &destination_second);

    time_t current_time = mktime(localtime(&second));
    time_t travel_time = mktime(localtime(&time_travel_second));
    time_t destination_time = mktime(localtime(&destination_second));

    while (current_time < travel_time) {
        printf("Traveling through time...\n");
        current_time = mktime(localtime(&second));
    }

    while (current_time < destination_time) {
        printf("Arriving at destination time...\n");
        current_time = mktime(localtime(&second));
    }

    printf("You have arrived at %d-%d-%d %d:%d:%d\n", destination_year, destination_month, destination_day, destination_hour, destination_minute, destination_second);

    return 0;
}