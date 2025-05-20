//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Cryptic
#include <stdio.h>

/* This program is a fitness tracker designed to help users
 * keep track of their exercise routine and progress. It prompts
 * the user to input their workout for the day and checks if they
 * have met their daily fitness goals. The program then generates
 * a report of the user's overall progress over a specified period
 * of time. */

int main() {

    // Declare variables
    int workout, days;
    double goal, progress, avg_progress;

    // Prompt the user for input
    printf("Welcome to the fitness tracker!\n");
    printf("Please enter your workout for the day: ");
    scanf("%d", &workout);
    printf("Please enter your daily fitness goal: ");
    scanf("%lf", &goal);
    printf("How many days would you like to track your progress for? ");
    scanf("%d", &days);

    // Calculate progress and check if goal has been met
    progress = (double)workout / goal * 100;
    if (progress >= 100) {
        printf("Congratulations! You have met your daily goal.\n");
    } else {
        printf("You still have some work to do to meet your daily goal.\n");
    }

    // Calculate average progress over the specified period of time
    avg_progress = 0.0;
    for (int i = 1; i <= days; i++) {
        printf("Enter your workout for day %d: ", i);
        scanf("%d", &workout);
        progress = (double)workout / goal * 100;
        avg_progress += progress;
    }
    avg_progress /= days;

    // Generate progress report
    printf("\n-----PROGRESS REPORT-----\n");
    printf("You have been tracking your progress for %d days.\n", days);
    printf("Your average progress has been %.2lf%%.\n", avg_progress);
    if (avg_progress >= 100) {
        printf("Congratulations! You have met your fitness goals!\n");
    } else {
        printf("Keep up the hard work, you're almost there!\n");
    }

    // Exit program
    return 0;
}