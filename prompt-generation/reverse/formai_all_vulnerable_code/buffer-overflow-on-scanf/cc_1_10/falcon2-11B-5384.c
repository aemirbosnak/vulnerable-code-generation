//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void print_welcome_message();
void print_menu();
void add_workout();
void display_workouts();
void display_workout(int workout_id);
void delete_workout(int workout_id);
void update_workout(int workout_id);
void exit_program();

int main() {
    // Initialize variables
    int choice = 0;
    int workout_id = 0;

    do {
        print_welcome_message();
        print_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_workout();
                break;
            case 2:
                display_workouts();
                break;
            case 3:
                printf("Enter workout ID: ");
                scanf("%d", &workout_id);
                display_workout(workout_id);
                break;
            case 4:
                printf("Enter workout ID: ");
                scanf("%d", &workout_id);
                delete_workout(workout_id);
                break;
            case 5:
                printf("Enter workout ID: ");
                scanf("%d", &workout_id);
                update_workout(workout_id);
                break;
            case 6:
                exit_program();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice!= 6);

    return 0;
}

// Function definitions
void print_welcome_message() {
    printf("Welcome to the Fitness Tracker!\n");
}

void print_menu() {
    printf("\n1. Add Workout\n2. Display Workouts\n3. Display Workout Details\n4. Delete Workout\n5. Update Workout\n6. Exit\n");
}

void add_workout() {
    int workout_type = 0;
    int reps = 0;
    int sets = 0;
    int weight = 0;

    printf("Enter workout type: ");
    scanf("%d", &workout_type);

    printf("Enter number of reps: ");
    scanf("%d", &reps);

    printf("Enter number of sets: ");
    scanf("%d", &sets);

    printf("Enter weight: ");
    scanf("%d", &weight);

    printf("Enter workout description: ");
    char workout_description[100];
    scanf("%s", workout_description);

    int new_workout_id = rand() % 1000000;

    printf("Workout added successfully with ID %d.\n", new_workout_id);

    printf("Workout Type: %d\n", workout_type);
    printf("Number of Reps: %d\n", reps);
    printf("Number of Sets: %d\n", sets);
    printf("Weight: %d\n", weight);
    printf("Description: %s\n", workout_description);
}

void display_workouts() {
    int num_workouts = 0;
    int workout_id = 0;

    printf("Displaying %d workouts:\n", num_workouts);

    for (int i = 0; i < num_workouts; i++) {
        printf("Workout ID: %d\n", workout_id);
        printf("Workout Type: %d\n", workout_id);
        printf("Number of Reps: %d\n", workout_id);
        printf("Number of Sets: %d\n", workout_id);
        printf("Weight: %d\n", workout_id);
        printf("Description: %s\n", workout_id);

        workout_id++;
    }
}

void display_workout(int workout_id) {
    printf("Displaying workout details for workout ID %d:\n", workout_id);
    printf("Workout Type: %d\n", workout_id);
    printf("Number of Reps: %d\n", workout_id);
    printf("Number of Sets: %d\n", workout_id);
    printf("Weight: %d\n", workout_id);
    printf("Description: %s\n", workout_id);
}

void delete_workout(int workout_id) {
    printf("Deleting workout with ID %d:\n", workout_id);
}

void update_workout(int workout_id) {
    int workout_type = 0;
    int reps = 0;
    int sets = 0;
    int weight = 0;

    printf("Updating workout with ID %d:\n", workout_id);
}

void exit_program() {
    printf("Exiting program.\n");
}