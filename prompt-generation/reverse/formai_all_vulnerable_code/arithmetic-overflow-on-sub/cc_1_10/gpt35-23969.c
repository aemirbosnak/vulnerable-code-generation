//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constant values for traffic light colors
#define GREEN 1
#define YELLOW 2
#define RED 3

// Define function to display traffic light colors
void displayTrafficLight(int color) {
    // Generate random flicker effect
    int flicker = rand() % 2;
    // Print traffic light color with flicker effect
    if (flicker == 0) {
        switch(color) {
            case GREEN:
                printf("      .--.\n");
                printf("   .-(    ).\n");
                printf("  (___.__)__) GREEN\n\n");
                break;
            case YELLOW:
                printf("      .--.\n");
                printf("   .-(    ).\n");
                printf("  (___.__)__) YELLOW\n\n");
                break;
            case RED:
                printf("      .--.\n");
                printf("   .-(    ).\n");
                printf("  (___.__)__) RED\n\n");
                break;
        }
    } else {
        printf("     .--.\n");
        printf("  .-(    ).\n");
        printf(" (___.--\n\n");
    }
}

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Initialize traffic light cycle variables
    int greenTime = 5;
    int yellowTime = 3;
    int redTime = 10;
    int startTime = time(NULL);
    int timeElapsed = 0;
    int trafficLightColor = GREEN;
    
    // Display initial traffic light color
    displayTrafficLight(trafficLightColor);
    
    // Traffic light cycle loop
    while(1) {
        // Calculate time elapsed since last traffic light change
        timeElapsed = time(NULL) - startTime;
        
        // Change traffic light color based on time elapsed
        if (trafficLightColor == GREEN && timeElapsed >= greenTime) {
            trafficLightColor = YELLOW;
            startTime = time(NULL);
            displayTrafficLight(trafficLightColor);
        } else if (trafficLightColor == YELLOW && timeElapsed >= yellowTime) {
            trafficLightColor = RED;
            startTime = time(NULL);
            displayTrafficLight(trafficLightColor);
        } else if (trafficLightColor == RED && timeElapsed >= redTime) {
            trafficLightColor = GREEN;
            startTime = time(NULL);
            displayTrafficLight(trafficLightColor);
        }
    }
    
    return 0;
}