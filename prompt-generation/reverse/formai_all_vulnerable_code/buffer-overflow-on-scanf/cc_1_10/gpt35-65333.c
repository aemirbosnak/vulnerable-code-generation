//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: safe
#include<stdio.h>
#include<math.h>
#include<string.h>

//Function to calculate BMI
float calculateBMI(float weight, float height){
    float bmi;
    bmi = weight/(height*height);
    return bmi;
}

//Function to calculate BMR
float calculateBMR(float weight, float height, int age, char gender){
    float bmr;
    if(gender == 'M') bmr = 88.362 + (13.397 * weight) + (4.799 * height * 100) - (5.677 * age);
    else bmr = 447.593 + (9.247 * weight) + (3.098 * height * 100) - (4.330 * age);
    return bmr;
}

//Function to calculate calorie intake based on activity level
float calculateCalorieIntake(float bmr, int activityLevel){
    float calorieIntake;
    switch(activityLevel){
        case 1:
            calorieIntake = bmr * 1.2;
            break;
        case 2:
            calorieIntake = bmr * 1.375;
            break;
        case 3:
            calorieIntake = bmr * 1.55;
            break;
        case 4:
            calorieIntake = bmr * 1.725;
            break;
        case 5:
            calorieIntake = bmr * 1.9;
            break;
        default:
            calorieIntake = 0.0;
            break;
    }
    return calorieIntake;
}

int main(){
    float weight, height, bmi, bmr, calorieIntake;
    int age, activityLevel;
    char gender;
    char name[50];

    printf("Enter your name: ");
    scanf("%[^\n]%*c", name);

    printf("Enter your weight in kg: ");
    scanf("%f", &weight);

    printf("Enter your height in meters: ");
    scanf("%f", &height);

    //Calculate BMI
    bmi = calculateBMI(weight, height);
    printf("\nYour BMI is: %.2f\n\n", bmi);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your gender (M/F): ");
    scanf(" %c", &gender);

    //Calculate BMR
    bmr = calculateBMR(weight, height, age, gender);
    printf("\nYour BMR is: %.2f\n\n", bmr);

    printf("Enter your activity level:\n1. Sedentary\n2. Lightly active\n3. Moderately active\n4. Very active\n5. Extra active\n");
    scanf("%d", &activityLevel);

    //Calculate Calorie Intake
    calorieIntake = calculateCalorieIntake(bmr, activityLevel);
    printf("\nYour recommended daily calorie intake is: %.2f\n\n", calorieIntake);

    return 0;
}