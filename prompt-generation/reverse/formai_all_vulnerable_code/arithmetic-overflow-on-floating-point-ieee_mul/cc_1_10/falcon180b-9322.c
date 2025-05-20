//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a struct to hold the user's fitness data
typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
    int steps;
    int distance;
    float calories;
} User;

// Function prototypes
void getUserInput(User* user);
float calculateBMI(float weight, float height);
float calculateCalories(int steps, float distance);

// Main function
int main() {
    User user;
    getUserInput(&user);
    printf("Hello, %s! You are %d years old, %d cm tall, and weigh %d kg.\n", user.name, user.age, (int)user.height, user.weight);
    printf("Your BMI is %.2f, and you have burned %.2f calories today.\n", calculateBMI(user.weight, user.height), calculateCalories(user.steps, user.distance));
    return 0;
}

// Function to get user input
void getUserInput(User* user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your weight in kg: ");
    scanf("%f", &user->weight);
    printf("Enter your height in cm: ");
    scanf("%f", &user->height);
    printf("Enter the number of steps you took today: ");
    scanf("%d", &user->steps);
    printf("Enter the distance you walked today in km: ");
    scanf("%f", &user->distance);
}

// Function to calculate BMI
float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

// Function to calculate calories burned
float calculateCalories(int steps, float distance) {
    float calories = 0.0;
    if (steps > 0 && distance > 0) {
        calories = (0.0175 * steps) + (0.035 * distance) + (3.5 * (distance * distance) / 200);
    }
    return calories;
}