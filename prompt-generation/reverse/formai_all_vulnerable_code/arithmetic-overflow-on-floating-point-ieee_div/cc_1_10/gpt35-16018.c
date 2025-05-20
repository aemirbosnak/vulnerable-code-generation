//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int age;
    float height;
    float weight;
    char gender[10];
} User;

typedef struct{
    User user;
    float bmi;
    float bmr;
    float calorieIntake;
} FitnessData;

void calculateBmi(FitnessData *data){
    float bmi = data->user.weight / (data->user.height * data->user.height);
    data->bmi = bmi;
}

void calculateBmr(FitnessData *data){
    float bmr;
    if(strcmp(data->user.gender, "male") == 0){
        bmr = 88.36 + (13.4 * data->user.weight) + (4.8 * data->user.height) - (5.7 * data->user.age);
    }else{
        bmr = 447.6 + (9.25 * data->user.weight) + (3.1 * data->user.height) - (4.3 * data->user.age);
    }
    data->bmr = bmr;
}

void calculateCalorieIntake(FitnessData *data, int activityLevel){
    float calorieIntake;
    if(activityLevel == 1){
        calorieIntake = data->bmr * 1.2;
    }else if(activityLevel == 2){
        calorieIntake = data->bmr * 1.375;
    }else if(activityLevel == 3){
        calorieIntake = data->bmr * 1.55;
    }else if(activityLevel == 4){
        calorieIntake = data->bmr * 1.725;
    }else{
        calorieIntake = data->bmr * 1.9;
    }
    data->calorieIntake = calorieIntake;
}

int main(){
    FitnessData userFitness;
    User newUser;
    float height, weight;
    int age, activityLevel;
    char gender[10];

    printf("Enter your age: ");
    scanf("%d", &age);
    newUser.age = age;

    printf("Enter your height in meters: ");
    scanf("%f", &height);
    newUser.height = height;

    printf("Enter your weight in kg: ");
    scanf("%f", &weight);
    newUser.weight = weight;

    printf("Enter your gender (male or female): ");
    scanf("%s", gender);
    strcpy(newUser.gender, gender);

    userFitness.user = newUser;
    calculateBmi(&userFitness);
    calculateBmr(&userFitness);

    printf("Your BMI is %.2f\n", userFitness.bmi);
    printf("Your BMR is %.2f\n", userFitness.bmr);

    printf("Enter your activity level (1 = Sedentary, 2 = Lightly active, 3 = Moderately active, 4 = Very active, 5 = Extra active): ");
    scanf("%d", &activityLevel);
    calculateCalorieIntake(&userFitness, activityLevel);

    printf("Your recommended calorie intake is %.2f calories\n", userFitness.calorieIntake);

    return 0;
}