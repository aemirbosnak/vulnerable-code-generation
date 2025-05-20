//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3

#define RED_TIME 5
#define YELLOW_TIME 3
#define GREEN_TIME 7

int current_light = RED_LIGHT;
int current_time = RED_TIME;

void change_light() {
    if (current_light == RED_LIGHT) {
        current_light = YELLOW_LIGHT;
        current_time = YELLOW_TIME;
    } else if (current_light == YELLOW_LIGHT) {
        current_light = GREEN_LIGHT;
        current_time = GREEN_TIME;
    } else if (current_light == GREEN_LIGHT) {
        current_light = RED_LIGHT;
        current_time = RED_TIME;
    }
}

void wait(int seconds) {
    clock_t start_time = clock();
    while (clock() - start_time < seconds * CLOCKS_PER_SEC);
}

int main() {
    srand(time(0));

    while (1) {
        printf("Current light: ");
        switch (current_light) {
            case RED_LIGHT:
                printf("RED\n");
                break;
            case YELLOW_LIGHT:
                printf("YELLOW\n");
                break;
            case GREEN_LIGHT:
                printf("GREEN\n");
                break;
            default:
                printf("UNKNOWN\n");
        }

        wait(current_time);
        change_light();
    }

    return 0;
}