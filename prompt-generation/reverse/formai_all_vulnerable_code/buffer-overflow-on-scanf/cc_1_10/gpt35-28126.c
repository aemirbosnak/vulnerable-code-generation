//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: scientific
#include <stdio.h>

float pitch, roll, yaw, throttle;

void update_drone(char input) {
    float change;
    switch (input) {
        case 'i':
            printf("Increase pitch by: ");
            scanf("%f", &change);
            pitch += change;
            printf("New pitch: %f", pitch);
            break;
        case 'd':
            printf("Decrease pitch by: ");
            scanf("%f", &change);
            pitch -= change;
            printf("New pitch: %f", pitch);
            break;
        case 'j':
            printf("Increase roll by: ");
            scanf("%f", &change);
            roll += change;
            printf("New roll: %f", roll);
            break;
        case 'l':
            printf("Decrease roll by: ");
            scanf("%f", &change);
            roll -= change;
            printf("New roll: %f", roll);
            break;
        case 'k':
            printf("Increase yaw by: ");
            scanf("%f", &change);
            yaw += change;
            printf("New yaw: %f", yaw);
            break;
        case 'h':
            printf("Decrease yaw by: ");
            scanf("%f", &change);
            yaw -= change;
            printf("New yaw: %f", yaw);
            break;
        case 'w':
            printf("Increase throttle by: ");
            scanf("%f", &change);
            throttle += change;
            printf("New throttle: %f", throttle);
            break;
        case 's':
            printf("Decrease throttle by: ");
            scanf("%f", &change);
            throttle -= change;
            printf("New throttle: %f", throttle);
            break;
        default:
            printf("Invalid input. Please try again.");
            break;
    }
}

int main() {
    char input;
    pitch = roll = yaw = throttle = 0.0;
    printf("Welcome to the C Drone Remote Control program!\n");
    printf("Use the following keys to control the drone:\n");
    printf("  i - Increase pitch\n");
    printf("  d - Decrease pitch\n");
    printf("  j - Increase roll\n");
    printf("  l - Decrease roll\n");
    printf("  k - Increase yaw\n");
    printf("  h - Decrease yaw\n");
    printf("  w - Increase throttle\n");
    printf("  s - Decrease throttle\n");
    printf("Press 'q' to quit.\n");
    while (1) {
        printf("Enter an input: ");
        scanf(" %c", &input);
        if (input == 'q') {
            printf("Exiting program...\n");
            break;
        } else {
            update_drone(input);
        }
    }
    return 0;
}