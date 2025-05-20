//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    int altitude = 0;
    int speed = 0;
    int battery_level = 100;
    char user_input;

    printf("Welcome to C drone remote control program!\n\n");

    while (1) {
        printf("Select an option - a : Increase altitude | b : Decrease altitude | c : Increase speed | d : Decrease speed | e : Check battery level | f : Exit\n");
        scanf(" %c", &user_input);

        if (user_input == 'a') {
            altitude++;
            printf("Drone altitude is now %d meters\n", altitude);
        }

        else if (user_input == 'b') {
            altitude--;
            printf("Drone altitude is now %d meters\n", altitude);
        }

        else if (user_input == 'c') {
            speed++;
            printf("Drone speed is now %d km/h\n", speed);
        }

        else if (user_input == 'd') {
            speed--;
            printf("Drone speed is now %d km/h\n", speed);
        }

        else if (user_input == 'e') {
            printf("Battery level is currently at %d%%\n", battery_level);
        }

        else if (user_input == 'f') {
            printf("Exiting program. Thank you for using C drone remote control!\n");
            break;
        }

        else {
            printf("Invalid input. Please select a valid option.\n");
        }

        if (altitude > 20) {
            printf("WARNING: Drone altitude too high!\n");
        }

        if (altitude < 1) {
            printf("WARNING: Drone on the ground!\n");
        }

        if (battery_level < 10) {
            printf("WARNING: Low battery level!\n");
        }

        battery_level--;
    }

    return 0;
}