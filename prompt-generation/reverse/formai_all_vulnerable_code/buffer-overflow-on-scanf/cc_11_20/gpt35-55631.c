//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    // initialize traffic light variables for each lane
    int north = 1; 
    int south = 1; 
    int east = 1; 
    int west = 1; 
    
    // set the pattern time for each light in seconds
    int green_time = 10;
    int yellow_time = 3; 

    printf("\nReady to rock and roll! The traffic light controller is starting the simulation.\n");

    // endless loop for simulation
    while(1) {

        // check for user input to stop the simulation
        char stop_sim;
        printf("Type 'S' to stop the simulation:");
        scanf("%c", &stop_sim);
        if (stop_sim == 'S' || stop_sim == 's') {
            printf("\nSimulation has ended. Thanks for playing!\n");
            return 0; 
        }

        // set the random seed for unpredictable traffic conditions
        srand(time(0));
        int traffic_flow = rand() % 10; // random number between 0 and 9 

        // NORTH-SOUTH Traffic Flow
        if (traffic_flow % 2 == 0) {

            // set North-South lights to green, East-West lights to red
            north = 1;
            south = 1;
            east = 0;
            west = 0;

            printf("\n----------------------------\n");
            printf("\nNORTH-SOUTH TRAFFIC FLOW:\n");
            printf("Green light for North and South lanes, Red light for East and West lanes.\n");

            for (int i = 0; i < green_time; i++) {
                printf("Time remaining: %d seconds\n", green_time - i);
                sleep(1); // wait for 1 second
            }

            // set North-South lights to yellow, East-West lights to red
            north = 0;
            south = 0;

            printf("\nYellow light for North and South lanes, Red light for East and West lanes.\n");

            for (int i = 0; i < yellow_time; i++) {
                printf("Time remaining: %d seconds\n", yellow_time - i);
                sleep(1); // wait for 1 second
            }

            // set North-South lights to red, East-West lights to green
            east = 1;
            west = 1;
    
            printf("\nRed light for North and South lanes, Green light for East and West lanes.\n");
            printf("\n----------------------------\n");

            for (int i = 0; i < green_time; i++) {
                printf("Time remaining: %d seconds\n", green_time - i);
                sleep(1); // wait for 1 second
            }

            // set North-South lights to red, East-West lights to yellow
            east = 0;
            west = 0;

            printf("\nRed light for North and South lanes, Yellow light for East and West lanes.\n");

            for (int i = 0; i < yellow_time; i++) {
                printf("Time remaining: %d seconds\n", yellow_time - i);
                sleep(1); // wait for 1 second
            }
        }

        // EAST-WEST Traffic Flow
        else {

            // set East-West lights to green, North-South lights to red
            north = 0;
            south = 0;
            east = 1;
            west = 1;

            printf("\n----------------------------\n");
            printf("\nEAST-WEST TRAFFIC FLOW:\n");
            printf("Green light for East and West lanes, Red light for North and South lanes.\n");

            for (int i = 0; i < green_time; i++) {
                printf("Time remaining: %d seconds\n", green_time - i);
                sleep(1); // wait for 1 second
            }

            // set East-West lights to yellow, North-South lights to red
            east = 0;
            west = 0;

            printf("\nYellow light for East and West lanes, Red light for North and South lanes.\n");

            for (int i = 0; i < yellow_time; i++) {
                printf("Time remaining: %d seconds\n", yellow_time - i);
                sleep(1); // wait for 1 second
            }

            // set East-West lights to red, North-South lights to green
            north = 1;
            south = 1;

            printf("\nRed light for East and West lanes, Green light for North and South lanes.\n");
            printf("\n----------------------------\n");

            for (int i = 0; i < green_time; i++) {
                printf("Time remaining: %d seconds\n", green_time - i);
                sleep(1); // wait for 1 second
            }

            // set East-West lights to red, North-South lights to yellow
            north = 0;
            south = 0;

            printf("\nRed light for East and West lanes, Yellow light for North and South lanes.\n");

            for (int i = 0; i < yellow_time; i++) {
                printf("Time remaining: %d seconds\n", yellow_time - i);
                sleep(1); // wait for 1 second
            }
        }
    }
    // end of program
    return 0;
 }