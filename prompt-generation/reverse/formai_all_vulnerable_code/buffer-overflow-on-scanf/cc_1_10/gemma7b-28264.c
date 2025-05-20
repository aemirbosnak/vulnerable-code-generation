//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fitness_Tracker {
    char name[20];
    int age;
    double height;
    double weight;
    double target_heart_rate;
    double current_heart_rate;
    double steps_taken;
    double distance_traveled;
    double calories_burned;
};

int main() {
    struct Fitness_Tracker tracker;
    char input[20];

    // Get the user's name, age, height, and weight
    printf("Enter your name: ");
    scanf("%s", tracker.name);

    printf("Enter your age: ");
    scanf("%d", &tracker.age);

    printf("Enter your height (in inches): ");
    scanf("%lf", &tracker.height);

    printf("Enter your weight (in pounds): ");
    scanf("%lf", &tracker.weight);

    // Calculate the user's target heart rate
    tracker.target_heart_rate = 220 - (110 - (1.83 * tracker.height)) * (tracker.age / 2);

    // Get the user's current heart rate
    printf("Enter your current heart rate: ");
    scanf("%lf", &tracker.current_heart_rate);

    // Calculate the user's steps taken and distance traveled
    tracker.steps_taken = 10000;
    tracker.distance_traveled = 5;

    // Calculate the user's calories burned
    tracker.calories_burned = (1.0 * tracker.weight) * tracker.distance_traveled * 6.8;

    // Display the user's fitness tracker data
    printf("\nName: %s", tracker.name);
    printf("\nAge: %d", tracker.age);
    printf("\nHeight: %.2lf inches", tracker.height);
    printf("\nWeight: %.2lf pounds", tracker.weight);
    printf("\nTarget Heart Rate: %.2lf beats per minute", tracker.target_heart_rate);
    printf("\nCurrent Heart Rate: %.2lf beats per minute", tracker.current_heart_rate);
    printf("\nSteps Taken: %d", tracker.steps_taken);
    printf("\nDistance Traveled: %.2lf miles", tracker.distance_traveled);
    printf("\nCalories Burned: %.2lf calories", tracker.calories_burned);

    return 0;
}