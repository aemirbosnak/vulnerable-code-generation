//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: puzzling
// Fitness Tracker Puzzle
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define struct for user input
struct User {
    char name[50];
    int age;
    float height;
    float weight;
    float daily_steps;
    float daily_calories;
};

// Define struct for user progress
struct Progress {
    int total_steps;
    int total_calories;
    float daily_steps;
    float daily_calories;
    float daily_distance;
    float daily_speed;
};

// Function to get user input
void getUserInput(struct User *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your height: ");
    scanf("%f", &user->height);
    printf("Enter your weight: ");
    scanf("%f", &user->weight);
    printf("Enter your daily steps: ");
    scanf("%f", &user->daily_steps);
    printf("Enter your daily calories: ");
    scanf("%f", &user->daily_calories);
}

// Function to calculate user progress
void calculateProgress(struct User *user, struct Progress *progress) {
    progress->total_steps += user->daily_steps;
    progress->total_calories += user->daily_calories;
    progress->daily_steps = user->daily_steps;
    progress->daily_calories = user->daily_calories;
    progress->daily_distance = user->daily_steps * 0.5;
    progress->daily_speed = progress->daily_distance / progress->daily_steps;
}

// Function to display user progress
void displayProgress(struct Progress *progress) {
    printf("Total steps: %d\n", progress->total_steps);
    printf("Total calories: %d\n", progress->total_calories);
    printf("Daily steps: %f\n", progress->daily_steps);
    printf("Daily calories: %f\n", progress->daily_calories);
    printf("Daily distance: %f\n", progress->daily_distance);
    printf("Daily speed: %f\n", progress->daily_speed);
}

// Main function
int main() {
    struct User user;
    struct Progress progress;
    getUserInput(&user);
    calculateProgress(&user, &progress);
    displayProgress(&progress);
    return 0;
}