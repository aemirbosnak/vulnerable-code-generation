#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int weight, height, age, activity_level;
    float bmi, recommended_weight;

    printf("Enter your weight (in kilograms): ");
    scanf("%d", &weight);

    printf("Enter your height (in meters): ");
    scanf("%d", &height);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your activity level (1 for sedentary, 2 for lightly active, 3 for moderately active, 4 for very active): ");
    scanf("%d", &activity_level);

    bmi = (weight * 703) / (height * height);

    recommended_weight = bmi * activity_level - weight;

    printf("Your BMI is: %.2f", bmi);

    printf("\nYour recommended weight is: %.2f", recommended_weight);

    return 0;
}
