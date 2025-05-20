//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure to hold user data
typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
    char gender[10];
} User;

// Define the structure to hold fitness data for a user
typedef struct {
    float weight;
    float height;
    bool workout_today;
    bool ate_healthily_today;
} FitnessData;

// Function to get user data
User get_user_data() {
    User user;
    printf("Enter your name: ");
    scanf("%s", user.name);
    printf("Enter your age: ");
    scanf("%d", &user.age);
    printf("Enter your weight (in kg): ");
    scanf("%f", &user.weight);
    printf("Enter your height (in meters): ");
    scanf("%f", &user.height);
    printf("Enter your gender: ");
    scanf("%s", user.gender);
    return user;
}

// Function to get fitness data for a user
FitnessData get_fitness_data() {
    FitnessData fitness_data;
    printf("Did you workout today? (1 for yes, 0 for no): ");
    scanf("%d", &fitness_data.workout_today);
    printf("Did you eat healthily today? (1 for yes, 0 for no): ");
    scanf("%d", &fitness_data.ate_healthily_today);
    return fitness_data;
}

// Function to calculate user's BMI
float calculate_bmi(User user) {
    return user.weight / (user.height * user.height);
}

int main() {
    // Get user data
    User user = get_user_data();

    // Get fitness data for the user
    FitnessData fitness_data = get_fitness_data();

    // Calculate the BMI for the user
    float bmi = calculate_bmi(user);

    // Print the user's information
    printf("\nUser Information:\n");
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %.2f kg\n", user.weight);
    printf("Height: %.2f m\n", user.height);
    printf("Gender: %s\n", user.gender);

    // Print the user's fitness information
    printf("\nFitness Information:\n");
    printf("Workout Today: %s\n", fitness_data.workout_today ? "Yes" : "No");
    printf("Ate Healthily Today: %s\n", fitness_data.ate_healthily_today ? "Yes" : "No");

    // Print the user's BMI
    printf("\nYour BMI is: %.2f\n", bmi);

    return 0;
}