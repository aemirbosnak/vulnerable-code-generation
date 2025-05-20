//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define variables for the lights and timers
int lights[3] = {0, 0, 0};
int timers[3] = {0, 0, 0};

// Define function to turn on/off a light
void turnOnLight(int lightNum, int on) {
    if (on) {
        lights[lightNum] = 1;
    } else {
        lights[lightNum] = 0;
    }
}

// Define function to start/stop a timer
void startTimer(int timerNum, int on) {
    if (on) {
        timers[timerNum] = 1;
    } else {
        timers[timerNum] = 0;
    }
}

// Define function to check if a timer has expired
int timerExpired(int timerNum) {
    if (timers[timerNum]) {
        printf("Timer %d has expired.\n", timerNum);
        return 1;
    }
    return 0;
}

// Define function to check if all lights are turned on
int allLightsOn() {
    for (int i = 0; i < 3; i++) {
        if (!lights[i]) {
            return 0;
        }
    }
    return 1;
}

// Define function to check if any lights are turned on
int anyLightsOn() {
    for (int i = 0; i < 3; i++) {
        if (lights[i]) {
            return 1;
        }
    }
    return 0;
}

// Define function to check if any timers have expired
int anyTimersExpired() {
    for (int i = 0; i < 3; i++) {
        if (timerExpired(i)) {
            return 1;
        }
    }
    return 0;
}

// Define function to control the lights based on timers
void controlLights() {
    if (anyLightsOn() && anyTimersExpired()) {
        printf("All lights are on and at least one timer has expired.\n");
    } else if (!anyLightsOn() && anyTimersExpired()) {
        printf("No lights are on and at least one timer has expired.\n");
    } else if (anyLightsOn() &&!anyTimersExpired()) {
        printf("At least one light is on and no timers have expired.\n");
    } else if (!anyLightsOn() &&!anyTimersExpired()) {
        printf("No lights are on and no timers have expired.\n");
    }
}

// Define main function
int main() {
    printf("Smart Home Light Control\n");

    // Turn on light 1 and start timer 1
    turnOnLight(1, 1);
    startTimer(1, 1);

    // Turn on light 2 and start timer 2
    turnOnLight(2, 1);
    startTimer(2, 1);

    // Turn on light 3 and start timer 3
    turnOnLight(3, 1);
    startTimer(3, 1);

    // Wait for the timers to expire
    sleep(5);

    // Turn off all lights and stop all timers
    for (int i = 0; i < 3; i++) {
        turnOnLight(i, 0);
        startTimer(i, 0);
    }

    // Check if all lights are turned off and all timers have expired
    while (!allLightsOn() ||!anyTimersExpired()) {
        controlLights();
        sleep(1);
    }

    // Turn on light 1 and start timer 1
    turnOnLight(1, 1);
    startTimer(1, 1);

    // Turn on light 2 and start timer 2
    turnOnLight(2, 1);
    startTimer(2, 1);

    // Turn on light 3 and start timer 3
    turnOnLight(3, 1);
    startTimer(3, 1);

    // Wait for the timers to expire
    sleep(5);

    // Turn off all lights and stop all timers
    for (int i = 0; i < 3; i++) {
        turnOnLight(i, 0);
        startTimer(i, 0);
    }

    // Check if all lights are turned off and all timers have expired
    while (!allLightsOn() ||!anyTimersExpired()) {
        controlLights();
        sleep(1);
    }

    return 0;
}