//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: lively
/* Welcome to our Traffic Light Controller program */
#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

/* Constants */
#define GREEN_LIGHT_DURATION 5000 /* in milliseconds */
#define YELLOW_LIGHT_DURATION 2000
#define RED_LIGHT_DURATION 4000
#define INITIAL_DELAY 2000

/* Function prototypes */
void printInstructions();
bool isInputValid(char input);
void runTrafficLightController();

/* Main function */
int main(){
    char input;

    printInstructions();

    do {
        printf("\nEnter 'Y' to start or 'Q' to quit: ");
        scanf(" %c", &input);
        input = toupper(input);
    } while(!isInputValid(input));

    if(input == 'Y'){
        runTrafficLightController();
    }

    printf("\nGoodbye!\n");

    return 0;
}

/* Prints out the instructions for the program */
void printInstructions(){
    printf("Welcome to the Traffic Light Controller program!\n");
    printf("This program simulates a traffic light that changes colors every few seconds.\n");
    printf("The colors of the traffic light and their duration are as follows:\n");
    printf("Green: %d seconds\n", GREEN_LIGHT_DURATION/1000);
    printf("Yellow: %d seconds\n", YELLOW_LIGHT_DURATION/1000);
    printf("Red: %d seconds\n", RED_LIGHT_DURATION/1000);
}

/* Checks if the input is valid (either 'Y' or 'Q') */
bool isInputValid(char input){
    if(input == 'Y' || input == 'Q'){
        return true;
    } else {
        printf("\nInvalid input! Please enter either 'Y' or 'Q'.\n");
        return false;
    }
}

/* Runs the traffic light simulation */
void runTrafficLightController(){
    printf("\nRunning Traffic Light Controller...\n\n");

    /* Seed the random number generator */
    srand(time(NULL));

    /* Set the initial state */
    int state = 1; /* 1 = green, 2 = yellow, 3 = red */

    /* Wait for INITIAL_DELAY milliseconds before starting */
    printf("Waiting %d seconds before starting...\n", INITIAL_DELAY/1000);
    printf("======================================\n\n");
    sleep(INITIAL_DELAY);

    /* Main loop */
    while(true){
        /* Print the current state */
        switch(state){
            case 1:
                printf("GREEN LIGHT ON\n");
                sleep(GREEN_LIGHT_DURATION);
                break;

            case 2:
                printf("YELLOW LIGHT ON\n");
                sleep(YELLOW_LIGHT_DURATION);
                break;

            case 3:
                printf("RED LIGHT ON\n");
                sleep(RED_LIGHT_DURATION);
                break;
        }

        /* Change the state */
        int randomNumber = rand() % 3; /* 0, 1, or 2 */
        if(randomNumber == 0){
            state = 1;
        } else if(randomNumber == 1){
            state = 2;
        } else if(randomNumber == 2){
            state = 3;
        }
    }
}