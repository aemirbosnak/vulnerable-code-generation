//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: intelligent
#include <stdio.h> //header file for standard input-output operations
#include <time.h> //header file for time functions
#include <stdlib.h> //header file for random number generation

//Definition of traffic light states
#define RED 0
#define GREEN 1
#define YELLOW 2

//Structure for the traffic light
struct TrafficLight {
    int currentState; //current state of the traffic light
    time_t lastSwitchTime; //time of last state switch
};

//Function to generate a random number between min and max
int randomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    //Initialize the traffic light
    struct TrafficLight trafficLight = {RED, time(NULL)};
    
    //Initialize variables for time and state change interval
    time_t currentTime;
    int stateChangeInterval;
    
    //Main loop for the traffic light controller program
    while(1) {
        currentTime = time(NULL);
        
        //Determine the current state of the traffic light and switch to the next state if necessary
        if(trafficLight.currentState == RED) {
            stateChangeInterval = randomNumber(5, 15); //random interval between 5 and 15 seconds
            if(currentTime - trafficLight.lastSwitchTime >= stateChangeInterval) {
                trafficLight.currentState = GREEN;
                trafficLight.lastSwitchTime = currentTime;
                printf("Traffic light switched from RED to GREEN\n");
            }
        }
        else if(trafficLight.currentState == GREEN) {
            stateChangeInterval = randomNumber(15, 25); //random interval between 15 and 25 seconds
            if(currentTime - trafficLight.lastSwitchTime >= stateChangeInterval) {
                trafficLight.currentState = YELLOW;
                trafficLight.lastSwitchTime = currentTime;
                printf("Traffic light switched from GREEN to YELLOW\n");
            }
        }
        else if(trafficLight.currentState == YELLOW) {
            stateChangeInterval = randomNumber(3, 8); //random interval between 3 and 8 seconds
            if(currentTime - trafficLight.lastSwitchTime >= stateChangeInterval) {
                trafficLight.currentState = RED;
                trafficLight.lastSwitchTime = currentTime;
                printf("Traffic light switched from YELLOW to RED\n");
            }
        }
        
        //Delay for 1 second before next iteration
        sleep(1);
    }
    
    return 0;
}