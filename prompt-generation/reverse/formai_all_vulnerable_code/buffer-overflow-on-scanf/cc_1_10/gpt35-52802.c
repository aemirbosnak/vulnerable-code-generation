//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Romeo and Juliet
#include <stdio.h>

// define variables for drone movements
int forward = 0;
int backward = 0;
int left = 0;
int right = 0;
int up = 0;
int down = 0;

// function to print drone movements
void printMovement() {
    printf("Drone Movement:\n");
    printf("Forward: %d\n", forward);
    printf("Backward: %d\n", backward);
    printf("Left: %d\n", left);
    printf("Right: %d\n", right);
    printf("Up: %d\n", up);
    printf("Down: %d\n", down);
}

// main function to control the remote
int main() {
    int input;

    // infinite loop to keep the remote running
    while(1) {
        printMovement();

        // get user input
        printf("\nEnter 1 for forward, 2 for backward, 3 for left, 4 for right, 5 for up, 6 for down: ");
        scanf("%d", &input);

        // update drone movements based on user input
        switch(input) {
            case 1:
                forward++;
                break;
            case 2:
                backward++;
                break;
            case 3:
                left++;
                break;
            case 4:
                right++;
                break;
            case 5:
                up++;
                break;
            case 6:
                down++;
                break;
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}