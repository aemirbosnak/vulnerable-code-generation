//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: complete
#include <stdio.h>

//function to calculate BMI
float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

int main() {
    float weight, height, bmi;
    int age, stepsCount, heartRate;

    //user inputs
    printf("Enter your weight in kilograms: ");
    scanf("%f", &weight);

    printf("Enter your height in meters: ");
    scanf("%f", &height);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your steps count for today: ");
    scanf("%d", &stepsCount);

    printf("Enter your heart rate for today: ");
    scanf("%d", &heartRate);

    //calculate BMI
    bmi = calculateBMI(weight, height);

    //display results
    printf("\nYour Body Mass Index (BMI): %.2f\n", bmi);

    if (bmi < 18.5) {
        printf("You are underweight.\n");
    } else if (bmi >= 18.5 && bmi < 25) {
        printf("You have a normal weight.\n");
    } else if (bmi >= 25 && bmi < 30) {
        printf("You are overweight.\n");
    } else {
        printf("You are obese.\n");
    }

    if (age >= 18) {
        printf("Your recommended steps per day: 10,000\n");
    } else {
        printf("Your recommended steps per day: 8,000\n");
    }

    printf("Your steps count for today: %d\n", stepsCount);

    if (stepsCount < 5000) {
        printf("You need to move more.\n");
    } else if (stepsCount >= 5000 && stepsCount < 10000) {
        printf("You are doing good.\n");
    } else {
        printf("You are doing great!\n");
    }

    printf("Your heart rate for today: %d\n", heartRate);

    if (heartRate < 60 || heartRate > 100) {
        printf("Your heart rate is not normal. You should consult a doctor.\n");
    } else {
        printf("Your heart rate is normal.\n");
    }

    return 0;
}