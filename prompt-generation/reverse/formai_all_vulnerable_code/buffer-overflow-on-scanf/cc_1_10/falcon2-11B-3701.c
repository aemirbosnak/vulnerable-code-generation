//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: minimalist
#include <stdio.h>

#define MAX_STEPS 10

void move_forward(int steps) {
    for (int i = 0; i < steps; i++) {
        printf("Forward...\n");
    }
}

void move_backward(int steps) {
    for (int i = 0; i < steps; i++) {
        printf("Backward...\n");
    }
}

void turn_left(int steps) {
    for (int i = 0; i < steps; i++) {
        printf("Turning left...\n");
    }
}

void turn_right(int steps) {
    for (int i = 0; i < steps; i++) {
        printf("Turning right...\n");
    }
}

int main() {
    int steps = 0;
    while (steps < MAX_STEPS) {
        printf("What would you like to do?\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Quit\n");

        int choice = 0;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move_forward(MAX_STEPS);
                break;
            case 2:
                move_backward(MAX_STEPS);
                break;
            case 3:
                turn_left(MAX_STEPS);
                break;
            case 4:
                turn_right(MAX_STEPS);
                break;
            case 5:
                printf("Bye!\n");
                return 0;
        }
    }

    return 0;
}