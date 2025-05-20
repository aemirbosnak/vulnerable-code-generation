//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function to calculate BMI
float calculateBMI(float weight, float height){
    float bmi = weight / (height * height);
    return bmi;
}

int main(){
    float weight, height, bmi;
    int goal;
    char name[20];

    // Get user input
    printf("Welcome to the Fitness Tracker Program!\n");
    printf("Please enter your name: ");
    scanf("%s", &name);
    printf("Please enter your weight (in kg): ");
    scanf("%f", &weight);
    printf("Please enter your height (in meters): ");
    scanf("%f", &height);
    bmi = calculateBMI(weight, height);
    printf("Your BMI is %.2f\n", bmi);

    // Determine user's fitness goal
    printf("What is your fitness goal?\n");
    printf("1. Lose weight\n2. Maintain weight\n3. Gain weight\n");
    scanf("%d", &goal);

    // Display daily goals based on user's fitness goal
    switch(goal){
        case 1:
            printf("You should aim for a daily calorie intake of %d calories.\n", (int)(bmi * 22));
            printf("You should try to burn %d calories per day through exercise.\n", (int)(bmi * 500));
            printf("Remember to eat a balanced diet and drink plenty of water.\n");
            break;
        case 2:
            printf("You should aim for a daily calorie intake of %d calories.\n", (int)(bmi * 24));
            printf("You should aim for at least 30 minutes of moderate exercise per day.\n");
            printf("Remember to eat a balanced diet and drink plenty of water.\n");
            break;
        case 3:
            printf("You should aim for a daily calorie intake of %d calories.\n", (int)(bmi * 26));
            printf("You should try to incorporate weight lifting into your exercise routine.\n");
            printf("Remember to eat a balanced diet and drink plenty of water.\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
            break;
    }

    printf("Thank you for using the Fitness Tracker Program, %s!\n", name);

    return 0;
}