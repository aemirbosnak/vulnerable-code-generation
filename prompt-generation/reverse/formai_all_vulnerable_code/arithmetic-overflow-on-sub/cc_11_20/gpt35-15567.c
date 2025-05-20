//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int altitude = 0;
    int distance = 0;
    int speed = 0;
    int battery_level = 100;
    int up_down = 0;
    int forward_backward = 0;
    int left_right = 0;
    int on_off = 0;

    printf("Welcome to C Drone Remote Control\n");
    printf("Please enter your command:\n");

    while (battery_level >= 20) {
        printf("> ");
        scanf("%d %d %d %d", &up_down, &forward_backward, &left_right, &on_off);

        if (on_off == 0) {
            printf("Turning off drone...\n");
            break;
        }

        if (up_down > 0) {
            altitude += up_down;
            printf("Increasing altitude...\n");
        } else if (up_down < 0) {
            altitude -= abs(up_down);
            printf("Decreasing altitude...\n");
        }

        if (forward_backward > 0) {
            distance += forward_backward;
            printf("Moving forward...\n");
        } else if (forward_backward < 0) {
            distance -= abs(forward_backward);
            printf("Moving backward...\n");
        }

        if (left_right > 0) {
            printf("Moving right...\n");
        } else if (left_right < 0) {
            printf("Moving left...\n");
        }

        speed = forward_backward * 10;

        if (speed > 100) {
            speed = 100;
        } else if (speed < -100) {
            speed = -100;
        }

        printf("Status Report:\n");
        printf("  Altitude: %d\n", altitude);
        printf("  Distance: %d\n", distance);
        printf("  Speed: %d\n", speed);
        printf("  Battery Level: %d\n", battery_level);
    }

    if (battery_level < 20) {
        printf("Battery Level Low. Returning to base...\n");
    }

    printf("Program Exiting. Thank you for using C Drone Remote Control.\n");

    return 0;
}