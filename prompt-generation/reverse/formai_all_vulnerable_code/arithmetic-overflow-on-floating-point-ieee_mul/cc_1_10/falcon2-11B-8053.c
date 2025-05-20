//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Struct to hold user information
struct UserInfo {
    double weight;
    double height;
    int activityLevel;
};

// Function to calculate calories burned based on activity level
double calculateCalories(struct UserInfo* userInfo) {
    double calories;
    
    switch(userInfo->activityLevel) {
        case 1:
            calories = (double)userInfo->weight * 0.30;
            break;
        case 2:
            calories = (double)userInfo->weight * 0.50;
            break;
        case 3:
            calories = (double)userInfo->weight * 0.75;
            break;
        case 4:
            calories = (double)userInfo->weight * 1.00;
            break;
        case 5:
            calories = (double)userInfo->weight * 1.50;
            break;
        case 6:
            calories = (double)userInfo->weight * 2.00;
            break;
        default:
            calories = 0;
            break;
    }

    return calories;
}

// Function to display user information and calculated calories burned
void displayInfo(struct UserInfo* userInfo) {
    printf("Weight: %.2f kg\n", userInfo->weight);
    printf("Height: %.2f cm\n", userInfo->height);
    printf("Calories burned: %.2f kcal\n", calculateCalories(userInfo));
}

int main() {
    // Create an instance of UserInfo
    struct UserInfo user;
    
    // Prompt user for input
    printf("Enter your weight (kg): ");
    scanf("%lf", &user.weight);
    printf("Enter your height (cm): ");
    scanf("%lf", &user.height);
    printf("Enter your activity level: ");
    scanf("%d", &user.activityLevel);
    
    // Calculate and display calories burned
    displayInfo(&user);
    
    return 0;
}