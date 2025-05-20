//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: calm
#include<stdio.h>
#include<time.h>

int main(){
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    int day_of_week, day_of_month, month, year, hour, minute, second;
    
    printf("Welcome to the Time Travel Simulator\n");
    printf("Please enter the year you would like to travel to: ");
    scanf("%d", &year);
    printf("Please enter the month you would like to travel to: ");
    scanf("%d", &month);
    printf("Please enter the day of the month you would like to travel to: ");
    scanf("%d", &day_of_month);
    printf("Please enter the hour you would like to travel to: ");
    scanf("%d", &hour);
    printf("Please enter the minute you would like to travel to: ");
    scanf("%d", &minute);
    printf("Please enter the second you would like to travel to: ");
    scanf("%d", &second);
    
    int year_diff = year - (tm_now->tm_year + 1900);
    int month_diff = month - (tm_now->tm_mon + 1);
    int day_of_month_diff = day_of_month - tm_now->tm_mday;
    int hour_diff = hour - tm_now->tm_hour;
    int minute_diff = minute - tm_now->tm_min;
    int second_diff = second - tm_now->tm_sec;
    
    int total_seconds = second_diff + minute_diff*60 + hour_diff*3600 + day_of_month_diff*86400 + month_diff*2592000 + year_diff*31536000;
    
    printf("You will be traveling %d seconds into the future\n", total_seconds);
    
    time_t future_time = now + total_seconds;
    struct tm *tm_future = localtime(&future_time);
    char day_of_week_str[10];
    
    switch(tm_future->tm_wday){
        case 0:
            strcpy(day_of_week_str, "Sunday");
            break;
        case 1:
            strcpy(day_of_week_str, "Monday");
            break;
        case 2:
            strcpy(day_of_week_str, "Tuesday");
            break;
        case 3:
            strcpy(day_of_week_str, "Wednesday");
            break;
        case 4:
            strcpy(day_of_week_str, "Thursday");
            break;
        case 5:
            strcpy(day_of_week_str, "Friday");
            break;
        case 6:
            strcpy(day_of_week_str, "Saturday");
            break;
        default:
            break;
    }
    
    printf("The date and time you will be traveling to is: %s %02d/%02d/%d %02d:%02d:%02d\n", day_of_week_str, tm_future->tm_mday, tm_future->tm_mon+1, tm_future->tm_year+1900, tm_future->tm_hour, tm_future->tm_min, tm_future->tm_sec);
    
    return 0;
}