//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int duration; // in minutes
    int calories; // calories burned
} Workout;

Workout workouts[MAX_WORKOUTS];
int workoutCount = 0;

// Function to add a workout
void addWorkout() {
    if (workoutCount >= MAX_WORKOUTS) {
        printf("\n😱 Oops! You've reached the max number of workouts! Can't add more!\n");
        return;
    }
     
    Workout newWorkout;
    
    printf("\n🎉 WOW! Let's log a new workout! 🎉\n");
    
    printf("Enter workout name: ");
    scanf(" %[^\n]", newWorkout.name); // Read string with spaces
    printf("Enter duration (in minutes): ");
    scanf("%d", &newWorkout.duration);
    printf("Enter calories burned: ");
    scanf("%d", &newWorkout.calories);
    
    workouts[workoutCount++] = newWorkout;

    printf("\n🥳 Done! You've logged: %s for %d minutes and burned %d calories! 👍\n", 
           newWorkout.name, newWorkout.duration, newWorkout.calories);
}

// Function to display all workouts
void displayWorkouts() {
    if (workoutCount == 0) {
        printf("\n😱 Uh-oh! No workouts logged yet! Get moving! 🚀\n");
        return;
    }

    printf("\n🔥 Here are your logged workouts! 🔥\n");
    for (int i = 0; i < workoutCount; i++) {
        printf("Workout %d: %s | Duration: %d min | Calories: %d\n", 
               i + 1, workouts[i].name, workouts[i].duration, workouts[i].calories);
    }
}

// Function to calculate total calories burned
void totalCaloriesBurned() {
    int totalCalories = 0;
    
    for (int i = 0; i < workoutCount; i++) {
        totalCalories += workouts[i].calories;
    }

    printf("\n💥 You have burned a total of %d calories from your workouts! Keep it up! 💪\n", totalCalories);
}

// Main menu function
void menu() {
    int choice;
    do {
        printf("\n===== Fitness Tracker Menu =====\n");
        printf("1. Add Workout\n");
        printf("2. Display Workouts\n");
        printf("3. Calculate Total Calories Burned\n");
        printf("4. Exit\n");
        printf("=================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addWorkout();
                break;
            case 2:
                displayWorkouts();
                break;
            case 3:
                totalCaloriesBurned();
                break;
            case 4:
                printf("\n👋 Bye! Keep chasing those fitness goals! See you next time! 🌟\n");
                break;
            default:
                printf("\n🤔 Hmm! That's not a valid choice! Please try again!\n");
        }
    } while (choice != 4);
}

int main() {
    printf("🙌 Welcome to the Shock-Fitness Tracker! 🌟 Let's get pumped up!\n");
    menu();
    return 0;
}