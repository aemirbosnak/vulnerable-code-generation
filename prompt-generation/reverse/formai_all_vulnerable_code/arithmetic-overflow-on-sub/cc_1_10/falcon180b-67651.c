//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT_ON 1
#define GREEN_LIGHT_ON 2
#define YELLOW_LIGHT_ON 3
#define RED_LIGHT_OFF 4
#define GREEN_LIGHT_OFF 5
#define YELLOW_LIGHT_OFF 6

#define LIGHT_CHANGE_DELAY 3 // seconds

int main() {
    int light_state = RED_LIGHT_ON;
    time_t last_change_time = 0;

    while(1) {
        time_t current_time = time(NULL);

        if(current_time - last_change_time >= LIGHT_CHANGE_DELAY) {
            switch(light_state) {
                case RED_LIGHT_ON:
                    printf("Red light is on.\n");
                    light_state = GREEN_LIGHT_ON;
                    break;
                case GREEN_LIGHT_ON:
                    printf("Green light is on.\n");
                    light_state = YELLOW_LIGHT_ON;
                    break;
                case YELLOW_LIGHT_ON:
                    printf("Yellow light is on.\n");
                    light_state = RED_LIGHT_ON;
                    break;
                case RED_LIGHT_OFF:
                    printf("Red light is off.\n");
                    light_state = GREEN_LIGHT_OFF;
                    break;
                case GREEN_LIGHT_OFF:
                    printf("Green light is off.\n");
                    light_state = YELLOW_LIGHT_OFF;
                    break;
                case YELLOW_LIGHT_OFF:
                    printf("Yellow light is off.\n");
                    light_state = RED_LIGHT_OFF;
                    break;
            }

            last_change_time = current_time;
        }
    }

    return 0;
}