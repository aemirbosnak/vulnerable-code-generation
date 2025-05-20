//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int drone_id = 1;
    int throttle = 0;
    int yaw = 0;
    int pitch = 0;
    int roll = 0;

    while(1) {
        printf("Drone Remote Control\n");
        printf("Commands:\n");
        printf("1 - Takeoff\n");
        printf("2 - Land\n");
        printf("3 - Forward\n");
        printf("4 - Backward\n");
        printf("5 - Left\n");
        printf("6 - Right\n");
        printf("7 - Up\n");
        printf("8 - Down\n");
        printf("9 - Yaw Left\n");
        printf("0 - Yaw Right\n");
        printf("A - Pitch Up\n");
        printf("B - Pitch Down\n");
        printf("C - Roll Left\n");
        printf("D - Roll Right\n");
        printf("E - Stop\n");
        printf("Q - Quit\n");

        char command;
        scanf("%c", &command);

        switch(command) {
            case '1':
                printf("Taking off...\n");
                sleep(2);
                printf("Drone is at 100 feet altitude.\n");
                break;
            case '2':
                printf("Landing...\n");
                sleep(2);
                printf("Drone is at 0 feet altitude.\n");
                break;
            case '3':
                printf("Forwarding...\n");
                throttle = 100;
                sleep(1);
                printf("Drone is at 200 feet altitude.\n");
                break;
            case '4':
                printf("Backwarding...\n");
                throttle = -100;
                sleep(1);
                printf("Drone is at 0 feet altitude.\n");
                break;
            case '5':
                printf("Yawing left...\n");
                yaw = -100;
                sleep(1);
                printf("Drone is at 180 degrees.\n");
                break;
            case '6':
                printf("Yawing right...\n");
                yaw = 100;
                sleep(1);
                printf("Drone is at 0 degrees.\n");
                break;
            case '7':
                printf("Pitching up...\n");
                pitch = 100;
                sleep(1);
                printf("Drone is at 30 degrees.\n");
                break;
            case '8':
                printf("Pitching down...\n");
                pitch = -100;
                sleep(1);
                printf("Drone is at -30 degrees.\n");
                break;
            case '9':
                printf("Rolling left...\n");
                roll = -100;
                sleep(1);
                printf("Drone is at -90 degrees.\n");
                break;
            case '0':
                printf("Rolling right...\n");
                roll = 100;
                sleep(1);
                printf("Drone is at 90 degrees.\n");
                break;
            case 'A':
                printf("Pitching up...\n");
                pitch = 200;
                sleep(1);
                printf("Drone is at 60 degrees.\n");
                break;
            case 'B':
                printf("Pitching down...\n");
                pitch = -200;
                sleep(1);
                printf("Drone is at -60 degrees.\n");
                break;
            case 'C':
                printf("Rolling left...\n");
                roll = -200;
                sleep(1);
                printf("Drone is at -120 degrees.\n");
                break;
            case 'D':
                printf("Rolling right...\n");
                roll = 200;
                sleep(1);
                printf("Drone is at 120 degrees.\n");
                break;
            case 'E':
                printf("Stopping...\n");
                throttle = 0;
                yaw = 0;
                pitch = 0;
                roll = 0;
                sleep(1);
                printf("Drone is stopped.\n");
                break;
            case 'Q':
                printf("Quitting...\n");
                exit(0);
                break;
            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}