//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXERCISES 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    float duration;
    int calories;
} Exercise;

typedef struct {
    Exercise exercises[MAX_EXERCISES];
    int numExercises;
} Workout;

void addExercise(Workout *workout) {
    if (workout->numExercises >= MAX_EXERCISES) {
        printf("Cannot add additional exercises.\n");
        return;
    }
    
    printf("Enter exercise name: ");
    fgets(workout->exercises[workout->numExercises].name, MAX_NAME_LENGTH, stdin);
    printf("Enter exercise duration (in minutes): ");
    scanf("%f", &workout->exercises[workout->numExercises].duration);
    printf("Enter calories burned: ");
    scanf("%d", &workout->exercises[workout->numExercises].calories);
    
    // Remove newline from fgets() input
    workout->exercises[workout->numExercises].name[strlen(workout->exercises[workout->numExercises].name)-1] = '\0';
    
    printf("%s added to workout.\n", workout->exercises[workout->numExercises].name);
    workout->numExercises++;
}

void printWorkout(Workout *workout) {
    printf("Workout:\n");
    for (int i = 0; i < workout->numExercises; i++) {
        printf("%s: %.2f minutes, %d calories\n", workout->exercises[i].name, 
               workout->exercises[i].duration, workout->exercises[i].calories);
    }
}

int main() {
    Workout workout;
    workout.numExercises = 0;
    int choice;
    
    do {
        printf("Fitness Tracker Main Menu:\n");
        printf("1. Add exercise to workout\n");
        printf("2. View workout\n");
        printf("3. Exit program\n");
        
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addExercise(&workout);
                break;
            case 2:
                printWorkout(&workout);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}