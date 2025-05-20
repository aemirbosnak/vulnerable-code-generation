//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a fitness tracker
struct fitness_tracker {
    char name[50];
    int age;
    float height;
    float weight;
    float bmi;
    int steps;
    int calories_burned;
};

// Function to calculate the BMI
float calculate_bmi(struct fitness_tracker *tracker) {
    return (tracker->weight / (tracker->height * tracker->height));
}

// Function to calculate the calories burned based on steps taken
int calculate_calories_burned(struct fitness_tracker *tracker) {
    return (tracker->steps * 0.05);
}

// Function to display the fitness tracker data
void display_fitness_tracker(struct fitness_tracker *tracker) {
    printf("Name: %s\n", tracker->name);
    printf("Age: %d\n", tracker->age);
    printf("Height: %f\n", tracker->height);
    printf("Weight: %f\n", tracker->weight);
    printf("BMI: %f\n", calculate_bmi(tracker));
    printf("Steps: %d\n", tracker->steps);
    printf("Calories Burned: %d\n", calculate_calories_burned(tracker));
}

// Main function
int main() {
    // Create a fitness tracker object
    struct fitness_tracker tracker;

    // Get user input for the fitness tracker data
    printf("Enter your name: ");
    scanf("%s", tracker.name);
    printf("Enter your age: ");
    scanf("%d", &tracker.age);
    printf("Enter your height (in cm): ");
    scanf("%f", &tracker.height);
    printf("Enter your weight (in kg): ");
    scanf("%f", &tracker.weight);
    printf("Enter the number of steps taken today: ");
    scanf("%d", &tracker.steps);

    // Display the fitness tracker data
    display_fitness_tracker(&tracker);

    return 0;
}