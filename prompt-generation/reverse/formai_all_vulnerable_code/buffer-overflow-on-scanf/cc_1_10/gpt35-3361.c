//FormAI DATASET v1.0 Category: Robot movement control ; Style: grateful
#include <stdio.h>

/* Function to control robot movement */
void robotMovement(char direction, int distance) {
    printf("Thank you for using our robot movement control program!\n");
    printf("Please wait while the robot moves...\n");

    /* Code to control robot movement based on direction and distance */
    switch(direction) {
        case 'U':   /* Upward Movement */
            printf("Robot moves upward by %d meters.\n", distance);
            break;

        case 'D':   /* Downward Movement */
            printf("Robot moves downward by %d meters.\n", distance);
            break;

        case 'L':   /* Leftward Movement */
            printf("Robot moves leftward by %d meters.\n", distance);
            break;

        case 'R':   /* Rightward Movement */
            printf("Robot moves rightward by %d meters.\n", distance);
            break;

        default:
            printf("Invalid direction entered. Please enter U, D, L, or R.\n");
            break;
    }

    printf("Robot movement complete!\n");
    printf("Thank you for trusting our robot control program.\n");
}

/* Main function */
int main() {
    char direction;
    int distance;

    /* Get user input for robot movement */
    printf("Welcome to our robot movement control program!\n");
    printf("Please enter the direction of movement (U/D/L/R): ");
    scanf("%c", &direction);
    printf("Please enter the distance of movement (in meters): ");
    scanf("%d", &distance);

    /* Call robotMovement function to control robot movement */
    robotMovement(direction, distance);

    return 0;
}