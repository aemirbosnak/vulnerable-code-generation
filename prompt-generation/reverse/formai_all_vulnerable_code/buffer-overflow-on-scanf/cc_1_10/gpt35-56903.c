//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>

int main() {
    char name[50];
    int age, weight, height; 
    float bmi, daily_calorie_intake;
    bool is_male;
    
    //Ask user for personal information
    printf("Please enter your name: ");
    scanf("%s", &name);
    printf("\nPlease enter your age: ");
    scanf("%d", &age);
    printf("\nPlease enter your weight in pounds: ");
    scanf("%d", &weight);
    printf("\nPlease enter your height in inches: ");
    scanf("%d", &height);
    printf("\nAre you male? (y/n): ");
    char gender;
    scanf("%s", &gender);
    is_male = (gender == 'y');
    
    //Calculate BMI
    float height_m = (float) height / 39.37; //convert inches to meters
    bmi = (float) weight / (height_m * height_m);
    
    //Calculate daily calorie intake based on gender and activity level
    int activity_level;
    printf("\nPlease enter your activity level (1- Sedentary, 2- Lightly Active, 3- Moderately Active, 4- Very Active): ");
    scanf("%d", &activity_level);
    switch(activity_level) {
        case 1:
            if(is_male) {
                daily_calorie_intake = 1.2 * (66 + (13.7 * weight) + (5 * height) - (6.8 * age));
            } else {
                daily_calorie_intake = 1.2 * (655 + (9.6 * weight) + (1.8 * height) - (4.7 * age));
            }
            break;
        case 2:
            if(is_male) {
                daily_calorie_intake = 1.375 * (66 + (13.7 * weight) + (5 * height) - (6.8 * age));
            } else {
                daily_calorie_intake = 1.375 * (655 + (9.6 * weight) + (1.8 * height) - (4.7 * age));
            }
            break;
        case 3:
            if(is_male) {
                daily_calorie_intake = 1.55 * (66 + (13.7 * weight) + (5 * height) - (6.8 * age));
            } else {
                daily_calorie_intake = 1.55 * (655 + (9.6 * weight) + (1.8 * height) - (4.7 * age));
            }
            break;
        case 4:
            if(is_male) {
                daily_calorie_intake = 1.725 * (66 + (13.7 * weight) + (5 * height) - (6.8 * age));
            } else {
                daily_calorie_intake = 1.725 * (655 + (9.6 * weight) + (1.8 * height) - (4.7 * age));
            }
            break;
        default:
            printf("\nInvalid activity level!");
            return 0;
    }
    
    //Display calculation results
    printf("\n--------------------------------------------------------");
    printf("\nYour BMI is: %.2f", bmi);
    printf("\nYour recommended daily calorie intake is: %.0f", daily_calorie_intake);
    printf("\n--------------------------------------------------------");
    
    return 0;
}