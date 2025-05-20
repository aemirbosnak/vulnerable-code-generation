//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int vehicleMode = 0;
    int vehicleSpeed = 0;
    int vehicleDirection = 0;
    int vehicleLight = 0;
    int vehicleBuzzer = 0;

    printf("Welcome to Retro Remote Control Vehicle Simulator!\n");
    printf("Choose a mode:\n");
    printf("1. Forward\n");
    printf("2. Reverse\n");
    printf("3. Left Turn\n");
    printf("4. Right Turn\n");
    printf("5. Stop\n");
    printf("6. Lights On\n");
    printf("7. Lights Off\n");
    printf("8. Buzzer On\n");
    printf("9. Buzzer Off\n");

    scanf("%d", &vehicleMode);

    switch (vehicleMode) {
        case 1:
            printf("Vehicle is moving forward!\n");
            vehicleSpeed = 1;
            break;
        case 2:
            printf("Vehicle is moving backward!\n");
            vehicleSpeed = -1;
            break;
        case 3:
            printf("Vehicle is turning left!\n");
            vehicleDirection = -1;
            break;
        case 4:
            printf("Vehicle is turning right!\n");
            vehicleDirection = 1;
            break;
        case 5:
            printf("Vehicle is stopped!\n");
            vehicleSpeed = 0;
            vehicleDirection = 0;
            break;
        case 6:
            printf("Lights are on!\n");
            vehicleLight = 1;
            break;
        case 7:
            printf("Lights are off!\n");
            vehicleLight = 0;
            break;
        case 8:
            printf("Buzzer is on!\n");
            vehicleBuzzer = 1;
            break;
        case 9:
            printf("Buzzer is off!\n");
            vehicleBuzzer = 0;
            break;
        default:
            printf("Invalid mode!\n");
            break;
    }

    printf("Vehicle speed: %d\n", vehicleSpeed);
    printf("Vehicle direction: %d\n", vehicleDirection);
    printf("Vehicle light: %d\n", vehicleLight);
    printf("Vehicle buzzer: %d\n", vehicleBuzzer);

    return 0;
}