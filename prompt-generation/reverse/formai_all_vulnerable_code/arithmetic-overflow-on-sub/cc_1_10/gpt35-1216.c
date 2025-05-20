//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate random number between two given numbers
int randNum(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to convert total seconds into hours, minutes, and seconds format
void convertSeconds(int totalSeconds, int *hours, int *minutes, int *seconds) {
    *hours = totalSeconds / 3600;
    totalSeconds %= 3600;
    *minutes = totalSeconds / 60;
    *seconds = totalSeconds % 60;
}

// Main function
int main() {
    // Declare necessary variables
    char name[30], unit[10];
    int age, weight, goal, targetWeight, netCalories, totalCalories = 0, totalSteps = 0, hours, minutes, seconds;
    time_t current_time;
    struct tm *local_time;
    FILE *fp;

    // Get user's name, age, weight, and fitness goal
    printf("Welcome to C Fitness Tracker!\n\nPlease enter your name: ");
    scanf("%s", name);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your weight (in kg): ");
    scanf("%d", &weight);
    printf("What is your fitness goal?\n1. Lose Weight\n2. Maintain Weight\n3. Gain Weight\n");
    scanf("%d", &goal);

    // Determine the user's calorie target based on their fitness goal
    switch(goal) {
        case 1:
            targetWeight = randNum(weight - 10, weight - 20);
            netCalories = randNum(500, 1000);
            strcpy(unit, "kg");
            break;
        case 2:
            targetWeight = weight;
            netCalories = randNum(-500, 500);
            strcpy(unit, "kg");
            break;
        case 3:
            targetWeight = randNum(weight + 10, weight + 20);
            netCalories = randNum(500, 1000);
            strcpy(unit, "kg");
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    // Display the user's calorie target and target weight
    printf("Your target weight is %d %s and your daily calorie target is %d calories.\n\n", targetWeight, unit, netCalories);

    // Open a file to save user's data
    fp = fopen("user_data.txt", "w");

    // Get today's date and time
    time(&current_time);
    local_time = localtime(&current_time);

    // Write user's data to file
    fprintf(fp, "Name: %s\n", name);
    fprintf(fp, "Age: %d\n", age);
    fprintf(fp, "Weight: %d kg\n", weight);
    fprintf(fp, "Target Weight: %d %s\n", targetWeight, unit);
    fprintf(fp, "Calorie Target: %d calories\n\n", netCalories);

    // Start the fitness tracker
    printf("Starting C Fitness Tracker...\n\n");

    // Loop through each day of the week
    for (int i = 1; i <= 7; i++) {
        // Display today's date
        printf("Day %d (%02d/%02d/%d)\n", i, local_time->tm_mday, local_time->tm_mon + 1, local_time->tm_year + 1900);

        // Get user's input for daily calorie intake and steps taken
        int dayCalories, daySteps;
        printf("Enter your daily calorie intake: ");
        scanf("%d", &dayCalories);
        printf("Enter the number of steps you took: ");
        scanf("%d", &daySteps);

        // Add daily calorie intake and steps to total
        totalCalories += dayCalories;
        totalSteps += daySteps;

        // Write user's data for the day to file
        fprintf(fp, "Day %d (%02d/%02d/%d)\n", i, local_time->tm_mday, local_time->tm_mon + 1, local_time->tm_year + 1900);
        fprintf(fp, "Calories: %d\n", dayCalories);
        fprintf(fp, "Steps: %d\n\n", daySteps);

        // Move to next day
        local_time->tm_mday++;
        mktime(local_time);
    }

    // Close the file
    fclose(fp);

    // Calculate if the user achieved their fitness goal
    int weightLost = weight - targetWeight;
    if (weightLost > 0 && totalCalories < netCalories) {
        printf("\nCongratulations, %s! You have achieved your goal of losing %d %s and reaching your target weight of %d %s.\n", name, weightLost, unit, targetWeight, unit);
    }
    else if (weightLost == 0 && totalCalories == netCalories) {
        printf("\nGood job, %s! You have maintained your weight and met your daily calorie target.\n", name);
    }
    else if (weightLost < 0 && totalCalories > netCalories) {
        printf("\nCongratulations, %s! You have achieved your goal of gaining %d %s and reaching your target weight of %d %s.\n", name, abs(weightLost), unit, targetWeight, unit);
    }
    else {
        printf("\nSorry, %s! You did not achieve your fitness goal this week.\n", name);
    }

    // Display user's total steps and calories burned
    convertSeconds(totalSteps * 3, &hours, &minutes, &seconds);
    printf("\nYou took a total of %d steps this week and burned %d calories through walking.\n", totalSteps, totalSteps * 3);
    printf("This is equivalent to %d hours, %d minutes, and %d seconds of walking.\n", hours, minutes, seconds);

    return 0;
}