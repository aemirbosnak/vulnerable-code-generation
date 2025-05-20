//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year, month, day, hour, min, sec, year2, month2, day2, hour2, min2, sec2;
    int time_difference, choice, total_seconds, total_years, total_months, total_days, total_hours, total_min, total_sec;
    const int SECONDS_IN_MINUTE = 60, MINUTES_IN_HOUR = 60, HOURS_IN_DAY = 24, DAYS_IN_MONTH = 30, MONTHS_IN_YEAR = 12;
    const double SECONDS_IN_YEAR = 31536000, SECONDS_IN_MONTH = 2592000, SECONDS_IN_DAY = 86400, SECONDS_IN_HOUR = 3600, SECONDS_IN_MINUTE_DBL = 60.0;
    
    printf("Enter the current date and time (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &year, &month, &day, &hour, &min, &sec);
    printf("Enter the desired date and time to travel to (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &year2, &month2, &day2, &hour2, &min2, &sec2);
    
    printf("Select unit of time to calculate time difference: \n");
    printf("1. Seconds\n2. Minutes\n3. Hours\n4. Days\n5. Months\n6. Years\n");
    scanf("%d", &choice);
    
    switch (choice)
    {
        case 1:
            time_difference = (day2 - day) * SECONDS_IN_DAY + (hour2 - hour) * SECONDS_IN_HOUR + (min2 - min) * SECONDS_IN_MINUTE + (sec2 - sec);
            break;
        case 2:
            time_difference = ((day2 - day) * HOURS_IN_DAY + (hour2 - hour)) * MINUTES_IN_HOUR + (min2 - min);
            break;
        case 3:
            time_difference = (day2 - day) * HOURS_IN_DAY + (hour2 - hour);
            break;
        case 4:
            time_difference = day2 - day;
            break;
        case 5:
            time_difference = (month2 - month) * DAYS_IN_MONTH + (day2 - day);
            break;
        case 6:
            time_difference = (year2 - year) * SECONDS_IN_YEAR;
            break;
        default:
            printf("Invalid choice!");
            return 0;
    }
    
    total_seconds = time_difference;
    total_min = (int)(total_seconds / SECONDS_IN_MINUTE);
    total_sec = total_seconds % SECONDS_IN_MINUTE;
    
    total_hours = total_min / MINUTES_IN_HOUR;
    total_min = total_min % MINUTES_IN_HOUR;
    
    total_days = total_hours / HOURS_IN_DAY;
    total_hours = total_hours % HOURS_IN_DAY;
    
    total_months = total_days / DAYS_IN_MONTH;
    total_days = total_days % DAYS_IN_MONTH;
    
    total_years = total_months / MONTHS_IN_YEAR;
    total_months = total_months % MONTHS_IN_YEAR;

    printf("\nTime difference is:\n");
    switch(choice)
    {
        case 1:
            printf("%d seconds\n", time_difference);
            break;
        case 2:
            printf("%d minutes and %d seconds\n", total_min, total_sec);
            break;
        case 3:
            printf("%d hours, %d minutes and %d seconds\n", total_hours, total_min, total_sec);
            break;
        case 4:
            printf("%d days, %d hours, %d minutes and %d seconds\n", total_days, total_hours, total_min, total_sec);
            break;
        case 5:
            printf("%d months, %d days, %d hours, %d minutes and %d seconds\n", total_months, total_days, total_hours, total_min, total_sec);
            break;
        case 6:
            printf("%d years, %d months, %d days, %d hours, %d minutes and %d seconds\n", total_years, total_months, total_days, total_hours, total_min, total_sec);
            break;
    }
    
    return 0;
}