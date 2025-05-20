//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    time_t now; //time_t is a data type for holding system time values
    struct tm past_time, *now_time;
    int years_to_go, months_to_go, days_to_go;

    //get current time
    time(&now);

    //initialize current time
    now_time = localtime(&now);

    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("Enter the year you would like to travel to:\n");
    scanf("%d", &past_time.tm_year);

    printf("Enter the month you would like to travel to:\n");
    scanf("%d", &past_time.tm_mon);

    printf("Enter the day you would like to travel to:\n");
    scanf("%d", &past_time.tm_mday);

    //subtract the current year from the target year to find how many years are left to go:
    years_to_go = past_time.tm_year - (now_time->tm_year + 1900);

    //next, calculate the months left to go
    if (past_time.tm_mon >= (now_time->tm_mon + 1)) {
        months_to_go = past_time.tm_mon - (now_time->tm_mon + 1);
    } else {
        months_to_go = 12 - (now_time->tm_mon + 1) + past_time.tm_mon;
        years_to_go--;
    }

    //calculate the days left to go
    if (past_time.tm_mday >= now_time->tm_mday) {
        days_to_go = past_time.tm_mday - now_time->tm_mday;
    } else {
        if (months_to_go == 0) {
            months_to_go = 11;
            years_to_go--;
        } else {
            months_to_go--;
        }

        //determine how many days are left in the previous month
        int prev_month_days;
        if (now_time->tm_mon == 0 || now_time->tm_mon == 2 || now_time->tm_mon == 4 || now_time->tm_mon == 6 || now_time->tm_mon == 7 || now_time->tm_mon == 9 || now_time->tm_mon == 11) {
            prev_month_days = 31;
        } else if (now_time->tm_mon == 1) {
            if (((now_time->tm_year + 1900) % 4 == 0 && (now_time->tm_year + 1900) % 100 != 0) || (now_time->tm_year + 1900) % 400 == 0) {
                prev_month_days = 29;
            } else {
                prev_month_days = 28;
            }
        } else {
            prev_month_days = 30;
        }

        days_to_go = prev_month_days - now_time->tm_mday + past_time.tm_mday;
    }

    printf("\n\nTravelling to %d/%d/%d...\n\n", past_time.tm_mday, past_time.tm_mon, past_time.tm_year);

    printf("Days left to go: %d\n", days_to_go);
    printf("Months left to go: %d\n", months_to_go);
    printf("Years left to go: %d\n", years_to_go);

    return 0;
}