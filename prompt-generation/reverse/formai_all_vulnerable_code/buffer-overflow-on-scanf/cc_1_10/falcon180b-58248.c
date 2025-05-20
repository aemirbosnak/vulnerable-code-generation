//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define a structure to store user data
struct user_data {
    char name[50];
    int age;
    int height;
    int weight;
    int steps;
    int calories_burned;
};

// Function to initialize user data
void init_user_data(struct user_data *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);

    printf("Enter your age: ");
    scanf("%d", &user->age);

    printf("Enter your height in cm: ");
    scanf("%d", &user->height);

    printf("Enter your weight in kg: ");
    scanf("%d", &user->weight);

    printf("Enter the number of steps you take per day: ");
    scanf("%d", &user->steps);
}

// Function to calculate calories burned based on user data
int calculate_calories_burned(struct user_data user) {
    int calories_burned = 0;

    double basal_metabolic_rate = (10 * user.weight) + (6.25 * user.height) - (5 * user.age);
    double activity_level = 1.2; // Sedentary

    if (user.steps > 5000) {
        activity_level = 1.375; // Lightly active
    } else if (user.steps > 7500) {
        activity_level = 1.55; // Moderately active
    } else if (user.steps > 10000) {
        activity_level = 1.725; // Very active
    } else if (user.steps > 12500) {
        activity_level = 1.9; // Extra active
    }

    double calories_burned_per_day = (basal_metabolic_rate * activity_level) / 24;
    calories_burned = (int) calories_burned_per_day;

    return calories_burned;
}

// Function to display user data and calories burned
void display_user_data(struct user_data user, int calories_burned) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Height: %d cm\n", user.height);
    printf("Weight: %d kg\n", user.weight);
    printf("Steps per day: %d\n", user.steps);
    printf("Calories burned per day: %d\n", calories_burned);
}

int main() {
    struct user_data user;
    init_user_data(&user);

    int calories_burned = calculate_calories_burned(user);

    display_user_data(user, calories_burned);

    return 0;
}