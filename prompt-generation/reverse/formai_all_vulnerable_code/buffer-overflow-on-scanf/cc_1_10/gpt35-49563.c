//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t now;
    struct tm *today;

    time(&now);
    today = localtime(&now);
	
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Today's date and time is: %s\n", asctime(today));
    printf("Choose a time period to travel to:\n");
    printf("1. The prehistoric era\n");
    printf("2. The medieval times\n");
    printf("3. The Wild West\n");
    printf("4. The future\n");
    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("\nTravelling to the prehistoric era...\n");
            today->tm_year -= 300000;
            break;
        case 2:
            printf("\nTravelling to the medieval times...\n");
            today->tm_year -= 700;
            break;
        case 3:
            printf("\nTravelling to the Wild West...\n");
            today->tm_year += 200;
            today->tm_mon = 6;
            today->tm_mday = 4;
            break;
        case 4:
            printf("\nTravelling to the future...\n");
            today->tm_year += 100;
            break;
        default:
            printf("Invalid choice. Exiting...\n");
            return -1;
    }

    time_t travel_time = mktime(today);
    struct tm *travel_date = localtime(&travel_time);

    printf("You have arrived at your destination on %s\n", asctime(travel_date));

    return 0;
}