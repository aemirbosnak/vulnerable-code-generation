//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); // Initializing the random number generator
    
    // Setting up variables and arrays
    int height, weight, age;
    int exercise[7];
    char gender;
    float bmi, bmr, calories;
    int i, j;
    
    // Prompting user for input
    printf("Welcome to the Fitness Tracker!\n\n");
    
    printf("Please enter your height (in cm): ");
    scanf("%d", &height);
    
    printf("Please enter your weight (in kg): ");
    scanf("%d", &weight);
    
    printf("Please enter your age: ");
    scanf("%d", &age);
    
    printf("Please enter your gender (M/F): ");
    scanf(" %c", &gender);
    
    printf("Please rate your weekly exercise level (0-6):\n"); 
    printf("0=none, 1=light, 2=moderate, 3=heavy, 4=very heavy\n");
    printf("5=competitive sports, 6=professional athlete/very intense training\n");
    
    for (i=0; i<7; i++){
        printf("Enter level for day %d: ", i+1);
        scanf("%d", &exercise[i]);
    }
    
    // Calculating BMI and BMR
    bmi = weight / ((height/100.0) * (height/100.0));
    
    if (gender == 'M'){
        bmr = 10 * weight + 6.25 * height - 5 * age + 5;
    } else if (gender == 'F') {
        bmr = 10 * weight + 6.25 * height - 5 * age - 161;
    } else {
        printf("Invalid gender input.\n");
        return 0;
    }
    
    // Calculating daily recommended calorie intake based on activity level
    calories = bmr * 1.2;  // Light exercise
    
    for (j=0; j<7; j++){
        if (exercise[j] == 1) {
            calories += bmr * 1.375;  // Moderate exercise
        } else if (exercise[j] == 2) {
            calories += bmr * 1.55; // Heavy exercise
        } else if (exercise[j] == 3) {
            calories += bmr * 1.725; // Very heavy exercise
        } else if (exercise[j] == 4) {
            calories += bmr * 1.9; // Competitive sports
        } else if (exercise[j] == 5) {
            calories += bmr * 2.1; // Professional athlete/intense training
        } else if (exercise[j] == 6) {
            calories += bmr * 2.3; // Endurance athlete
        } 
    }
    
    // Displaying results to user
    printf("\nYour BMI is: %.2f\n", bmi);
    printf("Your BMR is: %d calories/day\n", (int)bmr);
    printf("Your recommended daily calorie intake is: %.0f calories/day\n", calories);
    
    // Generating motivational message
    int randNum = rand() % 4;
    
    switch(randNum){
        case 0:
            printf("\nGreat job! Keep up the good work!\n");
            break;
        case 1:
            printf("\nYou're doing great! Don't give up!\n");
            break;
        case 2:
            printf("\nYou can do it! Keep pushing yourself!\n");
            break;
        case 3:
            printf("\nRemember why you started and keep going!\n");
            break;
    }
    
    return 0;
}