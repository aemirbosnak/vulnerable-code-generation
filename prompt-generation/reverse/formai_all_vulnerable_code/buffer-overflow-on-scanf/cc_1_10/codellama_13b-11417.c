//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: standalone
/*
 * Fitness Tracker Example Program
 *
 * This program tracks the user's daily physical activity and
 * provides a summary of their progress over time.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the data structure for a daily activity log
typedef struct {
    int steps;
    int calories;
    int distance;
    int duration;
} activity_log;

// Define the data structure for a user's progress
typedef struct {
    int total_steps;
    int total_calories;
    int total_distance;
    int total_duration;
    int current_streak;
    int longest_streak;
} user_progress;

// Function to calculate the user's progress
void calculate_progress(user_progress *progress, activity_log *log) {
    progress->total_steps += log->steps;
    progress->total_calories += log->calories;
    progress->total_distance += log->distance;
    progress->total_duration += log->duration;

    // Check if the current streak has ended
    if (log->steps == 0) {
        progress->current_streak = 0;
    } else {
        progress->current_streak++;
    }

    // Update the longest streak
    if (progress->current_streak > progress->longest_streak) {
        progress->longest_streak = progress->current_streak;
    }
}

// Function to display the user's progress
void display_progress(user_progress *progress) {
    printf("Total steps: %d\n", progress->total_steps);
    printf("Total calories burned: %d\n", progress->total_calories);
    printf("Total distance traveled: %d\n", progress->total_distance);
    printf("Total time spent exercising: %d\n", progress->total_duration);
    printf("Current streak: %d\n", progress->current_streak);
    printf("Longest streak: %d\n", progress->longest_streak);
}

int main() {
    // Initialize the user's progress
    user_progress progress = {0, 0, 0, 0, 0, 0};

    // Initialize the activity log
    activity_log log = {0, 0, 0, 0};

    // Prompt the user for their daily activity
    printf("Enter today's activity:\n");
    printf("Steps: ");
    scanf("%d", &log.steps);
    printf("Calories burned: ");
    scanf("%d", &log.calories);
    printf("Distance traveled: ");
    scanf("%d", &log.distance);
    printf("Duration (in minutes): ");
    scanf("%d", &log.duration);

    // Calculate the user's progress
    calculate_progress(&progress, &log);

    // Display the user's progress
    display_progress(&progress);

    return 0;
}