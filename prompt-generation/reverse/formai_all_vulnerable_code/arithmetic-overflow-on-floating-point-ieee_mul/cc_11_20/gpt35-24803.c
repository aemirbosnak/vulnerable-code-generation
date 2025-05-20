//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: thoughtful
#include <stdio.h>

int main() {
    double weight, height, bmi;
    int age, minutes;
    char gender;

    printf("Welcome to the Fitness Tracker Program!\n");

    printf("Please enter your weight (in kg): ");
    scanf("%lf", &weight);

    printf("Please enter your height (in cm): ");
    scanf("%lf", &height);

    printf("Please enter your age: ");
    scanf("%d", &age);

    printf("Please enter your gender (M/F): ");
    scanf(" %c", &gender);

    bmi = weight / ((height/100) * (height/100));
    printf("\nYour BMI is: %.2lf\n", bmi);
    if (bmi < 18.5) {
        printf("You are underweight. Consult a nutritionist!\n");
    } else if (bmi >= 18.5 && bmi < 25) {
        printf("You are normal. Keep up the good work!\n");
    } else if (bmi >= 25 && bmi < 30) {
        printf("You are overweight. Consider adjusting your diet and exercise routine.\n");
    } else {
        printf("You are obese. Consult a doctor and/or a fitness instructor!\n");
    }

    if (gender == 'M' || gender == 'm') {
        printf("To maintain your weight, you need to consume %.2lf calories per day.\n", 10*weight + 6.25*height - 5*age + 5);
    } else if (gender == 'F' || gender == 'f') {
        printf("To maintain your weight, you need to consume %.2lf calories per day.\n", 10*weight + 6.25*height - 5*age - 161);
    } else {
        printf("Invalid gender input. Calories calculation not possible.\n");
    }

    printf("Please enter how many minutes you've exercised today: ");
    scanf("%d", &minutes);

    if (minutes < 30) {
        printf("You need to exercise more!\n");
    } else if (minutes >= 30 && minutes < 60) {
        printf("Good job! Keep it up!\n");
    } else {
        printf("Excellent! You are on your way to fitness!\n");
    }

    return 0;
}