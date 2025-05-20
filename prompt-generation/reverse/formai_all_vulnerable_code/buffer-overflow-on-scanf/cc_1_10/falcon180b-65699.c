//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TICK_RATE 1000 // Time travel tick rate in microseconds
#define MAX_TIME_TRAVEL 1000 // Maximum time travel distance in seconds
#define TIME_SPEED 1.0 // Time speed when not time traveling
#define TIME_TRAVEL_SPEED 10.0 // Time speed when time traveling

// Function prototypes
void time_travel(double *time, double distance, int direction);
void tick(double *time);

int main() {
    double current_time = 0.0; // Current time in seconds
    double time_travel_distance = 0.0; // Distance to time travel in seconds
    int time_travel_direction = 1; // 1 for forward, -1 for backward

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Press ENTER to start...\n");
    getchar();

    while (1) {
        printf("Current time: %.2f seconds\n", current_time);
        printf("Enter time travel distance (0 to stop): ");
        scanf("%lf", &time_travel_distance);

        if (time_travel_distance == 0.0) {
            time_travel_direction = 1;
        } else {
            time_travel_direction = abs(time_travel_distance) > 0.0? 1 : -1;
            time_travel(&current_time, fabs(time_travel_distance), time_travel_direction);
        }

        tick(&current_time);
    }

    return 0;
}

void time_travel(double *time, double distance, int direction) {
    double travel_time = distance / TIME_TRAVEL_SPEED;
    double new_time = *time + travel_time * direction;

    if (new_time < 0.0) {
        printf("ERROR: Cannot travel to a time before the Big Bang!\n");
        return;
    } else if (new_time > MAX_TIME_TRAVEL) {
        printf("ERROR: Maximum time travel distance exceeded!\n");
        return;
    }

    *time = new_time;
    printf("Time travel complete. Current time: %.2f seconds.\n", *time);
}

void tick(double *time) {
    double delta_time = TICK_RATE / TIME_SPEED;
    *time += delta_time;

    if (*time >= MAX_TIME_TRAVEL) {
        printf("ERROR: Maximum simulation time exceeded!\n");
        exit(1);
    }
}