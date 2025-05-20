//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXERCISES 10
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int duration; // in minutes
    int repetitions;
    float caloriesBurned;
} Exercise;

typedef struct {
    Exercise exercises[MAX_EXERCISES];
    int totalExercises;
    time_t workoutDate;
} Workout;

void addExercise(Workout* workout) {
    if (workout->totalExercises < MAX_EXERCISES) {
        Exercise newExercise;
        
        printf("Enter exercise name: ");
        scanf("%s", newExercise.name);
        
        printf("Enter duration in minutes: ");
        scanf("%d", &newExercise.duration);
        
        printf("Enter number of repetitions: ");
        scanf("%d", &newExercise.repetitions);
        
        newExercise.caloriesBurned = (newExercise.duration * 5) + (newExercise.repetitions * 3); // arbitrary calculation
        workout->exercises[workout->totalExercises++] = newExercise;
        printf("Exercise added! 🎉\n");
    } else {
        printf("Maximum exercises reached! Cannot add more.\n");
    }
}

void viewWorkout(Workout workout) {
    printf("Workout on %s", ctime(&workout.workoutDate));
    printf("You have completed %d exercises:\n", workout.totalExercises);
    
    for (int i = 0; i < workout.totalExercises; i++) {
        Exercise e = workout.exercises[i];
        printf("Exercise Name: %s | Duration: %d mins | Repetitions: %d | Calories Burned: %.2f\n", 
               e.name, e.duration, e.repetitions, e.caloriesBurned);
    }
}

void saveWorkout(Workout workout) {
    FILE *file = fopen("workout_data.txt", "w");
    if (file != NULL) {
        fprintf(file, "Workout on %s", ctime(&workout.workoutDate));
        fprintf(file, "Total Exercises: %d\n", workout.totalExercises);
        
        for (int i = 0; i < workout.totalExercises; i++) {
            Exercise e = workout.exercises[i];
            fprintf(file, "Exercise Name: %s | Duration: %d mins | Repetitions: %d | Calories Burned: %.2f\n", 
                    e.name, e.duration, e.repetitions, e.caloriesBurned);
        }
        fclose(file);
        printf("Workout saved to workout_data.txt.\n");
    } else {
        printf("Error saving workout data!\n");
    }
}

void displayMenu() {
    printf("\nC Fitness Tracker Menu:\n");
    printf("1. Add Exercise\n");
    printf("2. View Workout\n");
    printf("3. Save Workout\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    Workout todayWorkout;
    todayWorkout.totalExercises = 0;
    todayWorkout.workoutDate = time(NULL);

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addExercise(&todayWorkout);
                break;
            case 2:
                viewWorkout(todayWorkout);
                break;
            case 3:
                saveWorkout(todayWorkout);
                break;
            case 4:
                printf("Exiting the Fitness Tracker. Stay fit! 💪\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 4);
    
    return 0;
}