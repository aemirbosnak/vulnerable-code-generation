//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: romantic
#include <stdio.h>
#include <math.h>

int main()
{
    float distance, speed, time;
    int choice;

    printf("**Welcome to the Romantic Unit Converter!**\n");
    printf("Please select an option:\n");
    printf("1. Miles to kilometers\n");
    printf("2. Kilometers to miles\n");
    printf("3. Speed in miles per hour to kilometers per hour\n");
    printf("4. Speed in kilometers per hour to miles per hour\n");
    printf("5. Time in hours to minutes\n");
    printf("6. Time in minutes to hours\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the distance in miles: ");
            scanf("%f", &distance);
            time = distance / 1609.22 * 3.6;
            printf("The distance in kilometers is: %.2f\n", time);
            break;
        case 2:
            printf("Enter the distance in kilometers: ");
            scanf("%f", &distance);
            time = distance * 1609.22 / 3.6;
            printf("The distance in miles is: %.2f\n", time);
            break;
        case 3:
            printf("Enter the speed in miles per hour: ");
            scanf("%f", &speed);
            time = distance / speed;
            printf("The time in hours is: %.2f\n", time);
            break;
        case 4:
            printf("Enter the speed in kilometers per hour: ");
            scanf("%f", &speed);
            time = distance * 1000 / speed;
            printf("The time in hours is: %.2f\n", time);
            break;
        case 5:
            printf("Enter the time in hours: ");
            scanf("%f", &time);
            distance = speed * time;
            printf("The distance traveled is: %.2f miles\n", distance);
            break;
        case 6:
            printf("Enter the time in minutes: ");
            scanf("%f", &time);
            distance = speed * time / 60;
            printf("The distance traveled is: %.2f miles\n", distance);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}