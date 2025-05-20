//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define SPEED 5
#define STOP 6
#define LIGHT_ON 7
#define LIGHT_OFF 8
#define HORN_ON 9
#define HORN_OFF 10
#define TURN_LEFT 11
#define TURN_RIGHT 12
#define MOVE_FORWARD 13
#define MOVE_BACKWARD 14
#define PARK 15
#define UNPARK 16

int main() {
    int choice;

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Please choose an option:\n");
    printf("1. Move forward\n");
    printf("2. Move backward\n");
    printf("3. Turn left\n");
    printf("4. Turn right\n");
    printf("5. Increase speed\n");
    printf("6. Decrease speed\n");
    printf("7. Stop\n");
    printf("8. Turn on lights\n");
    printf("9. Turn off lights\n");
    printf("10. Honk horn\n");
    printf("11. Park\n");
    printf("12. Unpark\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Vehicle is moving forward\n");
            break;
        case 2:
            printf("Vehicle is moving backward\n");
            break;
        case 3:
            printf("Vehicle is turning left\n");
            break;
        case 4:
            printf("Vehicle is turning right\n");
            break;
        case 5:
            printf("Vehicle is increasing speed\n");
            break;
        case 6:
            printf("Vehicle is decreasing speed\n");
            break;
        case 7:
            printf("Vehicle has stopped\n");
            break;
        case 8:
            printf("Lights are on\n");
            break;
        case 9:
            printf("Lights are off\n");
            break;
        case 10:
            printf("Horn is honking\n");
            break;
        case 11:
            printf("Vehicle is parked\n");
            break;
        case 12:
            printf("Vehicle is unparked\n");
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}