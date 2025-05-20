//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FitnessTracker {
    char name[20];
    int age;
    float weight;
    float height;
    float bmi;
    float daily_calorie;
    float calorie_intake;
    float calorie_burn;
};

int main() {
    struct FitnessTracker user;
    
    printf("Welcome to C Fitness Tracker\n\n");
    
    printf("Enter your name: ");
    fgets(user.name, 20, stdin);
    user.name[strcspn(user.name, "\n")] = 0;
    
    printf("Enter your age: ");
    scanf("%d", &user.age);
    
    printf("Enter your weight in kilograms: ");
    scanf("%f", &user.weight);
    
    printf("Enter your height in meters: ");
    scanf("%f", &user.height);
    
    user.bmi = user.weight / (user.height * user.height);
    printf("Your BMI is: %f\n", user.bmi);
    
    user.daily_calorie = 10 * user.weight + 6.25 * user.height * 100 - 5 * user.age + 5;
    printf("Your daily calorie requirement is: %f\n", user.daily_calorie);
    
    printf("Enter your calorie intake today: ");
    scanf("%f", &user.calorie_intake);
    
    printf("Enter your calorie burn today: ");
    scanf("%f", &user.calorie_burn);
    
    if (user.calorie_intake < user.daily_calorie && user.calorie_burn < user.daily_calorie) {
        printf("Good job, you are on track with your fitness goals!\n");
    }
    else if (user.calorie_intake >= user.daily_calorie && user.calorie_burn < user.daily_calorie) {
        printf("You have exceeded your daily calorie requirement, be careful!\n");
    }
    else if (user.calorie_intake < user.daily_calorie && user.calorie_burn > user.daily_calorie) {
        printf("Great job, you have burned more calories than you consumed today!\n");
    }
    else {
        printf("You have exceeded your daily calorie requirement and burned less calories than you consumed, be careful!\n");
    }
    
    return 0;
}