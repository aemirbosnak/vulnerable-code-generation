//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_X 10
#define MAX_Y 10
#define MAX_ANGLE 90

int main() {
    int x, y, angle;
    int step_x, step_y;
    
    printf("Enter starting coordinates (x, y): ");
    scanf("%d %d", &x, &y);
    printf("Enter starting angle (degrees): ");
    scanf("%d", &angle);
    
    while (1) {
        printf("Enter direction (F = forward, B = backward, L = left, R = right): ");
        char direction;
        scanf(" %c", &direction);
        
        if (direction == 'F') {
            step_x = 1;
            step_y = 0;
        } else if (direction == 'B') {
            step_x = -1;
            step_y = 0;
        } else if (direction == 'L') {
            step_x = 0;
            step_y = 1;
        } else if (direction == 'R') {
            step_x = 0;
            step_y = -1;
        } else {
            printf("Invalid direction. Try again.\n");
            continue;
        }
        
        if (x + step_x < 0 || x + step_x > MAX_X ||
            y + step_y < 0 || y + step_y > MAX_Y) {
            printf("Robot is outside the field. Try again.\n");
            continue;
        }
        
        x += step_x;
        y += step_y;
        angle += step_y;
        
        if (angle > MAX_ANGLE) {
            angle -= 360;
        } else if (angle < 0) {
            angle += 360;
        }
        
        printf("Robot moved %d units in x-direction and %d units in y-direction.\n", step_x, step_y);
        printf("Robot turned %d degrees.\n", angle);
        printf("New coordinates: (%d, %d)\n", x, y);
        
        printf("Enter direction (F = forward, B = backward, L = left, R = right): ");
        scanf(" %c", &direction);
    }
    
    return 0;
}