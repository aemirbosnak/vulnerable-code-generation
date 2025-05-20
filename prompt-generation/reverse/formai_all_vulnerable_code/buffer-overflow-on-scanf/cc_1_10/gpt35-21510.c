//FormAI DATASET v1.0 Category: Smart home automation ; Style: dynamic
#include <stdio.h>
#include <stdbool.h>

int main() {
    bool isHome = true;     //initiating as true because we are at home
    bool isLightsOn = false;  //initiating as false because lights are off
    bool isDoorLocked = true; //initiating as true because the door is locked
    bool isACOn = false;      //initiating as false because AC is off
    int temperature = 25;     //initiating temperature at 25 degrees Celsius

    printf("Welcome to the Smart Home Automation System\n\n");

    while(isHome) {
        printf("Please select the action you want to take:\n");
        printf("1. Turn on/off Lights\n");
        printf("2. Lock/Unlock the Door\n");
        printf("3. Turn on/off the AC\n");
        printf("4. Check Temperature\n");
        printf("5. Exit Smart Home\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(isLightsOn) {
                    printf("Turning off Lights\n");
                    isLightsOn = false;
                } else {
                    printf("Turning on Lights\n");
                    isLightsOn = true;
                }
                break;

            case 2:
                if(isDoorLocked) {
                    printf("Unlocking the Door\n");
                    isDoorLocked = false;
                } else {
                    printf("Locking the Door\n");
                    isDoorLocked = true;
                }
                break;

            case 3:
                if(isACOn) {
                    printf("Turning off the AC\n");
                    isACOn = false;
                    temperature += 5;  //Temperature increases by 5 degrees when the AC is turned off
                } else {
                    printf("Turning on the AC\n");
                    isACOn = true;
                    temperature -= 5;  //Temperature decreases by 5 degrees when the AC is turned on
                }
                break;

            case 4:
                printf("The temperature is %d degrees Celsius\n", temperature);
                break;

            case 5:
                printf("Exiting Smart Home Automation\n");
                isHome = false;
                break;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}