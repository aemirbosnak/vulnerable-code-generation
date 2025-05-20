//FormAI DATASET v1.0 Category: Robot movement control ; Style: unmistakable
#include <stdio.h>

int main() {
    printf("Press 'w' to move forward, 's' to move backward, 'a' to turn left, 'd' to turn right and 'q' to quit.\n");
    char input;
    int xpos = 0, ypos = 0;
    int angle = 0;
    while (1) {
        scanf("%c", &input);
        if (input == 'q') {
            break;
        }
        else if (input == 'w') {
            if (angle == 0) {
                ypos++;
            }
            else if (angle == 90) {
                xpos++;
            }
            else if (angle == 180) {
                ypos--;
            }
            else if (angle == 270) {
                xpos--;
            }
        }
        else if (input == 's') {
            if (angle == 0) {
                ypos--;
            }
            else if (angle == 90) {
                xpos--;
            }
            else if (angle == 180) {
                ypos++;
            }
            else if (angle == 270) {
                xpos++;
            }
        }
        else if (input == 'a') {
            angle = (angle + 90) % 360;
        }
        else if (input == 'd') {
            angle = (angle - 90 + 360) % 360;
        }
        else {
            printf("Invalid Input.\n");
        }
        printf("Current Position: (%d,%d) Angle: %d\n", xpos, ypos, angle);
    }
    return 0;
}