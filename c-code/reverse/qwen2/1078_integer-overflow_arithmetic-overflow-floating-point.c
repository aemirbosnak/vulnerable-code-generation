#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    double weight, height, bmi;
    int age, activityLevel;

    printf("Enter your weight in kilograms: ");
    scanf("%lf", &weight);
    printf("Enter your height in meters: ");
    scanf("%lf", &height);
    printf("Enter your age in years: ");
    scanf("%d", &age);
    printf("Enter your activity level (1 - Sedentary, 2 - Lightly Active, 3 - Moderately Active, 4 - Very Active, 5 - Super Active): ");
    scanf("%d", &activityLevel);

    bmi = weight / (height * height);

    printf("Your BMI is: %.2f\n", bmi);

    if (bmi < 18.5) {
        printf("Underweight\n");
    } else if (bmi >= 18.5 && bmi < 25) {
        printf("Normal weight\n");
    } else if (bmi >= 25 && bmi < 30) {
        printf("Overweight\n");
    } else {
        printf("Obesity\n");
    }

    switch (activityLevel) {
        case 1:
            printf("Daily calorie burn recommendation: %d calories\n", (int)(bmi * 24 * 7 * 1600));
            break;
        case 2:
            printf("Daily calorie burn recommendation: %d calories\n", (int)(bmi * 24 * 7 * 1800));
            break;
        case 3:
            printf("Daily calorie burn recommendation: %d calories\n", (int)(bmi * 24 * 7 * 2000));
            break;
        case 4:
            printf("Daily calorie burn recommendation: %d calories\n", (int)(bmi * 24 * 7 * 2200));
            break;
        case 5:
            printf("Daily calorie burn recommendation: %d calories\n", (int)(bmi * 24 * 7 * 2400));
            break;
        default:
            printf("Invalid activity level\n");
            return 1;
    }

    return 0;
}
