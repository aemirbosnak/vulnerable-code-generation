//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Define variables
    double mass, velocity, acceleration, time, distance, force;
    int choice;

    // Menu options
    printf("\nWelcome to the Digital Diary!\n");
    printf("Please select an option:\n");
    printf("1. Calculate force\n");
    printf("2. Calculate distance\n");
    printf("3. Calculate time\n");
    printf("4. Calculate velocity\n");
    printf("Enter your choice: ");

    // Get user input
    scanf("%d", &choice);

    // Switch case to handle user input
    switch (choice)
    {
        case 1:
            printf("Enter the mass of the object: ");
            scanf("%lf", &mass);
            printf("Enter the velocity of the object: ");
            scanf("%lf", &velocity);
            acceleration = mass * velocity * velocity / 9.8;
            printf("The acceleration of the object is: %.2lf m/s^2\n", acceleration);
            break;

        case 2:
            printf("Enter the acceleration of the object: ");
            scanf("%lf", &acceleration);
            time = acceleration * mass / 9.8;
            printf("The time taken for the object to reach a distance of 1 meter is: %.2lf seconds\n", time);
            break;

        case 3:
            printf("Enter the mass of the object: ");
            scanf("%lf", &mass);
            printf("Enter the force applied to the object: ");
            scanf("%lf", &force);
            time = force * mass / 9.8;
            printf("The time taken for the object to reach a velocity of 1 m/s is: %.2lf seconds\n", time);
            break;

        case 4:
            printf("Enter the mass of the object: ");
            scanf("%lf", &mass);
            printf("Enter the time taken for the object to travel a distance of 1 meter: ");
            scanf("%lf", &time);
            velocity = mass * time * acceleration / 9.8;
            printf("The velocity of the object is: %.2lf m/s\n", velocity);
            break;

        default:
            printf("Invalid input. Please try again.\n");
    }

    return 0;
}