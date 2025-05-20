//FormAI DATASET v1.0 Category: Weather simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, temp, count, choice;
    int hours[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int temps[] = {60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71};
    int precipitation[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

    srand(time(NULL));  // Initialize random seed

    printf("Weather Forecast Simulation\n\n");

    printf("Choose a city:\n");
    printf("1. New York\n");
    printf("2. Los Angeles\n");
    printf("3. Chicago\n");
    printf("4. Houston\n");
    printf("5. Miami\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("New York Weather Forecast:\n");
            break;
        case 2:
            printf("Los Angeles Weather Forecast:\n");
            break;
        case 3:
            printf("Chicago Weather Forecast:\n");
            break;
        case 4:
            printf("Houston Weather Forecast:\n");
            break;
        case 5:
            printf("Miami Weather Forecast:\n");
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    printf("--------------------------------\n");
    printf("| Hour | Temperature | Precipitation |\n");
    printf("--------------------------------\n");

    count = rand() % 6 + 5;  // Generate a random number of hours between 5 and 10

    for(i = 0; i < count; i++)
    {
        j = rand() % 12;  // Generate a random index for the arrays

        temp = temps[j] + rand() % 6 - 2;  // Get a random temperature between -2 and +3 degrees from the mean
        if(temp < 50)
        {
            temp = 50;
        }
        if(temp > 90)
        {
            temp = 90;
        }

        printf("| %02d:00 | %02d°F | ", hours[j], temp);

        if(precipitation[j] == 1)
        {
            printf("Yes |\n");
        }
        else
        {
            printf("No |\n");
        }

    }

    return 0;
}