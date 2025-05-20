//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

//structure to hold fitness data
struct fitness{
    char name[20];
    int age;
    float weight;
    float height;
    float bmi;
}person;

int main(){

    //getting user input for fitness data
    printf("Enter your name: ");
    gets(person.name);

    printf("Enter your age: ");
    scanf("%d", &person.age);

    printf("Enter your weight in kg: ");
    scanf("%f", &person.weight);

    printf("Enter your height in meters: ");
    scanf("%f", &person.height);
    
    //calculating BMI
    person.bmi = person.weight / (person.height*person.height);
    
    //displaying fitness data
    printf("\n\n----- Your Fitness Data -----\n\n");
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Weight: %.2f kg\n", person.weight);
    printf("Height: %.2f meters\n", person.height);
    printf("BMI: %.2f\n", person.bmi);
    
    //finding fitness category
    if(person.bmi<18.5)
        printf("\nYou are Underweight.");
    else if(person.bmi>=18.5 && person.bmi<=24.9)
        printf("\nYou are Normal.");
    else if(person.bmi>=25 && person.bmi<=29.9)
        printf("\nYou are Overweight.");
    else
        printf("\nYou are Obese.");
        
    return 0;
}