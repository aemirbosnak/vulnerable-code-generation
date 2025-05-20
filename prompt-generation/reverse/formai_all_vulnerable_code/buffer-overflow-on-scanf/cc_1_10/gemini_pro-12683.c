//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the user's profile
typedef struct {
    char name[32];
    int age;
    double height;
    double weight;
    int activity_level;
} user_profile;

// Define the fitness tracker's data
typedef struct {
    time_t timestamp;
    int steps;
    double distance;
    int calories;
    int heart_rate;
} fitness_data;

// Create a new user profile
user_profile create_user_profile() {
    user_profile profile;

    printf("Enter your name: ");
    scanf("%s", profile.name);

    printf("Enter your age: ");
    scanf("%d", &profile.age);

    printf("Enter your height (in inches): ");
    scanf("%lf", &profile.height);

    printf("Enter your weight (in pounds): ");
    scanf("%lf", &profile.weight);

    printf("Enter your activity level (1-5): ");
    scanf("%d", &profile.activity_level);

    return profile;
}

// Create a new fitness data entry
fitness_data create_fitness_data() {
    fitness_data data;

    data.timestamp = time(NULL);

    printf("Enter the number of steps you took: ");
    scanf("%d", &data.steps);

    printf("Enter the distance you traveled (in miles): ");
    scanf("%lf", &data.distance);

    printf("Enter the number of calories you burned: ");
    scanf("%d", &data.calories);

    printf("Enter your heart rate (in beats per minute): ");
    scanf("%d", &data.heart_rate);

    return data;
}

// Print the user's profile
void print_user_profile(user_profile profile) {
    printf("Name: %s\n", profile.name);
    printf("Age: %d\n", profile.age);
    printf("Height: %.2f inches\n", profile.height);
    printf("Weight: %.2f pounds\n", profile.weight);
    printf("Activity level: %d\n", profile.activity_level);
}

// Print the fitness data
void print_fitness_data(fitness_data data) {
    printf("Timestamp: %s", ctime(&data.timestamp));
    printf("Steps: %d\n", data.steps);
    printf("Distance: %.2f miles\n", data.distance);
    printf("Calories: %d\n", data.calories);
    printf("Heart rate: %d bpm\n", data.heart_rate);
}

// Main function
int main() {
    // Create a new user profile
    user_profile profile = create_user_profile();

    // Create a new fitness data entry
    fitness_data data = create_fitness_data();

    // Print the user's profile
    print_user_profile(profile);

    // Print the fitness data
    print_fitness_data(data);

    return 0;
}