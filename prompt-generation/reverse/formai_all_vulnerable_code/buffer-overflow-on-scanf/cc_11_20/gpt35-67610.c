//FormAI DATASET v1.0 Category: Smart home light control ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int lightPower = 0;
    int roomTemp = 20;
    int motionDetected = 0;
    int timeOfDay = 0; // 0 = day, 1 = night
    int userAction;

    printf("Welcome to the Smart Home Light Control System\n");

    while(1) {
        printf("Current Light Power: %d%%\n", lightPower);
        printf("Current Room Temperature: %d°C\n", roomTemp);

        if(motionDetected) {
            printf("Motion detected!\n");
        }

        if(timeOfDay == 0) {
            printf("It is currently day time.\n");
        } else {
            printf("It is currently night time.\n");
        }

        printf("What would you like to do?\n");
        printf("1. Increase Light Power\n");
        printf("2. Decrease Light Power\n");
        printf("3. Set Night Mode\n");
        printf("4. Set Day Mode\n");
        printf("5. Turn On Motion Sensor\n");
        printf("6. Turn Off Motion Sensor\n");
        printf("7. Exit\n");

        scanf("%d", &userAction);

        switch(userAction) {
            case 1:
                if(lightPower < 100) {
                    lightPower += 10;
                }
                break;
            case 2:
                if(lightPower > 0) {
                    lightPower -= 10;
                }
                break;
            case 3:
                timeOfDay = 1;
                break;
            case 4:
                timeOfDay = 0;
                break;
            case 5:
                motionDetected = 1;
                break;
            case 6:
                motionDetected = 0;
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid input. Please try again.\n");
        }

        if(timeOfDay == 1) {
            roomTemp -= 1;
        } else {
            roomTemp += 1;
        }

        if(lightPower == 0) {
            printf("Light turned off.\n");
        } else if(lightPower < 30) {
            printf("Light is dimmed.\n");
        } else {
            printf("Light is bright.\n");
        }

        if(roomTemp > 25) {
            printf("Room is warm.\n");
        } else if(roomTemp < 15) {
            printf("Room is cold.\n");
        } else {
            printf("Room is comfortable.\n");
        }
    }

    return 0;
}