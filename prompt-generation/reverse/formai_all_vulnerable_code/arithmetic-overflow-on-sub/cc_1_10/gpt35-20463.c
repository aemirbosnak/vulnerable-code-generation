//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Cyberpunk
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define GREEN_DELAY 10
#define YELLOW_DELAY 3
#define RED_DELAY 12
#define BLINK_DELAY 1

void set_lights(bool red, bool yellow, bool green) {
    if (red)
        printf("🔴");
    else
        printf("⚪️");
    if (yellow)
        printf("🟡");
    else
        printf("⚪️");
    if (green)
        printf("🟢");
    else
        printf("⚪️");
    printf("\n");
}

void delay(int seconds) {
    time_t start_time = time(NULL);
    while (time(NULL) - start_time < seconds);
}

int main() {
    bool red = true;
    bool yellow = false;
    bool green = false;

    while (true) {
        // Green light
        set_lights(false, false, true);
        delay(GREEN_DELAY);

        // Yellow light
        set_lights(false, true, false);
        delay(YELLOW_DELAY);

        // Red light
        set_lights(true, false, false);
        delay(RED_DELAY);

        // Red and yellow lights blinking
        for (int i = 0; i < 3; i++) {
            set_lights(true, true, false);
            delay(BLINK_DELAY);
            set_lights(false, false, false);
            delay(BLINK_DELAY);
        }
    }
}