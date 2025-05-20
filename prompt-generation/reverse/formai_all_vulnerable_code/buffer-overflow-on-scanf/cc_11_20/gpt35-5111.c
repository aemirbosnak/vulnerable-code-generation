//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t current_time;
    time(&current_time);
    struct tm *now = localtime(&current_time);
    srand(time(NULL));
    int year = 1900 + now->tm_year; //Get current year
    int month = now->tm_mon + 1; //Get current month
    int day = now->tm_mday; //Get current day
    int hour = now->tm_hour; //Get current hour
    int minute = now->tm_min; //Get current minute
    int second = now->tm_sec; //Get current second

    printf("Welcome to the Time Travel Simulator!\n");
    printf("The current date and time is: %d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second);

    printf("\n\nWhere would you like to go today?\n");
    printf("Choose a year from the past (1900-2019): ");
    int travel_year;
    scanf("%d",&travel_year);
    printf("Choose a month (1-12): ");
    int travel_month;
    scanf("%d",&travel_month);
    printf("Choose a day (1-31): ");
    int travel_day;
    scanf("%d",&travel_day);
    printf("Choose an hour (0-23): ");
    int travel_hour;
    scanf("%d",&travel_hour);
    printf("Choose a minute (0-59): ");
    int travel_minute;
    scanf("%d",&travel_minute);
    printf("Choose a second (0-59): ");
    int travel_second;
    scanf("%d",&travel_second);

    printf("\n\nYou have chosen to travel to: %d-%02d-%02d %02d:%02d:%02d\n", travel_year, travel_month, travel_day, travel_hour, travel_minute, travel_second);

    if(travel_year > year){
        printf("\nUnfortunately, time travel is not possible to the future yet.\n");
        printf("Please choose a year in the past from 1900 to %d.\n", year);
    }
    else if(travel_year < 1900){
        printf("\nYou have chosen a date earlier than 1900.\n");
        printf("Unfortunately, we do not have the technology to travel back that far yet.\n");
    }
    else{
        printf("\n\nPreparing to travel through time...\n");
        int i;
        for(i=0; i<5; i++){
            printf("...");
            sleep(1);
        }
        printf("\n\nTime travel successful!\n");
        printf("You have arrived at: %d-%02d-%02d %02d:%02d:%02d\n", travel_year, travel_month, travel_day, travel_hour, travel_minute, travel_second);

        if(travel_year == year && travel_month == month && travel_day == day){
            printf("You have arrived at the same date as the present time.\n");
            printf("Time travelers must take precaution not to disturb the present timeline.\n");
        }
        else if(travel_year < year){
            printf("It is %d years before your present time.\n", year-travel_year);
        }
        else{
            printf("It is %d years after your present time.\n", travel_year-year);
        }

        //Random events
        int event_chance = rand()%10; //Generate random number between 0 and 9
        if(event_chance > 7 && travel_year != year){
            printf("\n\nWARNING: AN ANACHRONISM HAS OCCURRED!\n");
            printf("An unexpected event has taken place in this timeline.\n");
            printf("Please be cautious and make sure your actions do not affect the present.\n");
        }
        else if(event_chance <= 7 && travel_year != year){
            printf("\n\nYou have arrived at a peaceful time in history.\n");
            printf("Enjoy your stay!\n");
        }
        else{
            printf("\n\nYou have arrived at the same date as the present time.\n");
            printf("Time travelers must take precaution not to disturb the present timeline.\n");
        }

        //Goodbye message
        printf("\n\nThank you for using the Time Travel Simulator.\n");
        printf("We hope you had a great experience visiting the past.\n");
        printf("Goodbye!\n");
    }

    return 0;
}