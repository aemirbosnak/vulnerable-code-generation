//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void displayMenu();
void trackSteps(int *steps);
void trackDistance(float *distance);
void trackCalories(float *calories, int steps);
void showSummary(int steps, float distance, float calories);

int main() {
    int steps = 0;
    float distance = 0.0f, calories = 0.0f;
    int choice;
    
    printf("🎉 Welcome to the Happy Fitness Tracker! 🎉\n");
    
    do {
        displayMenu();
        printf("Please choose an option (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                trackSteps(&steps);
                break;
            case 2:
                trackDistance(&distance);
                break;
            case 3:
                trackCalories(&calories, steps);
                break;
            case 4:
                showSummary(steps, distance, calories);
                break;
            case 0:
                printf("🎊 Thank you for using the Happy Fitness Tracker! Goodbye! 🎊\n");
                break;
            default:
                printf("🚫 Invalid choice, please select a valid option. 🚫\n");
                break;
        }
        printf("\n");
    } while (choice != 0);
    
    return 0;
}

void displayMenu() {
    printf("🌈 Menu Options 🌈\n");
    printf("1. Track Steps 🌟\n");
    printf("2. Track Distance 🚶\n");
    printf("3. Track Calories 🍽️\n");
    printf("4. Show Summary 📊\n");
    printf("0. Exit 🚪\n");
}

void trackSteps(int *steps) {
    int newSteps;
    printf("How many steps did you take today? ");
    scanf("%d", &newSteps);
    *steps += newSteps;
    printf("🎈 You have added %d steps! Total steps: %d 🎈\n", newSteps, *steps);
}

void trackDistance(float *distance) {
    float newDistance;
    printf("How many kilometers did you walk today? ");
    scanf("%f", &newDistance);
    *distance += newDistance;
    printf("🚀 You've added %.2f km! Total distance: %.2f km 🚀\n", newDistance, *distance);
}

void trackCalories(float *calories, int steps) {
    if (steps <= 0) {
        printf("😅 Please track your steps first before calculating calories!\n");
        return;
    }
    
    float caloriesBurned = steps * 0.04f; // Assuming 0.04 calories per step
    *calories += caloriesBurned;
    printf("🔥 You've burned %.2f calories today! Total calories: %.2f 🔥\n", caloriesBurned, *calories);
}

void showSummary(int steps, float distance, float calories) {
    printf("🌟 Your Fitness Summary 🌟\n");
    printf("Total Steps: %d steps\n", steps);
    printf("Total Distance: %.2f km\n", distance);
    printf("Total Calories Burned: %.2f calories\n", calories);
    
    if (steps > 0) {
        printf("🎉 Keep up the great work! 🎉\n");
    } else {
        printf("🤗 Let's get moving! 🤗\n");
    }
}