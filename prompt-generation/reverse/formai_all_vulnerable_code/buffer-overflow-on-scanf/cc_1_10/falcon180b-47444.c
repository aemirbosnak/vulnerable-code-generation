//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void traffic_light_controller(int duration);
void red_light(int duration);
void yellow_light(int duration);
void green_light(int duration);

int main() {
    int duration;

    // Get duration from user input
    printf("Enter the duration of the traffic light cycle in seconds: ");
    scanf("%d", &duration);

    // Call the traffic light controller function
    traffic_light_controller(duration);

    return 0;
}

// Traffic light controller function
void traffic_light_controller(int duration) {
    int red_duration = duration / 3;
    int yellow_duration = duration / 3;
    int green_duration = duration / 3;

    // Red light
    red_light(red_duration);

    // Yellow light
    yellow_light(yellow_duration);

    // Green light
    green_light(green_duration);
}

// Red light function
void red_light(int duration) {
    printf("Red light is on for %d seconds\n", duration);
    sleep(duration);
}

// Yellow light function
void yellow_light(int duration) {
    printf("Yellow light is on for %d seconds\n", duration);
    sleep(duration);
}

// Green light function
void green_light(int duration) {
    printf("Green light is on for %d seconds\n", duration);
    sleep(duration);
}