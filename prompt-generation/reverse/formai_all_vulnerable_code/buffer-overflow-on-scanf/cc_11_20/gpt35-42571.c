//FormAI DATASET v1.0 Category: Smart home automation ; Style: calm
#include <stdio.h>
#include <stdbool.h>

int main() {
    bool isLightsOn = false;
    bool isFanOn = false;
    bool isACOn = false;
    bool isTVOn = false;

    int userChoice;
    do {
        printf("Please select an option: \n");
        printf("1. Turn lights on/off \n");
        printf("2. Turn fan on/off \n");
        printf("3. Turn AC on/off \n");
        printf("4. Turn TV on/off \n");
        printf("5. Exit \n");

        scanf("%d", &userChoice);

        switch(userChoice) {
            case 1:
                if(isLightsOn) {
                    printf("Turning lights off \n");
                    isLightsOn = false;
                } else {
                    printf("Turning lights on \n");
                    isLightsOn = true;
                }
                break;
            case 2:
                if(isFanOn) {
                    printf("Turning fan off \n");
                    isFanOn = false;
                } else {
                    printf("Turning fan on \n");
                    isFanOn = true;
                }
                break;
            case 3:
                if(isACOn) {
                    printf("Turning AC off \n");
                    isACOn = false;
                } else {
                    printf("Turning AC on \n");
                    isACOn = true;
                }
                break;
            case 4:
                if(isTVOn) {
                    printf("Turning TV off \n");
                    isTVOn = false;
                } else {
                    printf("Turning TV on \n");
                    isTVOn = true;
                }
                break;
            case 5:
                printf("Exiting program \n");
                break;
            default:
                printf("Invalid input \n");
        }
    } while(userChoice != 5);

    return 0;
}