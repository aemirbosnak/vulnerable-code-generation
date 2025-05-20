//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct to hold user data
typedef struct {
    char name[50];
    int age;
    int weight;
    int height;
} User;

// Function to calculate BMI
float calculateBMI(int weight, int height) {
    float bmi = weight / (height * height);
    return bmi;
}

// Function to print user data and BMI
void printUserData(User user, float bmi) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %d\n", user.weight);
    printf("Height: %d\n", user.height);
    printf("BMI: %.2f\n", bmi);
}

// Function to get user input
void getUserInput(User *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);

    printf("Enter your age: ");
    scanf("%d", &user->age);

    printf("Enter your weight in kg: ");
    scanf("%d", &user->weight);

    printf("Enter your height in cm: ");
    scanf("%d", &user->height);
}

int main() {
    User user;

    // Get user input
    getUserInput(&user);

    // Calculate BMI
    float bmi = calculateBMI(user.weight, user.height);

    // Print user data and BMI
    printUserData(user, bmi);

    return 0;
}