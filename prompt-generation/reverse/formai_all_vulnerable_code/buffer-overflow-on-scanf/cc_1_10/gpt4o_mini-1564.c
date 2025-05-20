//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_NAME_LENGTH 50
#define MAX_NUTRITION_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int duration; // in minutes
    int caloriesBurned;
} Workout;

typedef struct {
    char foodName[MAX_NAME_LENGTH];
    int calories; // calories per serving
    int servings; // Number of servings consumed
} NutritionEntry;

typedef struct {
    Workout workouts[MAX_WORKOUTS];
    NutritionEntry nutrition[MAX_NUTRITION_ENTRIES];
    int workoutCount;
    int nutritionCount;
    float weight; // User's weight
} FitnessTracker;

void initTracker(FitnessTracker *tracker) {
    tracker->workoutCount = 0;
    tracker->nutritionCount = 0;
    tracker->weight = 0.0;
}

void addWorkout(FitnessTracker *tracker) {
    if (tracker->workoutCount >= MAX_WORKOUTS) {
        printf("Workout log is full!\n");
        return;
    }
    Workout workout;
    printf("Enter workout name: ");
    scanf("%s", workout.name);
    printf("Enter duration (in minutes): ");
    scanf("%d", &workout.duration);
    printf("Enter calories burned: ");
    scanf("%d", &workout.caloriesBurned);
    
    tracker->workouts[tracker->workoutCount++] = workout;
    printf("Workout added successfully!\n");
}

void addNutrition(FitnessTracker *tracker) {
    if (tracker->nutritionCount >= MAX_NUTRITION_ENTRIES) {
        printf("Nutrition log is full!\n");
        return;
    }
    NutritionEntry entry;
    printf("Enter food name: ");
    scanf("%s", entry.foodName);
    printf("Enter calories per serving: ");
    scanf("%d", &entry.calories);
    printf("Enter servings consumed: ");
    scanf("%d", &entry.servings);
    
    tracker->nutrition[tracker->nutritionCount++] = entry;
    printf("Nutrition entry added successfully!\n");
}

void displayWorkouts(FitnessTracker *tracker) {
    printf("\n--- Workouts ---\n");
    for (int i = 0; i < tracker->workoutCount; i++) {
        Workout w = tracker->workouts[i];
        printf("Workout Name: %s, Duration: %d mins, Calories Burned: %d\n", w.name, w.duration, w.caloriesBurned);
    }
}

void displayNutrition(FitnessTracker *tracker) {
    printf("\n--- Nutrition ---\n");
    for (int i = 0; i < tracker->nutritionCount; i++) {
        NutritionEntry n = tracker->nutrition[i];
        printf("Food Name: %s, Calories per serving: %d, Servings: %d\n", n.foodName, n.calories, n.servings);
    }
}

void displaySummary(FitnessTracker *tracker) {
    printf("\n--- Fitness Summary ---\n");
    int totalCaloriesBurned = 0;
    for (int i = 0; i < tracker->workoutCount; i++) {
        totalCaloriesBurned += tracker->workouts[i].caloriesBurned;
    }

    int totalCaloriesConsumed = 0;
    for (int i = 0; i < tracker->nutritionCount; i++) {
        totalCaloriesConsumed += tracker->nutrition[i].calories * tracker->nutrition[i].servings;
    }

    printf("Total Calories Burned: %d\n", totalCaloriesBurned);
    printf("Total Calories Consumed: %d\n", totalCaloriesConsumed);
}

void setWeight(FitnessTracker *tracker) {
    printf("Enter your weight: ");
    scanf("%f", &tracker->weight);
    printf("Weight recorded!\n");
}

int main() {
    FitnessTracker tracker;
    initTracker(&tracker);
    int choice;

    while (1) {
        printf("\n--- Fitness Tracker Menu ---\n");
        printf("1. Add Workout\n");
        printf("2. Add Nutrition Entry\n");
        printf("3. Display Workouts\n");
        printf("4. Display Nutrition\n");
        printf("5. Display Summary\n");
        printf("6. Set Weight\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addWorkout(&tracker); break;
            case 2: addNutrition(&tracker); break;
            case 3: displayWorkouts(&tracker); break;
            case 4: displayNutrition(&tracker); break;
            case 5: displaySummary(&tracker); break;
            case 6: setWeight(&tracker); break;
            case 7: printf("Exiting the program.\n"); exit(0);
            default: printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}