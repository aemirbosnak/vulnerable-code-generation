//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: puzzling
/*
 * Fitness Tracker
 *
 * This program tracks the user's fitness progress and calculates their BMI.
 * It also provides recommendations for improving their fitness based on their BMI.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure to store user's fitness data
typedef struct {
    float weight;
    float height;
    float age;
    float steps;
    float distance;
    float calories;
} FitnessData;

// Function to calculate the BMI
float calculateBMI(FitnessData *data) {
    return (data->weight / (data->height * data->height));
}

// Function to provide recommendations based on BMI
void provideRecommendations(FitnessData *data) {
    float bmi = calculateBMI(data);
    if (bmi < 18.5) {
        printf("You are underweight. You should eat more and exercise more to gain weight.");
    } else if (bmi >= 18.5 && bmi < 25) {
        printf("You are at a healthy weight. Keep up the good work!");
    } else if (bmi >= 25 && bmi < 30) {
        printf("You are overweight. You should try to reduce your calorie intake and exercise more.");
    } else {
        printf("You are obese. You should consult a doctor to determine the best course of action for your health.");
    }
}

int main() {
    // Get the user's fitness data
    FitnessData data;
    printf("Enter your weight in pounds: ");
    scanf("%f", &data.weight);
    printf("Enter your height in inches: ");
    scanf("%f", &data.height);
    printf("Enter your age: ");
    scanf("%f", &data.age);
    printf("Enter the number of steps you took today: ");
    scanf("%f", &data.steps);
    printf("Enter the distance you walked today in miles: ");
    scanf("%f", &data.distance);
    printf("Enter the number of calories you burned today: ");
    scanf("%f", &data.calories);

    // Calculate the BMI and provide recommendations
    float bmi = calculateBMI(&data);
    printf("Your BMI is %f\n", bmi);
    provideRecommendations(&data);

    return 0;
}