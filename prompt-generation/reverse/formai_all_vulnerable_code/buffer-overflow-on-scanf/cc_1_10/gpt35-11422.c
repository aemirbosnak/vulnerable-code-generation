//FormAI DATASET v1.0 Category: Robot movement control ; Style: secure
#include <stdio.h>

// function to check if robot is stuck
int isStuck(int x, int y) {
    if (x == 0 && y == 0) {
        printf("Error: Robot is stuck at origin\n");
        return 1;
    }
    return 0;
}

// function to move robot up
void moveUp(int* x, int* y) {
    (*y)++;
    if (isStuck(*x, *y)) {
        (*y)--;
    }
}

// function to move robot down
void moveDown(int* x, int* y) {
    (*y)--;
    if (isStuck(*x, *y)) {
        (*y)++;
    }
}

// function to move robot left
void moveLeft(int* x, int* y) {
    (*x)--;
    if (isStuck(*x, *y)) {
        (*x)++;
    }
}

// function to move robot right
void moveRight(int* x, int* y) {
    (*x)++;
    if (isStuck(*x, *y)) {
        (*x)--;
    }
}

int main() {
    int x = 0, y = 0;
    int choice = 0;

    printf("Welcome to Robot Movement Control:\n\n");
    printf("Use arrow keys to move robot. Press 5 to quit.\n\n");

    while (choice != 5) {
        // print robot position
        printf("Robot position: (%d, %d)\n", x, y);

        // display menu
        printf("\n1. Move up\n");
        printf("2. Move down\n");
        printf("3. Move left\n");
        printf("4. Move right\n");
        printf("5. Quit\n");

        // get user choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // execute appropriate function based on user choice
        switch (choice) {
            case 1:
                moveUp(&x, &y);
                break;
            case 2:
                moveDown(&x, &y);
                break;
            case 3:
                moveLeft(&x, &y);
                break;
            case 4:
                moveRight(&x, &y);
                break;
            case 5:
                printf("Quitting...\n");
                break;
            default:
                printf("Error: Invalid choice\n");
                break;
        }
    }

    return 0;
}