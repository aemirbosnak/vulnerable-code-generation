//FormAI DATASET v1.0 Category: Smart home automation ; Style: rigorous
#include <stdio.h>

// define custom data types for different automation tasks
typedef enum { OFF, ON } Power;
typedef enum { LOCKED, UNLOCKED } Lock;
typedef enum { OPEN, CLOSED } Door;
typedef enum { STOPPED, MOVING } Motor;
typedef enum { COOL, HEAT } Temperature;

// define a structure to store status of devices
struct SmartHomeStatus {
    Power light1;           // status of light 1
    Power light2;           // status of light 2
    Power fan;              // status of fan
    Lock frontdoor;         // status of front door lock
    Door frontdoor_sensor;  // status of front door sensor
    Motor blinds;           // status of blinds motor
    Temperature ac;         // status of air conditioner temperature
};

int main() {
    // initialize status of devices
    struct SmartHomeStatus status = {
        .light1 = OFF,
        .light2 = OFF,
        .fan = OFF,
        .frontdoor = LOCKED,
        .frontdoor_sensor = CLOSED,
        .blinds = STOPPED,
        .ac = COOL,
    };

    // print welcome message
    printf("Welcome to your smart home automation system!\n\n");

    // main loop to process user input
    while (1) {
        // print current status of devices
        printf("Current Status:\n");
        printf("Light 1: %s\n", status.light1 == ON ? "ON" : "OFF");
        printf("Light 2: %s\n", status.light2 == ON ? "ON" : "OFF");
        printf("Fan: %s\n", status.fan == ON ? "ON" : "OFF");
        printf("Front Door: %s\n", status.frontdoor == UNLOCKED ? "UNLOCKED" : "LOCKED");
        printf("Front Door Sensor: %s\n", status.frontdoor_sensor == OPEN ? "OPEN" : "CLOSED");
        printf("Blinds: %s\n", status.blinds == MOVING ? "MOVING" : "STOPPED");
        printf("Air Conditioner: %s\n", status.ac == COOL ? "COOL" : "HEAT");
        printf("\n");

        // print menu options
        printf("Select an option:\n");
        printf("1. Turn on Light 1\n");
        printf("2. Turn off Light 1\n");
        printf("3. Turn on Light 2\n");
        printf("4. Turn off Light 2\n");
        printf("5. Turn on Fan\n");
        printf("6. Turn off Fan\n");
        printf("7. Unlock Front Door\n");
        printf("8. Lock Front Door\n");
        printf("9. Open Front Door\n");
        printf("10. Close Front Door\n");
        printf("11. Move Blinds Up\n");
        printf("12. Move Blinds Down\n");
        printf("13. Set Air Conditioner to COOL\n");
        printf("14. Set Air Conditioner to HEAT\n");
        printf("15. Quit\n");
        printf("\n");

        // get user input
        int choice;
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                status.light1 = ON;
                printf("Light 1 turned ON.\n");
                break;

            case 2:
                status.light1 = OFF;
                printf("Light 1 turned OFF.\n");
                break;

            case 3:
                status.light2 = ON;
                printf("Light 2 turned ON.\n");
                break;

            case 4:
                status.light2 = OFF;
                printf("Light 2 turned OFF.\n");
                break;

            case 5:
                status.fan = ON;
                printf("Fan turned ON.\n");
                break;

            case 6:
                status.fan = OFF;
                printf("Fan turned OFF.\n");
                break;

            case 7:
                status.frontdoor = UNLOCKED;
                printf("Front door unlocked.\n");
                break;

            case 8:
                status.frontdoor = LOCKED;
                printf("Front door locked.\n");
                break;

            case 9:
                status.frontdoor_sensor = OPEN;
                printf("Front door opened.\n");
                break;

            case 10:
                status.frontdoor_sensor = CLOSED;
                printf("Front door closed.\n");
                break;

            case 11:
                status.blinds = MOVING;
                printf("Blinds moving up.\n");
                break;

            case 12:
                status.blinds = MOVING;
                printf("Blinds moving down.\n");
                break;

            case 13:
                status.ac = COOL;
                printf("Air conditioner set to COOL.\n");
                break;

            case 14:
                status.ac = HEAT;
                printf("Air conditioner set to HEAT.\n");
                break;

            case 15:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}