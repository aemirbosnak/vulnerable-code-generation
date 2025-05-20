//FormAI DATASET v1.0 Category: Smart home automation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdbool.h>

// Function declarations
bool isSwitchOn(char switchState);
void turnOnSwitch(char *switchState);
void turnOffSwitch(char *switchState);

// Main function
int main(){
    // Initialize switch states
    char livingRoomLight = '0';
    char fan = '0';
    char airConditioner = '0';
    char alarmSystem = '0';
    
    // Display menu
    int choice;
    do {
        printf("Welcome to Smart Home Automation\n");
        printf("1. Living Room Light: %s\n", isSwitchOn(livingRoomLight) ? "ON" : "OFF");
        printf("2. Fan: %s\n", isSwitchOn(fan) ? "ON" : "OFF");
        printf("3. Air Conditioner: %s\n", isSwitchOn(airConditioner) ? "ON" : "OFF");
        printf("4. Alarm System: %s\n", isSwitchOn(alarmSystem) ? "ON" : "OFF");
        printf("5. Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isSwitchOn(livingRoomLight)) {
                    turnOffSwitch(&livingRoomLight);
                } else {
                    turnOnSwitch(&livingRoomLight);
                }
                break;
            case 2:
                if (isSwitchOn(fan)) {
                    turnOffSwitch(&fan);
                } else {
                    turnOnSwitch(&fan);
                }
                break;
            case 3:
                if (isSwitchOn(airConditioner)) {
                    turnOffSwitch(&airConditioner);
                } else {
                    turnOnSwitch(&airConditioner);
                }
                break;
            case 4:
                if (isSwitchOn(alarmSystem)) {
                    turnOffSwitch(&alarmSystem);
                } else {
                    turnOnSwitch(&alarmSystem);
                }
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to check if a switch is on
bool isSwitchOn(char switchState) {
    return switchState == '1';
}

// Function to turn on a switch
void turnOnSwitch(char *switchState) {
    *switchState = '1';
    printf("Switch turned ON.\n");
}

// Function to turn off a switch
void turnOffSwitch(char *switchState) {
    *switchState = '0';
    printf("Switch turned OFF.\n");
}