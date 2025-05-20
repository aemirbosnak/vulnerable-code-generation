//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: enthusiastic
#include <stdio.h>

int main() 
{
    printf("Welcome to the ultimate C drone remote control program!\n");

    // Initialize drone variables
    int batteryLife = 100;
    int altitude = 0;
    int heading = 0;
    int speed = 0;

    // User input loop
    while (1) {
        printf("What would you like to do with your drone?\n");
        printf("1. Increase altitude\n");
        printf("2. Decrease altitude\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Increase speed\n");
        printf("6. Decrease speed\n");
        printf("7. Check battery life\n");
        printf("8. End the flight\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Increasing altitude...\n");
                altitude += 10;
                break;
            case 2:
                printf("Decreasing altitude...\n");
                if (altitude >= 10) {
                    altitude -= 10;
                } else {
                    printf("Cannot descend further.\n");
                }
                break;
            case 3:
                printf("Turning left...\n");
                heading -= 10;
                break;
            case 4:
                printf("Turning right...\n");
                heading += 10;
                break;
            case 5:
                printf("Increasing speed...\n");
                speed += 10;
                break;
            case 6:
                printf("Decreasing speed...\n");
                if (speed >= 10) {
                    speed -= 10;
                } else {
                    printf("Cannot slow down further.\n");
                }
                break;
            case 7:
                printf("Checking battery life... %d %%\n", batteryLife);
                break;
            case 8:
                printf("Ending flight...\n");
                printf("Final altitude: %d feet\n", altitude);
                printf("Final heading: %d degrees\n", heading);
                printf("Final speed: %d mph\n", speed);
                printf("Final battery life: %d %%\n", batteryLife);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        // Simulate battery drain
        batteryLife -= (speed/10 + altitude/100);
        
        if (batteryLife <= 0) {
            printf("Battery exhausted. Returning to home.\n");
            altitude = 0;
            heading = 0;
            speed = 0;
            break;
        }

        printf("Current altitude: %d feet\n", altitude);
        printf("Current heading: %d degrees\n", heading);
        printf("Current speed: %d mph\n", speed);
        printf("Remaining battery life: %d %%\n", batteryLife);
    }
    return 0;
}