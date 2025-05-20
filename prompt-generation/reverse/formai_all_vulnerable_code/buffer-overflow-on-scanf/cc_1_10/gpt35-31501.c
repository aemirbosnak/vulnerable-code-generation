//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display menu options
void displayMenu() {
    printf("\n\n");
    printf("------------------------------\n");
    printf("C FITNESS TRACKER\n");
    printf("------------------------------\n");
    printf("1. Enter New Workout Data\n");
    printf("2. View Progress\n");
    printf("3. Exit\n");
    printf("------------------------------\n");
}

// Function to calculate BMI
float calculateBMI(float height, float weight) {
    return weight / (height * height);
}

// Main function
int main() {
    // Variables to hold user input
    int menuOption, workoutMinutes, workoutCalories;
    float height, weight, bmi;
    char name[50];
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Display welcome message
    printf("Welcome to C Fitness Tracker!\n");
    
    // Get user's name
    printf("Please enter your name: ");
    scanf("%s", name);
    
    // Display menu options
    displayMenu();
    
    while (1) {
        // Get user's menu option
        printf("\n%s, please enter an option: ", name);
        scanf("%d", &menuOption);
        
        switch(menuOption) {
            case 1:
                // Get user's workout data
                printf("\nHow many minutes did you workout today? ");
                scanf("%d", &workoutMinutes);
                
                printf("How many calories did you burn? ");
                scanf("%d", &workoutCalories);
                
                // Save data to file
                FILE *fp;
                fp = fopen("workout_data.txt", "a");
                if (fp != NULL) {
                    fprintf(fp, "%d %d\n", workoutMinutes, workoutCalories);
                    fclose(fp);
                    printf("Workout data saved!");
                } else {
                    printf("Error saving workout data.");
                }
                
                break;
            case 2:
                // Display user's progress
                fp = fopen("workout_data.txt", "r");
                
                if (fp != NULL) {
                    int totalMinutes = 0, totalCalories = 0, workouts = 0;
                    
                    while(!feof(fp)) {
                        fscanf(fp, "%d %d\n", &workoutMinutes, &workoutCalories);
                        
                        totalMinutes += workoutMinutes;
                        totalCalories += workoutCalories;
                        workouts++;
                    }
                    
                    printf("\n%s, here is your progress so far:\n", name);
                    printf("Total Workout Minutes: %d\n", totalMinutes);
                    printf("Total Calories Burnt: %d\n", totalCalories);
                    printf("Average Workout Minutes per Session: %.1f\n", (float) totalMinutes / workouts);
                    printf("Average Calories Burnt per Session: %.1f\n", (float) totalCalories / workouts);
                    
                    // Calculate BMI
                    printf("\nPlease enter your weight (in kilograms): ");
                    scanf("%f", &weight);
                    
                    printf("Please enter your height (in meters): ");
                    scanf("%f", &height);
                    
                    bmi = calculateBMI(height, weight);
                    printf("Your BMI is: %.2f\n", bmi);
                    
                    // Give user a random workout tip
                    char *workoutTips[] = {
                        "Try to increase your workout duration by 5 minutes next time.",
                        "Vary your workout by trying a new activity every week.",
                        "Stay hydrated during your workout by drinking water every 15 minutes.",
                        "Don't forget to cool down after your workout to prevent injury.",
                        "Get a workout buddy to stay motivated.",
                        "Include strength training exercises in your workout routine to build muscle.",
                        "Monitor your heart rate during your workout to ensure you are working at the right intensity.",
                        "Take a break if you feel dizzy or lightheaded during your workout.",
                        "Gradually increase the intensity of your workout over time to avoid injury."
                    };
                    
                    int randIndex = rand() % 9;
                    printf("\nWORKOUT TIP: %s\n", workoutTips[randIndex]);
                    
                    fclose(fp);
                } else {
                    printf("No workout data found.");
                }
                
                break;
            case 3:
                // Exit program
                printf("\nGoodbye, %s. Keep up the good work!\n", name);
                return 0;
            default:
                // Invalid option
                printf("\nInvalid option. Please try again.");
        }
        
        // Display menu options
        displayMenu();
    }
}