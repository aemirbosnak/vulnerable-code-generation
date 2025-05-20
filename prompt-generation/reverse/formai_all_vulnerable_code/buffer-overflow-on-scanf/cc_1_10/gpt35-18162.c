//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ANGLE 45

// Function to validate the user input 
void validate_user_input(int *input) {
    while (*input > MAX_ANGLE || *input < 0) {
        printf("Invalid input. Please enter a value between 0 and 45: ");
        scanf("%d", input);
    }
}

int main() {
    int angle = 0;
    bool isFlying = false;

    printf("Welcome to the Drone Remote Control Program!\n");
    printf("Please enter an angle between 0 and %d to control the drone's pitch: ", MAX_ANGLE);
    scanf("%d", &angle);
    validate_user_input(&angle);

    printf("The drone is now ready to take off!\n");
    isFlying = true;

    while (isFlying) {
        printf("Please enter a command (w to move forward, a to move left, s to move backward, d to move right, q to quit):\n");
        char input;
        scanf(" %c", &input);

        switch(input) {
            case 'w':
                printf("Drone moves forward with pitch angle of %d degrees.\n", angle);
                break;
            case 'a':
                printf("Drone moves left with pitch angle of %d degrees.\n", angle);
                break;
            case 's':
                printf("Drone moves backward with pitch angle of %d degrees.\n", angle);
                break;
            case 'd':
                printf("Drone moves right with pitch angle of %d degrees.\n", angle);
                break;
            case 'q':
                printf("Quitting Drone Remote Control Program.\n");
                isFlying = false;
                break;
            default:
                printf("Invalid command. Please enter w, a, s, d, or q.\n");
                break;
        }
    }

    return 0;
}