//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to hold fitness data of a user
typedef struct {
    char name[50];
    int age;
    int height;
    int weight;
    float bmi;
    int heart_rate;
    int steps;
    int calories;
} FitnessData;

// Function to calculate BMI
float calculate_bmi(int weight, int height) {
    float bmi = (float)weight / ((float)height / 100 * (float)height / 100);
    return bmi;
}

// Function to calculate calories burned with given heart rate and steps
int calculate_calories_burned(int heart_rate, int steps) {
    int calories = ((float)heart_rate / 100) * ((float)steps / 20);
    return calories;
}

// Function to randomly generate heart rate readings
int generate_heart_rate() {
    int min_heart_rate = 60;
    int max_heart_rate = 200;
    int heart_rate = rand() % (max_heart_rate - min_heart_rate + 1) + min_heart_rate;
    return heart_rate;
}

// Function to randomly generate step count readings
int generate_steps() {
    int min_steps = 1000;
    int max_steps = 15000;
    int steps = rand() % (max_steps - min_steps + 1) + min_steps;
    return steps;
}

// Function to log fitness data for a user
void log_fitness_data(FitnessData *data) {
    data->heart_rate = generate_heart_rate();
    data->steps = generate_steps();
    data->calories = calculate_calories_burned(data->heart_rate, data->steps);
    data->bmi = calculate_bmi(data->weight, data->height);
}

// Function to print fitness data for a user
void print_fitness_data(FitnessData data) {
    printf("Name: %s\n", data.name);
    printf("Age: %d\n", data.age);
    printf("Height: %d cm\n", data.height);
    printf("Weight: %d kg\n", data.weight);
    printf("BMI: %.2f\n", data.bmi);
    printf("Heart Rate: %d bpm\n", data.heart_rate);
    printf("Steps: %d\n", data.steps);
    printf("Calories Burned: %d\n", data.calories);
}

int main() {
    FitnessData user;
    printf("Enter your name: ");
    scanf("%s", user.name);
    printf("Enter your age: ");
    scanf("%d", &user.age);
    printf("Enter your height (cm): ");
    scanf("%d", &user.height);
    printf("Enter your weight (kg): ");
    scanf("%d", &user.weight);

    srand(time(NULL)); // Seed random number generator

    log_fitness_data(&user);
    print_fitness_data(user);

    return 0;
}