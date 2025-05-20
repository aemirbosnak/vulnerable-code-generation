//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GREEN_LIGHT 0
#define YELLOW_LIGHT 1
#define RED_LIGHT 2

bool isButtonPressed() {
    // Simulate button press
    int random_num = rand() % 10;
    if (random_num == 0) {
        return true;
    }
    return false;
}

void delay(int seconds) {
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < seconds);
}

int main() {
    int current_light = GREEN_LIGHT;
    while (true) {
        printf("Current Light: ");
        if (current_light == GREEN_LIGHT) {
            printf("GREEN\n");
            delay(5);
            current_light = YELLOW_LIGHT;
            printf("Yellow light activated to give drivers anxiety...\n");
        } else if (current_light == YELLOW_LIGHT) {
            printf("YELLOW\n");
            delay(2);
            if (isButtonPressed()) {
                printf("Button pressed! Skipping RED light\n");
                current_light = GREEN_LIGHT;
            } else {
                current_light = RED_LIGHT;
                printf("RED light activated to stop drivers from going\n");
            }
        } else if (current_light == RED_LIGHT) {
            printf("RED\n");
            delay(5);
            if (isButtonPressed()) {
                printf("Button pressed! Skipping YELLOW light\n");
                current_light = GREEN_LIGHT;
            } else {
                current_light = YELLOW_LIGHT;
                printf("Yellow light activated, prepare to stop...\n");
            }
        }
    }
    return 0;
}