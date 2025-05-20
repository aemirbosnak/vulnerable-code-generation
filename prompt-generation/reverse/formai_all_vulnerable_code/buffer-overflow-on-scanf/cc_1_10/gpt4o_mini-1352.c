//GPT-4o-mini DATASET v1.0 Category: Traffic Light Controller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t running = 1;

void handle_sigint(int sig) {
    running = 0;
}

void display_light(const char* lightColor) {
    printf("\n=== Traffic Light ===\n");
    if (strcmp(lightColor, "RED") == 0) {
        printf("     [***RED***]\n");
        printf("        STOP\n");
        printf("Please wait for the light to change...\n");
    } else if (strcmp(lightColor, "GREEN") == 0) {
        printf("   [***GREEN***]\n");
        printf("       GO\n");
        printf("Drive safely!\n");
    } else if (strcmp(lightColor, "YELLOW") == 0) {
        printf("  [***YELLOW***]\n");
        printf("   SLOW DOWN\n");
        printf("Get ready to stop.\n");
    }
    printf("=====================\n");
}

void traffic_light_cycle(int red_duration, int green_duration, int yellow_duration) {
    while (running) {
        display_light("RED");
        sleep(red_duration);

        display_light("GREEN");
        sleep(green_duration);

        display_light("YELLOW");
        sleep(yellow_duration);
    }
}

int main() {
    int red_duration, green_duration, yellow_duration;

    signal(SIGINT, handle_sigint);

    printf("Traffic Light Controller Simulation\n");
    printf("===================================\n");
    
    printf("Enter RED light duration (in seconds): ");
    scanf("%d", &red_duration);
    
    printf("Enter GREEN light duration (in seconds): ");
    scanf("%d", &green_duration);
    
    printf("Enter YELLOW light duration (in seconds): ");
    scanf("%d", &yellow_duration);

    printf("Traffic light cycle with:\n");
    printf("RED : %d seconds\n", red_duration);
    printf("GREEN : %d seconds\n", green_duration);
    printf("YELLOW : %d seconds\n", yellow_duration);
    
    printf("\nPress Ctrl+C to stop the simulation.\n\n");

    traffic_light_cycle(red_duration, green_duration, yellow_duration);

    printf("Traffic light simulation stopped.\n");
    return 0;
}