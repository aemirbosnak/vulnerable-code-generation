#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int weight, height, age;
    float bmi, calories;
    char activity;

    printf("Enter your weight in kg: ");
    scanf("%d", &weight);
    printf("Enter your height in cm: ");
    scanf("%d", &height);
    printf("Enter your age in years: ");
    scanf("%d", &age);
    printf("Enter your activity level (L - Light, M - Moderate, H - Heavy): ");
    scanf(" %c", &activity);

    if (weight <= 0 || height <= 0 || age <= 0) {
        printf("Invalid input. Please enter positive values.\n");
        return 1;
    }

    bmi = (float)weight / ((height * height) / 10000.0);

    switch (activity) {
        case 'L':
            calories = 25 * bmi * age;
            break;
        case 'M':
            calories = 30 * bmi * age;
            break;
        case 'H':
            calories = 35 * bmi * age;
            break;
        default:
            printf("Invalid activity level. Please choose L, M, or H.\n");
            return 1;
    }

    if (bmi < 18.5) {
        printf("Underweight\n");
    } else if (bmi >= 18.5 && bmi < 25) {
        printf("Normal weight\n");
    } else if (bmi >= 25 && bmi < 30) {
        printf("Overweight\n");
    } else {
        printf("Obesity\n");
    }

    printf("Your BMI is %.2f\n", bmi);
    printf("Your daily calorie needs are approximately %.2f\n", calories);

    return 0;
}
