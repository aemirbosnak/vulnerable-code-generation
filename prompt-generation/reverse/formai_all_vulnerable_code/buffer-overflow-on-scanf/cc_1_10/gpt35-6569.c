//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: calm
#include <stdio.h>

int main() {
    // Define variables
    int currentWeight, targetWeight;
    int caloriesConsumed, caloriesBurned;

    // Get current weight from user
    printf("Enter your current weight in pounds: ");
    scanf("%d", &currentWeight);

    // Get target weight from user
    printf("Enter your target weight in pounds: ");
    scanf("%d", &targetWeight);

    // Get daily calories consumed from user
    printf("Enter your average daily calorie intake: ");
    scanf("%d", &caloriesConsumed);

    // Get daily calories burned from user
    printf("Enter your average daily calories burned: ");
    scanf("%d", &caloriesBurned);

    // Calculate body mass index (BMI)
    float height = 1.75; // in meters
    float bmi = currentWeight / (height * height);

    // Print out BMI results
    printf("Your BMI is: %.2f\n", bmi);

    // Calculate daily calorie deficit/surplus
    int dailyDeficit = caloriesBurned - caloriesConsumed;

    // Calculate total calorie deficit/surplus
    int totalDeficit = dailyDeficit * 7;

    // Calculate target weight loss per week
    int targetLoss = currentWeight - targetWeight;
    int targetDeficit = targetLoss * 3500;

    // Calculate weeks to reach target weight
    int weeksToTarget = targetDeficit / totalDeficit;

    // Print out results
    printf("You currently have a daily deficit/surplus of: %d calories\n", dailyDeficit);
    printf("You have a total deficit/surplus of: %d calories per week\n", totalDeficit);
    printf("To reach your target weight of %d pounds, you need to have a total deficit of %d calories\n", targetWeight, targetDeficit);
    printf("At your current rate, it will take you approximately %d weeks to reach your target weight.\n", weeksToTarget);

    return 0;
}