//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t currentTime, startTime, endTime;
    struct tm *startTm, *endTm;

    printf("Enter the time you want to travel to (in YYYY-MM-DD HH:MM:SS format): ");
    char inputTime[20];
    fgets(inputTime, 20, stdin);

    // Convert input time to time_t
    struct tm inputTm;
    strptime(inputTime, "%Y-%m-%d %H:%M:%S", &inputTm);
    time_t inputTimeT = mktime(&inputTm);

    // Get current time_t
    currentTime = time(NULL);

    // Set start and end times
    if (difftime(inputTimeT, currentTime) > 0) {
        startTime = currentTime;
        endTime = inputTimeT;
    } else {
        startTime = inputTimeT;
        endTime = currentTime;
    }

    // Convert start and end times to tm structs
    startTm = localtime(&startTime);
    endTm = localtime(&endTime);

    // Print start and end times
    char startStr[20], endStr[20];
    strftime(startStr, 20, "%Y-%m-%d %H:%M:%S", startTm);
    strftime(endStr, 20, "%Y-%m-%d %H:%M:%S", endTm);
    printf("Time travel from %s to %s\n", startStr, endStr);

    // Simulate time travel
    double secondsPerYear = 31557600; // Average seconds per year
    double timeRatio = difftime(endTime, startTime) / secondsPerYear;
    double age;
    printf("Enter your age: ");
    scanf("%lf", &age);
    double newAge = age / (1 - timeRatio);
    printf("If you time travel, you would be %.2f years old!\n", newAge);

    return 0;
}