//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: recursive
#include <stdio.h>

// function prototype
void control(int n);

int main() {
    int remoteCtrl;

    // user input for number of drone controls
    printf("Enter number of drone controls: ");
    scanf("%d", &remoteCtrl);

    // calling the recursive function
    control(remoteCtrl);

    return 0;
}

// recursive function definition
void control(int n) {
    if(n == 0) {
        printf("Drone landing...\n");
    }
    else {
        printf("Control the drone in %d direction(s) - (UP / DOWN / LEFT / RIGHT): ", n);

        char direction[10];
        scanf("%s", &direction);

        // executing the direction of the drone
        if(strcmp(direction, "UP") == 0) {
            printf("Moving UP\n");
        }
        else if(strcmp(direction, "DOWN") == 0) {
            printf("Moving DOWN\n");
        }
        else if(strcmp(direction, "LEFT") == 0) {
            printf("Moving LEFT\n");
        }
        else if(strcmp(direction, "RIGHT") == 0) {
            printf("Moving RIGHT\n");
        }
        else {
            printf("Invalid direction!\n");
            control(n); // recursive call if invalid direction
        }

        control(n-1); // recursive call
    }
}