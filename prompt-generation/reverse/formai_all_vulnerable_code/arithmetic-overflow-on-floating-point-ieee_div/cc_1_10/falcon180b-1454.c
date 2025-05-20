//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

int main() {
    int choice;
    double weight, height, bmi, steps, distance, calories, heart_rate;
    struct tm time_info;
    char date_string[80];
    time_t now;
    int hour, minute, second;

    printf("Welcome to the Fitness Tracker\n");
    printf("Please enter your weight in kg: ");
    scanf("%lf", &weight);
    printf("Please enter your height in cm: ");
    scanf("%lf", &height);

    bmi = weight / (height * height);
    printf("Your BMI is %.2f\n", bmi);

    printf("Select an activity:\n1. Walking\n2. Running\n3. Cycling\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the number of steps taken: ");
            scanf("%lf", &steps);
            distance = steps / 100;
            calories = 0.0175 * weight * distance;
            printf("You burned %.2f calories by walking %.2f km\n", calories, distance);
            break;
        case 2:
            printf("Enter the number of steps taken: ");
            scanf("%lf", &steps);
            distance = steps / 100;
            calories = 0.05 * weight * distance;
            printf("You burned %.2f calories by running %.2f km\n", calories, distance);
            break;
        case 3:
            printf("Enter the distance covered in km: ");
            scanf("%lf", &distance);
            calories = 0.028 * weight * distance;
            printf("You burned %.2f calories by cycling %.2f km\n", calories, distance);
            break;
        default:
            printf("Invalid choice\n");
    }

    printf("Enter your heart rate in beats per minute: ");
    scanf("%lf", &heart_rate);

    if (heart_rate < 60) {
        printf("Your heart rate is low\n");
    } else if (heart_rate >= 60 && heart_rate < 100) {
        printf("Your heart rate is normal\n");
    } else if (heart_rate >= 100 && heart_rate < 120) {
        printf("Your heart rate is elevated\n");
    } else {
        printf("Your heart rate is high\n");
    }

    time(&now);
    localtime_r(&now, &time_info);
    strftime(date_string, 80, "%Y-%m-%d %H:%M:%S", &time_info);
    printf("Current date and time: %s\n", date_string);

    return 0;
}