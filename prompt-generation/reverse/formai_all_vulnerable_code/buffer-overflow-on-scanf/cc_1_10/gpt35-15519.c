//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int option, steps_per_day;
    float calories_burned, distance_covered;

    printf("\n Welcome to C Fitness Tracker \n");
    printf("\n 1. Calculate calories burned");
    printf("\n 2. Calculate distance covered");
    printf("\n 3. Calculate steps per day");
    printf("\n 4. Exit");

    while(1)
    {
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\n Enter number of minutes worked out: ");
                int minutes;
                scanf("%d", &minutes);

                calories_burned = minutes * 6.2; // Average calories burnt per minute
                printf("\n You have burned %.2f calories\n", calories_burned);
                break;

            case 2:
                printf("\n Enter number of steps taken: ");
                scanf("%d", &steps_per_day);

                distance_covered = steps_per_day * 0.000762; // Average distance per step (in miles)
                printf("\n You have covered a distance of %.2f miles\n", distance_covered);
                break;

            case 3:
                printf("\n Enter number of steps taken today: ");
                scanf("%d", &steps_per_day);

                printf("\n You have taken %d steps today\n", steps_per_day);
                break;

            case 4:
                printf("\n Exiting C Fitness Tracker");
                exit(0);
                break;

            default:
                printf("\n Invalid option, please try again");
                break;
        }
    }
    return 0;
}