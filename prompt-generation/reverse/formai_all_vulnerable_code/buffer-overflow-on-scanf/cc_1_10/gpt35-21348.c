//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// create a struct to hold fitness tracker data
struct fitnessTracker {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
    int steps;
    int minutesExercised;
};

// function to calculate BMI based on weight and height
float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

// function to print out the fitness tracker data
void printFitnessTracker(struct fitnessTracker tracker) {
    printf("\n%s's Fitness Tracker:\n", tracker.name);
    printf("Age: %d\n", tracker.age);
    printf("Weight: %.2f lbs\n", tracker.weight);
    printf("Height: %.2f m\n", tracker.height);
    printf("BMI: %.2f\n", tracker.bmi);
    printf("Steps: %d\n", tracker.steps);
    printf("Minutes Exercised: %d\n", tracker.minutesExercised);
}

int main() {
    // create a new fitness tracker
    struct fitnessTracker user;
    
    // get user input for name, age, weight, and height
    printf("Welcome to the Fitness Tracker program!\n\n");
    printf("Please enter your name: ");
    fgets(user.name, 50, stdin);
    
    printf("Please enter your age: ");
    scanf("%d", &user.age);
    
    printf("Please enter your weight (in lbs): ");
    scanf("%f", &user.weight);
    
    printf("Please enter your height (in m): ");
    scanf("%f", &user.height);
    
    // calculate BMI based on user input
    user.bmi = calculateBMI(user.weight, user.height);
    
    // set initial steps and minutes exercised to 0
    user.steps = 0;
    user.minutesExercised = 0;
    
    // print out user's fitness tracker data
    printFitnessTracker(user);
    
    // start tracking user's steps
    srand(time(NULL));
    for (int i = 1; i <= 7; i++) {
        int dailySteps = rand() % 10000 + 2000;
        user.steps += dailySteps;
        printf("\nDay %d Steps: %d", i, dailySteps);
    }
    printf("\n\nTotal Steps: %d", user.steps);
    
    // ask user if they've exercised and track minutes exercised
    char response;
    printf("\n\nDid you exercise today? (y/n): ");
    scanf(" %c", &response);
    if (response == 'y' || response == 'Y') {
        int minutes;
        printf("How many minutes did you exercise?: ");
        scanf("%d", &minutes);
        user.minutesExercised += minutes;
        printf("\nTotal Minutes Exercised: %d\n", user.minutesExercised);
    }
    
    // print out updated fitness tracker data
    printFitnessTracker(user);
    
    return 0;
}