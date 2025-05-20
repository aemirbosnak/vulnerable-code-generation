//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: genious
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define pi 3.14159265358979323846
int main()
{
    int choice, start, end, distance;
    int newspeed, speed, time, timetaken, left;
    float fuel, fuelrate;

    printf("\nWelcome to the GPS Navigation Simulator\n");
    printf("=======================================\n");
    printf("Please select from the following options:\n");
    printf("1) Calculate distance between two points\n");
    printf("2) Calculate estimated travel time\n");

    scanf("%d", &choice);

    if(choice==1)
    {
        printf("\nEnter the starting point: ");
        scanf("%d", &start);
        printf("Enter the ending point: ");
        scanf("%d", &end);
        distance=end-start;
        printf("The distance between points %d and %d is %d miles.\n", start, end, abs(distance));
    }
    else if(choice==2)
    {
        printf("\nEnter the starting point: ");
        scanf("%d", &start);
        printf("Enter the ending point: ");
        scanf("%d", &end);
        distance=end-start;
        printf("The distance between points %d and %d is %d miles.\n", start, end, abs(distance));

        printf("\nEnter your current speed (in mph): ");
        scanf("%d", &speed);
        printf("Enter the new speed limit for upcoming route (in mph): ");
        scanf("%d", &newspeed);

        if(speed>newspeed)
        {
            printf("\nHey, slow down a bit! The speed limit on this route is %d mph.", newspeed);
        }

        printf("\nEnter your fuel rate (in gallons per hour): ");
        scanf("%f", &fuelrate);
        timetaken=distance/speed;
        printf("\nEstimated travel time: %d hours", timetaken);
        fuel=fuelrate*timetaken;
        printf("\nEstimated fuel required: %.2f gallons", fuel);

        left=fuel*(rand()%5+1);

        if(left>0)
            printf("\nYou will have %.2f gallons of fuel left when you reach your destination.", left);
        else
            printf("\nOops! Looks like you might run out of fuel before reaching your destination. Plan to refuel accordingly!");
    }
    else
    {
        printf("\nInvalid choice. Please try again.");
    }

    printf("\nThank you for using the GPS Navigation Simulator!");
    printf("\n=================================================");

    return 0;
}