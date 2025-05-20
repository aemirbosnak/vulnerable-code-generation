//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define the drone remote control structure
struct DroneRemoteControl {
    int up_down;
    int left_right;
    int forward_back;
    int rotate;
};

// Define the function to take user input for drone control
void takeUserInput(struct DroneRemoteControl *control) {
    printf("Please enter the control values for the drone: \n");
    printf("Up/Down (-100 to 100): ");
    scanf("%d", &control->up_down);

    printf("Left/Right (-100 to 100): ");
    scanf("%d", &control->left_right);

    printf("Forward/Back (-100 to 100): ");
    scanf("%d", &control->forward_back);

    printf("Rotate (-100 to 100): ");
    scanf("%d", &control->rotate);
}

// Define the function to validate user input
int validateUserInput(struct DroneRemoteControl *control) {
    if (control->up_down < -100 || control->up_down > 100) {
        printf("Error: Up/Down value should be between -100 and 100\n");
        return 0;
    }

    if (control->left_right < -100 || control->left_right > 100) {
        printf("Error: Left/Right value should be between -100 and 100\n");
        return 0;
    }

    if (control->forward_back < -100 || control->forward_back > 100) {
        printf("Error: Forward/Back value should be between -100 and 100\n");
        return 0;
    }

    if (control->rotate < -100 || control->rotate > 100) {
        printf("Error: Rotate value should be between -100 and 100\n");
        return 0;
    }

    return 1;
}

// Define the function to control the drone
void controlDrone(struct DroneRemoteControl *control) {
    printf("Drone is now controlled with Up/Down = %d, Left/Right = %d, Forward/Back = %d, and Rotate = %d.\n", control->up_down, control->left_right, control->forward_back, control->rotate);
}

// Main function
int main() {
    struct DroneRemoteControl control;

    // Take user input for drone control
    takeUserInput(&control);

    // Validate user input
    if (validateUserInput(&control)) {
        // Control the drone
        controlDrone(&control);

        printf("Thank you for using our drone remote control program!\n");
    } else {
        printf("Please input valid values for drone control.\n");
    }

    return 0;
}