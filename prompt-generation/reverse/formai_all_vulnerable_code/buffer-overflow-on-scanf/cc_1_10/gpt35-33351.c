//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define struct for workout data
typedef struct workoutData{
    int day;
    int month;
    int year;
    int caloriesBurned;
    int duration; // in minutes
} WorkoutData;

 // Function to calculate BMR (Basal Metabolic Rate)
float calculateBMR(float weight, int age, float height, bool isMale) {
    float BMR;
    if(isMale) {
        BMR = 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age);
    } else {
        BMR = 447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age);
    }
    return BMR;
}

 // Function to calculate calories burned during a workout
int calculateCaloriesBurned(float BMR, float intensity, int duration) {
    float MET = intensity * 3.5;
    int calories = ((BMR / 24) * MET * duration) / 1000;
    return calories;
}

// Function to add data to workout log
void addData(WorkoutData data[], int* numData) {
    int day, month, year, caloriesBurned, duration;
    printf("Enter workout data:\n");
    printf("Day (1-31): ");
    scanf("%d", &day);
    printf("Month (1-12): ");
    scanf("%d", &month);
    printf("Year: ");
    scanf("%d", &year);
    printf("Calories burned: ");
    scanf("%d", &caloriesBurned);
    printf("Duration (in minutes): ");
    scanf("%d", &duration);
    data[*numData].day = day;
    data[*numData].month = month;
    data[*numData].year = year;
    data[*numData].caloriesBurned = caloriesBurned;
    data[*numData].duration = duration;
    *numData += 1;
    printf("Data added successfully!\n");
}

// Function to display workout log
void displayLog(WorkoutData data[], int numData) {
    printf("Workout log:\n");
    printf("Date\t\tCalories Burned\tDuration (min)\n");
    for(int i=0; i<numData; i++) {
        printf("%d/%d/%d\t\t%d\t\t%d\n", data[i].day, data[i].month, data[i].year, data[i].caloriesBurned, data[i].duration);
    }
}

// Function to generate a random workout
void generateWorkout(float weight, int age, float height, bool isMale) {
    float intensity = ((float) rand() / RAND_MAX) * 0.5 + 0.5; // Generates a random intensity between 0.5 and 1.0
    int duration = ((rand() % 60) + 30); // Generate a random duration between 30 and 90 minutes
    float BMR = calculateBMR(weight, age, height, isMale);
    int caloriesBurned = calculateCaloriesBurned(BMR, intensity, duration);
    printf("Generated workout:\n");
    printf("Intensity: %.2f\n", intensity);
    printf("Duration: %d minutes\n", duration);
    printf("Calories burned: %d\n", caloriesBurned);
}

int main() {
    float weight = 75.0; // in kilograms
    int age = 25;
    float height = 1.8; // in meters
    bool isMale = true;
    WorkoutData data[100];
    int numData = 0;
    srand(time(NULL)); // Set random seed based on system time
    char choice;
    do {
        printf("\nWelcome to Fitness Tracker!\n");
        printf("1. Add data\n");
        printf("2. Display log\n");
        printf("3. Generate workout\n");
        printf("4. Exit\n");
        printf("Enter your choice (1/2/3/4): ");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                addData(data, &numData);
                break;
            case '2':
                displayLog(data, numData);
                break;
            case '3':
                generateWorkout(weight, age, height, isMale);
                break;
            case '4':
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != '4');
    return 0;
}