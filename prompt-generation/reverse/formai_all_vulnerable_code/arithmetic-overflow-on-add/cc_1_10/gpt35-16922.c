//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

#define ON 1
#define OFF 0

void updateTrafficLight(int timeElapsed);
void updateLight(int light, int state);
void printTrafficLight();
void delay(int milliseconds);

int main() {
    srand(time(NULL));

    while (1) {
        int timeElapsed = 0;
        int maxTime = (rand() % 11) + 5; // Random number between 5 and 15
        printf("Time Elapsed: %d\n", timeElapsed);
        printTrafficLight();

        while (timeElapsed <= maxTime) {
            if (timeElapsed < 3) {
                updateTrafficLight(1);
            } else if (timeElapsed < 5) {
                updateTrafficLight(2);
            } else {
                updateTrafficLight(3);
            }

            printf("Time Elapsed: %d\n", timeElapsed);
            printTrafficLight();
            delay(1000); // Delay for 1 second
            timeElapsed++;
        }
    }
    return 0;
}

void updateTrafficLight(int timeElapsed) {
    static int currentLight = RED;
    static int currentState = OFF;

    if (timeElapsed == 1) {
        currentState = ON;
    } else if (timeElapsed == 2) {
        currentState = OFF;
        currentLight = GREEN;
    } else if (timeElapsed == 3) {
        currentState = ON;
    } else if (timeElapsed == 4) {
        currentState = OFF;
        currentLight = YELLOW;
    } else if (timeElapsed == 5) {
        currentState = ON;
    } else {
        currentState = OFF;
        currentLight = RED;
    }

    updateLight(currentLight, currentState);
}

void updateLight(int light, int state) {
    // Update the light with the given state
    printf("%s: %s\n", 
           light == RED ? "Red" : light == YELLOW ? "Yellow" : "Green",
           state == ON ? "On" : "Off");
}

void printTrafficLight() {
    // Print the entire traffic light
    printf("Traffic Light:\n");
    updateLight(RED, OFF);
    updateLight(YELLOW, OFF);
    updateLight(GREEN, OFF);
    printf("\n");
}

void delay(int milliseconds) {
    // Delay for the specified time
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds) {} 
}