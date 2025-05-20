//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define the traffic light states
#define RED 0
#define YELLOW 1
#define GREEN 2

//Define the duration of each traffic light state in seconds
#define RED_DURATION 10
#define YELLOW_DURATION 5
#define GREEN_DURATION 15

//Define the total duration of the traffic light cycle in seconds
#define TOTAL_DURATION (RED_DURATION + YELLOW_DURATION + GREEN_DURATION)

void trafficLightController() {
    int state = RED; //Initialize the traffic light state to red
    time_t startTime; //Declare a variable to store the start time of the traffic light cycle
    time_t currentTime; //Declare a variable to store the current time

    srand(time(NULL)); //Seed the random number generator with the current time

    startTime = time(NULL); //Store the start time of the traffic light cycle in the startTime variable

    while (1) {
        currentTime = time(NULL); //Store the current time in the currentTime variable

        if (currentTime - startTime >= TOTAL_DURATION) { //Check if the traffic light cycle has completed
            startTime = currentTime; //Reset the start time of the traffic light cycle
        }

        switch (state) {
            case RED:
                printf("The traffic light is red.\n");
                break;
            case YELLOW:
                printf("The traffic light is yellow.\n");
                break;
            case GREEN:
                printf("The traffic light is green.\n");
                break;
            default:
                printf("Invalid traffic light state.\n");
                break;
        }

        if (state == RED) {
            state = GREEN; //Change the traffic light state from red to green
        } else if (state == GREEN) {
            state = YELLOW; //Change the traffic light state from green to yellow
        } else if (state == YELLOW) {
            state = RED; //Change the traffic light state from yellow to red
        }

        sleep(1); //Pause for 1 second before updating the traffic light state again
    }
}

int main() {
    trafficLightController(); //Call the trafficLightController function to start the traffic light controller
    return 0;
}