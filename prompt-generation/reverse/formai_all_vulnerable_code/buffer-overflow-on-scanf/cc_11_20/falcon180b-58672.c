//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    srand(time(NULL));
    int choice;
    double time_speed;
    int time_travel_duration;
    int year, month, day;
    int current_year, current_month, current_day;
    int destination_year, destination_month, destination_day;
    int time_travel_days;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please choose a time travel speed:\n1. Slow\n2. Medium\n3. Fast\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            time_speed = 1;
            break;
        case 2:
            time_speed = 10;
            break;
        case 3:
            time_speed = 100;
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    printf("Please choose a time travel duration (in days):\n");
    scanf("%d", &time_travel_duration);

    printf("Please choose a destination year:\n");
    scanf("%d", &destination_year);

    printf("Please choose a destination month (1-12):\n");
    scanf("%d", &destination_month);

    printf("Please choose a destination day (1-31):\n");
    scanf("%d", &destination_day);

    time_travel_days = time_travel_duration * time_speed;
    current_year = 2021;
    current_month = 1;
    current_day = 1;

    while(time_travel_days > 0) {
        year = current_year;
        month = current_month;
        day = current_day;

        if(destination_year < year) {
            printf("You cannot travel to a year before your current year.\n");
            return 1;
        }

        if(destination_year == year && destination_month < month) {
            printf("You cannot travel to a month before your current month.\n");
            return 1;
        }

        if(destination_year == year && destination_month == month && destination_day < day) {
            printf("You cannot travel to a day before your current day.\n");
            return 1;
        }

        if(destination_year == year && destination_month == month && destination_day == day) {
            printf("You have arrived at your destination!\n");
            return 0;
        }

        current_day++;

        if(current_day > 31) {
            current_day = 1;
            current_month++;

            if(current_month > 12) {
                current_month = 1;
                current_year++;
            }
        }

        time_travel_days--;
    }

    printf("Time travel failed.\n");
    return 1;
}