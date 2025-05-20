//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with the current time

    int battery_life = rand() % 100; // generate a random battery life percentage between 0 and 99
    int signal_strength = rand() % 10; // generate a random signal strength between 0 and 9
    int altitude = rand() % 50; // generate a random altitude between 0 and 49

    printf("Welcome to the C Drone Remote Control program!\n\n");

    printf("Battery life: %d%\n", battery_life);
    if (battery_life < 20) {
        printf("WARNING: Low battery!\n");
    }

    printf("Signal strength: %d/10\n", signal_strength);
    if (signal_strength < 6) {
        printf("WARNING: Weak signal!\n");
    }

    printf("Altitude: %d meters\n", altitude);
    if (altitude > 30) {
        printf("WARNING: High altitude!\n");
    }

    printf("\nUse the following commands to control the drone:\n");
    printf("takeoff - make the drone takeoff\n");
    printf("land - make the drone land\n");
    printf("up <distance> - move the drone up by <distance> meters\n");
    printf("down <distance> - move the drone down by <distance> meters\n");
    printf("left <distance> - move the drone left by <distance> meters\n");
    printf("right <distance> - move the drone right by <distance> meters\n");
    printf("forward <distance> - move the drone forward by <distance> meters\n");
    printf("backward <distance> - move the drone backward by <distance> meters\n");
    printf("rotateleft <angle> - rotate the drone left by <angle> degrees\n");
    printf("rotateright <angle> - rotate the drone right by <angle> degrees\n");

    printf("\nEnter a command: ");
    char command[50];
    scanf("%s", command);

    // check if the battery life or signal strength is too low before executing the command
    if ((battery_life < 10 && strcmp(command, "takeoff") != 0) || (signal_strength < 3 && strcmp(command, "land") != 0)) {
        printf("ERROR: Cannot execute command, battery life or signal strength too low!\n");
    }
    else {
        // execute the command
        printf("Executing command: %s\n", command);
    }

    return 0;
}