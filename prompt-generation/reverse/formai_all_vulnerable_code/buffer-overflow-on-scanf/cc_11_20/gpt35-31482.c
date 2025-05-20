//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Introduction
    printf("Welcome to the appointment scheduler, fair user!\n");
    printf("What is your name, dearest?\n");
    
    // Input name of user
    char name[20];
    scanf("%s", name);
    printf("\nAh, %s, a name as fair as a rose in bloom!\n", name);
    printf("And what may we do for you today?\n");

    // Input appointment date and time
    int month, day, year, hour;
    printf("\nPlease enter the month of your desired appointment (1-12):\n");
    scanf("%d", &month);
    printf("Please enter the day of your desired appointment (1-31):\n");
    scanf("%d", &day);
    printf("Please enter the year of your desired appointment (e.g. 2021):\n");
    scanf("%d", &year);
    printf("Please enter the hour of your desired appointment (0-23):\n");
    scanf("%d", &hour);
    printf("\nThank you for choosing the Capulet appointment scheduler, %s. ", name);

    // Check if appointment is valid
    time_t now = time(0);
    struct tm *tm = localtime(&now);
    int current_month = tm->tm_mon + 1;
    int current_day = tm->tm_mday;
    int current_year = tm->tm_year + 1900;
    int current_hour = tm->tm_hour;

    if (year < current_year || (year == current_year && month < current_month) || (year == current_year && month == current_month && day < current_day))
    {
        printf("Alas! That appointment has already passed. Please select another date and time.\n");
        return 0;
    }

    if (year == current_year && month == current_month && day == current_day && hour <= current_hour)
    {
        printf("Alack! That appointment has already passed. Please select another date and time.\n");
        return 0;
    }

    // Appointment scheduled successfully
    printf("\nHark! Your appointment with the fair Romeo has been scheduled for %d/%d/%d at %d:00.\n", month, day, year, hour);
    printf("Thou art a valued patron, %s. May thy day be bright as the sun!\n", name);

    return 0;
}