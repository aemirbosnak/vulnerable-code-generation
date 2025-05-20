//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int steps;
    int distance;
    int calories;
    int height;
    int weight;
} FitnessTracker;

void initializeTracker(FitnessTracker* tracker) {
    tracker->steps = 0;
    tracker->distance = 0;
    tracker->calories = 0;
    tracker->height = 0;
    tracker->weight = 0;
}

void updateTracker(FitnessTracker* tracker, int steps, int distance, int calories) {
    tracker->steps += steps;
    tracker->distance += distance;
    tracker->calories += calories;
}

int calculateCalories(int height, int weight) {
    return (weight * 4) / 45;
}

int main() {
    FitnessTracker tracker;
    initializeTracker(&tracker);

    printf("Enter your height in inches: ");
    scanf("%d", &tracker.height);

    printf("Enter your weight in pounds: ");
    scanf("%d", &tracker.weight);

    int steps;
    int distance;
    int calories;

    printf("How many steps did you take? ");
    scanf("%d", &steps);

    printf("How far did you travel in miles? ");
    scanf("%d", &distance);

    printf("How many calories did you burn? ");
    scanf("%d", &calories);

    updateTracker(&tracker, steps, distance, calories);

    printf("Steps: %d\n", tracker.steps);
    printf("Distance: %d miles\n", tracker.distance);
    printf("Calories burned: %d\n", tracker.calories);

    printf("Calculated calories: %d\n", calculateCalories(tracker.height, tracker.weight));

    return 0;
}