#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <limits.h>

int main() {
    double weight, height, bmi;
    int age;

    printf("Enter your weight in kilograms: ");
    scanf("%lf", &weight);
    printf("Enter your height in meters: ");
    scanf("%lf", &height);
    printf("Enter your age in years: ");
    scanf("%d", &age);

    if (weight <= 0 || height <= 0 || age <= 0) {
        printf("Invalid input. Please enter positive values.\n");
        return 1;
    }

    bmi = weight / (height * height);

    if (bmi < 18.5) {
        printf("Underweight\n");
    } else if (bmi >= 18.5 && bmi < 24.9) {
        printf("Normal weight\n");
    } else if (bmi >= 25 && bmi < 30) {
        printf("Overweight\n");
    } else {
        printf("Obesity\n");
    }

    if (age < 18) {
        printf("Recommended daily calorie intake: %d calories\n", (int)(weight * 11));
    } else if (age >= 18 && age < 65) {
        printf("Recommended daily calorie intake: %d calories\n", (int)(weight * 12));
    } else {
        printf("Recommended daily calorie intake: %d calories\n", (int)(weight * 10));
    }

    return 0;
}
