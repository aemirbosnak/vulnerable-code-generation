//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice;
    time_t current_time;
    struct tm *time_info;
    char time_str[30];

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please choose a year to travel back to:\n");
    printf("1. 1950\n2. 1980\n3. 2000\n4. 2010\n5. Enter a specific year\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Traveling back to 1950...\n");
            current_time = time(NULL);
            time_info = localtime(&current_time);
            time_info->tm_year = 1950 - 1900;
            mktime(time_info);
            strftime(time_str, sizeof(time_str), "%Y", time_info);
            printf("You have arrived in the year %s!\n", time_str);
            break;

        case 2:
            printf("Traveling back to 1980...\n");
            current_time = time(NULL);
            time_info = localtime(&current_time);
            time_info->tm_year = 1980 - 1900;
            mktime(time_info);
            strftime(time_str, sizeof(time_str), "%Y", time_info);
            printf("You have arrived in the year %s!\n", time_str);
            break;

        case 3:
            printf("Traveling back to 2000...\n");
            current_time = time(NULL);
            time_info = localtime(&current_time);
            time_info->tm_year = 2000 - 1900;
            mktime(time_info);
            strftime(time_str, sizeof(time_str), "%Y", time_info);
            printf("You have arrived in the year %s!\n", time_str);
            break;

        case 4:
            printf("Traveling back to 2010...\n");
            current_time = time(NULL);
            time_info = localtime(&current_time);
            time_info->tm_year = 2010 - 1900;
            mktime(time_info);
            strftime(time_str, sizeof(time_str), "%Y", time_info);
            printf("You have arrived in the year %s!\n", time_str);
            break;

        case 5:
            printf("Please enter a year to travel back to (1900-2021): ");
            int year;
            scanf("%d", &year);
            if (year < 1900 || year > 2021)
            {
                printf("Sorry, that year is out of range.\n");
                exit(1);
            }
            printf("Traveling back to %d...\n", year);
            current_time = time(NULL);
            time_info = localtime(&current_time);
            time_info->tm_year = year - 1900;
            mktime(time_info);
            strftime(time_str, sizeof(time_str), "%Y", time_info);
            printf("You have arrived in the year %s!\n", time_str);
            break;

        default:
            printf("Invalid choice.\n");
            exit(1);
    }

    return 0;
}