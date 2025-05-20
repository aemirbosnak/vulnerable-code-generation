//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_WORKOUTS 10
#define MAX_TIME 100


struct workout {
    char name[50];
    int duration;
    int calories;
};

void print_workout(struct workout w) {
    printf("Name: %s\n", w.name);
    printf("Duration: %d minutes\n", w.duration);
    printf("Calories burned: %d\n", w.calories);
    printf("\n");
}

int main() {
    int num_workouts = 0;
    struct workout workouts[MAX_WORKOUTS];
    char input[100];
    int choice;
    int duration;
    int calories;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your name: ");
    scanf("%s", input);
    printf("Hello, %s! Let's get started.\n\n", input);

    while (1) {
        printf("Please choose an option:\n");
        printf("1. Add a workout\n");
        printf("2. View workout history\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_workouts >= MAX_WORKOUTS) {
                    printf("You have reached the maximum number of workouts.\n");
                } else {
                    printf("Enter the name of the workout: ");
                    scanf("%s", workouts[num_workouts].name);
                    printf("Enter the duration of the workout (in minutes): ");
                    scanf("%d", &duration);
                    printf("Enter the number of calories burned: ");
                    scanf("%d", &calories);
                    workouts[num_workouts].duration = duration;
                    workouts[num_workouts].calories = calories;
                    num_workouts++;
                    printf("Workout added successfully!\n");
                }
                break;
            case 2:
                if (num_workouts == 0) {
                    printf("You have not added any workouts yet.\n");
                } else {
                    printf("Your workout history:\n");
                    for (int i = 0; i < num_workouts; i++) {
                        print_workout(workouts[i]);
                    }
                }
                break;
            case 3:
                printf("Thank you for using the Fitness Tracker! Goodbye, %s.\n", input);
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}