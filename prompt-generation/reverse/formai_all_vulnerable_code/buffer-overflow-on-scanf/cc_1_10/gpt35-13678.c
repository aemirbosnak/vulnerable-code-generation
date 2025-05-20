//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: lively
#include <stdio.h> //header file for input/output operations
#include <stdbool.h> //header file for boolean variable type

//function prototype
float calculateBMI(float weight, float height);

int main() {
    float weight, height;
    int age;
    bool isLoggingIn = false;
    
    printf("Welcome to Fitness Tracker!\n");
    
    //Login
    while(!isLoggingIn) {
        printf("Please enter your age: ");
        scanf("%d", &age);
        
        if(age >= 18) {
            isLoggingIn = true;
            printf("Welcome to your Dashboard!\n");
        } else {
            printf("Sorry, you are not old enough to use this tool. You must be 18 or older.\n");
        }
    }
    
    printf("Please enter your weight in pounds: ");
    scanf("%f", &weight);
    
    printf("Please enter your height in inches: ");
    scanf("%f", &height);
    
    //Calculate BMI
    float bmi = calculateBMI(weight, height);
    
    //Display Results
    printf("Your BMI is: %.2f\n", bmi);
    
    if (bmi < 18.5) {
        printf("You are underweight.\n");
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        printf("You are at a healthy weight.\n");
    } else if (bmi >= 25 && bmi <= 29.9) {
        printf("You are overweight.\n");
    } else if (bmi >= 30) {
        printf("You are obese.\n");
    }
    
    return 0;
}

/*
    Calculates BMI
    @param weight - weight in pounds
    @param height - height in inches
    @return BMI as float
*/
float calculateBMI(float weight, float height) {
    float bmi = (weight / (height * height)) * 703;
    return bmi;
}