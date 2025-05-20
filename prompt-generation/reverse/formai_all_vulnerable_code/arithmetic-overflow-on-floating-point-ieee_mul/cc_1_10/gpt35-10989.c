//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: careful
#include <stdio.h>

// function to calculate BMI
float calculateBMI(float weight, float height) {
    float bmi = (weight / (height * height)) * 703;
    return bmi;
}

// function to calculate daily caloric needs
int calculateCalories(int age, char gender, float weight, float height, float workoutLevel) {
    int calories;
    if (gender == 'M') {
        calories = (int)((88.36 + (13.4 * weight) + (4.8 * height * 30.48) - (5.7 * age)) * workoutLevel);
    } else {
        calories = (int)((447.6 + (9.2 * weight) + (3.1 * height * 30.48) - (4.3 * age)) * workoutLevel);
    }
    return calories;
}

int main() {
    float weight, height, workoutLevel;
    int age, calories;
    char gender;

    printf("------ Welcome to Fitness Tracker ------\n");

    // prompt user for weight and height
    printf("Enter your weight in pounds: ");
    scanf("%f", &weight);
    printf("Enter your height in feet: ");
    scanf("%f", &height);

    // prompt user for age and gender
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your gender (M/F): ");
    scanf(" %c", &gender);

    // prompt user for workout level
    printf("Enter your workout level (1- Sedentary, 1.2- Lightly active, 1.4- Moderately active, 1.6- Very active, 1.8- Super active): ");
    scanf("%f", &workoutLevel);

    // calculate BMI and display it
    float bmi = calculateBMI(weight, height);
    printf("\nYour BMI is: %.2f\n\n", bmi);

    // calculate daily caloric needs and display it
    calories = calculateCalories(age, gender, weight, height, workoutLevel);
    printf("Your daily caloric needs are: %d calories\n\n", calories);

    printf("------ Thank you for using Fitness Tracker ------");
    return 0;
}