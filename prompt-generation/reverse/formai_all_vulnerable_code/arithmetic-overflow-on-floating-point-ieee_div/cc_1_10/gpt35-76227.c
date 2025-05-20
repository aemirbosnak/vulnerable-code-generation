//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: imaginative
#include <stdio.h>   // for standard input/output library
#include <stdlib.h>   // for standard library
#include <string.h>    // for string library

// function to calculate BMI
float calculateBMI(float weight, float height){
    height = height / 100;  // converting height to meter
    float BMI = weight / (height * height);  // formula to calculate BMI
    return BMI;
}

// function to calculate BMR
float calculateBMR(float weight, float height, float age, char gender[]){
    // formula to calculate BMR for male
    if(strcmp(gender, "male")==0){
        float BMR = 88 + (13.4 * weight) + (4.8 * height) - (5.7 * age);
        return BMR;
    }
    // formula to calculate BMR for female
    else if(strcmp(gender, "female")==0){
        float BMR = 447 + (9.2 * weight) + (3.1 * height) - (4.3 * age);
        return BMR;
    }
}

// function to display fitness report
void displayReport(float BMI, float BMR){
    printf("\nYour BMI is %0.2f\n", BMI);   // display BMI
    printf("Your BMR is %0.2f\n", BMR);   // display BMR
    // display fitness recommendation based on BMI
    if(BMI<18.5){
        printf("You are underweight. You should eat more and exercise regularly.\n");
    }
    else if(BMI>=18.5 && BMI<=24.9){
        printf("You have a healthy BMI. Keep up the good work!\n");
    }
    else if(BMI>=25.0 && BMI<=29.9){
        printf("You are overweight. You should eat healthy and exercise regularly.\n");
    }
    else{
        printf("You are obese. You should consult a doctor, eat healthy and exercise regularly.\n");
    }
    // display recommended calorie intake based on BMR
    printf("Your recommended daily calorie intake to maintain current weight is %0.2f calories.\n", BMR);
}

// main function to get user input and call functions
int main(){
    char name[50], gender[10];
    float weight, height, age;
    printf("Enter your name: ");
    scanf("%[^\n]%*c", name);   // read name with spaces from user
    printf("Enter your gender (male/female): ");
    scanf("%s", gender);   // read gender from user
    printf("Enter your weight in kg: ");
    scanf("%f", &weight);   // read weight from user
    printf("Enter your height in cm: ");
    scanf("%f", &height);   // read height from user
    printf("Enter your age: ");
    scanf("%f", &age);   // read age from user
    float BMI = calculateBMI(weight, height);   // calculate BMI
    float BMR = calculateBMR(weight, height, age, gender);   // calculate BMR
    displayReport(BMI, BMR);   // display report
    return 0;
}