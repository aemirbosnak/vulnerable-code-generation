//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to get user input
int getUserInput() {
    int input;
    printf("Enter your daily fitness score (1-10): ");
    scanf("%d", &input);
    return input;
}

int main() {
    // initialize variables
    int totalScore = 0;
    int maxScore = 0;
    int minScore = 10;

    // get current time
    time_t currentTime;
    time(&currentTime);

    // print header
    printf("------------------\n");
    printf("Fitness Tracker\n");
    printf("------------------\n\n");

    // loop to get user input and update variables
    for (int i = 0; i < 7; i++) {
        int dailyScore = getUserInput();
        totalScore += dailyScore;
        if (dailyScore > maxScore) {
            maxScore = dailyScore;
        }
        if (dailyScore < minScore) {
            minScore = dailyScore;
        }
    }

    // calculate average score
    double averageScore = (double)totalScore / 7.0;

    // print summary
    printf("\n------------Summary------------\n");
    printf("Total Score: %d\n", totalScore);
    printf("Average Score: %.2f\n", averageScore);
    printf("Highest Score: %d\n", maxScore);
    printf("Lowest Score: %d\n", minScore);
    printf("Date: %s", ctime(&currentTime));

    return 0;
}