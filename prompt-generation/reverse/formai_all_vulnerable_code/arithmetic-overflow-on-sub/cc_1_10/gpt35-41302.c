//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Enum for traffic light colors
enum Color {
    RED,
    GREEN,
    YELLOW
};

// Function to get current time
time_t getCurrentTime() {
    time_t currentTime;
    time(&currentTime);
    return currentTime;
}

// Function to get difference between two times
int getElapsedTime(time_t startTime, time_t endTime) {
    return (int) (endTime - startTime);
}

// Function to display traffic light color
void displayTrafficLightColor(enum Color color) {
    switch(color) {
        case RED:
            printf("\n\nTraffic Light: RED");
            break;
        case YELLOW:
            printf("\n\nTraffic Light: YELLOW");
            break;
        case GREEN:
            printf("\n\nTraffic Light: GREEN");
            break;
        default:
            printf("\n\nError: Invalid Color");
            break;
    }
}

// Async function to change traffic light color after a specified time interval
void setTrafficLight(enum Color color, int interval) {
    time_t startTime = getCurrentTime();
    time_t endTime;
    int elapsedTime = 0;

    while(elapsedTime < interval) {
        endTime = getCurrentTime();
        elapsedTime = getElapsedTime(startTime, endTime);
    }

    // Display new traffic light color after specified interval
    switch(color) {
        case RED:
            displayTrafficLightColor(GREEN);
            break;
        case YELLOW:
            displayTrafficLightColor(RED);
            break;
        case GREEN:
            displayTrafficLightColor(YELLOW);
            break;
        default:
            printf("\n\nError: Invalid Color");
            break;
    }
}

// Main function to control traffic light
int main() {
    // Display initial traffic light color
    displayTrafficLightColor(GREEN);
    setTrafficLight(GREEN, 5000);

    displayTrafficLightColor(YELLOW);
    setTrafficLight(YELLOW, 2000);

    displayTrafficLightColor(RED);
    setTrafficLight(RED, 4000);

    return 0;
}