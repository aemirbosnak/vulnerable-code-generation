//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
// Define the colored lights as an enumeration 
enum colors {RED, YELLOW, GREEN};
 
// Allocate time intervals for each colored light 
const int RED_TIME = 10, YELLOW_TIME = 3, GREEN_TIME = 10;
 
// Delay function that uses the clock() function to pause 
// the program for the desired amount of time
void delay(int amount_of_time)
{
    int current_time = clock();
    while (clock() < current_time + amount_of_time);
}
 
int main()
{
    // Initialize variables
    int current_light = RED;
    int seconds_remaining = RED_TIME;
 
    printf("\t WELCOME TO THE C TRAFFIC LIGHT CONTROLLER \n\n");
 
    // Implement infinite loop to simulate the traffic light changing colors 
    while (1) {
        // Switch statement that controls the current light 
        switch (current_light) {
            case RED:
                // Display the red light 
                printf("RED\n");
 
                // Decrement the seconds remaining for the current light 
                seconds_remaining--;
 
                // Check if the time limit has been reached 
                if (seconds_remaining == 0) {
                    // Move to the next light and allocate time 
                    current_light = YELLOW;
                    seconds_remaining = YELLOW_TIME;
                }
                break;
            case YELLOW:
                // Display the yellow light 
                printf("YELLOW\n");
 
                // Decrement the seconds remaining for the current light 
                seconds_remaining--;
 
                // Check if the time limit has been reached 
                if (seconds_remaining == 0) {
                    // Move to the next light and allocate time 
                    current_light = GREEN;
                    seconds_remaining = GREEN_TIME;
                }
                break;
            case GREEN:
                // Display the green light 
                printf("GREEN\n");
 
                // Decrement the seconds remaining for the current light 
                seconds_remaining--;
 
                // Check if the time limit has been reached 
                if (seconds_remaining == 0) {
                    // Move to the next light and allocate time 
                    current_light = RED;
                    seconds_remaining = RED_TIME;
                }
                break;
        }
 
        // Delay function to simulate actual time intervals 
        delay(1000);
    }
    return 0;
}