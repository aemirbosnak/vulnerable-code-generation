//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Donald Knuth
#include <stdio.h>

int main() {
    // set initial parameters
    int speed = 0;
    int direction = 0;
    int battery_level = 100;
    int signal_strength = 5;
    char mode = 'M';
    char command;

    // loop until battery runs out
    while (battery_level > 0) {
        printf("\nSignal strength: ");
        for (int i = 0; i < signal_strength; i++) {
            printf("|");
        }
        printf("\nBattery level: %d\n", battery_level);
        printf("Mode: %c\n", mode);
        printf("Speed: %d\n", speed);
        printf("Direction: %d\n", direction);

        // get user input
        printf("Enter command: ");
        scanf(" %c", &command);

        // process user input
        switch (command) {
            case 'w':
                speed += 10;
                if (speed > 100) {
                    speed = 100;
                }
                break;
            case 's':
                speed -= 10;
                if (speed < 0) {
                    speed = 0;
                }
                break;
            case 'a':
                direction -= 10;
                if (direction < -180) {
                    direction += 360;
                }
                break;
            case 'd':
                direction += 10;
                if (direction > 180) {
                    direction -= 360;
                }
                break;
            case 'r':
                signal_strength++;
                if (signal_strength > 5) {
                    signal_strength = 5;
                }
                break;
            case 'f':
                signal_strength--;
                if (signal_strength < 1) {
                    signal_strength = 1;
                }
                break;
            case 'p':
                mode = 'P';
                break;
            case 'm':
                mode = 'M';
                break;
            default:
                printf("Invalid command.\n");
                break;
        }

        // simulate movement
        battery_level -= speed / 10;
        if (battery_level < 0) {
            battery_level = 0;
        }
        if (mode == 'P') {
            printf("Pausing... press any key to resume.\n");
            getchar();
            getchar();
        }
    }

    printf("Battery level critical. Terminating program.\n");

    return 0;
}