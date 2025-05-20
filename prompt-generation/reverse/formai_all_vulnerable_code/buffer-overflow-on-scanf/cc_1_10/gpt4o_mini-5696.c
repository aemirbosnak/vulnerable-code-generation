//GPT-4o-mini DATASET v1.0 Category: Traffic Light Controller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GREEN_DURATION 5
#define YELLOW_DURATION 2
#define RED_DURATION 5

typedef enum {RED, GREEN, YELLOW} TrafficLightState;

void display_traffic_light(TrafficLightState state) {
    system("clear"); // clears the console
    switch (state) {
        case GREEN:
            printf("     🟢     \n");
            printf("   _______   \n");
            printf("  |       |  \n");
            printf("  |  GO!  |  \n");
            printf("  |_______|  \n");
            break;
        case YELLOW:
            printf("     🟡     \n");
            printf("   _______   \n");
            printf("  |       |  \n");
            printf("  |  SLOW! |  \n");
            printf("  |_______|  \n");
            break;
        case RED:
            printf("     🔴     \n");
            printf("   _______   \n");
            printf("  |       |  \n");
            printf("  |  STOP! |  \n");
            printf("  |_______|  \n");
            break;
    }
}

void run_traffic_light_cycle() {
    while (1) {
        // Green light phase
        display_traffic_light(GREEN);
        sleep(GREEN_DURATION);

        // Yellow light phase
        display_traffic_light(YELLOW);
        sleep(YELLOW_DURATION);

        // Red light phase
        display_traffic_light(RED);
        sleep(RED_DURATION);
    }
}

void traffic_light_animation(int cycles) {
    for (int i = 0; i < cycles; i++) {
        printf("Cycle %d:\n", i + 1);
        run_traffic_light_cycle();
    }
}

int main() {
    int cycles;
    printf("Enter the number of cycles to run the traffic light controller: ");
    scanf("%d", &cycles);

    if (cycles <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }

    traffic_light_animation(cycles);
    return 0;
}