//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to calculate BMI
float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

// function to generate random heart rate
int generateHeartRate() {
    return (rand() % 30) + 70;
}

// function to count number of steps
int countSteps() {
    return (rand() % 5000) + 5000;
}

int main() {
    // initializing variables
    float weight, height, bmi;
    int age, heartRate, steps;

    // getting user input
    printf("Welcome to Sherlock's Fitness Tracker. \n");
    printf("Let us begin by asking you a few questions.\n");
    printf("What is your age? ");
    scanf("%d", &age);
    printf("What is your weight in kilograms? ");
    scanf("%f", &weight);
    printf("What is your height in meters? ");
    scanf("%f", &height);

    // calculating BMI
    bmi = calculateBMI(weight, height);

    // generating random heart rate and step count
    srand(time(NULL));
    heartRate = generateHeartRate();
    steps = countSteps();

    // outputting results
    printf("\nThank you for the information. Here are your results:\n");
    printf("Your BMI is %.2f.\n", bmi);
    printf("Your heart rate is %d beats per minute.\n", heartRate);
    printf("You have taken %d steps today.\n", steps);

    // giving Sherlock's recommendation based on the results
    printf("\nBased on your results, Sherlock recommends that you:\n");
    if (bmi < 18.5) {
        printf("Consume more calories to gain weight.\n");
    }
    else if (bmi < 25) {
        printf("Maintain your weight by eating healthy and exercising regularly.\n");
    }
    else {
        printf("Reduce your calorie intake and exercise more to lose weight.\n");
    }

    if (heartRate < 60 || heartRate > 100) {
        printf("Consult a doctor about your irregular heart rate.\n");
    }
    else {
        printf("Continue your regular exercise routine.\n");
    }

    if (steps < 5000) {
        printf("Increase your physical activity to reach the recommended daily steps of 10,000.\n");
    }
    else {
        printf("Good job on meeting the daily step count!\n");
    }

    return 0;
}