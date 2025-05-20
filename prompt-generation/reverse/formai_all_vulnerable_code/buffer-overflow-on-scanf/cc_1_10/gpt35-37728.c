//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORKOUT 10
#define MAX_NAME 50

// Definition of the exercise struct
typedef struct {
    char name[MAX_NAME];
    int sets;
    int reps;
    int weight;
} Exercise;

// Definition of the workout struct
typedef struct {
    char name[MAX_NAME];
    Exercise exercises[MAX_WORKOUT];
    int num_exercises;
} Workout;

// Function prototype
void addWorkout(Workout workouts[], int *num_workouts);
void listWorkouts(Workout workouts[], int num_workouts);
void viewWorkout(Workout workouts[], int num_workouts, char workout_name[]);
void updateWorkout(Workout workouts[], int num_workouts, char workout_name[], char exercise_name[]);
void deleteWorkout(Workout workouts[], int *num_workouts, char workout_name[]);

int main()
{
    printf("Welcome to the C Fitness Tracker!\n\n");
    printf("Please select from the following options:\n");
    printf("========================================\n");
    printf("1. Add new workout\n");
    printf("2. List all workouts\n");
    printf("3. View a workout\n");
    printf("4. Update a workout\n");
    printf("5. Delete a workout\n");
    printf("6. Exit program\n");

    int choice;
    Workout workouts[MAX_WORKOUT];
    int num_workouts = 0;

    do {
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        // Clear input buffer
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                addWorkout(workouts, &num_workouts);
                break;
            case 2:
                listWorkouts(workouts, num_workouts);
                break;
            case 3: {
                char workout_name[MAX_NAME];
                printf("Enter workout name: ");
                fgets(workout_name, MAX_NAME, stdin);
                viewWorkout(workouts, num_workouts, workout_name);
                break;
            }
            case 4: {
                char workout_name[MAX_NAME];
                char exercise_name[MAX_NAME];
                printf("Enter workout name: ");
                fgets(workout_name, MAX_NAME, stdin);
                printf("Enter exercise name: ");
                fgets(exercise_name, MAX_NAME, stdin);
                updateWorkout(workouts, num_workouts, workout_name, exercise_name);
                break;
            }
            case 5: {
                char workout_name[MAX_NAME];
                printf("Enter workout name: ");
                fgets(workout_name, MAX_NAME, stdin);
                deleteWorkout(workouts, &num_workouts, workout_name);
                break;
            }
            case 6:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

// Function to add a workout
void addWorkout(Workout workouts[], int *num_workouts) {
    printf("\nAdd New Workout\n");
    printf("====================\n");

    if (*num_workouts == MAX_WORKOUT) {
        printf("Maximum number of workouts reached.\n");
        return;
    }

    Workout new_workout;

    // Get workout name
    printf("Enter workout name: ");
    fgets(new_workout.name, MAX_NAME, stdin);

    // Remove newline character from workout name
    new_workout.name[strcspn(new_workout.name, "\n")] = 0;

    // Get exercises for workout
    printf("\nEnter exercises (max %d)\n", MAX_WORKOUT);
    printf("====================\n");

    int num_exercises = 0;
    char choice;

    do {
        if (num_exercises == MAX_WORKOUT) {
            printf("Maximum number of exercises reached.\n");
            break;
        }

        Exercise new_exercise;

        // Get exercise name
        printf("Enter exercise name: ");
        fgets(new_exercise.name, MAX_NAME, stdin);

        // Remove newline character from exercise name
        new_exercise.name[strcspn(new_exercise.name, "\n")] = 0;

        // Get sets, reps, and weight for exercise
        printf("Enter sets: ");
        scanf("%d", &new_exercise.sets);
        printf("Enter reps: ");
        scanf("%d", &new_exercise.reps);
        printf("Enter weight: ");
        scanf("%d", &new_exercise.weight);

        // Add exercise to workout and increment num_exercises
        new_workout.exercises[num_exercises] = new_exercise;
        num_exercises++;

        // Clear input buffer
        while (getchar() != '\n');

        // Ask user if they want to add another exercise
        printf("Add another exercise? (y/n): ");
        scanf("%c", &choice);

        // Clear input buffer
        while (getchar() != '\n');

    } while (choice == 'y' || choice == 'Y');

    // Add workout to workouts array and increment num_workouts
    new_workout.num_exercises = num_exercises;
    workouts[*num_workouts] = new_workout;
    *num_workouts += 1;

    printf("\nWorkout added successfully.\n");
}

// Function to list all workouts
void listWorkouts(Workout workouts[], int num_workouts) {
    printf("\nList of Workouts\n");
    printf("====================\n");

    if (num_workouts == 0) {
        printf("No workouts added yet.\n");
        return;
    }

    for (int i = 0; i < num_workouts; i++) {
        printf("%s", workouts[i].name);

        if (workouts[i].num_exercises == 1) {
            printf(" (%d exercise)\n", workouts[i].num_exercises);
        } else {
            printf(" (%d exercises)\n", workouts[i].num_exercises);
        }
    }
}

// Function to view a workout
void viewWorkout(Workout workouts[], int num_workouts, char workout_name[]) {
    bool workout_found = false;

    for (int i = 0; i < num_workouts; i++) {
        if (strcmp(workouts[i].name, workout_name) == 0) {
            printf("\n%s Workout\n", workouts[i].name);
            printf("====================\n");

            for (int j = 0; j < workouts[i].num_exercises; j++) {
                printf("%s\n", workouts[i].exercises[j].name);
                printf("Sets: %d\tReps: %d\tWeight: %d\n", workouts[i].exercises[j].sets,
                       workouts[i].exercises[j].reps, workouts[i].exercises[j].weight);
                printf("====================\n");
            }

            workout_found = true;
            break;
        }
    }

    if (!workout_found) {
        printf("Workout not found.\n");
    }
}

// Function to update a workout
void updateWorkout(Workout workouts[], int num_workouts, char workout_name[], char exercise_name[]) {
    bool workout_found = false;

    for (int i = 0; i < num_workouts; i++) {
        if (strcmp(workouts[i].name, workout_name) == 0) {
            for (int j = 0; j < workouts[i].num_exercises; j++) {
                if (strcmp(workouts[i].exercises[j].name, exercise_name) == 0) {
                    printf("\nUpdate Exercise\n");
                    printf("====================\n");

                    // Get new sets, reps, and weight for exercise
                    printf("Enter new sets: ");
                    scanf("%d", &workouts[i].exercises[j].sets);
                    printf("Enter new reps: ");
                    scanf("%d", &workouts[i].exercises[j].reps);
                    printf("Enter new weight: ");
                    scanf("%d", &workouts[i].exercises[j].weight);

                    // Clear input buffer
                    while (getchar() != '\n');

                    printf("\nExercise updated successfully.\n");
                    workout_found = true;
                    break;
                }
            }

            break;
        }
    }

    if (!workout_found) {
        printf("Workout or exercise not found.\n");
    }
}

// Function to delete a workout
void deleteWorkout(Workout workouts[], int *num_workouts, char workout_name[]) {
    bool workout_found = false;

    for (int i = 0; i < *num_workouts; i++) {
        if (strcmp(workouts[i].name, workout_name) == 0) {
            printf("\nDelete %s Workout\n", workouts[i].name);
            printf("====================\n");
            printf("Are you sure you want to delete this workout? (y/n): ");

            char choice;
            scanf("%c", &choice);

            // Clear input buffer
            while (getchar() != '\n');

            if (choice == 'y' || choice == 'Y') {
                for (int j = i; j < *num_workouts - 1; j++) {
                    workouts[j] = workouts[j+1];
                }

                *num_workouts -= 1;
                printf("\nWorkout deleted successfully.\n");
            }

            workout_found = true;
            break;
        }
    }

    if (!workout_found) {
        printf("Workout not found.\n");
    }
}