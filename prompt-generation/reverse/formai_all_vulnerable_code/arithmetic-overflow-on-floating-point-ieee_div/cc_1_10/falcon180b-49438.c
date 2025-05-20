//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice;
    float weight, height, bmi, heart_rate, steps, calories, distance;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your weight in pounds: ");
    scanf("%f", &weight);
    printf("Please enter your height in inches: ");
    scanf("%f", &height);

    bmi = weight / (height * height);
    printf("Your BMI is %.2f.\n", bmi);

    printf("Please choose an activity:\n");
    printf("1. Running\n2. Walking\n3. Cycling\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("How many steps did you take? ");
            scanf("%f", &steps);
            distance = steps / 2.5;
            calories = weight * 0.1 * distance;
            printf("You burned %.2f calories and walked %.2f miles.\n", calories, distance);
            break;
        case 2:
            printf("How many steps did you take? ");
            scanf("%f", &steps);
            distance = steps / 2.5;
            calories = weight * 0.05 * distance;
            printf("You burned %.2f calories and walked %.2f miles.\n", calories, distance);
            break;
        case 3:
            printf("How many miles did you cycle? ");
            scanf("%f", &distance);
            calories = weight * 0.1 * distance;
            printf("You burned %.2f calories and cycled %.2f miles.\n", calories, distance);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    printf("Please enter your heart rate: ");
    scanf("%f", &heart_rate);
    printf("Your heart rate is %.2f beats per minute.\n", heart_rate);

    return 0;
}