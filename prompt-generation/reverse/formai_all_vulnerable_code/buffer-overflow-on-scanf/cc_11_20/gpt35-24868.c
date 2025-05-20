//FormAI DATASET v1.0 Category: Smart home automation ; Style: creative
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define LIGHT_OFF 0
#define LIGHT_ON 1
#define AC_OFF 0
#define AC_ON 1

bool isLightOn = false;
bool isACOn = false;

int main() {

    printf("Welcome to Smart Home Automation System\n");

    while(true) {
        printf("Enter 1 to turn on/off light, 2 to turn on/off AC and 3 to exit: \n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(isLightOn) {
                    isLightOn = false;
                    printf("Light turned off\n");
                } else {
                    isLightOn = true;
                    printf("Light turned on\n");
                }
                break;

            case 2:
                if(isACOn) {
                    isACOn = false;
                    printf("AC turned off\n");
                } else {
                    isACOn = true;
                    printf("AC turned on\n");
                }
                break;

            case 3:
                printf("Thank you for using Smart Home Automation System\n");
                return 0;

            default:
                printf("Invalid choice, please try again\n");
        }

        // Perform the actual action of turning on/off the light and AC
        if(isLightOn == LIGHT_ON) {
            printf("Turning on the light\n");
            // Code here to turn on the light
            sleep(1);
        } else if(isLightOn == LIGHT_OFF) {
            printf("Turning off the light\n");
            // Code here to turn off the light
            sleep(1);
        }

        if(isACOn == AC_ON) {
            printf("Turning on the AC\n");
            // Code here to turn on the AC
            sleep(1);
        } else if(isACOn == AC_OFF) {
            printf("Turning off the AC\n");
            // Code here to turn off the AC
            sleep(1);
        }
    }

    return 0;
}