//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: romantic
#include <stdio.h>
#include <time.h>

int main() {

    time_t current_time;
    struct tm *time_info;
    char time_string[9];
    
    time(&current_time);
    time_info = localtime(&current_time);
    
    strftime(time_string, sizeof(time_string), "%H%M%S", time_info);
    int current_hour = atoi(time_string); // current hour in 24-hour format
    
    printf("Welcome to the Time Travel Simulator! \n");
    printf("Would you like to travel back in time? (Yes/No)\n");

    char response[10];
    scanf("%s", response);
    
    if (response[0] == 'Y' || response[0] == 'y') {
        
        printf("Please select a year to travel to:\n");
        int year;
        scanf("%d", &year);
        
        printf("Please select a month to travel to (1-12):\n");
        int month;
        scanf("%d", &month);
        
        printf("Please select a day to travel to (1-31):\n");
        int day;
        scanf("%d", &day);
        
        printf("Please select an hour to travel to (0-23):\n");
        int hour;
        scanf("%d", &hour);
        
        int valid_year = (year >= 0 && year <= 9999);
        int valid_month = (month >= 1 && month <= 12);
        int valid_day = (day >= 1 && day <= 31);
        int valid_hour = (hour >= 0 && hour <= 23);
        
        if (valid_year && valid_month && valid_day && valid_hour) {
            
            int year_diff = time_info->tm_year + 1900 - year;
            int month_diff = time_info->tm_mon + 1 - month;
            int day_diff = time_info->tm_mday - day;
            int hour_diff = current_hour - hour;
            
            printf("\nYou are now in the year %d, month %d, day %d, hour %d.\n", year, month, day, hour);
            printf("You traveled %d years, %d months, %d days, and %d hours back in time.\n", year_diff, month_diff, day_diff, hour_diff);
            printf("Enjoy your journey!\n");
            
        } else {
            
            printf("\nInvalid input. Please try again.\n");
        }
        
    } else {
        
        printf("Thank you for using the Time Travel Simulator. Goodbye!\n");
    }
    
    return 0;
}