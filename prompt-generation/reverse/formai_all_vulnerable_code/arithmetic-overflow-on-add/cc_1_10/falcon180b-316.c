//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

#define RED_LIGHT_TIME 10
#define YELLOW_LIGHT_TIME 5
#define GREEN_LIGHT_TIME 15

int main() {
    int light = RED;
    int count = 0;
    int r_count = 0;
    int y_count = 0;
    int g_count = 0;
    time_t start_time;
    time_t end_time;
    time_t current_time;

    printf("Traffic Light Controller\n");

    start_time = time(NULL);
    end_time = start_time + 60; // 60 seconds

    while(time(NULL) < end_time) {
        current_time = time(NULL);

        switch(light) {
            case RED:
                printf("Red light is on\n");
                if(count == RED_LIGHT_TIME) {
                    light = YELLOW;
                    count = 0;
                    r_count++;
                }
                count++;
                break;
            case YELLOW:
                printf("Yellow light is on\n");
                if(count == YELLOW_LIGHT_TIME) {
                    light = GREEN;
                    count = 0;
                    y_count++;
                }
                count++;
                break;
            case GREEN:
                printf("Green light is on\n");
                if(count == GREEN_LIGHT_TIME) {
                    light = RED;
                    count = 0;
                    g_count++;
                }
                count++;
                break;
        }

        if(current_time > start_time + 5) {
            printf("Current light: %d\n", light);
        }

        if(current_time > end_time) {
            printf("Program ended\n");
            printf("Red light: %d seconds\n", r_count * RED_LIGHT_TIME);
            printf("Yellow light: %d seconds\n", y_count * YELLOW_LIGHT_TIME);
            printf("Green light: %d seconds\n", g_count * GREEN_LIGHT_TIME);
            return 0;
        }
    }

    return 0;
}