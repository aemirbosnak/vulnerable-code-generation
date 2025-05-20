//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Inspector Holmes's Fitness Tracker
    char name[20];
    int age;
    float height, weight;
    char blood_group[3];
    int steps_taken;
    float distance_traveled;
    char activity_type[50];

    printf("Welcome, esteemed client. Please provide your name:");
    scanf("%s", name);

    printf("And your age:");
    scanf("%d", &age);

    printf("Height in inches:");
    scanf("%f", &height);

    printf("Weight in pounds:");
    scanf("%f", &weight);

    printf("Blood group:");
    scanf("%s", blood_group);

    printf("Number of steps taken:");
    scanf("%d", &steps_taken);

    printf("Distance traveled in miles:");
    scanf("%f", &distance_traveled);

    printf("Activity type:");
    scanf("%s", activity_type);

    // Calculate BMI and heart rate
    float bmi = (weight * 703) / (height * height);
    int heart_rate = 220 - (age * 2);

    // Display results
    printf("\n**Case Summary:**\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Height: %f inches\n", height);
    printf("Weight: %f pounds\n", weight);
    printf("Blood group: %s\n", blood_group);
    printf("Steps taken: %d\n", steps_taken);
    printf("Distance traveled: %f miles\n", distance_traveled);
    printf("Activity type: %s\n", activity_type);
    printf("BMI: %.2f\n", bmi);
    printf("Heart rate: %d beats per minute\n", heart_rate);

    return 0;
}