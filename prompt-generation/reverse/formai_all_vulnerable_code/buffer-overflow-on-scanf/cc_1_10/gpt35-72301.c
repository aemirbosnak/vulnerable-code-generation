//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: real-life
#include <stdio.h>

void takeOff() {
    printf("Taking off...\n");
}

void fly(int direction, int distance) {
    printf("Flying %d meters %s...\n", distance, direction == 1 ? "forward" :
                                      direction == 2 ? "backward" :
                                      direction == 3 ? "left" :
                                      direction == 4 ? "right" :
                                      "unknown");
}

void land() {
    printf("Landing...\n");
}

int main() {

    int choice, direction, distance;

    printf("--- Welcome to the C Drone Remote Control Program ---\n\n");

    while (1) {

        printf("1. Take off\n");
        printf("2. Fly forward\n");
        printf("3. Fly backward\n");
        printf("4. Fly left\n");
        printf("5. Fly right\n");
        printf("6. Land\n");
        printf("0. Quit\n");

        printf("\nEnter your choice (0-6): ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                takeOff();
                break;

            case 2:
            case 3: 
            case 4:
            case 5:
                printf("\nEnter distance in meters: ");
                scanf("%d", &distance);
                fly(choice, distance);
                break;

            case 6:
                land();
                break;

            case 0: 
                printf("\nGoodbye!\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again...\n");
        }
    }

    return 0;
}