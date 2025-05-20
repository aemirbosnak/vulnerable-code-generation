//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: surprised
#include<stdio.h>
#include<time.h>

int main(){

    time_t now = time(NULL); // get the current timestamp
    struct tm *t = localtime(&now); // convert timestamp to struct tm

    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("Current date and time: %s", asctime(t));

    int year, month, day, hour, minute, second;

    printf("\nEnter the year you want to travel to: ");
    scanf("%d", &year);

    printf("Enter the month you want to travel to: ");
    scanf("%d", &month);

    printf("Enter the day you want to travel to: ");
    scanf("%d", &day);

    printf("Enter the hour you want to travel to: ");
    scanf("%d", &hour);

    printf("Enter the minute you want to travel to: ");
    scanf("%d", &minute);

    printf("Enter the second you want to travel to: ");
    scanf("%d", &second);

    struct tm travel_time = {0}; // create a struct tm for the travel time
    travel_time.tm_year = year - 1900; // set the year (years since 1900)
    travel_time.tm_mon = month - 1; // set the month (0-11)
    travel_time.tm_mday = day; // set the day (1-31)
    travel_time.tm_hour = hour; // set the hour (0-23)
    travel_time.tm_min = minute; // set the minute (0-59)
    travel_time.tm_sec = second; // set the second (0-59)

    time_t travel_timestamp = mktime(&travel_time); // convert struct tm to timestamp

    printf("\nTraveling to %s", asctime(&travel_time));

    while(now < travel_timestamp){
        now = time(NULL); // update current timestamp
    }

    printf("\nYou have arrived at %s", asctime(&travel_time));

    return 0;
}