//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: intelligent
#include<stdio.h>

//Function for calculating BMI
float calcBMI(float weight, float height){
    float bmi = weight/(height * height);
    return bmi;
}

int main(){
    float weight, height, bmi;
    int steps;

    printf("Welcome to the Fitness Tracker!\n");

    //Taking input from the user
    printf("Enter your weight in kgs: ");
    scanf("%f", &weight);
    printf("Enter your height in meters: ");
    scanf("%f", &height);
    printf("Enter the number of steps you have walked today: ");
    scanf("%d", &steps);

    //Calculating BMI
    bmi = calcBMI(weight, height);

    //Displaying the results
    printf("Your BMI is: %f\n", bmi);
    if(bmi<18.5){
        printf("You are Underweight.\n");
    }
    else if(bmi>=18.5 && bmi<25){
        printf("You are Normal.\n");
    }
    else if(bmi>=25 && bmi<30){
        printf("You are Overweight.\n");
    }
    else{
        printf("You are Obese.\n");
    }

    printf("You have walked %d steps today.\n", steps);
    if(steps<5000){
        printf("You need to be more active.\n");
    }
    else if(steps>=5000 && steps<10000){
        printf("You are doing good but can do better.\n");
    }
    else{
        printf("You are doing great! Keep it up.\n");
    }

    return 0;
}