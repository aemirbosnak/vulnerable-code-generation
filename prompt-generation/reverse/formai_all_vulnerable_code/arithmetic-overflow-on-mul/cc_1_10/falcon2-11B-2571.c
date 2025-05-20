//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of days to track
#define DAYS_TO_TRACK 30

// Define the number of steps to reach each day
#define STEPS_GOAL 10000

// Define the heart rate range
#define HEART_RATE_LOW 60
#define HEART_RATE_HIGH 90

// Define the sleep duration range
#define SLEEP_DURATION_LOW 7
#define SLEEP_DURATION_HIGH 9

int main() {
    // Initialize the user's progress
    int steps = 0;
    int heartRate = HEART_RATE_LOW;
    int sleepDuration = SLEEP_DURATION_LOW;

    // Prompt the user to input their daily steps
    printf("Enter your daily steps: ");
    scanf("%d", &steps);

    // Prompt the user to input their heart rate
    printf("Enter your heart rate: ");
    scanf("%d", &heartRate);

    // Prompt the user to input their sleep duration
    printf("Enter your sleep duration: ");
    scanf("%d", &sleepDuration);

    // Calculate the user's total daily activity
    int totalSteps = steps * DAYS_TO_TRACK;
    int totalHeartRate = heartRate * DAYS_TO_TRACK;
    int totalSleepDuration = sleepDuration * DAYS_TO_TRACK;

    // Calculate the user's progress
    float progress = (float)steps / (float)STEPS_GOAL * 100;
    float heartRateProgress = (float)heartRate / (float)HEART_RATE_HIGH * 100;
    float sleepDurationProgress = (float)sleepDuration / (float)SLEEP_DURATION_HIGH * 100;

    // Display the user's progress
    printf("Daily Steps: %d (Progress: %.2f%%)\n", steps, progress);
    printf("Heart Rate: %d (Progress: %.2f%%)\n", heartRate, heartRateProgress);
    printf("Sleep Duration: %d (Progress: %.2f%%)\n", sleepDuration, sleepDurationProgress);

    // Display feedback based on the user's progress
    if (progress >= 75) {
        printf("Great job! You are making excellent progress.\n");
    } else if (progress >= 50) {
        printf("You are doing well, but you can do better.\n");
    } else {
        printf("You need to work harder to reach your goal.\n");
    }

    return 0;
}