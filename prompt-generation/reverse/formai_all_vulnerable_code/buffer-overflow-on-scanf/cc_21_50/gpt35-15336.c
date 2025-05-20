//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main(){
    int year, month, day, hour, minute;
    printf("Enter the year (YYYY): ");
    scanf("%d", &year);
    printf("Enter the month (MM): ");
    scanf("%d", &month);
    printf("Enter the day (DD): ");
    scanf("%d", &day);
    printf("Enter the hour (HH): ");
    scanf("%d", &hour);
    printf("Enter the minute (MM): ");
    scanf("%d", &minute);

    if(year < 0 || month < 1 || month > 12 || day < 1 || day > 31 || hour < 0 || hour > 23 || minute < 0 || minute > 59){
        printf("Invalid date or time entered.\n");
        exit(0);
    }

    printf("\nThe entered date and time is: %d-%d-%d %d:%d\n", year, month, day, hour, minute);

    int time_zone;
    printf("\nEnter the number of hours you want to travel in time: ");
    scanf("%d", &time_zone);

    if(abs(time_zone) > 24){
        printf("Time travel beyond 24 hours is not possible.\n");
        exit(0);
    }

    int new_hour = hour + time_zone;
    if(new_hour < 0){
        new_hour += 24;
        day--;
    }
    else if(new_hour >= 24){
        new_hour -= 24;
        day++;
    }

    int new_month = month;
    if(day <= 0){
        if(month == 3 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
            day = 29;
        else if(month == 3)
            day = 28;
        else if(month == 5 || month == 7 || month == 10 || month == 12)
            day = 30;
        else
            day = 31;
        new_month--;
    }
    else if(day > 31){
        day = 1;
        new_month++;
    }

    if(new_month <= 0){
        year--;
        new_month += 12;
    }
    else if(new_month > 12){
        year++;
        new_month -= 12;
    }

    printf("\nAfter time travel of %d hours, the new date and time is: %d-%d-%d %d:%d\n", abs(time_zone), year, new_month, day, new_hour, minute);
    return 0;
}