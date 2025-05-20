//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: brave
#include<stdio.h>

int main(){
    printf("Welcome to C Fitness Tracker\n\n");
    float weight, height, bmi;
    int age, calories_burned, steps_taken;
    char gender;
    
    printf("Please enter your weight in kilograms: ");
    scanf("%f", &weight);
    
    printf("Please enter your height in meters: ");
    scanf("%f", &height);
    
    printf("Please enter your age in years: ");
    scanf("%d", &age);
    
    printf("Please enter your gender (M/F): ");
    scanf(" %c", &gender);
    
    bmi = weight / (height * height);
    printf("\nYour BMI is %.2f\n\n", bmi);
    
    if(bmi < 18.5){
        printf("You are underweight.\n\n");
    }else if(bmi >= 18.5 && bmi <= 24.9){
        printf("You are at a healthy weight.\n\n");
    }else if(bmi >= 25 && bmi <= 29.9){
        printf("You are overweight.\n\n");
    }else{
        printf("You are obese.\n\n");
    }
    
    if(gender == 'M'){
        calories_burned = (0.2017 * age) + (0.6309 * weight) + (0.09036 * height) - 55.0969;
    }else{
        calories_burned = (0.074 * age) + (0.4472 * weight) + (0.1263 * height) - 20.4022;
    }
    
    printf("You have burned %d calories today.\n\n", calories_burned);
    
    printf("Please enter the number of steps you have taken today: ");
    scanf("%d", &steps_taken);
    
    if(steps_taken < 5000){
        printf("You need to walk more. Only %d steps taken.\n\n", steps_taken);
    }else if(steps_taken >= 5000 && steps_taken < 10000){
        printf("You are doing well. %d steps taken.\n\n", steps_taken);
    }else{
        printf("Great job! You have taken %d steps today.\n\n", steps_taken);
    }
    
    return 0;
}