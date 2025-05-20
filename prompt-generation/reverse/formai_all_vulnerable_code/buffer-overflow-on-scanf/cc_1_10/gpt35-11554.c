//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MIN_HEART_RATE = 50;
const int MAX_HEART_RATE = 220;
const int MAX_STEPS_PER_DAY = 20000;
const int MAX_CALORIES_PER_DAY = 5000;

// function to generate random heart rate
int generateRandomHeartRate() {
    int hr = rand() % (MAX_HEART_RATE - MIN_HEART_RATE + 1) + MIN_HEART_RATE;
    return hr;
}

// function to track fitness progress
void trackFitness() {
    int heartRate;
    int steps;
    int calories;
    int totalSteps = 0;
    int totalCalories = 0;
    time_t now;

    printf("Welcome to the Fitness Tracker!\n\n");

    // get current time
    time(&now);

    // print current time
    printf("Today is %s", ctime(&now));

    // loop for tracking progress throughout the day
    while(1) {
        // generate random heart rate
        heartRate = generateRandomHeartRate();
        printf("Current heart rate: %d\n", heartRate);

        // get user input for steps and calculate calories burned
        printf("Enter how many steps you have taken so far today: ");
        scanf("%d", &steps);
        calories = steps * 0.05;
        printf("You have burned %d calories so far!\n", calories);

        // update total steps and calories
        totalSteps += steps;
        totalCalories += calories;

        // check if daily goals are met
        if(totalSteps >= MAX_STEPS_PER_DAY) {
            printf("Congratulations! You have met your daily step goal of %d!\n", MAX_STEPS_PER_DAY);
            break;
        }
        if(totalCalories >= MAX_CALORIES_PER_DAY) {
            printf("Congratulations! You have exceeded your target calories burned for the day of %d!\n", MAX_CALORIES_PER_DAY);
            break;
        }

        // delay for 5 seconds before looping again
        printf("Tracking progress again in 5 seconds...\n\n");
        sleep(5);
    }
}

int main() {
    // seed the random number generator based on system time
    srand(time(NULL));

    // call the trackFitness function
    trackFitness();

    return 0;
}