//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold user data
typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
} User;

// Function prototypes
void get_user_data(User* user);
float calculate_bmi(float weight, float height);

int main() {
    // Initialize user data
    User user = {.name = "",.age = 0,.weight = 0,.height = 0,.bmi = 0};

    // Get user data
    get_user_data(&user);

    // Calculate BMI
    user.bmi = calculate_bmi(user.weight, user.height);

    // Print user data
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %f\n", user.weight);
    printf("Height: %f\n", user.height);
    printf("BMI: %f\n", user.bmi);

    return 0;
}

// Function to get user data
void get_user_data(User* user) {
    printf("Enter your name: ");
    scanf("%s", user->name);

    printf("Enter your age: ");
    scanf("%d", &user->age);

    printf("Enter your weight (in kg): ");
    scanf("%f", &user->weight);

    printf("Enter your height (in cm): ");
    scanf("%f", &user->height);
}

// Function to calculate BMI
float calculate_bmi(float weight, float height) {
    return weight / (height * height);
}