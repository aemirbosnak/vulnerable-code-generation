#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int weight, height, age;
    char activity;
    float bmi, calorie_need;

    printf("Enter your weight (kg): ");
    scanf("%d", &weight);
    printf("Enter your height (cm): ");
    scanf("%d", &height);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your activity level (L/M/H): ");
    scanf(" %c", &activity);

    if (weight <= 0 || height <= 0 || age <= 0) {
        printf("Invalid input. Please enter positive values.\n");
        return 1;
    }

    bmi = (float)weight / ((height * height) / 10000.0);

    if (bmi < 18.5) {
        printf("Underweight\n");
    } else if (bmi >= 18.5 && bmi < 24.9) {
        printf("Normal weight\n");
    } else if (bmi >= 25 && bmi < 30) {
        printf("Overweight\n");
    } else {
        printf("Obesity\n");
    }

    switch (activity) {
        case 'L':
            calorie_need = 2000 + (10 * age);
            break;
        case 'M':
            calorie_need = 2500 + (12 * age);
            break;
        case 'H':
            calorie_need = 3000 + (14 * age);
            break;
        default:
            printf("Invalid activity level. Please enter L, M, or H.\n");
            return 1;
    }

    printf("Your daily calorie need is approximately %.2f calories.\n", calorie_need);

    return 0;
}
