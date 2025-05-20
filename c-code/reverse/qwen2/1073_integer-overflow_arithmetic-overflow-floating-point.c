#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    float weight, height, age;
    int activityLevel;

    printf("Enter your weight in kilograms: ");
    scanf("%f", &weight);

    printf("Enter your height in meters: ");
    scanf("%f", &height);

    printf("Enter your age in years: ");
    scanf("%d", &age);

    printf("Enter your activity level (1 - Sedentary, 2 - Lightly Active, 3 - Moderately Active, 4 - Very Active, 5 - Super Active): ");
    scanf("%d", &activityLevel);

    float bmi = weight / (height * height);
    float basalMetabolicRate = 88.362 + (13.397 * weight) + (4.799 * height * 100) - (5.677 * age);
    float totalDailyEnergyExpenditure = basalMetabolicRate * activityLevel;

    printf("Your BMI is: %.2f\n", bmi);
    printf("Recommended daily calorie burn: %.2f kcal\n", totalDailyEnergyExpenditure);

    return 0;
}
