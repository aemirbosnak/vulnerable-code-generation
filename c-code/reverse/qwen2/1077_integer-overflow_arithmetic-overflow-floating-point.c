#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_AGE 120
#define MIN_AGE 5
#define MAX_HEIGHT 300
#define MIN_HEIGHT 40
#define MAX_WEIGHT 600
#define MIN_WEIGHT 10

double calculateBMI(double weight, double height) {
    return weight / (height * height);
}

int calculateCalories(int age, double weight, int activityLevel) {
    const int base = 70;
    if (age < MIN_AGE || age > MAX_AGE || weight < MIN_WEIGHT || weight > MAX_WEIGHT) return -1;
    switch(activityLevel) {
        case 1: return base + (weight * 1.2); // Sedentary
        case 2: return base + (weight * 1.375); // Lightly Active
        case 3: return base + (weight * 1.55); // Moderately Active
        case 4: return base + (weight * 1.725); // Very Active
        case 5: return base + (weight * 1.9); // Super Active
        default: return -1; // Invalid activity level
    }
}

int main() {
    double weight, height;
    int age, activityLevel;

    printf("Enter your weight in kilograms: ");
    scanf("%lf", &weight);

    printf("Enter your height in centimeters: ");
    scanf("%lf", &height);

    printf("Enter your age in years: ");
    scanf("%d", &age);

    printf("Enter your activity level (1-5): ");
    scanf("%d", &activityLevel);

    if (weight <= 0 || height <= 0 || age <= 0 || activityLevel < 1 || activityLevel > 5) {
        printf("Invalid input.\n");
        return 1;
    }

    double bmi = calculateBMI(weight, height);
    int calories = calculateCalories(age, weight, activityLevel);

    if (bmi == -1 || calories == -1) {
        printf("Error calculating BMI or daily calorie needs.\n");
        return 1;
    }

    printf("Your BMI is: %.2f\n", bmi);
    printf("Your daily calorie needs are: %d\n", calories);

    return 0;
}
