//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
/* C Fitness Tracker Example in Claude Shannon Style */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double distance;
    double speed;
    double calories;
    int duration;
} FitnessData;

double calculate_distance(double speed, int duration) {
    return speed * duration;
}

double calculate_speed(double distance, int duration) {
    return distance / duration;
}

double calculate_calories(double weight, double speed, int duration) {
    return 0.75 * weight * speed * speed * duration / 200;
}

void print_fitness_data(FitnessData data) {
    printf("Distance: %.2f km\n", data.distance);
    printf("Speed: %.2f km/h\n", data.speed);
    printf("Calories: %.2f kcal\n", data.calories);
    printf("Duration: %d minutes\n", data.duration);
}

int main() {
    // Variables to store user input
    double weight;
    double distance;
    int duration;

    // Get user input
    printf("Enter your weight in kilograms: ");
    scanf("%lf", &weight);
    printf("Enter the distance in kilometers: ");
    scanf("%lf", &distance);
    printf("Enter the duration in minutes: ");
    scanf("%d", &duration);

    // Calculate fitness data
    FitnessData data = {
        .distance = distance,
        .speed = calculate_speed(distance, duration),
        .calories = calculate_calories(weight, data.speed, duration),
        .duration = duration
    };

    // Print fitness data
    printf("\nFitness Data:\n");
    print_fitness_data(data);

    return 0;
}