//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: protected
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int choice,speed,distance,angle;
    char repeat;
    while(1)
    {
        system("clear");
        printf("\n\n\t\t\t\tRemote Control Vehicle Simulation\n");
        printf("\n\n\t\t\t\t1. Forward\n");
        printf("\n\t\t\t\t2. Backward\n");
        printf("\n\t\t\t\t3. Left\n");
        printf("\n\t\t\t\t4. Right\n");
        printf("\n\t\t\t\t5. Stop\n");
        printf("\n\n\t\t\t\tEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\n\n\t\t\t\tEnter the speed (0-10): ");
                scanf("%d",&speed);
                printf("\n\n\t\t\t\tEnter the distance (in meters): ");
                scanf("%d",&distance);
                printf("\n\n\t\t\t\tVehicle is moving forward at %d meters/second for %d meters.\n",speed,distance);
                break;

            case 2:
                printf("\n\n\t\t\t\tEnter the speed (0-10): ");
                scanf("%d",&speed);
                printf("\n\n\t\t\t\tEnter the distance (in meters): ");
                scanf("%d",&distance);
                printf("\n\n\t\t\t\tVehicle is moving backward at %d meters/second for %d meters.\n",speed,distance);
                break;

            case 3:
                printf("\n\n\t\t\t\tEnter the angle (in degrees): ");
                scanf("%d",&angle);
                printf("\n\n\t\t\t\tVehicle is turning left at an angle of %d degrees.\n",angle);
                break;

            case 4:
                printf("\n\n\t\t\t\tEnter the angle (in degrees): ");
                scanf("%d",&angle);
                printf("\n\n\t\t\t\tVehicle is turning right at an angle of %d degrees.\n",angle);
                break;

            case 5:
                printf("\n\n\t\t\t\tVehicle has stopped.\n");
                break;

            default:
                printf("\n\n\t\t\t\tInvalid choice. Please try again.\n");
        }
        printf("\n\n\t\t\t\tDo you want to continue? (y/n): ");
        scanf(" %c",&repeat);
        if(repeat=='n' || repeat=='N')
        {
            break;
        }
    }
    return 0;
}