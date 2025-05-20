//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define structure for storing workout data
struct Workout {
    char name[50];
    int sets;
    int reps;
    int weight;
};

// function to print workout data in a formatted table
void printWorkout(struct Workout workout) {
    printf("| %-25s | %-10d | %-10d | %-10d |\n", workout.name, workout.sets, workout.reps, workout.weight);
}

int main() {
    int option = 0;
    int count = 0;
    struct Workout workouts[100];
    printf("==========================\n");
    printf("Fitness Tracker Application\n");
    printf("==========================\n\n");

    while (option != 4) {
        printf("Please select an option:\n");
        printf("1. Add workout data\n");
        printf("2. View workout history\n");
        printf("3. Delete workout data\n");
        printf("4. Quit\n");
        printf("Option: ");
        scanf("%d", &option);
        printf("\n");

        switch (option) {
            case 1:
                printf("Add workout data\n");
                struct Workout workout;
                printf("Enter workout name: ");
                scanf("%s", &workout.name);
                printf("Enter number of sets: ");
                scanf("%d", &workout.sets);
                printf("Enter number of reps: ");
                scanf("%d", &workout.reps);
                printf("Enter weight: ");
                scanf("%d", &workout.weight);
                workouts[count] = workout;
                count++;
                printf("\nWorkout data added!\n\n");
                break;

            case 2:
                printf("View workout history\n");
                printf("| %-25s | %-10s | %-10s | %-10s |\n", "Workout Name", "Sets", "Reps", "Weight");
                for (int i = 0; i < count; i++) {
                    printWorkout(workouts[i]);
                }
                printf("\n");
                break;

            case 3:
                printf("Delete workout data\n");
                if (count == 0) {
                    printf("No workout data available to delete.\n\n");
                } else {
                    printf("Enter index of workout to delete: ");
                    int index;
                    scanf("%d", &index);
                    if (index < 0 || index >= count) {
                        printf("Invalid index.\n\n");
                    } else {
                        for (int i = index; i < count - 1; i++) {
                            workouts[i] = workouts[i + 1];
                        }
                        count--;
                        printf("\nWorkout data deleted!\n\n");
                    }
                }
                break;

            case 4:
                printf("Thank you for using Fitness Tracker Application. Goodbye!");
                break;

            default:
                printf("Invalid option. Please try again.\n\n");
                break;
        }
    }

    return 0;
}