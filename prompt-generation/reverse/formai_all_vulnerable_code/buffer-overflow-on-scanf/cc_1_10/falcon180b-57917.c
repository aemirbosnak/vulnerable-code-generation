//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[100];
    int age;
    int height;
    int weight;
} User;

void createUser(User* user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your height (in cm): ");
    scanf("%d", &user->height);
    printf("Enter your weight (in kg): ");
    scanf("%d", &user->weight);
}

void displayUser(User user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Height: %d cm\n", user.height);
    printf("Weight: %d kg\n", user.weight);
}

void calculateBMI(User user, float* bmi) {
    *bmi = ((float)user.weight / (user.height * user.height)) * 10000;
}

void trackFitness(User user, int days, float* bmi) {
    for (int i = 0; i < days; i++) {
        printf("Day %d:\n", i+1);
        displayUser(user);
        calculateBMI(user, bmi);
        printf("BMI: %.2f\n\n", *bmi);
    }
}

int main() {
    User user;
    float bmi;
    int days;

    printf("Enter the number of days you want to track your fitness: ");
    scanf("%d", &days);

    createUser(&user);

    trackFitness(user, days, &bmi);

    return 0;
}