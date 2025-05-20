//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int battery = 100;
    int altitude = 0;
    int xPos = 0;
    int yPos = 0;
    int minAlt = 5;
    int maxAlt = 50;
    int maxRange = 100;
    int maxBattery = 100;
    int minBattery = 0;

    printf("Welcome to the C Drone Remote Control Program!\n");

    while(battery > 0) {
        int choice = 0;
        printf("\nWhat would you like to do?\n");
        printf("1. Take off\n");
        printf("2. Move\n");
        printf("3. Land\n");
        printf("4. Check Battery\n");
        printf("5. Check Altitude\n");
        printf("6. Check Position\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                if (altitude == 0) {
                    printf("Taking off...\n");
                    altitude = rand() % (maxAlt - minAlt + 1) + minAlt;
                    printf("Altitude: %d meters\n", altitude);
                }
                else {
                    printf("The drone is already in the air!\n");
                }
                break;

            case 2:
                if (altitude > 0) {
                    int distance = 0;
                    printf("How far would you like to move (max %d meters)? ", maxRange);
                    scanf("%d", &distance);

                    if (distance > maxRange) {
                        printf("The drone can't move that far.\n");
                    }
                    else if (distance > ((battery * 2) / altitude)) {
                        printf("The battery is not strong enough!\n");
                    }
                    else {
                        float xChange = ((float)distance / (float)altitude) * 100;
                        float yChange = sqrt(pow(distance, 2) - pow(xChange, 2));
                        yChange *= 100;

                        if (xChange + xPos > maxRange || yChange + yPos > maxRange) {
                            printf("The drone can't move that far.\n");
                        }
                        else {
                            xPos += xChange;
                            yPos += yChange;
                            printf("Moved %d meters\n", distance);
                            printf("New position: (%d, %d)\n", xPos, yPos);
                            battery -= (distance * altitude) / 2;
                            printf("Battery remaining: %d%%\n", battery);
                        }
                    }
                }
                else {
                    printf("The drone is not in the air!\n");
                }
                break;

            case 3:
                if (altitude > 0) {
                    printf("Landing...\n");
                    altitude = 0;
                    printf("Landed.\n");
                }
                else {
                    printf("The drone is not in the air!\n");
                }
                break;

            case 4:
                printf("Battery remaining: %d%%\n", battery);
                break;

            case 5:
                if (altitude > 0) {
                    printf("Altitude: %d meters\n", altitude);
                }
                else {
                    printf("The drone is not in the air!\n");
                }
                break;

            case 6:
                printf("Position: (%d, %d)\n", xPos, yPos);
                break;

            case 7:
                printf("Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    printf("The battery is dead. Goodbye!\n");
    return 0;
}