//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate BMI
float calculateBMI(float weight, float height) {
    float bmi = (weight / (height * height));
    return bmi;
}

// Function to calculate heart rate
float calculateHeartRate(float beatsPerMinute) {
    float heartRate = beatsPerMinute / 60;
    return heartRate;
}

// Function to calculate calories burned
float calculateCaloriesBurned(float weight, float heartRate, float minutes) {
    float calories = ((weight * 0.0175) * heartRate * (minutes / 60));
    return calories;
}

// Function to calculate distance traveled
float calculateDistanceTraveled(float speed, float minutes) {
    float distance = (speed * minutes) / 60;
    return distance;
}

int main() {
    float weight, height, heartRate, speed, minutes, bmi, caloriesBurned, distanceTraveled;

    // Get user input for weight and height
    printf("Enter your weight in pounds: ");
    scanf("%f", &weight);
    printf("Enter your height in inches: ");
    scanf("%f", &height);

    // Calculate BMI
    bmi = calculateBMI(weight, height);
    printf("Your BMI is: %.2f\n", bmi);

    // Get user input for heart rate
    printf("Enter your heart rate in beats per minute: ");
    scanf("%f", &heartRate);

    // Calculate heart rate
    heartRate = calculateHeartRate(heartRate);
    printf("Your heart rate is: %.2f beats per minute\n", heartRate);

    // Get user input for speed and minutes
    printf("Enter your speed in miles per hour: ");
    scanf("%f", &speed);
    printf("Enter the number of minutes you exercised: ");
    scanf("%f", &minutes);

    // Calculate calories burned
    caloriesBurned = calculateCaloriesBurned(weight, heartRate, minutes);
    printf("You burned %.2f calories\n", caloriesBurned);

    // Calculate distance traveled
    distanceTraveled = calculateDistanceTraveled(speed, minutes);
    printf("You traveled %.2f miles\n", distanceTraveled);

    return 0;
}