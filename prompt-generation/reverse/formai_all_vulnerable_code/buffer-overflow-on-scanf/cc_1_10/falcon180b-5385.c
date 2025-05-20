//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVEL 10
#define TIME_TRAVEL_SUCCESS 0
#define TIME_TRAVEL_FAILURE -1

int main()
{
    int choice, result;
    struct tm time_travel_dates[MAX_TIME_TRAVEL];
    char date_string[80];

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter your choice:\n");
    printf("1. Set time travel date\n");
    printf("2. Travel through time\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter the date in the format YYYY-MM-DD HH:MM:SS\n");
            scanf("%s", date_string);
            result = strptime(date_string, "%Y-%m-%d %H:%M:%S", &time_travel_dates[0]);

            if(result == NULL)
            {
                printf("Invalid date format!\n");
            }
            else
            {
                printf("Time travel date set successfully!\n");
            }

            break;

        case 2:
            printf("Enter the destination year\n");
            scanf("%d", &result);

            if(result < 0 || result > 9999)
            {
                printf("Invalid year!\n");
            }
            else
            {
                printf("Time travel initiated...\n");
                srand(time(NULL));
                int random_year = rand() % (9999 - 0 + 1) + 0;

                if(random_year == result)
                {
                    printf("Time travel successful! You have reached the year %d.\n", result);
                }
                else
                {
                    printf("Time travel failed! You have reached the year %d instead.\n", random_year);
                }
            }

            break;

        case 3:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}