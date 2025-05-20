//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERNAME_LEN 20

struct user {
    char username[MAX_USERNAME_LEN];
    int age;
    float height;
    float weight;
    float BMR;
    float calorieGoal;
};

int getBMR(int age, float height, float weight, int gender) {
    int BMR;
    if (gender == 1) {
        BMR = 10 * weight + 6.25 * height - 5 * age + 5;
    } else {
        BMR = 10 * weight + 6.25 * height - 5 * age - 161;
    }
    return BMR;
}

float getCalorieGoal(float BMR, int activityLevel) {
    float calorieGoal;
    switch(activityLevel) {
        case 1:
            calorieGoal = BMR * 1.2;
            break;
        case 2:
            calorieGoal = BMR * 1.375;
            break;
        case 3:
            calorieGoal = BMR * 1.55;
            break;
        case 4:
            calorieGoal = BMR * 1.725;
            break;
        case 5:
            calorieGoal = BMR * 1.9;
            break;
        default:
            printf("Invalid activity level.\n");
            break;
    }
    return calorieGoal;  
}

float getBMI(float height, float weight) {
    return weight / (height * height);
}

void printUserInfo(struct user currentUser) {
    printf("Username: %s\n", currentUser.username);
    printf("Age: %d\n", currentUser.age);
    printf("Height: %0.2f meters\n", currentUser.height);
    printf("Weight: %0.2f kilograms\n", currentUser.weight);
    printf("BMR: %0.0f calories\n", currentUser.BMR);
    printf("Calorie Goal: %0.0f calories\n", currentUser.calorieGoal);
}

int main() {
    struct user currentUser;
    printf("Welcome to the C Fitness Tracker!\n");
    printf("Please enter your username (limit %d characters): ", MAX_USERNAME_LEN);
    scanf("%s", &currentUser.username);
    printf("Please enter your age: ");
    scanf("%d", &currentUser.age);
    printf("Please enter your height in meters: ");
    scanf("%f", &currentUser.height);
    printf("Please enter your weight in kilograms: ");
    scanf("%f", &currentUser.weight);
    printf("Please enter your gender (1 for male, 2 for female): ");
    int gender;
    scanf("%d", &gender);
    currentUser.BMR = getBMR(currentUser.age, currentUser.height, currentUser.weight, gender);
    printf("Please enter your activity level (1 for sedentary, 2 for lightly active, 3 for moderately active, 4 for very active, 5 for extra active): ");
    int activityLevel;
    scanf("%d", &activityLevel);
    currentUser.calorieGoal = getCalorieGoal(currentUser.BMR, activityLevel);
    printf("\n");
    printf("Thank you! Here is your user information:\n");
    printf("----------------------------\n");
    printUserInfo(currentUser);
    
    float currentWeight = currentUser.weight;
    float currentBMI = getBMI(currentUser.height, currentWeight);
    int currentDay = 1;
    time_t t = time(NULL);
    struct tm *timeNow = localtime(&t);
    int currentMonth = timeNow->tm_mon + 1; // Month is 0-indexed in struct tm
    printf("\n");
    
    while (1) {
        int choice;
        printf("Please select from the following menu options:\n");
        printf("1. Record Daily Weight\n");
        printf("2. See User Information\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice) {
            case 1:
                printf("What is your current weight in kilograms? ");
                scanf("%f", &currentWeight);
                currentBMI = getBMI(currentUser.height, currentWeight);
                printf("\n");
                printf("Thank you! Your new weight has been recorded.\n");
                break;
            case 2:
                printf("User Information:\n");
                printf("----------------------------\n");
                printUserInfo(currentUser);
                printf("Current Weight: %0.2f kilograms\n", currentWeight);
                printf("Current BMI: %0.2f\n", currentBMI);
                printf("Current Month: %d\n", currentMonth);
                printf("Current Day: %d\n", currentDay);
                break;
            case 3:
                printf("Goodbye! Thank you for using the C Fitness Tracker.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
        printf("\n");
        currentDay++;
        if (currentDay > 31) { // Assuming all months have 31 days
            currentDay = 1;
            currentMonth++;
        }
    }
    
    return 0;
}