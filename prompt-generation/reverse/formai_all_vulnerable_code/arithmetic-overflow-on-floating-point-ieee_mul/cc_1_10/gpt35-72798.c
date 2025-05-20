//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>

struct FitnessTracker {
    char name[20];
    int age;
    float weight;
    float height;
    float BMI;
    int steps;
};

void calculateBMI(struct FitnessTracker *device) {
    float heightInMeters = device->height / 100;
    device->BMI = device->weight / (heightInMeters * heightInMeters);
}

int main() {
    struct FitnessTracker user;
    printf("Welcome to the C Fitness Tracker\n");

    printf("Enter your name: ");
    scanf("%s", &user.name);
    printf("Enter your age: ");
    scanf("%d", &user.age);
    printf("Enter your weight in kg: ");
    scanf("%f", &user.weight);
    printf("Enter your height in cm: ");
    scanf("%f", &user.height);

    calculateBMI(&user);

    printf("Hello %s, your BMI is %.2f\n", user.name, user.BMI);

    int goalSteps;
    printf("What is your daily step goal? ");
    scanf("%d", &goalSteps);

    int totalSteps = 0;
    int inputSteps;
    do {
        printf("Enter the number of steps taken: ");
        scanf("%d", &inputSteps);
        totalSteps += inputSteps;
        printf("Total steps taken: %d\n", totalSteps);
    } while (totalSteps < goalSteps);

    printf("Congratulations, you reached your daily step goal!\n");

    return 0;
}