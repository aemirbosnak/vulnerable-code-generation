//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
    int ms = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + ms) {
        //wait
    }
}

int main() {
    int x_pos = 0, y_pos = 0;
    int speed = 10;
    int angle = 0;

    while (1) {
        //simulate remote control input
        int direction = rand() % 4;

        switch (direction) {
            case 0:
                y_pos += speed;
                printf("Moving Forward\n");
                break;
            
            case 1:
                y_pos -= speed;
                printf("Moving Backward\n");
                break;
            
            case 2:
                x_pos += speed;
                printf("Moving Right\n");
                break;
            
            case 3:
                x_pos -= speed;
                printf("Moving Left\n");
                break;
        }

        //simulate turning
        angle += 15;
        if (angle >= 360) {
            angle = 0;
        }

        printf("Current Position: (%d, %d)\n", x_pos, y_pos);
        printf("Current Angle: %d degrees\n", angle);

        delay(1); //wait for 1 second
    }

    return 0;
}