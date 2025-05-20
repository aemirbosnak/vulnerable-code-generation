#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int calculateBMI(int weight, int height) {
    return (weight * 703) / (height * height);
}

int calculateCalories(int activityLevel, int weight) {
    if (activityLevel == 1) return weight * 12;
    if (activityLevel == 2) return weight * 15;
    if (activityLevel == 3) return weight * 18;
    if (activityLevel == 4) return weight * 21;
    if (activityLevel == 5) return weight * 24;
    return 0;
}

int main() {
    int weight, height, activityLevel;
    printf("Enter your weight in pounds: ");
    scanf("%d", &weight);
    printf("Enter your height in inches: ");
    scanf("%d", &height);
    printf("Enter your activity level (1-5): ");
    scanf("%d", &activityLevel);

    int bmi = calculateBMI(weight, height);
    int calories = calculateCalories(activityLevel, weight);

    printf("Your BMI is: %d\n", bmi);
    printf("Your daily caloric needs are: %d\n", calories);

    return 0;
}
