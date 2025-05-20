//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

//Defining struct Fitness with attributes
struct Fitness{
    char name[50];
    int age;
    float weight;
    float height;
};

//Function to calculate Body Mass Index
float bmi_calculator(float weight, float height){
    float bmi;
    bmi = weight/(height*height);
    return bmi;
}

//Function to suggest fitness plan based on BMI
void suggest_fitness_plan(float bmi){
    if(bmi<18.5){
        printf("\nYour BMI indicates that you are underweight. You need to focus on building muscle mass and improving your overall strength. A fitness plan that includes weight training along with a balanced diet will help.\n");
    }
    else if(bmi>=18.5 && bmi<=24.9){
        printf("\nYour BMI indicates that you are healthy. A fitness plan that includes a mix of cardio and weight training along with a balanced diet will help you in maintaining your current fitness level.\n");
    }
    else if(bmi>=25.0 && bmi<=29.9){
        printf("\nYour BMI indicates that you are overweight. A fitness plan that includes a mix of cardio, weight training and a balanced diet with restriction of calories will help you in weight loss and achieving your desired fitness level.\n");
    }
    else{
        printf("\nYour BMI indicates that you are obese. It is important to consult a healthcare professional before starting any fitness plan. A fitness plan that includes a mix of cardio, weight training and a balanced diet will help you in achieving your desired fitness level with gradual weight loss and improved overall health.\n");
    }
}

int main(){
    struct Fitness person; //Defining struct variable
    
    //Taking user input
    printf("Welcome to C Fitness Tracker!\n");
    printf("\nEnter your name: ");
    fgets(person.name,50,stdin);
    printf("\nEnter your age: ");
    scanf("%d",&person.age);
    printf("\nEnter your weight in kilograms: ");
    scanf("%f",&person.weight);
    printf("\nEnter your height in meters: ");
    scanf("%f",&person.height);
    
    //Calculating BMI and suggesting fitness plan
    float bmi = bmi_calculator(person.weight,person.height);
    printf("\nDear %s,",person.name);
    printf("\nYour Body Mass Index is: %.2f",bmi);
    suggest_fitness_plan(bmi);
    
    return 0;
}