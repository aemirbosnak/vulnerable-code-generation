//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: beginner-friendly
#include <stdio.h>

// function prototypes
void takeoff();
void land();
void flyLeft();
void flyRight();
void flyForward();
void flyBackward();
void rotateLeft();
void rotateRight();

// main function
int main() {
    int choice;

    while (1) {
        // displaying options to the user
        printf("\n1. Takeoff");
        printf("\n2. Land");
        printf("\n3. Fly Left");
        printf("\n4. Fly Right");
        printf("\n5. Fly Forward");
        printf("\n6. Fly Backward");
        printf("\n7. Rotate Left");
        printf("\n8. Rotate Right");
        printf("\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // calling appropriate function based on user's choice
        switch (choice) {
            case 1:
                takeoff();
                break;
            case 2:
                land();
                break;
            case 3:
                flyLeft();
                break;
            case 4:
                flyRight();
                break;
            case 5:
                flyForward();
                break;
            case 6:
                flyBackward();
                break;
            case 7:
                rotateLeft();
                break;
            case 8:
                rotateRight();
                break;
            case 9:
                printf("\nExiting program...");
                exit(0);
            default:
                printf("\nInvalid choice, please try again.");
        }
    }
    return 0;
}

// function definitions
void takeoff() {
    printf("\nDrone taking off...");
}

void land() {
    printf("\nDrone landing...");
}

void flyLeft() {
    printf("\nDrone flying left...");
}

void flyRight() {
    printf("\nDrone flying right...");
}

void flyForward() {
    printf("\nDrone flying forward...");
}

void flyBackward() {
    printf("\nDrone flying backward...");
}

void rotateLeft() {
    printf("\nDrone rotating left...");
}

void rotateRight() {
    printf("\nDrone rotating right...");
}