#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    float weight, height, bmi, calories;
    int age, activityLevel;

    printf("Enter your weight in kilograms: ");
    if (scanf("%f", &weight) != 1 || weight <= 0) {
        printf("Invalid input. Please enter a positive number.\n");
        return 1;
    }

    printf("Enter your height in meters: ");
    if (scanf("%f", &height) != 1 || height <= 0) {
        printf("Invalid input. Please enter a positive number.\n");
        return 1;
    }

    printf("Enter your age in years: ");
    if (scanf("%d", &age) != 1 || age <= 0) {
        printf("Invalid input. Please enter a positive number.\n");
        return 1;
    }

    printf("Enter your activity level (1 for sedentary, 2 for light exercise, 3 for moderate exercise, 4 for heavy exercise): ");
    if (scanf("%d", &activityLevel) != 1 || activityLevel < 1 || activityLevel > 4) {
        printf("Invalid input. Please enter a number between 1 and 4.\n");
        return 1;
    }

    bmi = weight / (height * height);
    switch (activityLevel) {
        case 1:
            calories = 1600 + (10 * age);
            break;
        case 2:
            calories = 1800 + (15 * age);
            break;
        case 3:
            calories = 2000 + (20 * age);
            break;
        case 4:
            calories = 2200 + (25 * age);
            break;
    }

    printf("Your BMI is: %.2f\n", bmi);
    printf("Recommended daily calorie burn: %d\n", (int)calories);

    return 0;
}
