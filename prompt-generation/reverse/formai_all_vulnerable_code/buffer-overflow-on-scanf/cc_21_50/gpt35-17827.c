//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: rigorous
#include<stdio.h>

int main()
{
    int battery_level = 100;
    int throttle = 0;
    int pitch = 0;
    int roll = 0;
    int yaw = 0;
    int altitude = 0;

    printf("*********Welcome to the C Drone Remote Control*********\n\n");

    while(1)
    {
        printf("Current Battery Level: %d%%\n", battery_level);
        printf("Choose your operation:\n");
        printf("1. Increase throttle\n");
        printf("2. Decrease throttle\n");
        printf("3. Pitch forward\n");
        printf("4. Pitch backward\n");
        printf("5. Roll right\n");
        printf("6. Roll left\n");
        printf("7. Yaw right\n");
        printf("8. Yaw left\n");
        printf("9. Increase altitude\n");
        printf("10. Decrease altitude\n");
        printf("11. Exit program\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(throttle < 100)
                {
                    throttle += 10;
                    printf("Throttle increased by 10\n");
                }
                break;

            case 2:
                if(throttle > 0)
                {
                    throttle -= 10;
                    printf("Throttle decreased by 10\n");
                }
                break;

            case 3:
                if(pitch < 10)
                {
                    pitch += 1;
                    printf("Pitch increased by 1\n");
                }
                break;

            case 4:
                if(pitch > -10)
                {
                    pitch -= 1;
                    printf("Pitch decreased by 1\n");
                }
                break;

            case 5:
                if(roll < 10)
                {
                    roll += 1;
                    printf("Roll increased by 1\n");
                }
                break;

            case 6:
                if(roll > -10)
                {
                    roll -= 1;
                    printf("Roll decreased by 1\n");
                }
                break;

            case 7:
                if(yaw < 10)
                {
                    yaw += 1;
                    printf("Yaw increased by 1\n");
                }
                break;

            case 8:
                if(yaw > -10)
                {
                    yaw -= 1;
                    printf("Yaw decreased by 1\n");
                }
                break;

            case 9:
                if(altitude < 100)
                {
                    altitude += 10;
                    printf("Altitude increased by 10\n");
                }
                break;

            case 10:
                if(altitude > 0)
                {
                    altitude -= 10;
                    printf("Altitude decreased by 10\n");
                }
                break;

            case 11:
                printf("Exiting program\n");
                return 0;

            default:
                printf("Invalid choice\n");
                break;
        }

        battery_level -= 1;   // reduce battery level by 1 with each operation

        if(battery_level == 0)
        {
            printf("Battery level exhausted. Exiting program\n");
            return 0;
        }

        printf("Current status:\n");
        printf("Throttle: %d%%\n", throttle);
        printf("Pitch: %d\n", pitch);
        printf("Roll: %d\n", roll);
        printf("Yaw: %d\n", yaw);
        printf("Altitude: %d metres\n\n", altitude);
    }

    return 0;
}